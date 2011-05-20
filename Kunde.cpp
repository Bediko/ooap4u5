#include "Kunde.h"
#include <string>
#include <list>
#include "tokenizer.h"
#include <cstdlib>
#include <sstream>
#include "PreisStrategie.h"

using namespace std;

int Kunde::_number=0;



Kunde::Kunde()
{
    _id=-1;

    _name="NULL";
    _ort="NULL";
    _preisStrategie=NULL;

}

Kunde::Kunde(string name,string ort,int typ)
{
    _id=_number;
    Kunde::_number++;
    _name=name;
    _ort=ort;
    switch(typ)
    {
    default:
        _preisStrategie=new PreisStrategie();
        break;
    case 1:
        _preisStrategie=new MitarbeiterPreis();
        break;
    case 2:
        _preisStrategie=new GrossKundenPreis();
    }
}

Kunde::~Kunde()
{
        delete(_preisStrategie);
        _ausleihen.erase();
}
Kunde::Kunde(const Kunde& rhs)
{
    switch(rhs._preisStrategie->typ())
{
   default:
        _preisStrategie=new PreisStrategie();
        break;
    case 1:
        _preisStrategie=new MitarbeiterPreis();
        break;
    case 2:
        _preisStrategie=new GrossKundenPreis();
}

  _ausleihen=rhs._ausleihen;
  _name=rhs._name;
  _ort=rhs._ort;
  _id=rhs._id;
}

Kunde Kunde::operator=(const Kunde& kunde)
{
    switch(kunde._preisStrategie->typ())
{
   default:
        _preisStrategie=new PreisStrategie();
        break;
    case 1:
        _preisStrategie=new MitarbeiterPreis();
        break;
    case 2:
        _preisStrategie=new GrossKundenPreis();
}
  _ausleihen=kunde._ausleihen;
  _name=kunde._name;
  _ort=kunde._ort;
  _id=kunde._id;
  //return *this;
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
Kunde * Kunde::parse(string kunde)
{
    string name,ort;
    int typ;
    Tokenizer tok(kunde,";,\n");
    name=tok.nextToken();
    ort=tok.nextToken();
    typ=atoi(tok.nextToken().c_str());
    return  new Kunde(name,ort,typ);
}

string Kunde::toString()
{
    ostringstream os;
    os<<_name<<";"<<_ort<<";"<<_preisStrategie->typ()<<endl;
    return os.str();
}
