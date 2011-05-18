
#include"CD.h"
#include<string>
#include<list>
#include<sstream>
#include<cstdlib>
#include"tokenizer.h"

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
    int preis;
    preis=_basispreis*dauer;
    switch(_typ)
    {
    case 0:
        if(dauer>4)
            preis+=((dauer-4)*_strafeProTag);
        break;
    case 1:
        if(dauer>10)
            preis+=(dauer-10)*_strafeProTag;
        break;
    case 2:
        if(dauer>1)
            preis+=(dauer-1)*_strafeProTag;
        break;
    }
	return preis;
}

CD CD::parse(string cd)
{
    string titel,interpret;
    Tokenizer tok(cd," ,\n");
    int typ,basispreis,strafeprotag,dauer;


    typ=atoi(tok.nextToken().c_str());
    basispreis=atoi(tok.nextToken().c_str());
    strafeprotag=atoi(tok.nextToken().c_str());
    dauer=atoi(tok.nextToken().c_str());
    titel=tok.nextToken();
    interpret=tok.nextToken();

    return CD(typ,dauer,titel,interpret,NULL);


}

string CD::toString()
{
	ostringstream os;
	os<<_typ << " "<<_basispreis<<" "<<_strafeProTag<<" "<<_dauer<<" "<<_titel<<" "<<_interpret<<endl;
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

CD::CD(int typ,int dauer, string titel, string interpret,AusleihPos *ausleihe)
{
    _id=CD::_number;
    CD::_number++;

	_typ=typ;
	switch(_typ)
	{
	    case 0:
	    _basispreis=200;
        _strafeProTag=100;
        break;
        case 1:
	    _basispreis=100;
        _strafeProTag=40;
        break;
        case 2:
	    _basispreis=200;
        _strafeProTag=500;
        break;
	}

    _dauer=dauer;
	_titel=titel;
	_interpret=interpret;
	_ausleihe=ausleihe;

}

CD::~CD()
{
    delete(_ausleihe);

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
