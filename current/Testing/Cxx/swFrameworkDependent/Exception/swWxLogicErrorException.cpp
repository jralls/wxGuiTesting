///////////////////////////////////////////////////////////////////////////////
// Name:        swFrameworkDependent/Exception/swWxLogicErrorException.cpp
// Author:      Reinhold Fuereder
// Created:     2004
// Copyright:   (c) 2005 Reinhold Fuereder
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
    return wxConvCurrent->cWX2MB(m_what.c_str ());
}

} // End namespace sw
