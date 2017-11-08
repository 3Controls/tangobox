/*
 * reading03.cpp
 * 
 *  example program for Tango training
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
    string attname = "long64_spectrum_ro";
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
    DevVarLong64Array* value=0;
    
    vector<DevLong64> vectorvalue;
    try{
        da = dev->read_attribute(attname); //read the attribute
        da >> value;  //use overoladed operator to extract the value
        // notice that extracting into DevVar*Array consumes the data, now da is empty
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to read attribute as DevVarLong64Array" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // trivial error handling
    }
    DevLong64 ele=(*value)[0];
    cout << devname << "/" << attname << " value[0]: "<< ele << endl;
    delete value; //data ownership ha been transferred to user
    try{
        da = dev->read_attribute(attname); //read the attribute
        da >> vectorvalue; //notice that extracting into vectro<Dev*> does not consume the data!
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to read attribute vector<DevLong64>" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // semplicistic error handling
    }
    DevLong64 elevector=vectorvalue[0]; 
    cout << devname << "/" << attname << " vectorvalue[0]: "<< elevector << endl;
    cout << "attname length:" << vectorvalue.size() << "  " << da.get_dim_x() << endl;

    //handy  overlodaded stream operator, good for debugging/loggging/testing

    cout << "-----------------------------------------------"<<endl;
    cout << "DeviceData: "<< da << endl;
    delete dev;
    exit(EXIT_SUCCESS);
}
