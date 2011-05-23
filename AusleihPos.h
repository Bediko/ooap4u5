

#ifndef __AUSLEIHPOS_H__
#define __AUSLEIHPOS_H__

#include "Date.h"
#include "Kunde.h"
#include "CD.h"

class AusleihPos {
protected:
	CD _cd;
	Kunde _kunde;
	Date _tagDerAusleihe;

public:
	AusleihPos(CD c, Kunde k, Date d);

	int identKunde();
	int identCD();
	Kunde *getKunde();
	Date getDate();
	CD *getCD();
	static AusleihPos parse(string a);
	string toString();

};



#endif