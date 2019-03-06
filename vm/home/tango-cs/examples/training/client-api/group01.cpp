/*
 * group01.cpp
 * 
 *  example program for Tango training - using Group class
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
    string devpattern = "powersupply/device/*";
    string attname = "Current";
    Group *grp = 0;
    // step 1) create the Group
    try{
        grp = new Tango::Group("TST");
        //add devices to group
        grp->add(devpattern);
        cout << "number of devices in group: " << grp->get_size() << endl;
        if (grp->ping() == true)
            cout << "all devices in group are alive" << endl;
        else cout << "some devices are not alive" << endl;
        
    }
    catch(Tango::DevFailed &e)
    {
        Tango::Except::print_exception(e);
        cerr << "failed to create Group" << endl;
        exit(EXIT_FAILURE); // semplicistic error handling
    }
    
    //perform a command on group
    {
    GroupCmdReplyList grl = grp->command_inout("Status");
    if (grl.has_failed() ) cout << "some commands failed"<< endl;
    for (int r=0; r< grl.size();r++){
        if (grl[r].has_failed()){
            cout << grl[r].dev_name() << " has failed" << endl;
        }
        else{
        DeviceData ans=grl[r].get_data();
        string status;
        ans >> status;
        cout << r << ":" << grl[r].dev_name() << " "<< status << endl;
        }
    }
    }
    //write an attribute - same value for all elements of group
    {
        DeviceAttribute da=DeviceAttribute("Current",100.55);
        GroupReplyList rpl = grp->write_attribute(da);
        if(rpl.has_failed()){
            for (int r=0; r< rpl.size();r++){
                if (rpl[r].has_failed()){
                    cout << rpl[r].dev_name() << " Current has failed" << endl;
                }
            }
        }
    }


    delete grp;
    exit(EXIT_SUCCESS);
}
