/*
 * devvar01.cpp
 * 
 *  example program for Tango training - handling some peculiar tango types
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
    
    // -- inserting values
    DevVarDoubleArray arg;
    arg.length(3); // 3 strings
    arg[0] = 1.2;
    arg[1] = 2.3;
    arg[2] = 3.4;
    
    // fill a vector<double> with a DevVarDoubleArray
    vector<double> dvect;
    dvect << arg;
    
    // you can do also do the reverse...
    dvect.push_back(4.5);
    arg << dvect;
    cout << "arg length after new insertion:" << arg.length() << endl;
    // use "externally" defined buffer for values
    double buff[5];
    buff[0]=0.5;
    buff[1]=0.6;
    buff[2]=0.7;
    buff[3]=0.8;
    buff[4]=0.9;
    
    DevVarDoubleArray *staticarg;
    long len=5;
    long maxlen=5;
    staticarg = new DevVarDoubleArray(maxlen,len,buff); //by default ownership of buff is not acquired by staticarg ; 
                                                        //add bool=true parametr to constructor in case
                                                        //if you want to gain ownership that automatically delete buff whe deleting staticarg
    cout << "staticarg length:" << staticarg->length() << endl;
    cout << (*staticarg)[0] << " " << (*staticarg)[1] << endl;
    delete staticarg;
    
    //for string arrays remember that elements must be handled as DevString
    DevVarStringArray strgarr;
    strgarr.length(3); // 3 strings
    strgarr[0] = CORBA::string_dup("ONE");
    strgarr[1] = CORBA::string_dup("TWO");
    strgarr[2] = CORBA::string_dup("THREE");
    
    vector<string> ds;
    ds << strgarr;
    cout << ds[0] << endl;
}

