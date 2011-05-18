#ifndef PREISSTRATEGIE_H
#define PREISSTRATEGIE_H

#include "date.h"
#include "CD.h"
#include "dictionary.h"
using namespace std;
class CD;

class PreisStrategie{
protected:
	int _typ;
public:
    virtual int preis(Dictionary<CD*>  cds, Date tag);
	int typ();
	PreisStrategie();
};

class GrossKundenPreis: public PreisStrategie{

public:
	int preis(Dictionary<CD*> cds, Date tag);
	GrossKundenPreis();

};

class MitarbeiterPreis: public PreisStrategie{

public:
	int preis(Dictionary<CD*> cds, Date tag);
	MitarbeiterPreis();

};



#endif
