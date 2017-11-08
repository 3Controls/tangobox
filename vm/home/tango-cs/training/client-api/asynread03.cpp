/*
 * asynread03.cpp
 * 
 *  example program for Tango training - reading an attribute
 *  using the asynch call / callback - push model
 * 
 * C. Scafuri
 * Elettra - Sincrotrone Trieste S.C.p.A.
 * 2016
 */



#include <tango.h>
#include <cstdlib>
using namespace Tango;



class ReadCallBack : public CallBack
{
    //for our use we must overload the attr_read method
    
public:
    ReadCallBack();
    virtual void attr_read(AttrReadEvent* myevent);
    // other virtual methods tha can overloaded
    // virtual void cmd_ended(CmdDoneEvent *);
    // virtual void attr_written(AttrWrittenEvent *);
};

ReadCallBack::ReadCallBack(){}

void ReadCallBack::attr_read(AttrReadEvent* myevent)
{
    //thi method is fired when the async read_attribute has terminated
    try
    {
        Tango::DevShort ev_value;
        if(myevent->err == false)
        {
            (*(myevent->argout))[0] >> ev_value;
            cout<<"attr_name: "<< myevent->attr_names[0] << " = " << ev_value << endl;
            //the calback method should at this point pass the read value to the rest of the program
        }
        else{
            cout << " event with error"<<endl;
            for (int j=0; j< myevent->errors.length();j++){
                cout << myevent->errors[j].reason.in() << endl;
                cout << myevent->errors[j].origin.in() << endl;
                cout << myevent->errors[j].desc.in() << endl;
            }
        }
    }
    catch(Tango::DevFailed &e)
    {
        cerr<<"Tango excpetion while extracting data"<<endl;
        Tango::Except::print_exception(e);
    }
    catch(...)
    {
        cerr<<"generic excpetion while extracting data"<<endl;
    }
}


int main(int argc, char **argv)
{

    string devname = "sys/tg_test/1";
    string attname = "short_scalar";
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
    // step 2) create the callback object 
    ReadCallBack rd_short_cb;
    // force the callabk model!
    ApiUtil *au = ApiUtil::instance(); //get referece  to ApiUtil singleton
    au->set_asynch_cb_sub_model(PUSH_CALLBACK);

    // the default mode is PULL_CALLBACK 
    // prepare the reading
    try{
        dev->read_attribute_asynch(attname, rd_short_cb); //read the attribute asyncrhonously - callback variant
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to read attribute" << endl;
        delete dev; // free resources
        exit(EXIT_FAILURE); // semplicistic error handling
    }

    //do something else
    for (unsigned int i=0; i< 100; i++){
        cout << "-"<<flush;
        usleep(10000);
    }
    cout << endl;
    delete dev;
    exit(EXIT_SUCCESS);
}
