#include "Verleih.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	CD CD1;
	CD CD2;
	CD CD3(1,15,300,180, "Titel", "Interpret",NULL);
	bool ok=true;

	if(ok)
    {
        if(CD1.interpret()!=CD2.interpret())
        {
          ok=!ok;
          cout<<"CD Baseconstruktor failed"<<endl;
        }
    }
    if(ok)
    {

       if(CD3.interpret()!="Interpret")
       {
           ok=!ok;
           cout<<"CD Construktor failed"<<endl;
       }
    }
    if(ok)
    {
       if(CD3.interpret()!="Test")
       {
           ok=!ok;
           cout<<"CD Construktor failed"<<endl;
       }
    }







	if(ok)
        cout<<"All tests passed.";
	return 0;
}
