###############################################################################
# Name:        CMakeLists.txt
# Author:      Reinhold Füreder
# Created:     2004
# Copyright:   (c) 2005 Reinhold Füreder
# Licence:     wxWindows licence
###############################################################################

PROJECT (Testing)
if ( APPLE )
   SET (wxWidgets_INCLUDE_DIRS_NO_SYSTEM 1)
endif ( APPLE )
SUBDIRS (swFrameworkDependent)
SUBDIRS (swWxGuiTesting)
