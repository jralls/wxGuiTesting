///////////////////////////////////////////////////////////////////////////////
// Name:        swWxGuiTesting/CppTest/CppTextTestApp.cpp
// Author:      Reinhold F�reder
// Created:     2004
// Copyright:   (c) 2005 Reinhold F�reder
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

//#include "TextTestRunner.h"

int main (int argc, char* argv[])
{
    // Get the top level suite from the registry
    CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();

    // Adds the test to the list of test to run
    CPPUNIT_NS::TextUi::TestRunner runner;
    //TstTextTestRunner runner;
    runner.addTest (suite);

    // Change the default outputter to a compiler error format outputter
    runner.setOutputter (new CPPUNIT_NS::CompilerOutputter (&runner.result (),
            std::cerr));

    // Run the test - don't close window in debug mode at the end
    bool wasSucessful = runner.run ();

    // Return error code 1 if the one of test failed.
    return wasSucessful ? 0 : 1;
}

