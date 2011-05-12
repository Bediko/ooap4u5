	
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
	os<<_id<<

	
CD::CD();
	
CD::CD(int typ,int basispreis,int strafeProTag, int dauer, string titel, string interpret);
	
CD::~CD(){};
	
CD::CD(const CD& rhs);
	
CD::CD operator=(CD);
	
CD::CD operator==(CD);
	
CD::CD operator<(CD);