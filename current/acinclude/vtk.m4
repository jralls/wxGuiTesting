dnl ===============================================================================
dnl Author: Francesco Montorsi, modified by John Ralls
dnl RCS-ID: $Id: vtk.m4,v 1.1 2007-11-27 23:28:56 john Exp $
dnl
dnl Implements the AM_OPTIONS_VTK, to add the --with-vtk=path option, and the
dnl AM_PATH_VTK macro used to detect VTK presence, location and version.
dnl ===============================================================================




dnl
dnl  AM_OPTIONS_VTK
dnl  ------------------------------------------------------------------------
dnl  Adds the --with-vtk=path option to the configure options
dnl
AC_DEFUN([AM_OPTIONS_VTK],
  [
  AC_ARG_WITH([vtk], [AC_HELP_STRING([--with-vtk],  
    [The prefix where VTK is installed (default is /usr/local)(optional)])],
    [with_vtk=$withval], [with_vtk="/usr/local"])

  AC_ARG_WITH([vtk-version], [AC_HELP_STRING([--with-vtk-version],  
    [VTK's include directory name is vtk-suffix, e.g. vtk-5.0/. What's the suffix? (Default -5.0)])],
    [vtk_suffix=$withval], [vtk_suffix="-5.0"])
  ]
)

dnl
dnl  AM_PATH_VTK([minimum-version], [action-if-found], [action-if-not-found])
dnl  ------------------------------------------------------------------------
dnl
dnl  NOTE: [minimum-version] must be in the form [X.Y.Z]
dnl
AC_DEFUN([AM_PATH_VTK],
  [
#AM_PATH_VTK
  VTK_CFLAGS=""
  VTK_LDFLAGS=""
  USE_VTK="FALSE"
  dnl do we want to check for VTK ?
  if [[ $with_vtk = "yes" ]]; then
    dnl in case user wrote --with-vtk=yes
    with_vtk="/usr/local"
  fi

  if [[ $with_vtk != "no" ]]; then
    VTK_PREFIX="$with_vtk"
    AC_CHECK_FILE([$VTK_PREFIX/include/vtk$vtk_suffix/vtkCommonInstantiator.h],
                  [vtkFound="OK"])
    AC_MSG_CHECKING([if VTK is installed in $VTK_PREFIX])
    if [[ -z "$vtkFound" ]]; then
      dnl not found !
      AC_MSG_RESULT([no])
      $3
    else
      dnl found !
      AC_MSG_RESULT([yes])
      dnl these are the VTK libraries of a default build
      VTK_LIBS="-lvtkCommon -lvtkDICOMParser -lvtkexpat -lvtkFiltering -lvtkfreetype -lvtkftgl -lvtkGraphics -lvtkHybrid -lvtkImaging -lvtkIO -lvtkjpeg -lvtkpng -lvtkRendering -lvtktiff -lvtkzlib"

      dnl set VTK c,cpp,ld flags
      VTK_CFLAGS="-I$VTK_PREFIX/include/vtk$vtk_suffix"
      VTK_LDFLAGS="-L$VTK_PREFIX/lib $VTK_LIBS"
      USE_VTK="TRUE"

                    OLD_CFLAGS=$CFLAGS
                    OLD_CXXFLAGS=$CXXFLAGS
                    OLD_LDFLAGS=$LDFLAGS
                    CFLAGS="$VTK_CFLAGS $CFLAGS"
                    CXXFLAGS="$VTK_CXXFLAGS $CXXFLAGS"
                    LDFLAGS="$VTK_LDFLAGS $LDFLAGS"
		    AC_MSG_NOTICE([CFLAGS=$CFLAGS])
      #now, check version
      if [[ -n "$1" ]]; then
        #the version of VTK we need:
        maj=`echo $1 | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
        min=`echo $1 | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
        rel=`echo $1 | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`
        AC_MSG_CHECKING([if VTK version is at least $maj.$min.$rel])
        dnl in order to be able to compile the following test program, we need 
	dnl to check whether the installed VTK is greater or not
        AC_COMPILE_IFELSE(
          [AC_LANG_PROGRAM(
             [
	       //#include <vtkVersion.h>
	       #include <vtkConfigure.h>
	       #include <stdio.h>
	     ],
             [
               printf("VTK version is: %d.%d.%d", VTK_MAJOR_VERSION, VTK_MINOR_VERSION, VTK_BUILD_VERSION);
               #if VTK_MAJOR_VERSION < $maj
               #error Installed VTK is too old !
               #endif
               #if VTK_MINOR_VERSION < $min
               #error Installed VTK is too old !
               #endif
               #if VTK_BUILD_VERSION < $rel
               #error Installed VTK is too old !
               #endif
             ])
           ], [vtkVersion="OK"])
        if [[ "$vtkVersion" = "OK" ]]; then
          AC_MSG_RESULT([yes])
          $2
        else #$vtkVersion="OK"
          AC_MSG_RESULT([no])
          VTK_CFLAGS=""
          VTK_LDFLAGS=""
	  USE_VTK="FALSE"
	  $3
        fi #$vtkVersion="OK"
      else # -n $1
          dnl if we don't have to check for minimum version (because the user 
	  dnl did not set that option), then we can execute here the block 
	  dnl action-if-found
          $2
      fi # -n $1
    fi # -z $vtkfound
  fi #with-vtk == "no"
  CFLAGS=$OLD_CFLAGS
  CXXFLAGS=$OLD_CXXFLAGS
  LDFLAGS=$OLD_LDFLAGS
  AC_SUBST(VTK_CFLAGS)
  AC_SUBST(VTK_CXXFLAGS, $VTK_CFLAGS)
  AC_SUBST(VTK_LDFLAGS)
  AC_SUBST(USE_VTK)
  ])


