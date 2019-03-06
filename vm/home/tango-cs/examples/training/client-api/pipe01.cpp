/*
 * pipe01.cpp
 * 
 *  example program for Tango training - reading a pipe
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
    string pipename = "string_long_short_ro";
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
    
    // prepare the reading - we KNOW ALREADY the pipe structure : string, long , short
    DevicePipe dp;
    string pst;
    DevLong plong;
    DevShort pshort;
   
    
    try{
        dp = dev->read_pipe(pipename); //read the pipe
        dp >> pst >> plong >> pshort;  //use overoladed operator to extract the value
        /* can be done also in steps... but order must be followed
        dp >> pst;
        dp >> plong;
        dp >> pshort;
        */
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to read pipe" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // semplicistic error handling
    }
    
    cout << devname << "/" << pipename << " values: string="<< pst << " long=" << plong << " short=" << pshort << endl;
    delete dev;
    exit(EXIT_SUCCESS);
}
