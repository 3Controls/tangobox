/*
 * reading01.cpp
 * 
 *  example program for Tango training - reading an attribute
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
        exit(EXIT_FAILURE); // semplicistic error handling

    }
    
    // prepare the reading
    DeviceAttribute da;
    double value=0.0;
    
    try{
        da = dev->read_attribute(attname); //read the attribute
        da >> value;  //use overoladed operator to extract the value
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to read attribute" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // semplicistic error handling
    }
    
    cout << devname << "/" << attname << " value: "<< value << endl;
    delete dev;
    exit(EXIT_SUCCESS);
}