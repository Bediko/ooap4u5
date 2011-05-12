#ifndef PREISSTRATEGIE_H
#define PREISSTARTEGIE_H

#include "date.h"
#include "CD.h"
#include <list>
using namespace std;
class CD;

class PreisStrategie{
protected:
	int typ;
public:
	int preis(list<CD*>  cds, Date tag);
	int type();
};



#endif