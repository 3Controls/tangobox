/*
 * pipe02.cpp
 * 
 *  example program for Tango training - reading a pipe of unknow  structure and writ it back with new values
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
    string devname = "powersupply/device/0";
    string pipename = "Info";
    
    //string devname = "sys/tg_test/1";
    //string pipename = "string_long_short_ro";
    
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
    DevicePipe dp;
    string pst;
    DevLong plong;
    DevShort pshort;
    DevState pstate;
    DevDouble pdouble;
    string pstring;
   
    
    try{
        dp = dev->read_pipe(pipename); //read the pipe
        unsigned int num_p_ele = dp.get_data_elt_nb();
        int dtype;
        string dname;
        cout << "root blob name:"<< dp.get_root_blob_name() <<endl;
        for (unsigned int i=0; i < num_p_ele ; i++){
            dname =  dp.get_data_elt_name(i);
            dtype =  dp.get_data_elt_type(i);
            cout << "index: " << i << " ElName: "<< dname << " type: "<<dtype;
            switch(dtype)
            {
                case DEV_LONG:
                    dp >> plong;
                    cout << " long value:" << plong << endl;
                    break;
                case DEV_STATE:
                    dp >> pstate;
                    cout << " state value:" << pstate << endl;
                    break;
                case DEV_STRING:
                    dp >> pst ;
                    cout << " string value:" << pst << endl;
                    break;
                case DEV_SHORT:
                    dp >> pshort;
                    cout << " short value:" << pshort << endl;
                    break;
                case DEV_DOUBLE:
                    dp >> pdouble;
                    cout << " double value:" << pdouble << endl;
                    break;
                default :
                    cout << " THIS TYPE IS NOT YET HANDLED" << endl;
            }
        }
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to read pipe" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // simplicistic error handling
    }
    
    //now write  set values in the pipe and write to device
    // notice that the write pipe has a different structrue compared to the read one!
    
    try{
        DevicePipe dpw("Info");
        //crete DataElements from templates
        DataElement<DevState> de_state("State", Tango::ON);
        DataElement<DevDouble> de_double("Current", 43.14);
        dpw.set_data_elt_nb(2);
        dpw << de_state << de_double;
        dev->write_pipe(dpw);
        cout << "write with template objects done " << endl;
    }
    
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to write pipe  with template objects" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // simplicistic error handling
    }
    try{
        DevicePipe dpw("Info");
        vector<string> de_names{"State","Current"};
        
        dpw.set_data_elt_names(de_names); //implicitly sets the numebr of elements
        
        //load elements into DeviePipe 
        pstate=Tango::ON;
        pdouble=2.4;
        
        // you can use the overloaed operator - ORDER OF INSERTION IS IMPORTANT:
        //dpw << pstate << pdouble; 
        
        // you can also use the map-like access and  oveloaded operators - code is more readbale
        dpw["State"] << pstate;
        dpw["Current"] << pdouble;
        dev->write_pipe(dpw);
        cout << "write to pipe with insert opearator done " << endl;
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to write pipe with insert opearator done " << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // simplicistic error handling
    }
    
    delete dev;
    exit(EXIT_SUCCESS);
}
