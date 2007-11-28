///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CaptureEvents/swCRMenuSelectionEvent.cpp
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swCRMenuSelectionEvent.h"
#endif

#include "swCRMenuSelectionEvent.h"

#include "swFrameFactory.h"
#include "swGuiObjectManager.h"
#include "swToolBarRegistry.h"
#include "swWxGuiTestHelper.h"
#include "swCRWindowHierarchyHandler.h"
#include "swCRCppEmitter.h"

namespace swTst {


CRMenuSelectionEvent::CRMenuSelectionEvent (wxEvent *event) :
CRCapturedEvent (event)
{
    m_isTool = false;
    m_isFromMainFrameMenuBar = false;
    m_isFromTopWindow = false;
    m_isFromPopupMenu = false;
    m_isChecked = false;
    m_isStdId = false;
}


CRMenuSelectionEvent::~CRMenuSelectionEvent ()
{
    // Nothing to do
}


void CRMenuSelectionEvent::Process (CRCapturedEvent **pendingEvt)
{
    bool found = false;
    wxMenuBar *menuBar = NULL;

    // (1) Find out if the affected menu item is in the main frame's menubar:
    if (sw::FrameFactory::GetInstance ()) {

        wxFrame *mainFrame = sw::FrameFactory::GetInstance ()->GetMainFrame ()->
                GetFrame ();
        wxASSERT (mainFrame != NULL);
        menuBar = mainFrame->GetMenuBar ();
        wxASSERT (menuBar != NULL);

        if (m_event->GetEventObject () == mainFrame) {

            m_isFromMainFrameMenuBar = true;
            found = true;
        }
    }
    // (2) Or if it is part of top level window:
    if (!found) {

        wxWindow *topWdw = wxTheApp->GetTopWindow ();
        wxFrame *topFrame = dynamic_cast< wxFrame * >(topWdw);
        if (topFrame != NULL) {

            menuBar = topFrame->GetMenuBar ();
            wxASSERT (menuBar != NULL);

            if (m_event->GetEventObject () == topFrame) {

                m_isFromTopWindow = true;
                found = true;
            }
        }
    }
    // Menu and menu item label for all menu bar menus; NOT pop-up menus:
    if (found) {

        wxMenu *menu;
        wxMenuItem *menuItem = menuBar->FindItem (m_event->GetId (), &menu);
        wxASSERT (menuItem != NULL);
        wxASSERT (menu != NULL);
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
    }
    // (3) Or a pop-up menu:
    if (!found) {

        wxMenu *menu = wxDynamicCast (m_event->GetEventObject (), wxMenu);
        if (menu != NULL) {

            wxMenu *menu2;
            wxMenuItem *menuItem = menu->FindItem (m_event->GetId (), &menu2);
            wxASSERT (menuItem != NULL);
            wxASSERT (menu2 != NULL);
            //wxASSERT (menu2 != menu);
            // If menu item is part of a sub menu -> go up to "real" menu
            //while (menu->GetParent () != NULL) {
            //
            //    menu = menu->GetParent ();
            //}
            m_popupMenuKey = WxGuiTestHelper::FindPopupMenuKey (menu);
            if (!m_popupMenuKey.IsEmpty ()) {

                m_isFromPopupMenu = true;
                found = true;
        
                // Only for pop-up menus:
                m_menuLabel = menu->GetTitle ();

                m_menuItemLabel = menu->GetLabel (m_event->GetId ());

                // Find container for m_event->GetEventObject() to be used for
                //  event handling parent?
                wxWindow *evtHandlerWdw = WxGuiTestHelper::FindPopupMenuEvtHandlerWdw (m_popupMenuKey);
                wxASSERT (evtHandlerWdw != NULL);

                CRWindowHierarchyHandler *hierarchy = CRWindowHierarchyHandler::GetInstance ();
                wxASSERT (hierarchy != NULL);
                m_popupMenuContainerName = hierarchy->FindContainerName (evtHandlerWdw);
                wxASSERT (!m_popupMenuContainerName.IsEmpty ());
            }
        }
    }
    // (4) Or another menubar: TODO

    // (5) Or a tool from a toolbar?
    if (!found) {

        wxWindow *wdwEvtObject = wxDynamicCast (m_event->GetEventObject (),
                wxWindow);
        if (wdwEvtObject != NULL) {

            // One way to find out if it is a tool; works only for dynamic toolbars:
            //sw::NewBitmapButton *newTool = dynamic_cast< sw::NewBitmapButton * >(wdwEvtObject);
            //if (newTool != NULL) {

            // Better (not tested for non-dynamic toolbars yet):
            m_toolbarName = sw::ToolBarRegistry::GetInstance ()->
                    FindToolBarNameByWdwPtr (wdwEvtObject);
            if ((m_toolbarName.IsEmpty ()) && (wdwEvtObject->GetParent () != NULL)) {

                m_toolbarName = sw::ToolBarRegistry::GetInstance ()->
                        FindToolBarNameByWdwPtr (wdwEvtObject->GetParent ());
            }
            if (!m_toolbarName.IsEmpty ()) {

                m_isTool = true;
                // Standard tool IDs (wxID_LOWEST < stdID < wxID_HIGHEST) don't
                // need to be looked up; others must be registered in
                // GuiObjectManager:
                if ((wxID_LOWEST < m_event->GetId ()) &&
                       (m_event->GetId () < wxID_HIGHEST)) {

                    m_isStdId = true;

                } else {

                    m_guiObjName = sw::GuiObjectManager::GetInstance ()->
                            FindName (m_event->GetId ());
                    wxASSERT (!m_guiObjName.IsEmpty ());
                }
            }
        }
    }

    // Finally, if still not processed emit comment with infos about event, and
    // make the event irrelevant??? TODO

    // (A) Find out if it is a checkable menu item; and if so, if it is checked
    // or unchecked:
    wxASSERT (m_event->IsCommandEvent ());
    wxCommandEvent *cmdEvt = wxDynamicCast (m_event, wxCommandEvent);
    if ((cmdEvt->GetInt () == 1) || (cmdEvt->IsChecked ())) {
    
        m_isChecked = true;
    }
}


void CRMenuSelectionEvent::EmitCpp ()
{
    // (I) Expected emitting for menu items:
    // (1) Menu item is part of main frame menubar:
    /*
    wxFrame *mainFrame = sw::FrameFactory::GetInstance ()->GetMainFrame ()->
            GetFrame ();
    wxMenuBar *menuBar = mainFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);

    int importMenuItemId = menuBar->FindMenuItem (_("File"), _("STL File..."));
    CPPUNIT_ASSERT_MESSAGE ("STL import menu item not found",
            importMenuItemId != wxNOT_FOUND);

    swTst::WxGuiTestEventSimulationHelper::SelectMenuItem (importMenuItemId, mainFrame);
    swTst::WxGuiTestHelper::FlushEventQueue ();
    */

    // (2) Menu item is part of top level window menu:
    /*
    CPPUNIT_ASSERT_MESSAGE ("Application top window invalid", wxTheApp->GetTopWindow () != NULL);
    wxFrame *topFrame = dynamic_cast< wxFrame * >(wxTheApp->GetTopWindow ());
    CPPUNIT_ASSERT_MESSAGE ("Top window is not a frame", topFrame != NULL);
    wxMenuBar *menuBar = topFrame->GetMenuBar ();
    CPPUNIT_ASSERT_MESSAGE ("Menubar not found", menuBar != NULL);

    ...
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

        if (m_isFromMainFrameMenuBar) {

            eventHdlVarName = _T("mainFrame");
            str.Clear ();
            str << _T("wxFrame *") << eventHdlVarName <<
                    _T(" = sw::FrameFactory::GetInstance ()->GetMainFrame ()->GetFrame ();");
            emitter->AddCode (str);

        } else if (m_isFromTopWindow) {

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
        
        } else if (m_isFromPopupMenu) {
        
            menuItemContVarName = emitter->MakeVarName (m_menuLabel, 
							_T("PopupMenu"));
            str.Clear ();
            str << _T("wxMenu *") << menuItemContVarName <<
                    _T(" = swTst::WxGuiTestHelper::FindPopupMenu (\"") <<
                    m_popupMenuKey << _T("\");");
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Pop-up menu '") << 
		m_popupMenuKey << _T("' not found\", ") << menuItemContVarName <<
		_T(" != NULL);");
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
                    m_popupMenuContainerName,
                    wxString::Format (_T("pop-up menu '%s'"), 
				      m_menuLabel.c_str ()));
        }
    
        if (m_isFromMainFrameMenuBar || m_isFromTopWindow) {

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
		menuItemContVarName << _T("->FindMenuItem (_(\")") << 
		m_menuLabel << _T("\"), _(\"") << m_menuItemLabel << _T("\"));");
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Menu item ID '") << 
		m_menuItemLabel << _T("' not found\", ") << 
		menuItemIdVarName << _T(" != wxNOT_FOUND);");
            emitter->AddCode (str);
        }

        if (m_isChecked) {

            wxString menuItemVarName = emitter->MakeVarName (m_menuItemLabel,
							     _T("MenuItem"));

            str.Clear ();
            str << _T("wxMenuItem *") << menuItemVarName << _T(" = ") <<
		menuItemContVarName << _T("->FindItem (") << 
		menuItemIdVarName << _T(");");
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"Menu item '") << 
		m_menuItemLabel << _T("' not found\", ") << menuItemVarName << 
		_T(" != NULL);");
            emitter->AddCode (str);

            emitter->AddComment (_T("Check if checkable menu item is not already checked?"));
            str.Clear ();
            str << _T("if (!") << menuItemVarName << _T("->IsChecked ()) { ...");
            emitter->AddComment (str);

            str.Clear ();
            str << _T("swTst::WxGuiTestEventSimulationHelper::SelectAndCheckMenuItem (") <<
                    menuItemIdVarName << _T(", ") << eventHdlVarName << _T(");");
            emitter->AddCode (str);

        } else {

            str.Clear ();
            str << _T("swTst::WxGuiTestEventSimulationHelper::SelectMenuItem (") 
		<< menuItemIdVarName << _T(", ") << eventHdlVarName << _T(");");
            emitter->AddCode (str);
        }

    } else {

        wxString toolBarVarName = emitter->MakeVarName (m_toolbarName);

        str.Clear ();
        str << _T("sw::ToolBar *") << toolBarVarName 
	    <<
	    _T(" = sw::ToolBarRegistry::GetInstance ()->FindToolBarByName (\"") 
	    << m_toolbarName << _T("\");");
        emitter->AddCode (str);

        str.Clear ();
        str << _T("CPPUNIT_ASSERT_MESSAGE (\"Toolbar '") << m_toolbarName <<
	    _T("' not found\", ") << toolBarVarName << _T(" != NULL);");
        emitter->AddCode (str);

        if (m_isStdId) {

            wxString isCheckedBoolStr = m_isChecked ? _T("true") : _T("false");

            str.Clear ();
            str << _T("swTst::WxGuiTestEventSimulationHelper::ToggleTool (") <<
		m_event->GetId () << _T(", ") << isCheckedBoolStr << _T(", ") <<
		toolBarVarName << _T(", ") << toolBarVarName << 
		_T("->GetWindow ());");
            emitter->AddCode (str);

        } else {

            wxString guiObjVarName = emitter->MakeVarName (m_guiObjName, 
							   _T("GuiObj"));

            str.Clear ();
            str << _T("sw::GuiObject *") << guiObjVarName 
		<< _T(" = sw::GuiObjectManager::GetInstance ()->FindGuiObject (\"") 
		<< m_guiObjName << _T("\");");
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\"GuiObject '") << m_guiObjName <<
		_T("' not found\", ") << guiObjVarName << _T(" != NULL);");
            emitter->AddCode (str);

            wxString toolGuiObjVarName = emitter->MakeVarName (m_guiObjName,
                    _T("ToolGuiObj"));

            str.Clear ();
            str << _T("sw::ToolGuiObject *") << toolGuiObjVarName <<
                    _T(" = dynamic_cast < sw::ToolGuiObject * >(") <<
                    guiObjVarName << _T(");");
            emitter->AddCode (str);

            str.Clear ();
            str << _T("CPPUNIT_ASSERT_MESSAGE (\")GuiObject '") << m_guiObjName <<
		_T("' is not a ToolGuiObject\", ") << toolGuiObjVarName <<
		_T(" != NULL);");
            emitter->AddCode (str);

            wxString toolIdVarName = emitter->MakeVarName (_T("toolId"));

            str.Clear ();
            str << _T("int ") << toolIdVarName <<
                    _T(" = sw::GuiObjectManager::GetInstance ()->FindId (") <<
                    toolGuiObjVarName << _T(");");
            emitter->AddCode (str);

            wxString isCheckedBoolStr = m_isChecked ? _T("true") : _T("false");

            str.Clear ();
            str << _T("swTst::WxGuiTestEventSimulationHelper::ToggleTool (") <<
		toolIdVarName << _T(", ") << isCheckedBoolStr << _T(", ") <<
		toolBarVarName << _T(", ") << toolBarVarName << 
		_T("->GetWindow ());");
            emitter->AddCode (str);
        }
    }

    str.Clear ();
    str << _T("swTst::WxGuiTestHelper::FlushEventQueue ();\n");
    emitter->AddCode (str);
}

} // End namespace swTst

