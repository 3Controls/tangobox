/*
 * writng01.cpp
 * 
 *  example program for Tango training - writing an attribute
 * 
 * C. Scafuri
 * Elettra - Sincrotrone Trieste S.C.p.A.
 * 2016
 */



#include <tango.h>
#include <cstdlib>
using namespace Tango;
int main(int argc, char **argv)
{
    string devname = "sys/tg_test/1";
    string attname = "double_scalar";
    DeviceProxy *dev = 0;
    // step 1) create the device proxy
    try{
        dev = new Tango::DeviceProxy(devname);
    }
    catch(Tango::DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to create DeviceProxy" << endl;
        exit(EXIT_FAILURE); // trivial error handling

    }
    
    // prepare the
    double value=1.4142;
    DeviceAttribute da(attname,value); //use direct constructor for deviceAttribute
    
    // DeviceAttribute da;
    // da.set_name("double_scalar");
    // double dblvalue = 5.678;
    // da << dblvalue;   //or use insertion operator!

    try{
        dev->write_attribute(da); //write the attribute
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to write attribute" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // trivial error handling
    }
    delete dev;
    exit(EXIT_SUCCESS);
}