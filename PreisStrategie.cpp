

#include "PreisStrategie.h"
#include "AusleihPos.h"



// *************************************** PreisStrategie ***********************************************

PreisStrategie::PreisStrategie() {
	_typ = Kunde::NORMAL;
}

int PreisStrategie::preis(CD cd, Date tag) {
	Date d = cd.holeAusleihe()->getDate();
	
	return cd.preis(tag-d);
}

int PreisStrategie::typ() {
	return _typ;
}

PreisStrategie *PreisStrategie::itoPS(int typ) {
	PreisStrategie *ps;
	
	if (typ == Kunde::NORMAL)
		ps = new PreisStrategie;
	else if (typ == Kunde::MITARBEITER)
		ps = new MitarbeiterPreis;
	else if (typ == Kunde::GROSSKUNDE)
		ps = new GrossKundenPreis;
	else
		throw "ERROR: no such PreisStrategie-type found!!";

	return ps;
}






// ************************************ MitarbeiterPreis ************************************************

MitarbeiterPreis::MitarbeiterPreis() {
	_typ = Kunde::MITARBEITER;
}

int MitarbeiterPreis::preis(CD cd, Date tag) {
	if(cd.ident() != 2)
		return PreisStrategie::preis(cd, tag);
	else
		return 0;
}







// ********************************** GrossKundenPreis ***************************************************

GrossKundenPreis::GrossKundenPreis() {
	_typ = Kunde::GROSSKUNDE;
}

int GrossKundenPreis::preis(CD cd, Date tag) {
	int preis = 0;

	preis = PreisStrategie::preis(cd, tag);

	preis = preis - (preis * 0.15);
	
	return preis;
}