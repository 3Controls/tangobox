/*
 * command01.cpp
 * 
 *  example program for Tango training - executing a command
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
    string cmdname = "DevShort";
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

    // prepare the inputa data
    DevShort value=3210;
    DeviceData datain; //use direct constructor for DeviceData
    datain << value;

    DeviceData dataout;
    DevShort outvalue;
    
    try{
        dataout = dev->command_inout(cmdname, datain); //execute command
        dataout.set_exceptions(DeviceData::wrongtype_flag);  //by default type is not checked but we can turn it on
        dataout >> outvalue; //extract data
        cout << "command data out: " << outvalue << endl;
    }

    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to execute command" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // trivial error handling
    }
    
    //example with vod/void command and checking explicitly
    try{
        
        dev->command_inout("DevVoid"); //excute command - we know it is void/void
        
        DeviceData datavoid;
        datavoid = dev->command_inout("DevVoid"); //excute command
        datavoid.reset_exceptions(DeviceData::isempty_flag); //comment....
        cout << "DevVoid result is empty:" << datavoid.is_empty() <<endl;
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to execute DevVoid command" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // trivial error handling
    }

    delete dev;
    exit(EXIT_SUCCESS);
}
