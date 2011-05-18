#include "Kunde.h"
#include <string>
#include <list>
#include "tokenizer.h"
#include <cstdlib>
#include <sstream>
#include "PreisStrategie.h"

using namespace std;

int Kunde::_number=0;



Kunde::Kunde(string n, string o,PreisStrategie *p)
{
    _id=_number;
    Kunde::_number++;
    _name=n;
    _ort=o;
    _preisStrategie=p;
}
Kunde::~Kunde()
{
    delete(_preisStrategie);
        _ausleihen.erase();

}
Kunde::Kunde(const Kunde& rhs)
{
  _preisStrategie=rhs._preisStrategie;
  _ausleihen=rhs._ausleihen;
  _name=rhs._name;
  _ort=rhs._ort;
  _id=rhs._id;
}
Kunde Kunde::operator=(const Kunde& Kunde)
{
    _preisStrategie=Kunde._preisStrategie;
  _ausleihen=Kunde._ausleihen;
  _name=Kunde._name;
  _ort=Kunde._ort;
  _id=Kunde._id;
  return *this;
}

bool Kunde::operator==(const Kunde& Kunde)
{
    return (_name==Kunde._name)&&(_ort==Kunde._ort);
}
bool Kunde::operator<(const Kunde& Kunde)
{
    return ((_name.compare(Kunde._name)<0)||(_name.compare(Kunde._name)==0))&&_ort.compare(Kunde._ort)<0;
}

int Kunde::ident()
{
    return _id;
}
void Kunde::setzeName(string n)
{
    _name=n;
}
string Kunde::getname()
{
    return _name;
}
void Kunde::setzeOrt(string o)
{
    _ort=o;
}
string Kunde::getort()
{
    return _ort;
}
void Kunde::setzePStrat(PreisStrategie *P)
{
    _preisStrategie=P;
}
int Kunde::preis(Dictionary<CD*> cds, Date tag)
{
    return _preisStrategie->preis(cds,tag);
}

void Kunde::leiheAus(AusleihPos *apos)
{
    _ausleihen.insert(_id,apos);
}
void Kunde::rueckgabe(AusleihPos *apos)
{
    _ausleihen.remove(_id);
}
Dictionary<AusleihPos *> Kunde::holeAusleihen()
{
    return _ausleihen;
}
Kunde Kunde::parse(string kunde)
{
    string name,ort;
    int typ;
    PreisStrategie *p;
    Tokenizer tok(kunde," ,\n");


    name=tok.nextToken();
    ort=tok.nextToken();
    typ=atoi(tok.nextToken().c_str());
    if(typ==0)
        p=new PreisStrategie();
    else if(typ==1)
        p=new GrossKundenPreis();
    else if(typ==2)
        p=new MitarbeiterPreis();

    return Kunde(name,ort,p);
}
string Kunde::toString()
{
    ostringstream os;
    os<<_name<<" "<<_ort<<" "<<_preisStrategie->typ()<<endl;
    return os.str();
}
