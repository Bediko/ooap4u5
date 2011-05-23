

#ifndef __PREISSTRATEGIE_H__
#define __PREISSTRATEGIE_H__

#include "CD.h"
#include "Date.h"
#include <vector>

// ************************** PreisStrategie *******************************************
class PreisStrategie {

protected:
	int _typ;

public:
	PreisStrategie();

	static PreisStrategie *itoPS(int typ);
	virtual int preis(CD cd, Date tag);
	int typ();
};






// ************************* MitarbeiterPreis *****************************************
class MitarbeiterPreis : public PreisStrategie {
public:
	MitarbeiterPreis();

	int preis(CD cd, Date tag);

};




// ************************* GrossKundenPreis ******************************************
class GrossKundenPreis : public PreisStrategie {
public:
	GrossKundenPreis();

	int preis(CD cd, Date tag);

};


#endif