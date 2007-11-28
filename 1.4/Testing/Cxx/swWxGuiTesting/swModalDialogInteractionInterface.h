/////////////////////////////////////////////////////////////////////////////
// $RCSfile: swModalDialogInteractionInterface.h,v $
// Original Author/Owner: reinhold
//
// $Revision: 1.1 $ $Name:  $ $State: Exp $
//
// $Date: 2006/10/18 08:06:24 $ $Author: reinhold $
//
/////////////////////////////////////////////////////////////////////////////

#ifndef SWMODALDIALOGINTERACTIONINTERFACE_H
#define SWMODALDIALOGINTERACTIONINTERFACE_H

#ifdef __GNUG__
//    #pragma interface "swModalDialogInteractionInterface.h"
#endif

namespace swTst {


/*! \class ModalDialogInteractionInterface
    \brief Instantiations of this interface can be handed over to the
    ModalDialogTimer to be executed after the timeout.
*/
class ModalDialogInteractionInterface
{
public:
    /*! \fn virtual void Execute () = 0
        \brief Manipulate, or interact with modal dialog before dismissing it.
    */
    virtual void Execute () = 0;

};

} // End namespace swTst

#endif // SWMODALDIALOGINTERACTIONINTERFACE_H
