#include "Verleih.h"
#include <iostream>
#include <string>


using namespace std;
bool test()
{
	CD CD1;
	CD CD2;
	CD CD3(0,1, "A", "A",NULL);
	CD CD4(1,1, "B", "B",NULL);
	CD CD6(2,1,"C","C",NULL);
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
        if(CD3.holeTyp()!=0)
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
    if(ok)
    {
        AusleihPos *apos=NULL;
        CD3.ausleihen(apos);
        if(CD3.holeAusleihen()!=NULL)
        {
            ok=!ok;
            cout<<"cd.ausleihen faild"<<endl;
        }
    }

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
    {
        CD *CD5;
        CD5=CD5->parse(CD4.toString());
        if((*CD5==CD4)==false)
        {
            ok=!ok;
            cout<<"string/parse failed"<<endl;
        }
    }
    if(ok)
    {
        CD3.setzeTyp(0);
        if(CD3.preis(1)!=200 || CD4.preis(1)!=100 || CD6.preis(1)!=200)
        {
            ok=!ok;
            cout<<"cd.preis basic fail"<<endl;
        }
        if(CD3.preis(5)!=1100 || CD4.preis(11)!=1140 || CD6.preis(2)!=900)
        {
            ok=!ok;
            cout<<"cd.preis tolong fail"<<endl;
        }
    }



 // *****************************************************************************************************************
 PreisStrategie *p1,*p2,*p3;
 p1= new MitarbeiterPreis();
 p2= new GrossKundenPreis();
 p3= new PreisStrategie();
 Kunde *Kunde1=new Kunde("Test Test","Testtown",0);
 Kunde Kunde2("Max Mustermann","Musterstadt",1);
 Kunde Kunde3("Sir Optimus Prime","Grailham",2);
 Dictionary<CD*> cds;
 cds.insert(CD3.ident(),&CD3);
 Date *tag =new Date(20,5,2011,new DateFormatDE());



    if(ok)
    {
        if(Kunde1->ident()!=0)
        {
            ok=!ok;
            cout<<"kunde.ident fail"<<endl;
        }
    }
    if(ok)
    {
        Kunde1->setzeName("Test");
        if(Kunde1->getname()!="Test")
        {
            ok=!ok;
            cout<<"kunde.name fail"<<endl;
        }

    }
    if(ok)
    {
        Kunde1->setzeOrt("Test");
        if(Kunde1->getort()!="Test")
        {
            ok=!ok;
            cout<<"kunde.ort fail"<<endl;
        }

    }
    if(ok)
    {
        AusleihPos *apos=new AusleihPos(Kunde1,&CD3,tag);
        CD3.ausleihen(apos);
        Kunde1->leiheAus(apos);

        if(Kunde1->preis(cds,*tag)!=0)
        {
            ok=!ok;
            cout<<"kunde.preis fail"<<endl;
        }
        if(ok)
            Kunde1->rueckgabe(apos);


    if(ok)
    {

        Kunde1=Kunde1->parse(Kunde2.toString());
        if(Kunde1->getort()!=Kunde2.getort())
        {
            ok=!ok;
            cout<<"kunde parse/string fail"<<endl;
        }
    }
//**************************************************************
    AusleihPos *apos1;
    if(ok)
    {

       apos1=apos1->parse(apos->toString());
        if(apos1->getDate()->toString()!=apos->getDate()->toString())
        {
            ok=!ok;
            cout<<"apos.parse fail"<<endl;
        }
    }


    }






	return ok;
}
