#ifndef KUNDE_H
#define KUNDE_H
#include<string>
#include<list>
#include "AusleihPos.h"
#include "PreisStrategie.h"
#include "CD.h"

using namespace std;
class AusleihPos;
class CD;
class Kunde{
private:
	list<AusleihPos> ausleihen;
	PreisStrategie preisStrategie;
	int number;
	int id;
	string name;
	string ort;
public:
	int ident();
	void setzeName(string n);
	string getname();
	void setzeOrt(string o);
	string getort();
	void setzePStrat(PreisStrategie *P);
	int preis(list<CD> cds, Date tag);
	void leiheAus(AusleihPos *apos);
	void rueckgabe(AusleihPos *apos);
	list<AusleihPos *> holeAusleihen();
	Kunde parse(string kunde);
	string toString();
};





#endif