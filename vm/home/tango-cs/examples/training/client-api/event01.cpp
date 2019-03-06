/*
 * event01.cpp
 * 
 *  example program for Tango training
 * 
 * C. Scafuri
 * Elettra - Sincrotrone Trieste S.C.p.A.
 * 2016
 */


#include <tango.h>
#include <eventconsumer.h>
#include <cstdio>
#include <cstdlib>
#include <signal.h>
#include <ctime>

class MyEventCallBack : public Tango::CallBack
{
    void push_event(Tango::EventData* );
};

void MyEventCallBack::push_event(Tango::EventData *myevent)
{
    

    try
    {
        Tango::DevDouble ev_value;

        timeval now;
        gettimeofday(&now, NULL);
        char time_buff[22];
        strftime(time_buff, 22, "%F %H:%M:%S", localtime(&now.tv_sec));
        cout << time_buff <<  " "  << myevent->attr_name ;
        if(!myevent->err)
        {
            // 			cout<<"dim_x: "<< myevent->attr_value.dim_x<<endl;

            *(myevent->attr_value) >> ev_value;
            int evtype = myevent->attr_value->get_type();
            cout <<"  value: " << ev_value <<  endl;
            //type values belong to CmdArgType enum (defined in tango_const.h)
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


// global variables - for simplicity  in this example
Tango::DeviceProxy *dev;
int event_id;

void inthandler(int signum)
{

    if (event_id >0){
        cout << "unsubscribing event" << endl;
        try{
            dev->unsubscribe_event(event_id);
            event_id = 0;
            exit(EXIT_SUCCESS);
        }
        catch (Tango::DevFailed &e)
        {
            cerr << "failed to unsubscribe event" << endl;
            Tango::Except::print_exception(e);

        }
    }
}

int main(int argc, char **argv)
{
    signal(SIGINT, inthandler);
    MyEventCallBack* my_callback = new  MyEventCallBack;
    vector<string> dummyfilters;
    string devname(argv[1]);
    string attrname(argv[2]);
    
    cout <<"test subscribe event to: " << devname<<"/"<<attrname<<endl;
    
    try{
        dev = new Tango::DeviceProxy(devname);
    }
    catch(Tango::DevFailed &e)
    {
        cerr << "failed to create DeviceProxy!" << endl;
        Tango::Except::print_exception(e);
        
    }
    try{
        event_id = dev->subscribe_event(attrname, Tango::CHANGE_EVENT,my_callback,false); //last paramet is the stateless flag, default is false
        
    }
    catch (Tango::DevFailed &e)
    {
        cout << "event subscrition failed!" << endl;
        Tango::Except::print_exception(e);
        exit(EXIT_FAILURE);
        
    }
    cout << "event subscribed with id: " << event_id << endl;
    sleep(1000000);

    //clean exit
    if(event_id >0){
        try{
            dev->unsubscribe_event(event_id);
            event_id = 0;
        }
        catch (Tango::DevFailed &e)
        {
            cerr << "failed to unsubscribe event" << endl;
            Tango::Except::print_exception(e);
            
        }
    }
    exit(EXIT_SUCCESS);
}


