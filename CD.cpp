
#include"CD.h"
#include<string>
#include<list>
#include<sstream>

using namespace std;
int CD::_number=0;

int CD::ident()
{
	return _id;
}
string CD::titel()
{
	return _titel;
}

string CD::interpret()
{
	return _interpret;
}
void CD::setzeTyp(int typ)
{
	_typ=typ;
}
int CD::holeTyp()
{
	return _typ;
}
void CD::ausleihen(AusleihPos *apos)
{
	_ausleihe=apos;
}

AusleihPos* CD::holeAusleihen()
{
	return _ausleihe;
}

int CD::preis(int dauer)
{
	return _basispreis*dauer;
}

CD CD::parse(string cd)
{
}

string CD::toString()
{
	ostringstream os;
	os<<_id<<" "<<_typ << " "<<_basispreis<<" "<<_strafeProTag<<" "<<_dauer<<" "<<_titel<<" "<<_interpret<<endl;
	return os.str();
}


CD::CD()
{
    _id=CD::_number;
	_typ=-1;
	_basispreis=-1;
	_strafeProTag=-1;
    _dauer=-1;
	_titel="NULL";
	_interpret="NULL";
	_ausleihe=NULL;
	CD::_number++;
}

CD::CD(int typ,int basispreis,int strafeProTag, int dauer, string titel, string interpret,AusleihPos *ausleihe)
{
    _id=CD::_number;
    CD::_number++;

	_typ=typ;
	_basispreis=basispreis;
	_strafeProTag=strafeProTag;
    _dauer=dauer;
	_titel=titel;
	_interpret=interpret;
	_ausleihe=ausleihe;

}

CD::~CD()
{
    delete(_ausleihe);
    CD::_number--;
}

CD::CD(const CD& rhs)
{

	_id=rhs._id;
	_typ=rhs._typ;
	_basispreis=rhs._basispreis;
	_strafeProTag=rhs._strafeProTag;
	_dauer=rhs._dauer;
	_titel=rhs._titel;
	_interpret=rhs._interpret;
	_ausleihe=rhs._ausleihe;
}

CD CD::operator=(const CD& CD)
{
    delete(_ausleihe);
	_id=CD._id;
	_typ=CD._typ;
	_basispreis=CD._basispreis;
	_strafeProTag=CD._strafeProTag;
	_dauer=CD._dauer;
	_titel=CD._titel;
	_interpret=CD._interpret;
	_ausleihe=0;
	_ausleihe=CD._ausleihe;
	return *this;
}

bool  CD::operator==(const CD& CD){

return (_titel.compare(CD._titel)==0)&&(_interpret.compare(CD._interpret)==0);
}

bool CD::operator<(const CD& CD)
{
    return ((_interpret.compare(CD._interpret)<0)||(_interpret.compare(CD._interpret)==0))&&_titel.compare(CD._titel)<0;
}
