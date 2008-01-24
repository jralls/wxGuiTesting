/////////////////////////////////////////////////////////////////////////////
// $RCSfile: ModalDialogInteractionInterface.h,v $
// Original Author/Owner: reinhold
//
// $Revision: 1.1 $ $Name:  $ $State: Exp $
//
// $Date: 2006/10/18 08:06:24 $ $Author: reinhold $
//
//
// $Id$
/////////////////////////////////////////////////////////////////////////////

#ifndef MODALDIALOGINTERACTIONINTERFACE_H
#define MODALDIALOGINTERACTIONINTERFACE_H

#ifdef __GNUG__
//    #pragma interface "ModalDialogInteractionInterface.h"
#endif

namespace wxTst {


/*! \class ModalDialogInteractionInterface
    \brief Instantiations of this interface can be handed over to the
    ModalDialogTimer to be executed after the timeout.
*/
class ModalDialogInteractionInterface
{
public:
    virtual ~ModalDialogInteractionInterface() {}
    /*! \fn virtual void Execute () = 0
        \brief Manipulate, or interact with modal dialog before dismissing it.
    */
    virtual void Execute () = 0;

};

} // End namespace wxTst

#endif // MODALDIALOGINTERACTIONINTERFACE_H
