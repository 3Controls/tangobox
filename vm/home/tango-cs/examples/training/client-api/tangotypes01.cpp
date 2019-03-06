/*
 * tangotypes01.cpp
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
   {
   // -- inserting values
    DevVarDoubleStringArray arg; 
    arg.dvalue.length(3); // 3 strings
    arg.svalue.length(2); // 2 doubles
    
    arg.dvalue[0] = 1.2;
    arg.dvalue[1] = 2.3;
    arg.dvalue[2] = 3.4;
    
    arg.svalue[0] = CORBA::string_dup("first");
    arg.svalue[1] = CORBA::string_dup("second");
    
    //-- extracting values
    
    cout << "DevVarDoubleStringArray\n" << arg.dvalue.length() << endl;
    for (unsigned int i=0; i< arg.dvalue.length(); i++)
    	cout << arg.dvalue[i] << endl;
    
    cout << arg.svalue.length() << endl;
    for (unsigned int i=0; i< arg.svalue.length(); i++)
    	cout << arg.svalue[i] << endl;
    
    }
    {
    DevVarLongStringArray *arg = new DevVarLongStringArray();
    
    arg->svalue.length(3);
    arg->lvalue.length(2);
    
    arg->svalue[0] = CORBA::string_dup("FIRST");
    arg->svalue[1] = CORBA::string_dup("SECOND");
    arg->svalue[2] = CORBA::string_dup("THIRD");
    
    arg->lvalue[0] = 11;
    arg->lvalue[1] = 22;
    
    
    cout << "\nDevVarLongStringArray\n" <<  arg->lvalue.length() << endl;
    for (unsigned int i=0; i< arg->lvalue.length(); i++)
    	cout << arg->lvalue[i] << endl;
    
    cout << arg->svalue.length() << endl;
    for (unsigned int i=0; i< arg->svalue.length(); i++)
    	cout << arg->svalue[i] << endl;
    
    delete arg;
    }
    
    {
      DevString mystring = CORBA::string_alloc(5);
      strcpy(mystring,"tango");
      DevString tangostring = CORBA::string_dup("pluto");
      cout << mystring << endl;
      cout << tangostring << endl;
      CORBA::string_free(tangostring);
      CORBA::string_free(mystring);
    }
 }

