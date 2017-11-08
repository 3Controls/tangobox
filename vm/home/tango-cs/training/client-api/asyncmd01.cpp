/*
* asyncmd.cpp
* 
*  example program for Tango training -executing a command
*  using the asynch call / callback - push model
* 
* C. Scafuri
* Elettra - Sincrotrone Trieste S.C.p.A.
* 2016
*/



#include <tango.h>
#include <cstdlib>
using namespace Tango;



class CmdCallBack : public CallBack
{
    //for our use we must overload the attr_read method
    
public:
    CmdCallBack();
    virtual void cmd_ended(CmdDoneEvent *);
    // other virtual methods tha can overloaded
    //virtual void attr_read(AttrReadEvent* myevent);
    // virtual void attr_written(AttrWrittenEvent *);
};

CmdCallBack::CmdCallBack(){}

void CmdCallBack::cmd_ended(CmdDoneEvent * myevent)
{
    //thi method is fired when the async command_inout has terminated
    try
    {
        //DeviceData dataout;
        Tango::DevUShort ev_value;
        if(myevent->err == false)
        {
            myevent->argout >> ev_value;
            cout<<"command_name: "<< myevent->cmd_name << " = " << ev_value << endl;
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
        cerr<<"Tango excpetion while extracting output data"<<endl;
        Tango::Except::print_exception(e);
    }
    catch(...)
    {
        cerr<<"generic excpetion while extracting output data"<<endl;
    }
}


int main(int argc, char **argv)
{
    
    string devname = "sys/tg_test/1";
    string cmdname = "DevUShort";
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
    CmdCallBack cmd_short_cb;
    
    // step 3)force the callabk model, by default it is PULL_CALLBACK 
    
    ApiUtil *au = ApiUtil::instance(); //get referece  to ApiUtil singleton
    au->set_asynch_cb_sub_model(PUSH_CALLBACK);
    
    // prepare the command execution
    DevUShort value=3210;
    DeviceData datain; //use direct constructor for DeviceData
    datain << value;
    try{
        dev->command_inout_asynch(cmdname, datain, cmd_short_cb); //execute the command asyncrhonously - callback variant
    }
    catch(DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to execute command_ionut_asynch" << endl;
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
