///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/swCRCppEmitter.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWCRCPPEMITTER_H
#define SWCRCPPEMITTER_H

#ifdef __GNUG__
    #pragma interface "swCRCppEmitter.h"
#endif

#include "Common.h"

#include <map>
#include <set>

#include "wx/textfile.h"

namespace swTst {


/*! \class CRCppEmitter
    \brief Singleton emitting C++ code used for test case bootstrapping.
*/
class CRCppEmitter
{
public:
    /*! \fn static CRCppEmitter * GetInstance ()
        \brief Get single private instance (Singleton pattern).

        \return single private instance
    */
    static CRCppEmitter * GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();


    /*! \fn virtual void SetTabSize (unsigned int size)
        \brief Set new tabulator size.

        \param size new tabulator size
    */
    virtual void SetTabSize (unsigned int size);


    /*! \fn virtual unsigned int GetTabSize () const
        \brief Get current tabulator size.

        \return current tabulator size
    */
    virtual unsigned int GetTabSize () const;


    /*! \fn virtual wxString GetTab () const
        \brief Get current tabulator in the shape of a string (helper method).

        \return current tabulator
    */
    virtual wxString GetTab () const;


    /*! \fn virtual void SetTestCaseFileContext (const wxString &filename, int lineNmb = -1)
        \brief Set filename and line number of current test case capturing.

        The first valid line number is 1.

        \param filename name of current test case capturing
        \param lineNmb line number of current test case capturing (if set to -1
            the first CAPTURE macro occurence is used)
    */
    virtual void SetTestCaseFileContext (const wxString &filename, int lineNmb = -1);


    /*! \fn virtual wxString GetCaptureFilename () const
        \brief [TEST] Get filename of current capturing target.
        
        Only required for testing!

        \return current capturing target filename
    */
    virtual wxString GetCaptureFilename () const;
    

    /*! \fn virtual void AddComment (wxString str)
        \brief Add comment, no-na.

        \param str comment to add
    */
    virtual void AddComment (wxString str);


    /*! \fn virtual void AddCode (wxString str)
        \brief Add code, no-na.

        \param str code to add
    */
    virtual void AddCode (wxString str);


    /*! \fn virtual void AddVerbatimStringWithLineBreaks (wxString str)
        \brief Add long string verbatim, i.e. keep line breaks.

        \param str string to add
    */
    virtual void AddVerbatimStringWithLineBreaks (wxString str);


    /*! \fn virtual wxString AddContainerLookupCode (const wxString &containerName, const wxString &itemDesc = "", const wxString &containerVarNameSuffix = "")
        \brief Add code for container lookup.

        Prevents multiple outputs of the same container lookup code, thus, use
        returned actual container name in further code emitting.

        \param containerName name of container to emit lookup code
        \param itemDesc description of item initiating the container lookup;
            only used for emitted assertion message
        \param containerVarNameSuffix suffix for container variable name
        \return name of container variable in emitted code
    */
    virtual wxString AddContainerLookupCode (const wxString &containerName,
            const wxString &itemDesc = "",
            const wxString &containerVarNameSuffix = "");


    /*! \fn virtual wxString MakeVarName (const wxString &name, const wxString &suffix = "")
        \brief Make unique variable name based on given name.

        Stores returned variable name in container for guaranteeing future
        variable uniqueness as well.
        Suffix:  e.g. "&Open... Ctrl+O" + "MenuItemId"
          => "Open... Ctrl+O" + "MenuItemId"
          => "Open" + "MenuItemId"
          => "openMenuItemId"

        \param name base for unique variable name
        \param suffix optional suffix of variable name
        \return unique variable name based on given name
    */
    virtual wxString MakeVarName (const wxString &name,
            const wxString &suffix = "");

protected:
    /*! \fn CRCppEmitter ()
        \brief Constructor
    */
    CRCppEmitter ();


    /*! \fn virtual ~CRCppEmitter ()
        \brief Destructor
    */
    virtual ~CRCppEmitter ();


    /*! \fn virtual wxString BreakString (const wxString &str, const wxArrayString &breakStrs, unsigned int &idx, int minIdx = -1, bool isCode = false) const
        \brief Break string if exceeding line length after breakStrs.

        \param str string to break
        \param breakStrs characters used for breaking given string, if
            exceeding line length
        \param idx index in string to break of remaining string; or 0, if there
            is no remaining string
        \param minIdx line break may not occur before
        \param isCode if true, care must be taken with line splicing
        \return first line of correctly broken string
    */
    virtual wxString BreakString (const wxString &str,
            const wxArrayString &breakStrs, unsigned int &idx,
            int minIdx = -1, bool isCode = false) const;


    /*! \fn virtual bool HasBrokenInString (const wxString &line) const
        \brief Calculates, if given line has been broken in the middle of a
        string constant.

        This allows to use line splicing correctly: before by means of '\' at
        the end of line, now using '"' at the end and beginning of the code
        emitting.

        \param line line to investigate for string constant delimiters ('"' char)
        \return true, if line has been broken in the middle of a string constant
    */
    virtual bool HasBrokenInString (const wxString &line) const;


    /*! \fn virtual bool IsContainerVarNameDuplicate (const wxString &str) const
        \brief Checks, if given string is a duplicate of a container variable
        name.

        \param str string to check for duplication
        \return true, if given string is a duplicate
    */
    virtual bool IsContainerVarNameDuplicate (const wxString &str) const;

private:
    static CRCppEmitter *ms_instance;

    wxTextFile m_origFile, m_newFile;
    wxString m_tab;
    unsigned int m_maxChars;

    // Emit container lookup code only once -> map with container name,
    // container variable name:
    typedef std::map< wxString, wxString > ContainerMap;
    ContainerMap m_contMap;

    typedef std::set< wxString > StringSet;
    StringSet m_varNameSet;

private:
    // No copy and assignment constructor:
    CRCppEmitter (const CRCppEmitter &rhs);
    CRCppEmitter & operator= (const CRCppEmitter &rhs);
};

} // End namespace swTst

#endif // SWCRCPPEMITTER_H

