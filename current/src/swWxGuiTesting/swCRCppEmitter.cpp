///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRCppEmitter.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRCppEmitter.h"
#endif

#include <wxGuiTest/swCRCppEmitter.h>

#include <Exception/swWxLogicErrorException.h>

namespace swTst {


// Init single instance:
CRCppEmitter *CRCppEmitter::ms_instance = NULL;


CRCppEmitter::CRCppEmitter ()
{
    this->SetTabSize (4);
    m_maxChars = 80;
}


CRCppEmitter::~CRCppEmitter ()
{
    // Finish copying file after capture keyword:
    while (!m_origFile.Eof ()) {

        wxString line = m_origFile.GetNextLine ();
        m_newFile.AddLine (line);
    }

    m_origFile.Close ();
    m_newFile.Write ();
    m_newFile.Close ();

    m_contMap.clear ();
    m_varNameSet.clear ();
}


CRCppEmitter * CRCppEmitter::GetInstance ()
{
    if (ms_instance == NULL) {

        ms_instance = new CRCppEmitter ();
    }
    return ms_instance;
}


void CRCppEmitter::Destroy ()
{
    if (ms_instance != NULL) {

        delete ms_instance;
        ms_instance = NULL;
    }
}


void CRCppEmitter::SetTabSize (unsigned int size)
{
    m_tab = wxString (_T(' '), size);
}


unsigned int CRCppEmitter::GetTabSize () const
{
    return m_tab.Length ();
}


wxString CRCppEmitter::GetTab () const
{
    return m_tab;
}


void CRCppEmitter::SetTestCaseFileContext (const wxString &filename, int lineNmb)
{
    wxASSERT_MSG (::wxFileExists (filename), _T("File does not exist"));
    wxASSERT (lineNmb != 0);
    if (!m_origFile.Open (filename)) {

        throw new sw::WxLogicErrorException (wxString::Format (
        		_T("Could not open test case file: %s"), filename.c_str ()));
    }
    // Find unique filename with prefix of current test case filename in order
    // to prevent file overwritting and create "backup" files, plus allow
    // debugging without side effects:
    wxString newFilename;
    unsigned int uniqueCnt = 0;
    do {

        uniqueCnt++;
        newFilename = wxString::Format (_T("%s.cr%d"), filename.c_str (), 
                uniqueCnt);

    } while (::wxFileExists (newFilename));
    if (!m_newFile.Create (newFilename)) {

        throw new sw::WxLogicErrorException (
        wxString::Format (_T("%s: %s"),
                _("Could not create bootstrap test case file"), 
                filename.c_str ()));
    }
    // Copy old file until line number or first occurence of capture keyword:
    const wxString CAPTURE_KEYWORD = _T("CAPTURE");
    bool isDone = false;
    wxString line = m_origFile.GetFirstLine ();
    while ((!isDone) && (!m_origFile.Eof ())) {

        if (lineNmb >= 0) {
            
            if ((lineNmb - 1) <= m_origFile.GetCurrentLine ()) {

                isDone = true;
            }

        } else {

            wxString stripped = line.Strip (wxString::both);
            if (CAPTURE_KEYWORD == stripped) {

                isDone = true;
            }
        }
        if (!isDone) {

            m_newFile.AddLine (line);
            line = m_origFile.GetNextLine ();
        }
    }
    // Write out current file - but is not finished yet:
    m_newFile.Write ();
}


wxString CRCppEmitter::GetCaptureFilename() const {
    return m_newFile.GetName ();
}

void CRCppEmitter::AddComment (wxString str)
{
    wxArrayString COMMENT_BREAK_CHARS;
    COMMENT_BREAK_CHARS.Add (_T(" "));
    COMMENT_BREAK_CHARS.Add (_T(","));
    COMMENT_BREAK_CHARS.Add (_T("."));
    COMMENT_BREAK_CHARS.Add (_T(":"));
    COMMENT_BREAK_CHARS.Add (_T("!"));
    COMMENT_BREAK_CHARS.Add (_T("?"));

    wxString pre = m_tab + _T("// ");
    const unsigned int MIN_CONTENT_LEN = 20;
    str.Prepend (pre);

    unsigned int idx;
    do {

        m_newFile.AddLine (this->BreakString (str, COMMENT_BREAK_CHARS, idx,
                pre.Length () + MIN_CONTENT_LEN));
        if (idx != 0) {

            str = str.Mid (idx);
            str.Prepend (pre);
        }

    } while (idx != 0);
    // Again, flush current file status (but not finished yet):
    m_newFile.Write ();
}


void CRCppEmitter::AddCode (wxString str)
{
    wxArrayString CODE_BREAK_CHARS;
    CODE_BREAK_CHARS.Add (_T(" "));
    CODE_BREAK_CHARS.Add (_T(","));
    CODE_BREAK_CHARS.Add (_T("."));
    CODE_BREAK_CHARS.Add (_T("("));
    CODE_BREAK_CHARS.Add (_T("::"));
    CODE_BREAK_CHARS.Add (_T("->"));

    wxString pre = m_tab;
    const unsigned int MIN_CONTENT_LEN = 20;
    str.Prepend (pre);

    bool isInString = false;
    unsigned int idx;
    do {

        wxString line = this->BreakString (str, CODE_BREAK_CHARS, idx,
                pre.Length () + MIN_CONTENT_LEN, true);
        // Don't break line within string constants, use line splicing instead:
        isInString = this->HasBrokenInString (line);
        if (isInString) {

            line.Append (_T("\""));
        }

        m_newFile.AddLine (line);
        if (idx != 0) {

            str = str.Mid (idx);

            // Change string literal line splicing from appending "\" to end with
            // "\"" and start next line with "\"":
            if (isInString) {

                str.Prepend (_T("\""));
            }

            for (int i = 0; i < 3; i++) {

                str.Prepend (pre);
            }
        }

    } while (idx != 0);
    // Again, flush current file status (but not finished yet):
    m_newFile.Write ();
}


void CRCppEmitter::AddVerbatimStringWithLineBreaks (wxString str)
{
    m_newFile.AddLine (str);
    // Again, flush current file status (but not finished yet):
    m_newFile.Write ();
}


wxString CRCppEmitter::AddContainerLookupCode (const wxString &containerName,
        const wxString &itemDesc, const wxString &containerVarNameSuffix)
{
    // Look if container lookup code has already been emitted:
    ContainerMap::iterator it = m_contMap.find (containerName);
    if (it != m_contMap.end ()) {

        return it->second;
    }
    // Has not been emitted yet!
    // Make first letter of container variable name lower case:
    wxString containerVarName = MakeFirstCharLowerCase(containerName +
            containerVarNameSuffix);
    // Make container variable name unique:
    unsigned int cnt = 0;
    wxString uniqueContainerVarName = containerVarName;
    while ((this->IsContainerVarNameDuplicate (uniqueContainerVarName)) ||
            (m_varNameSet.find (uniqueContainerVarName) != m_varNameSet.end ())) {

        cnt++;
        uniqueContainerVarName = wxString::Format (_T("%s%d"), containerVarName.c_str (), cnt);
    }
    m_contMap[containerName] = uniqueContainerVarName;
    m_varNameSet.insert (uniqueContainerVarName);
    // And acutal emitting:
    wxString lookup, assert;
    lookup << _T("wxWindow *") << uniqueContainerVarName << 
            _T(" = wxWindow::FindWindowByName (_T(\"") << containerName << _T("\"));");
    this->AddCode (lookup);

    assert << _T("CPPUNIT_ASSERT_MESSAGE (\"Container window ");
    if (itemDesc.IsEmpty ()) {

        assert << _T("'") << containerName << _T("'");

    } else {

        assert << _T("for ") << itemDesc;
    }
    assert << _T(" not found\", ") << uniqueContainerVarName << _T(" != NULL);");
    this->AddCode (assert);

    return uniqueContainerVarName;
}


wxString CRCppEmitter::MakeVarName (const wxString &name,
        const wxString &suffix)
{
    // Remove '&' and ' ' characters -- the former is often used for
    // accelerator keys in menus et al.:
    wxString varNameToClean = name;
    varNameToClean.Replace (_T(" "), _T(""));
    varNameToClean.Replace (_T("&"), _T(""));
    // Extract alphanumeric characters till first non-alphanumeric char (e.g.
    // "&Open...  Ctrl+O" => "Open...  Ctrl+O" => "Open"):
    wxString varName;
    if ((isalpha (varNameToClean.GetChar (0))) || (varNameToClean.GetChar (0) == '_')) {

        varName.Append (varNameToClean.GetChar (0));

    } else {

        // Variable names must start with alphabetical character:
        varName.Append (_T("var"));
    }
    bool foundTerminator = false;
    int idx = 1;
    while ((!foundTerminator) && (idx < varNameToClean.Length ())) {

        if ((isalnum (varNameToClean.GetChar (idx))) || (varNameToClean.GetChar (idx) == '_')) {

            varName.Append (varNameToClean.GetChar (idx));

        } else {

            foundTerminator = true;
        }
        idx++;
    }
    // Make first letter lower case:
    varName = MakeFirstCharLowerCase(varName);
    // Append suffix before unifying:
    varName.Append (suffix);
    // Make variable name unique:
    unsigned int cnt = 0;
    wxString uniqueVarName = varName;
    while ((this->IsContainerVarNameDuplicate (uniqueVarName)) ||
            (m_varNameSet.find (uniqueVarName) != m_varNameSet.end ())) {

        cnt++;
        uniqueVarName = wxString::Format (_T("%s%d"), varName.c_str (), cnt);
    }
    wxASSERT(!uniqueVarName.IsEmpty());
    m_varNameSet.insert (uniqueVarName);

    return uniqueVarName;
}


wxString CRCppEmitter::BreakString (const wxString &str,
        const wxArrayString &breakStrs, unsigned int &idx, int minIdx,
        bool isCode) const
{
    if (str.Length () > m_maxChars) {

        size_t foundIdx = 0;
        size_t maxFoundIdx = 0;
        unsigned int breakStrsIdx = 0;
        for (int i = 0; i < breakStrs.Count (); i++) {

            // Blanks at the line ends can be omitted (unless it is code):
            int breakStrLen;
            if (isCode) {

                breakStrLen = breakStrs.Item (i).Length ();

            } else {

                breakStrLen = breakStrs.Item (i).Strip ().Length ();
            }

            foundIdx = str.rfind (breakStrs.Item (i),
                    m_maxChars - breakStrLen);
            if (foundIdx != wxString::npos) {
                
                // Prevent line break in non-integer number code emitting: 
                if (breakStrs.Item (i) == _T(".")) {
                    // 1. Check that "." is not in a string
                    wxString line = str.Left (foundIdx);
                    if (!HasBrokenInString(line)) {
                        // 2. Check that all characters before "." are digits,
                        // prepended by "," and whitespace
                        int charIdx = foundIdx - 1;
                        bool foundComma = false;
                        bool foundWhitespace = false;
                        bool finished = false;
                        while (charIdx > 0 && !finished) {
                            if (isdigit (line.GetChar (charIdx))) {
                                if (foundWhitespace || foundComma) {
                                    finished = true;
                                }
                                charIdx--;
                            } else if (line.GetChar (charIdx) == ' ') {
                                if (foundComma) {
                                    finished = true;
                                }
                                foundWhitespace = true;
                                charIdx--;                                            
                            } else if (line.GetChar (charIdx) == ',') {
                                finished = true;
                                foundComma = true;
                                foundIdx = 0;
                            } else {
                                finished = true;
                            }
                        }
                    }
                }

                if (foundIdx > maxFoundIdx) {

                    maxFoundIdx = foundIdx;
                    breakStrsIdx = i;
                }
            }
        }
        // No breaking string found, break by brute force:
        if ((maxFoundIdx == 0) || ((minIdx > 0) && (maxFoundIdx < minIdx))) {

            idx = m_maxChars;
            return str.Left (m_maxChars);

        } else {

            idx = maxFoundIdx + breakStrs.Item (breakStrsIdx).Length ();
            // Blanks at the line ends can be omitted (unless it is code):
            wxString firstLine;
            if (isCode) {

                firstLine = str.Left (idx);

            } else {

                firstLine = str.Left (idx).Strip ();
            }
            return firstLine;
        }

    } else {

        idx = 0;
        return str;
    }
}


bool CRCppEmitter::HasBrokenInString (const wxString &line) const
{
    int freq = line.Freq ('"');
    return (freq % 2 == 1);
}


bool CRCppEmitter::IsContainerVarNameDuplicate (const wxString &str) const
{
    bool found = false;
    ContainerMap::const_iterator it = m_contMap.begin ();
    while ((!found) && (it != m_contMap.end ())) {

        if (str == it->second) {

            found = true;

        } else {

            it++;
        }
    }
    return found;
}


wxString CRCppEmitter::MakeFirstCharLowerCase (const wxString &str) const
{
    wxString firstChar = str.Mid(0, 1).Lower();
    return firstChar + str.Mid(1);
}

} // End namespace swTst

