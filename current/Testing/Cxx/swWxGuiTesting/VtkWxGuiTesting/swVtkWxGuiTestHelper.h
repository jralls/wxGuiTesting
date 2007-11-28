///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/VtkWxGuiTesting/swVtkWxGuiTestHelper.h
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWVTKWXGUITESTHELPER_H
#define SWVTKWXGUITESTHELPER_H

#ifdef __GNUG__
    #pragma interface "swVtkWxGuiTestHelper.h"
#endif

#include "Common.h"

#include <map>

class wxVTKRenderWindowInteractor;

namespace swTst {

class WxVtkInteractorEventRecorder;


/*! \class VtkWxGuiTestHelper
    \brief Helper methods for wxVtk interaction recording (Singleton pattern).
*/
class VtkWxGuiTestHelper
{
public:
    typedef std::map < wxString, WxVtkInteractorEventRecorder * > RecorderMap;
    RecorderMap m_recorderMap;

public:
    /*! \fn static VtkWxGuiTestHelper * GetInstance ()
        \brief Get single private instance.

        \return single private instance
    */
    static VtkWxGuiTestHelper * GetInstance ();


    /*! \fn static void Destroy ()
        \brief Threadsafe destruction of static singleton instance.
    */
    static void Destroy ();


    /*! \fn static void SetUseWxVtkInteractionRecording (bool use)
        \brief Set flag indicating usage of wxVtk interaction recording.

        \param use true if wxVtk interaction should be recorded
    */
    static void SetUseWxVtkInteractionRecording (bool use);

    
    /*! \fn static bool GetUseWxVtkInteractionRecording ()
        \brief Get flag indicating usage of wxVtk interaction recording.

        \return true, if wxVtk interaction should is recorded
    */
    static bool GetUseWxVtkInteractionRecording ();

    
    /*! \fn virtual void RegisterForRecording (wxVTKRenderWindowInteractor *wxVtkRwi, const wxString &recorderId, const wxString &wxVtkId)
        \brief Register a wxVtk interactor for recording.

        Does nothing in non-testing mode.

        \param wxVtkRwi wxVtk interactor to register
        \param recorderId string identifying the recorder (several views may
            want to share the recorder in the shape of multiplexing)
        \param wxVtkId string identifying the wxVtk interactor to assign the
            recorded events to a single view in case of shared recorder
    */
    virtual void RegisterForRecording (wxVTKRenderWindowInteractor *wxVtkRwi,
            const wxString &recorderId, const wxString &wxVtkId);


    /*! \fn virtual WxVtkInteractorEventRecorder * GetWxVtkRecorder (const wxString &recorderId) const
        \brief Get registered wxVtk interaction recorder, or NULL.

        \param recorderId string ID of recorder
        \return registerd wxVtk interaction recorder, or NULL if none exists
            with the given ID
    */
    virtual WxVtkInteractorEventRecorder * GetWxVtkRecorder (
            const wxString &recorderId) const;


    /*! \fn virtual RecorderMap & GetWxVtkRecorders ()
        \brief Get all registered wxVtk interaction recorders.

        \return map of all registered wxVtk interaction recorders
    */
    virtual RecorderMap & GetWxVtkRecorders ();

protected:
    /*! \fn VtkWxGuiTestHelper ()
        \brief Constructor
    */
    VtkWxGuiTestHelper ();


    /*! \fn virtual ~VtkWxGuiTestHelper ()
        \brief Destructor
    */
    virtual ~VtkWxGuiTestHelper ();

private:
    static VtkWxGuiTestHelper *ms_instance;

    static bool ms_useWxVtkInteractionRecording;

private:
    // No copy and assignment constructor:
    VtkWxGuiTestHelper (const VtkWxGuiTestHelper &rhs);
    VtkWxGuiTestHelper & operator= (const VtkWxGuiTestHelper &rhs);
};

} // End namespace swTst

#endif // SWVTKWXGUITESTHELPER_H
