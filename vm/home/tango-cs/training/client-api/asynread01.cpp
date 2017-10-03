/*
 * asynread01.cpp
 * 
 *  example program for Tango training - reading an attribute
 *  using the asynch call / polling mode
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
    DeviceAttribute* da;
    double value=0.0;
    long request_id =0;
    try{
        request_id = dev->read_attribute_asynch(attname); //read the attribute asyncrhonously
       
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to read attribute" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // semplicistic error handling
    }
    try{
        long wait_time_ms =390000; //0=wait untill response arrives, 39=+wait at most 39 ms
        //try different wait_times and observe the behaviour of the call
        da = dev->read_attribute_reply(request_id,wait_time_ms);
        (*da) >> value;  //use overoladed operator to extract the value
        cout << "polled asynch read: " << devname << "/" << attname << " value: "<< value << endl;
        delete da;
    }
    catch(AsynReplyNotArrived &e)
    {
        // if wait_time is too short AsynReplyNotArrived excption is rised
        Tango::Except::print_exception(e);
        cerr << "attribute reply not yet arrive - wait longer!" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // semplicistic error handling
    }
    catch(DevFailed &e)
    {
        //if the server raised an exception during read_attribute, it will be re-thrown
        // it must be handled by te client
        Tango::Except::print_exception(e);
        cerr << "failed to read attribute reply" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // semplicistic error handling
    } 
    delete dev;
    exit(EXIT_SUCCESS);
}
