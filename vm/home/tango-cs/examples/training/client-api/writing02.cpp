/*
 * writng02.cpp
 * 
 *  example program for Tango training - writing an attribute spectrum
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
    string attname = "double_spectrum";
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
    // prepare DeviceAttribute object!
    vector<DevDouble> values;
    for (unsigned int i=0; i< 256; i++)
        values.push_back(1.1234);

    //DeviceAttribute da(attname,values); //use direct constructor for deviceAttribute
    DeviceAttribute da;
    da.set_name(attname);
    da << values;
    //another way - use float_spectrum_attribute
    
    DevVarFloatArray *fl;
    fl = new DevVarFloatArray();
    fl->length(256);
    float fin=1.24;
    for (unsigned int i=0; i< 256; i++)
        (*fl)[i]=fin;
    DeviceAttribute daf;
    daf.set_name("float_spectrum"); //const char* argument
    daf << fl; //with oveloaded operator

    try{
        dev->write_attribute(da); //write the attribute
        dev->write_attribute(daf); //write the attribute - ORB takes ownership of data - no need to delete
        cout << "write done"<<endl;
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to write attribute" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // trivial error handling
    }
    delete dev; // free resources
    exit(EXIT_SUCCESS);
}