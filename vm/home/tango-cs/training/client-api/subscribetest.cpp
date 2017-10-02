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

void MyEventCallBack::push_event(Tango::EventData *evento)
{
	Tango::DevDouble valore;
	time_t now=time(0);
	char *tstamp=ctime(&now);
	cout<<"----------------------------------------------"<<endl;
	try
	{
		cout << tstamp << " event arrived: " << evento->attr_name ;
		if(!evento->err)
		{
// 			cout<<"dim_x: "<< evento->attr_value.dim_x<<endl;
            
			*(evento->attr_value) >> valore;
            cout <<"type: " << evento->attr_value->get_type() << "   valore: " << valore <<  endl;
            //type values belong to CmdArgType enum (tango_const.h)
		}
		else{
			cout << " event with error"<<endl;
			for (int j=0; j< evento->errors.length();j++){
				cout << evento->errors[j].reason.in() << endl;
				cout << evento->errors[j].origin.in() << endl;
				cout << evento->errors[j].desc.in() << endl;
			}
		}
			

	}
	catch(Tango::DevFailed &e)
	{
		cerr<<"Eccezione Tango nell' estrazione dati"<<endl;
	}
	catch(...)
	{
		cerr<<"Eccezione generica nell' estrazione dati"<<endl;
	}
	cout<<"----------------------------------------------"<<endl;
}

Tango::DeviceProxy *dev;
int event_id;

void inthandler(int signum)
{
	cout << "Unsubscribing events" << endl;
	for (int i=0; i<1;i++){
 	try{
			dev->unsubscribe_event(event_id);
	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		cerr << "Fallita la unsubscribe() per i tango events" << endl;
	}
	}
}

int main(int argc, char **argv)
{
	signal(SIGINT, inthandler);
	MyEventCallBack* bec = new  MyEventCallBack;
	vector<string> dummyfilters;
	string devname(argv[1]);
	string attrname(argv[2]);

	cout <<devname<<"/"<<attrname<<endl;

	try{
		dev = new Tango::DeviceProxy(devname);
	}
	catch(Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		cerr << "fallita la creazione del device proxy!" << endl;
	}
	cout << "Device creato!" << endl;
	try{
		event_id = dev->subscribe_event(attrname, Tango::CHANGE_EVENT,bec);

	}
	catch (Tango::DevFailed &e)
	{
		Tango::Except::print_exception(e);
		cout << "Fallita la registrazione per i tango events!" << endl;
	}
	cout << "event_client() id: " << event_id << endl;
	sleep(1000000);
}


