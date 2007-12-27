CXX=g++
RES=/Developer/Tools/Rez

CPPUNITDIR=/usr/local/cppunit-1.12
WXDIR=/usr/local/wxMac-2.8.6
WXDEFINES= -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES -D__WXDEBUG__ -D__WXMAC__
WXGUITESTDIR=/usr/local/wxGuiTesting
XRCDIR=rc

APPSUFFIX=app
PROGSUFFIX=exe

PROGNAME=xrcdemo
CAPTURENAME=$(PROGNAME)_capture
TESTNAME=$(PROGNAME)_test
APPNAME=$(PROGNAME).$(APPSUFFIX)
CAPTUREAPP=$(CAPTURENAME).$(APPSUFFIX)
TESTAPP=$(TESTNAME).$(APPSUFFIX)


INCLUDE_FLAGS=-I$(CPPUNITDIR)/include -I$(WXDIR)/include/wx-2.8 -I$(WXDIR)/lib/wx/include/mac-unicode-debug-2.8 -I$(WXGUITESTDIR)/include
LIBDIRS=-L$(CPPUNITDIR)/lib -L$(WXDIR)/lib -L$(WXGUITESTDIR)/lib
LIBS= -framework IOKit -framework Carbon -framework Cocoa -framework System -framework QuickTime  -lwx_macud-2.8 -lcppunit -lswWxGuiTestingd

WXSRCDIR=/usr/local/src/wxMac-2.8.6
WXSAMPLE=$(WXSRCDIR)/samples
WXRSRC=$(WXSRCDIR)/src/mac/carbon
PROGOBJECTS=custclas.o derivdlg.o myframe.o xrcdemo.o 
TESTPROGOBJECTS=custclas.to derivdlg.to myframe.to xrcdemo.to CppTextTestApp.to
CAPTUREOBJECTS=SimpleCRTest.to
TESTOBJECTS=SimpleTest.to ReplayTest.to


CXXFLAGS=-g -O0 $(INCLUDE_FLAGS) -DXRCDIR=\"$(XRCDIR)\" $(WXDEFINES)
LDFLAGS=$(LIBDIRS) $(LIBS)
TESTFLAG=-DSW_USE_WX_APP_GUI_TESTING 

.SUFFIXES: .to .$(PROGSUFFIX) .$(APPSUFFIX)

all: $(APPNAME) $(CAPTUREAPP) $(TESTAPP)

$(PROGNAME).$(PROGSUFFIX): $(PROGOBJECTS)
	$(CXX) -o $@ $? $(LDFLAGS)

$(TESTNAME).$(PROGSUFFIX): $(TESTPROGOBJECTS) $(TESTOBJECTS)
	$(CXX) -o $@ $? $(LDFLAGS)

$(CAPTURENAME).$(PROGSUFFIX): $(TESTPROGOBJECTS) $(CAPTUREOBJECTS)
	$(CXX) -o $@ $? $(LDFLAGS)

.cpp.to :
	$(CXX) -o $@ $< -c $(CXXFLAGS) $(TESTFLAG)

.$(PROGSUFFIX).$(APPSUFFIX):
	$(RES) -d __DARWIN__ -t APPL -d __WXMAC__     -i $(WXSAMPLES)/$(PROGNAME) -d WXUSINGDLL -i $(WXSAMPLE)  -i $(WXSRCDIR)/include -o xrcdemo Carbon.r sample.r
	/Developer/Tools/SetFile -a C $<
	mkdir -p $@/Contents/MacOS
	mkdir -p $@/Contents/Resources
	sed -e "s/IDENTIFIER/us.ceridwen.$</"\
        	-e "s/EXECUTABLE/xrcdemo/" \
        	-e "s/VERSION/2.8.6/" \
        	$(WXRSRC)/Info.plist.in > $@/Contents/Info.plist
	echo -n "APPL????" >$@/Contents/PkgInfo
	ln -f $< $@/Contents/MacOS/xrcdemo
	cp -f $(WXRSRC)/wxmac.icns $@/Contents/Resources/wxmac.icns

clean:
	rm -f *.o
	rm -f *.to
	rm -rf $(APPNAME) 
	rm -rf $(CAPTUREAPP) 
	rm -rf $(TESTAPP)
	rm -f $(PROGNAME).$(PROGSUFFIX) 
	rm -f $(CAPTURENAME).$(PROGSUFFIX) 
	rm -f $(TESTNAME).$(PROGSUFFIX)