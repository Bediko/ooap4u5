#ifndef GROSSKUNDENPREIS_H
#define GROSSKUNDENPREIS_H
#include <list>
#include "date.h"
#include "CD.h"
#include"PreisStrategie.h"

using namespace std;

class MitarbeiterPreis: public PreisStrategie{
protected:
	int typ;
public:
	int preis(list<CD*> cds, Date tag);
	
};



#endif