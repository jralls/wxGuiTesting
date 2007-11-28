///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppGuiTest/swWxGuiTestEvtSimHlpEvtHandler.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWWXGUITESTEVTSIMHLPEVTHANDLER_H
#define SWWXGUITESTEVTSIMHLPEVTHANDLER_H

#ifdef __GNUG__
    #pragma interface "swWxGuiTestEvtSimHlpEvtHandler.h"
#endif

#include "Common.h"

#include "wx/treectrl.h"

class wxSpinEvent;
class wxNotebookEvent;

namespace swTst {


/*! \class WxGuiTestEvtSimHlpEvtHandler
    \brief Test frame event handling.

    Ideally each event should be fired and therefore handled exactly once, but
    it seems that this is not the case (e.g. tree item selection).
*/
class WxGuiTestEvtSimHlpEvtHandler : public wxEvtHandler
{
    DECLARE_EVENT_TABLE()

public:
    /*! \fn WxGuiTestEvtSimHlpEvtHandler (wxFrame *frame)
        \brief Constructor

        \param frame main frame
    */
    WxGuiTestEvtSimHlpEvtHandler (wxFrame *frame);


    /*! \fn virtual ~WxGuiTestEvtSimHlpEvtHandler ()
        \brief Destructor
    */
    virtual ~WxGuiTestEvtSimHlpEvtHandler ();


    /*! \fn virtual void Init ()
        \brief Init counters or event occurence indicator.

        When creating a notebook there is already a notebook change event if it
        contains at least one page.
    */
    virtual void Init ();


    // Getter methods to inform about correct event simulation:
    bool HasMenuItemSelProcessed () const;
    bool HasCheckableMenuItemProcessed () const;
    bool HasButtonClickProcessed () const;
    bool HasTextCtrlValChgProcessed () const;
    bool HasSpinCtrlDblValChgWithoutEvtProcessed () const;
    bool HasTreeItemSelProcessed () const;
    bool HasTreeItemRightClickProcessed () const;
    bool HasNotebookPageSelProcessed () const;
    bool HasChoiceSelProcessed () const;
    bool HasCheckboxCheckingProcessed () const;
    bool HasRadioBoxSelProcessed () const;
    bool HasSliderValChgProcessed () const;
    bool HasSpinCtrlValChgProcessed () const;
    bool HasToolTogglingProcessed () const;
    bool HasCheckableToolTogglingProcessed () const;

protected:
    /*! \fn void OnMenuItem (wxCommandEvent& event)
        \brief Handle selection of normal menu item.
    */
    void OnMenuItem (wxCommandEvent& event);


    /*! \fn void OnCheckableMenuItem (wxCommandEvent& event)
        \brief Handle selection of checkable menu item.
    */
    void OnCheckableMenuItem (wxCommandEvent& event);


    /*! \fn void OnButtonClick (wxCommandEvent& event)
        \brief Handle button click.
    */
    void OnButtonClick (wxCommandEvent& event);

    /*! \fn void OnTextCtrlChange (wxCommandEvent& event)
        \brief Handle text control value change.
    */
    void OnTextCtrlChange (wxCommandEvent& event);
    

    /*! \fn void OnSpinCtrlDblChange (wxSpinEvent& event)
        \brief Handle double typed spin control value change.
    */
    void OnSpinCtrlDblChange (wxSpinEvent& event);


    /*! \fn void OnTreeSelChange (wxTreeEvent &event)
        \brief Handle tree item selection change.
    */
    void OnTreeSelChange (wxTreeEvent &event);
    

    /*! \fn void OnTreeItemRightClick (wxTreeEvent &event)
        \brief Handle tree item right click.
    */
    void OnTreeItemRightClick (wxTreeEvent &event);


    /*! \fn void OnNotebookPageChange (wxNotebookEvent &event)
        \brief Handle notebook page change.
    */
    void OnNotebookPageChange (wxNotebookEvent &event);


    /*! \fn void OnChoiceSelChange (wxCommandEvent &event)
        \brief Handle choice item selection change.
    */
    void OnChoiceSelChange (wxCommandEvent &event);


    /*! \fn void OnCheckboxChecking (wxCommandEvent &event)
        \brief Handle checkbox checking.
    */
    void OnCheckboxChecking (wxCommandEvent &event);


    /*! \fn void OnRadioBoxSelChange (wxCommandEvent &event)
        \brief Handle radiobox selection.
    */
    void OnRadioBoxSelChange (wxCommandEvent &event);


    /*! \fn void OnSliderChange (wxScrollEvent &event)
        \brief Handle slider change.
    */
    void OnSliderChange (wxScrollEvent &event);


    /*! \fn void OnSpinCtrlChange (wxSpinEvent &event)
        \brief Handle spinctrl change.
    */
    void OnSpinCtrlChange (wxSpinEvent &event);


    /*! \fn void OnToggleTool (wxCommandEvent& event)
        \brief Handle tool toggling.
    */
    void OnToggleTool (wxCommandEvent& event);


    /*! \fn void OnToggleCheckableTool (wxCommandEvent& event)
        \brief Handle checkable tool toggling.
    */
    void OnToggleCheckableTool (wxCommandEvent& event);

private:
    wxFrame *m_frame;

    // DONT FORGET TO INITIALIZE THESE TO FALSE
    // IN THE CONSTRUCTOR!!!
    bool m_menuItemSelProcessed;
    bool m_chkMenuItemSelProcessed;
    bool m_buttonClickProcessed;
    bool m_textCtrlValChangeEvent;
    bool m_spinCtrlDblValChangeEvent;
    bool m_treeSelProcessed;
    bool m_treeItemRightClickProcessed;
    bool m_notebookPageSelProcessed;
    bool m_choiceSelProcessed;
    bool m_checkboxChkgProcessed;
    bool m_radioBoxSelProcessed;
    bool m_sliderChangeProcessed;
    bool m_spinCtrlChangeProcessed;
    bool m_toolTogglingProcessed;
    bool m_checkableToolTogglingProcessed;

};

} // End namespace swTst

#endif // SWWXGUITESTEVTSIMHLPEVTHANDLER_H

