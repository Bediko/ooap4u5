
#include"CD.h"
#include<string>
#include<list>
#include<sstream>

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
	ausleihe=apos;
}

AusleihPos* CD::holeAusleihen()
{
	return ausleihe;
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
    _id=-1;
	_typ=-1;
	_basispreis=-1;
	_strafeProTag=-1;
    _dauer=-1;
	_titel="NULL";
	_interpret="NULL";
	ausleihe=NULL;
}

CD::CD(int typ,int basispreis,int strafeProTag, int dauer, string titel, string interpret)
{

	_typ=typ;
	_basispreis=basispreis;
	_strafeProTag=strafeProTag;
    _dauer=dauer;
	_titel=titel;
	_interpret=interpret;

}

CD::~CD()
{
    delete(ausleihe);
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
	ausleihe=rhs.ausleihe;
}

CD CD::operator=(const CD& CD)
{

	_id=CD._id;
	_typ=CD._typ;
	_basispreis=CD._basispreis;
	_strafeProTag=CD._strafeProTag;
	_dauer=CD._dauer;
	_titel=CD._titel;
	_interpret=CD._interpret;
	ausleihe=CD.ausleihe;
}

bool  CD::operator==(const CD& CD){
if(_titel==CD._titel && _interpret==CD._interpret)
    return true;
return false;
}

bool CD::operator<(const CD& CD)
{
    return _interpret<CD._interpret;
}
