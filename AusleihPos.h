#ifndef AUSLEIHPOS_H
#define AUSLEIHPOS_H
#include<string>
#include "Kunde.h"

using namespace std;

class AusleihPos{
private:
	Kunde kunde;
	Date tagDerAusleihe;
public:
	AusleihPos parse(string a);
	string toString();
	AusleihPos();
	~AusleihPos();
	AusleihPos(const CD& rhs);
	AusleihPos operator=(CD);
	AusleihPos operator==(CD);
	AusleihPos operator<(CD);
};


#endif