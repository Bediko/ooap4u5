#ifndef KUNDE_H
#define KUNDE_H
#include<string>
#include<list>
#include "AusleihPos.h"
#include "PreisStrategie.h"
#include "CD.h"
#include "dictionary.h"

using namespace std;
class AusleihPos;
class CD;
class PreisStrategie;
class Kunde{
private:
	Dictionary<AusleihPos*> _ausleihen;
	PreisStrategie *_preisStrategie;
	static int _number;
	int _id;
	string _name;
	string _ort;
public:
    Kunde(string n, string o,PreisStrategie *p);
    Kunde();
    ~Kunde();
    Kunde(const Kunde& rhs);
	Kunde(string name,string ort,int typ);
	Kunde operator=(const Kunde& kunde);

	int ident();
	void setzeName(string n);
	string getname();
	void setzeOrt(string o);
	string getort();
	void setzePStrat(PreisStrategie *P);
	int preis(Dictionary<CD*> cds, Date tag);
	void leiheAus(AusleihPos *apos);
	void rueckgabe(AusleihPos *apos);
	Dictionary<AusleihPos *> holeAusleihen();
	static Kunde parse(string kunde);
	string toString();
};





#endif
