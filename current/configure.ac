AC_INIT(wxGuiTesting, 0.7)
AC_CONFIG_SRCDIR([src/wxGuiTest/WxGuiTestApp.cpp])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AM_OPTIONS_WXCONFIG

#Create a "debug" flag
AC_ARG_ENABLE(debug, 
	     AC_HELP_STRING([--enable-debug], 
	                    [Build for debugging (default is yes)]), 
	     [case "${enableval}" in 
	       yes) debug=true ;;
	       no)  debug=false ;;
	       *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug) ;;
	     esac], [debug=true])

AM_OPTIONS_VTK
AM_PATH_VTK([4.0.2], [AC_MSG_NOTICE(["VTK Found"])], 
		     [AC_MSG_WARN(["VTK Not Found, compilation will be without VTK Support"])])
AM_PATH_WXCONFIG([2.8.0], wxWin=1, wxWin=0, [std], [--static=no $wx_debug_arg])
if test "$wxWin" != 1; then
   AC_MSG_ERROR([ wxWindows not found.  Check the path. ])
fi
echo "Set wx prefix"
if test "x$wx_config_name" != "x" ; then
   wx_prefix=`$wx_config_name --prefix`;
   echo "wx_prefix set to $wx_prefix by wx_config_name $wx_config_name";
elif test "x$wx_config_prefix" != "x"; then
   wx_prefix=$wx_config_prefix;
   echo "wx_prefix set to $wx_prefix from wx_config_prefix";
else  
      wx_prefix=`wx-config --prefix`;
      echo "wx_prefix set to $wx_prefix by wx-config";
fi

AM_PATH_CPPUNIT([1.10.0], cppunit=1, cppunit=0)
if test "$cppunit" != 1; then
   AC_MSG_ERROR([ CPP Unit Not Found. ])
fi

UNICODE_FLAG=$(test ! $($WX_CONFIG_WITH_ARGS --unicode >/dev/null 2>&1))
DEBUG_FLAG=$(test ! $($WX_CONFIG_WITH_ARGS --debug >/dev/null 2>&1))
SHARED_FLAG=$($WX_CONFIG_WITH_ARGS --static >/dev/null 2>&1)
     
AC_MSG_CHECKING([if wxWidgets was built with UNICODE enabled])
if test "$UNICODE_FLAG" != "0"; then
   AC_MSG_RESULT([yes])
   WX_UNICODE=1
else
   AC_MSG_RESULT([no])
   WX_UNICODE=0
fi
     
     
AC_MSG_CHECKING([if wxWidgets was built in DEBUG or RELEASE mode])
if test "$DEBUG_FLAG" != "0"; then
     AC_MSG_RESULT([debug])
     WX_DEBUG=1
else
     AC_MSG_RESULT([release])
     WX_DEBUG=0
fi
     
AC_MSG_CHECKING([if wxWidgets was built in SHARED or STATIC mode])
if test "$SHARED_FLAG" != "0"; then
     AC_MSG_RESULT([shared])
     WX_SHARED=1
else
     AC_MSG_RESULT([static])
     WX_SHARED=0
fi

if test "x$debug" == "xtrue"; then
   AC_SUBST(BUILD, "debug")
else
   AC_SUBST(BUILD, "release")
fi

AC_MSG_CHECKING("Finding toolkit value")
case "$host" in 
     *-*-darwin*)
         TOOLKIT=MAC
     ;;
     *)
         TOOLKIT=GTK
	 AM_PATH_GTK_2_0([2.0.0], gtk=1, gtk=0)
	 if test $gtk != 1; then
	    AC_MSG_ERROR([GTK headers not available. Native Events will not compile])
	 else
	    AC_SUBST(PLATFORM_CFLAGS, $GTK_CFLAGS)
	    AC_SUBST(PLATFORM_LIBS, $GTK_LIBS)

	 fi
     ;;
esac
AC_MSG_RESULT("$TOOLKIT")

AC_SUBST(CFLAGS, "")
AC_SUBST(CXXFLAGS, "")
AC_SUBST(TOOLKIT)
AC_SUBST(WXSRCPATH, "$srcdir/build/macosx")
AC_PROG_CC_C_O
AC_PROG_CXX
AC_PROG_INSTALL


AC_BAKEFILE([m4_include(autoconf_inc.m4)])
AC_CONFIG_FILES([Makefile])

AC_OUTPUT