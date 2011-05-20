#ifndef AUSLEIHPOS_H
#define AUSLEIHPOS_H
#include<string>
#include "Kunde.h"

using namespace std;
class Date;
class Kunde;
class CD;
class AusleihPos{

private:
	Kunde *_kunde;
	Date *_tagDerAusleihe;
	CD *_cd;
public:
    Date *getDate();
	static AusleihPos * parse(string a);
	string toString();
	AusleihPos(Kunde *kunde,CD *cd,Date *tagDerAusleihe);
	~AusleihPos();

};


#endif
