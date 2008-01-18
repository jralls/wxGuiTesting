///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRMenuSelectionEvent.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
// Modifications: John Ralls, 2007-2008
// Modifications Copyright: (c) 2008 John Ralls
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRMenuSelectionEvent.h"
#endif

#include "swCRMenuSelectionEvent.h"

#include <wxGuiTest/swWxGuiTestHelper.h>
#include <wxGuiTest/swCRWindowHierarchyHandler.h>
#include <wxGuiTest/swCRCppEmitter.h>

using namespace swTst;


CRMenuSelectionEvent::CRMenuSelectionEvent (wxEvent *event) :
    CRCapturedEvent (event),
    m_isTool(false),
//    m_isFromMainFrameMenuBar = false,
    m_isFromTopWindow(false),
    m_eventObjectIsMenu(false),
    m_isFromPopupMenu (false),
    m_isChecked(false),
    m_isControl(false)
{}


CRMenuSelectionEvent::~CRMenuSelectionEvent ()
{
    // Nothing to do
}


bool CRMenuSelectionEvent::processTopFrame(wxFrame* topFrame) {
    wxMenuBar* menuBar = topFrame->GetMenuBar ();
    wxASSERT (menuBar != NULL);
            
    //TODO/Note: Bug in wxGTK (until v2.8.6) -- event object is menu
    // instead of (top level window) frame!
    // Cf. http://thread.gmane.org/gmane.comp.lib.wxwidgets.devel/93324

    if (m_event->GetEventObject () == topFrame) {

	m_isFromTopWindow = true;
	processMainMenu(menuBar);
	return true;
    }
    return false;

}


bool CRMenuSelectionEvent::processTopMenu(wxMenu* menu) {
    m_eventObjectIsMenu = true;
    // Officially (?) the wxMenu does not know anything about its parent
    // the menu bar, nor its parent window classes like frames:
    wxMenuBar* menuBar = menu->GetMenuBar ();
    wxASSERT (menuBar != NULL);

    wxWindow *topWdw = wxTheApp->GetTopWindow ();
    wxFrame *topFrame = dynamic_cast< wxFrame * >(topWdw);
    if (topFrame != NULL && topFrame->GetMenuBar () == menuBar) {

	m_isFromTopWindow = true;
	processMainMenu(menuBar);
	return true;
    }
    //TODO: else -> the menu has a menu bar in a non-top window!
    return false;
}

void CRMenuSelectionEvent::processMainMenu (wxMenuBar* menuBar) {

    wxMenu *menu;
    wxMenuItem *menuItem = menuBar->FindItem (m_event->GetId (), &menu);
    wxASSERT (menuItem != NULL);
    wxASSERT (menu != NULL);
    bool isCheckable = menuItem->IsCheckable ();
    // If menu item is part of a sub menu -> go up to "real" menu
    while (menu->GetParent () != NULL) {

	menu = menu->GetParent ();
    }

    bool menuFound = false;
    int menuIdx = 0;
    while ((!menuFound) && (menuIdx < menuBar->GetMenuCount ())) {

	if (menuBar->GetMenu (menuIdx) == menu) {

	    menuFound = true;

	} else {

	    menuIdx++;
	}
    }
    wxASSERT (menuIdx < menuBar->GetMenuCount ());
    m_menuLabel = menuBar->GetLabelTop (menuIdx);

    m_menuItemLabel = menuBar->GetLabel (m_event->GetId ());
     // (A) Find out if it is a checkable menu item; and if so, if it is checked
    // or unchecked:
   if (isCheckable)
	processCheckable();
}

bool CRMenuSelectionEvent::processPopUp (wxMenu* menu) {

    wxMenu *menu2;
    wxMenuItem *menuItem = menu->FindItem (m_event->GetId (), &menu2);
    wxASSERT (menuItem != NULL);
    wxASSERT (menu2 != NULL);
    bool isCheckable = menuItem->IsCheckable ();
//wxASSERT (menu2 != menu);
// If menu item is part of a sub menu -> go up to "real" menu
//while (menu->GetParent () != NULL) {
//
//    menu = menu->GetParent ();
//}
    m_popupMenuKey = WxGuiTestHelper::FindPopupMenuKey (menu);
    if (m_popupMenuKey.IsEmpty ())
	return false;

    m_isFromPopupMenu = true;
    // Only for pop-up menus:
    m_menuLabel = menu->GetTitle ();

    m_menuItemLabel = menu->GetLabel (m_event->GetId ());

    // Find container for m_event->GetEventObject() to be used for
    //  event handling parent?
    wxWindow *evtHandlerWdw = WxGuiTestHelper::FindPopupMenuEvtHandlerWdw (m_popupMenuKey);
    wxASSERT (evtHandlerWdw != NULL);

    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);
    m_parentContainerName = hierarchy->FindContainerName (evtHandlerWdw);
    wxASSERT (!m_parentContainerName.IsEmpty ());
    // (A) Find out if it is a checkable menu item; and if so, if it is checked
    // or unchecked:

    if (isCheckable)
	processCheckable();
    return true;
}
bool CRMenuSelectionEvent::processToolBar(wxToolBar *toolBar) {

// We're here because Process detected a toolbar via ClassInfo
    int id = m_event->GetId();
    if (id == wxID_SEPARATOR)
	return true; //It's a separator and we're not interested.
    wxToolBarToolBase* tool = toolBar->FindById(id);
    if (tool == NULL) {
	wxLogDebug(_T("Tool %d not found"), id);
	return true;
    }
    if (tool->IsSeparator()) 
	return true;

    m_isTool = true;

    m_toolbarName = toolBar->GetName();
    CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
    wxASSERT (hierarchy != NULL);
    m_parentContainerName = hierarchy->FindContainerName (toolBar);
    wxASSERT (!m_parentContainerName.IsEmpty ());

    if (tool->IsControl()) {
	m_isControl = true;
	wxControl* control = tool->GetControl();
	m_controlName = control->GetClassInfo()->GetClassName();
	wxLogDebug(_T("Tool %d is a %s"), id, m_controlName.c_str());
//At this point, we hope that the control's own events will fire the
//appropriate handler. We may, therefore, be able to get rid of this section.
    }
    if (tool->CanBeToggled() && tool->IsToggled())
	    m_isChecked = true;

}



void CRMenuSelectionEvent::processCheckable() {
    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    if ((cmdEvt->GetInt () == 1) || (cmdEvt->IsChecked ())) {
    
        m_isChecked = true;
    }
}


void CRMenuSelectionEvent::Process (CRCapturedEvent **pendingEvt)
{
    // (1) Or if it is part of top level window:
    wxWindow *topWdw = wxTheApp->GetTopWindow ();
    wxFrame *topFrame = dynamic_cast< wxFrame * >(topWdw);
    if (topFrame != NULL && processTopFrame(topFrame))
	return;
    // (2) Or is it from wxGTK <= v2.8.6 or wxMac (event object is wxMenu):
    // Menu and menu item label for all menu bar menus; NOT pop-up menus:
    // (3) Or a pop-up menu:
    wxMenu *menu = wxDynamicCast (m_event->GetEventObject (), wxMenu);
    if (menu != NULL && (processTopMenu(menu) || processPopUp(menu)))
	return;
    // (4) Or another menubar: TODO

    // (5) Or a tool from a toolbar?
    wxToolBar *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (),
                wxToolBar);
    if (wdwEvtObject != NULL && processToolBar(wdwEvtObject))
	return;
    // Finally, if still not processed emit comment with infos about event, and
    // make the event irrelevant??? TODO

}


void CRMenuSelectionEvent::EmitCpp ()
{
    // (I) Expected emitting for menu items:
    // (1) Menu item is part of top level window menu:
    /*
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);

    ...
    */

    // (2) Event object is menu, and menu item is part of top level window menu:
    /*
    wxMenu *menuMenu;
    wxMenuItem *checkableMenuItemMenuItem = menuBar->FindItem (
            checkableMenuItemId, &menuMenu);
    CPPUNIT_ASSERT_MESSAGE ("Menu item 'CheckableMenuItem' not found", 
            checkableMenuItemMenuItem != NULL);
    CPPUNIT_ASSERT_MESSAGE ("Menu for menu item 'CheckableMenuItem' not found",
            menuMenu != NULL);
    // Check if checkable menu item is not already checked?
    // if (!checkableMenuItemMenuItem->IsChecked ()) { ...
    swTst::WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (
            checkableMenuItemMenuItemId, menuMenu);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */

    // (3) Menu item is part of a pop-up menu:
    /*
    wxMenu *popupMenu = swTst::WxGuiTestHelper::FindPopupMenu (
            "sccDatasetBrowserPopupMenu");
    CPPUNIT_ASSERT_MESSAGE ("Pop-up menu not found", popupMenu != NULL);    
    int selectMenuItemId = popupMenu->FindItem (_("Select"));
    CPPUNIT_ASSERT_MESSAGE ("Select menu item ID not found",
            selectMenuItemId != wxNOT_FOUND);

    swTst::WxGuiTestEventSimulationHelper::SelectMenuItem (
            selectMenuItemId, dsTreeCtrl);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */

    // (A) + (1) Checkable menu item is part of main frame menubar:
    /*
    int dsBrowserMenuItemId = menuBar->FindMenuItem (_("Toolboxes"),
            _("Dataset Browser"));
    CPPUNIT_ASSERT_MESSAGE ("Dataset browser menu item ID not found",
            dsBrowserMenuItemId != wxNOT_FOUND);
    wxMenuItem *dsBrowserMenuItem = menuBar->FindItem (dsBrowserMenuItemId);
    CPPUNIT_ASSERT_MESSAGE ("Dataset browser menu item not found",
            dsBrowserMenuItem != NULL);
    if (!dsBrowserMenuItem->IsChecked ()) {

        swTst::WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (
                dsBrowserMenuItemId, mainFrame);
        swTst::WxGuiTestHelper::FlushEventQueue ();
    }
    */

    // (II) Expected emitting for toolbar tools:
    /*
    sw::ToolBar *toolBar = sw::ToolBarRegistry::GetInstance ()->
            FindToolBarByName ("ToolBarName");
    CPPUNIT_ASSERT_MESSAGE ("Toolbar 'ToolBarName' not found",
            toolBar != NULL);
    // (a) Standard tool IDs (wxID_LOWEST < stdID < wxID_HIGHEST) don't need to be
    // looked up:
    swTst::WxGuiTestEventSimulationHelper::ToggleTool (m_event->GetId (),
            m_isChecked, toolBar, toolBar);
    // (b) others should be registered in the GuiObjectManager:
    sw::GuiObject *guiObject = sw::GuiObjectManager::GetInstance ()->
            FindGuiObject ("GuiObjectName");
    CPPUNIT_ASSERT_MESSAGE ("GuiObject 'GuiObjectName' not found",
            guiObject != NULL);
    sw::ToolGuiObject *toolGuiObject = dynamic_cast < sw::ToolGuiObject * >(
            guiObject);
    CPPUNIT_ASSERT_MESSAGE ("GuiObject 'GuiObjectName' is not a ToolGuiObject",
            toolGuiObject != NULL);
    int toolId = sw::GuiObjectManager::GetInstance ()->FindId (toolGuiObject);
    swTst::WxGuiTestEventSimulationHelper::ToggleTool (toolId, m_isChecked,
            toolBar, toolBar);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */

    CRCppEmitter *emitter = CRCppEmitter::GetInstance ();
    wxString str;

    if (!m_isTool) {

        //TODO: prevent double emitting of:
        //  - eventHdlVarName (mainframe; pop-up: event object container)
        //  - menuItemContVarName (menubar; pop-up: menu)
        wxString eventHdlVarName, menuItemContVarName, menuItemIdVarName;

	if (m_isFromTopWindow) {

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Application top window invalid\", wxTheApp->GetTopWindow () != NULL);");
            emitter->AddCode (str);
    
            eventHdlVarName = _T("topFrame");
            str.Clear ();
            str << _T("wxFrame *") << eventHdlVarName <<
		_T(" = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());");
            emitter->AddCode (str);
    
            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Top window is not a frame\", ")
                    << eventHdlVarName << _T(" != NULL);");
            emitter->AddCode (str);
        
        } 
	else if (m_isFromPopupMenu) {
        
            menuItemContVarName = emitter->MakeVarName (m_menuLabel, 
                    _T("PopupMenu"));
            str.Clear ();
            str << _T("wxMenu *") << menuItemContVarName <<
                    _T(" = swTst::WxGuiTestHelper::FindPopupMenu (\"") <<
                    m_popupMenuKey << _T("\");");
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Pop-up menu '") << 
                    m_popupMenuKey << _T("' not found\", ") <<
                    menuItemContVarName << _T(" != NULL);");
            emitter->AddCode (str);

            menuItemIdVarName = emitter->MakeVarName (m_menuItemLabel,
                    _T("MenuItemId"));
            str.Clear ();
            str << _T("int ") << menuItemIdVarName << _T(" = ") << 
                    menuItemContVarName << _T("->FindItem (_(\")_T(") << 
                    m_menuItemLabel << _T(")\"));");
            emitter->AddCode (str);
        
            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Menu item ID '") << 
                    m_menuItemLabel << _T("' not found\", ") << menuItemIdVarName <<
                    _T(" != wxNOT_FOUND);");
            emitter->AddCode (str);

            eventHdlVarName = emitter->AddContainerLookupCode (
                    m_parentContainerName,
                    wxString::Format (_T("pop-up menu '%s'"), 
                    m_menuLabel.c_str ()));
	}// m_isFromPopupMenu, m_isFromTopWindow
    
        if (// m_isFromMainFrameMenuBar ||
	    m_isFromTopWindow) {

            menuItemContVarName = _T("menuBar");
            str.Clear ();
            str << _T("wxMenuBar *") << menuItemContVarName << _T(" = ") <<
                    eventHdlVarName << _T("->GetMenuBar ();");
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Menubar not found\", ") <<
                    menuItemContVarName << _T(" != NULL);");
            emitter->AddCode (str);

            menuItemIdVarName = emitter->MakeVarName (m_menuItemLabel,
                    _T("MenuItemId"));
            str.Clear ();
            str << _T("int ") << menuItemIdVarName << _T(" = ") << 
                    menuItemContVarName << _T("->FindMenuItem (_(\"") << 
                    m_menuLabel << _T("\"), _(\"") << m_menuItemLabel << _T("\"));");
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Menu item ID '") << 
                    m_menuItemLabel << _T("' not found\", ") << 
                    menuItemIdVarName << _T(" != wxNOT_FOUND);");
            emitter->AddCode (str);
        }

        if (m_isChecked) {

            wxString menuVarName;
            if (m_eventObjectIsMenu) {

                menuVarName = emitter->MakeVarName (m_menuLabel,
                        _T("Menu"));

                str.Clear ();
                str << _T("wxMenu *") << menuVarName << _T(";");
                emitter->AddCode (str);
            }

            wxString menuItemVarName = emitter->MakeVarName (m_menuItemLabel,
                    _T("MenuItem"));

            str.Clear ();
            if (!m_eventObjectIsMenu) {

                str << _T("wxMenuItem *") << menuItemVarName << _T(" = ") <<
                        menuItemContVarName << _T("->FindItem (") << 
                        menuItemIdVarName << _T(");");

            } else {

                str << _T("wxMenuItem *") << menuItemVarName << _T(" = ") <<
                        menuItemContVarName << _T("->FindItem (") << 
                        menuItemIdVarName << _T(", &") <<
                        menuVarName << _T(");");
            }
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Menu item '") << 
                    m_menuItemLabel << _T("' not found\", ") << menuItemVarName << 
                    _T(" != NULL);");
            emitter->AddCode (str);

            if (m_eventObjectIsMenu) {

                str.Clear ();
                str << _T("CPPUNIT_ASSERT_MESSAGE (\"Menu for menu item '") << 
                        m_menuItemLabel << _T("' not found\", ") << menuVarName << 
                        _T(" != NULL);");
                emitter->AddCode (str);
            }

            emitter->AddComment (_T("Check if checkable menu item is not already checked?"));
            str.Clear ();
            str << _T("if (!") << menuItemVarName << _T("->IsChecked ()) { ...");
            emitter->AddComment (str);

            str.Clear ();
            if (!m_eventObjectIsMenu) {

                str << _T("swTst::WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (") <<
                        menuItemIdVarName << _T(", ") << eventHdlVarName << _T(");");

            } else { //!m_eventObjectIsMenu

                str << _T("swTst::WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (") <<
                        menuItemIdVarName << _T(", ") << menuVarName << _T(");");
            }
            emitter->AddCode (str);

        } else { //m_isChecked

            str.Clear ();
            str << _T("swTst::WxGuiTestEventSimulationHelper::SelectMenuItem (") 
                    << menuItemIdVarName << _T(", ") << eventHdlVarName << _T(");");
            emitter->AddCode (str);
        }

    } else { //!m_isTool
        wxString toolBarVarName = emitter->MakeVarName (m_toolbarName);
	wxString containerVarName = emitter->MakeVarName(m_parentContainerName);
	wxString containerWdwVarName = emitter->MakeVarName(m_parentContainerName,
							    _T("Wdw"));

        str.Clear ();
	str << _T("wxWindow* ") << containerWdwVarName 
	    << _T(" = wxWindow::FindWindowByName( _T(\"") 
	    << m_parentContainerName << _T("\"));");
        emitter->AddCode (str);

        str.Clear ();
        str << _T("CPPUNIT_ASSERT_MESSAGE (\"Parent Window '") 
	    << m_parentContainerName << _T("' not found\", ") 
	    << containerWdwVarName << _T(" != NULL);");
        emitter->AddCode (str);

        str.Clear ();
	str << _T("wxFrame* ") << containerVarName << _T(" = wxDynamicCast(") 
	    << containerWdwVarName << _T(", wxFrame);");
        emitter->AddCode (str);

        str.Clear ();
        str << _T("CPPUNIT_ASSERT_MESSAGE (\"Converting Window for frame '") 
	    << m_parentContainerName << _T("' not found\", ") 
	    << containerVarName << _T(" != NULL);");
        emitter->AddCode (str);

        str.Clear ();
        str << _T("wxToolBar* ") << toolBarVarName 
	    << _T(" = ") << containerVarName << _T("->GetToolBar();");
        emitter->AddCode (str);

        str.Clear ();
        str << _T("CPPUNIT_ASSERT_MESSAGE (\"Toolbar '") << m_toolbarName 
	    << _T("' not found\", ") << toolBarVarName << _T(" != NULL);");
        emitter->AddCode (str);

	wxString isCheckedBoolStr = m_isChecked ? _T("true") : _T("false");

	str.Clear ();
	if (!m_isControl) {
	    str << _T("swTst::WxGuiTestEventSimulationHelper::ToggleTool(") 
		<< m_event->GetId () << _T(", ") << isCheckedBoolStr 
		<< _T(", ") << toolBarVarName << _T(", ") << containerVarName 
		<< _T(");");
	    emitter->AddCode (str);
	}

    }
    str.Clear ();
    str << _T("swTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}



