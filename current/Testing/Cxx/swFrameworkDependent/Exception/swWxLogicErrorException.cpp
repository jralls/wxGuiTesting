///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Exception/swWxLogicErrorException.cpp
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifdef __GNUG__
    #pragma implementation "swWxLogicErrorException.h"
#endif

#include "swWxLogicErrorException.h"

namespace sw {


WxLogicErrorException::WxLogicErrorException (const wxString& what)
{
    m_what = what;
}


WxLogicErrorException::~WxLogicErrorException () throw()
{
    // Nothing to do
}


const char *WxLogicErrorException::what () const throw()
{
    return m_what.c_str ();
}

} // End namespace sw
