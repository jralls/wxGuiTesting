///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Exception/swWxLogicErrorException.h
// Author:      Reinhold Füreder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Füreder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef SWWXLOGICERROREXCEPTION_H
#define SWWXLOGICERROREXCEPTION_H

#ifdef __GNUG__
    #pragma interface "swWxLogicErrorException.h"
#endif

#include "Common.h"

#include <exception>

#include <wx/string.h>

namespace sw {


/*! \class WxLogicErrorException
    \brief Acts like an std::logic_error but accepts wxWidgets error message.
*/
class WxLogicErrorException : public std::exception
{
public:
    /*! \fn WxLogicErrorException (const wxString& what)
        \brief Constructor

        \param what error message
    */
    WxLogicErrorException (const wxString& what);


    /*! \fn ~WxLogicErrorException ()
        \brief Destructor
    */
    virtual ~WxLogicErrorException () throw();


    /*! \fn virtual const char *what() const throw()
        \brief Returns converted wxWidgets type error message.

        \return error message
    */
    virtual const char *what () const throw();

private:
    wxString m_what;
};

} // End namespace sw

#endif // SWWXLOGICERROREXCEPTION_H
