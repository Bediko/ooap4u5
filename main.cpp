#include "Verleih.h"
#include <iostream>
#include <string>

using namespace std;
int main()
{
	CD CD1;
	CD CD2;
	CD CD3(1,15,300,180, "A", "A",NULL);
	CD CD4(1,15,300,180, "B", "B",NULL);
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


       if(CD3.interpret()!="A")
       {
           ok=!ok;
           cout<<"cd.interpret failed"<<endl;
       }
    }
    if(ok)
    {


       if(CD3.titel()!="A")
       {
           ok=!ok;
           cout<<"cd.titel failed"<<endl;
       }
    }
    if(ok)
    {
        if(CD3.ident()!=2)
           {
             ok=!ok;
             cout<<"cd.ident fail"<<endl;
           }


    }
    if(ok)
    {
        if(CD3.holeTyp()!=1)
        {
            ok=!ok;
            cout<<"cd.holeTyp failed"<<endl;
        }
    }
    if(ok)
    {
        CD3.setzeTyp(2);
        if(CD3.holeTyp()!=2)
        {
            ok=!ok;
            cout<<"cd.setzeTyp failed"<<endl;
        }
    }
    if(ok)
    {
        if(CD3.holeAusleihen()!=NULL)
        {
            ok=!ok;
            cout<<"cd.holeausleihen faild"<<endl;
        }
    }
   /* if(ok)
    {
        apos=new AusleihPos();
        CD3.ausleihen(apos);
        if(CD3.holeAusleihen()!=NULL)
        {
            ok=!ok;
            cout<<"cd.ausleihen faild"<<endl;
        }
    }*/

    if(ok)
    {
        CD1=CD3;
        if(CD1.interpret()!=CD3.interpret())
        {
            ok=!ok;
            cout<<"=-operator fail"<<endl;
        }
    }

    if(ok)
    {

        if((CD1==CD3)==false)
        {
            ok=!ok;
            cout<<"==-operator fail"<<endl;
        }
    }
    if(ok)
    {

        if((CD3<CD4)==false)
        {
            ok=!ok;
            cout<<"<-operator fail"<<endl;
        }
    }




	if(ok)
        cout<<"All tests passed.";
	return 0;
}
