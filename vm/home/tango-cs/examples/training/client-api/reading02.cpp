/*
 * reading02.cpp
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

    // step 2) prepare the reading
    DeviceAttribute da;
    double value=0.0;
    try{
        da = dev->read_attribute(attname); //read the attribute
        cout << "attibute_name:" << da.get_name() << endl;
        cout << "attibute_timestamp:" << da.get_date().tv_sec << endl;
        cout << "dim_x: "<< da.get_dim_x() << "  dim_y: "<<da.get_dim_y() << endl;
        cout << "type: "<< da.get_type() << endl;
        cout << "quality:" << da.get_quality() << endl;

        // get reading and setting , they (almost) always differ!!!
        if (da.get_dim_x() == 1 && da.get_dim_y() == 0){ //safety check on dimensions 
            vector<double> outval;
            da >> outval;  // the operator is now overloaed on vector<double>   != double !!!!!!
            cout << "reading:" << outval[0] << "  setting:" << outval[1] << endl;
        }
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to read attribute" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // semplicistic error handling
    }
    delete dev;
    exit(EXIT_SUCCESS);
}