
#ifndef __KUNDE_H__
#define __KUNDE_H__

#include "PreisStrategie.h"

class AusleihPos;


class Kunde {

protected:
	static int _number;
	int _id;
	string _name;
	string _ort;
	vector<AusleihPos *> _ausleihen;
	PreisStrategie *_preisStrategie;

public:
	static const int NORMAL = 0;
	static const int MITARBEITER = 1;
	static const int GROSSKUNDE = 2;

	Kunde();
	Kunde(string name, string ort, int typ);
	Kunde(string name, string ort, int typ, int id);

	int ident();
	void setzeName(string n);
	string name();
	void setzeOrt(string o);
	string ort();
	void setzePStrat(PreisStrategie *ps);
	int preis(CD cd, Date tag);
	void ausleihen(AusleihPos *apos);
	void rueckgabe(AusleihPos *apos);
	vector<AusleihPos *> holeAusleihen();
	static Kunde parse(string kunde);
	string toString();
	int getTyp();
};



#endif