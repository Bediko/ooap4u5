

#include "Kunde.h"
#include "Verleih.h"
#include "Tokenizer.h"
#include <cstdlib>

int Kunde::_number = 1;

Kunde::Kunde() {
	_name = "";
	_ort = "";
	_id = 0;
	_preisStrategie = new PreisStrategie;
}

Kunde::Kunde(string name, string ort, int typ) {
	_name = name;
	_ort = ort;
	_id = Kunde::_number++;
	_preisStrategie = PreisStrategie::itoPS(typ);
}

Kunde::Kunde(string name, string ort, int typ, int id) {
	_name = name;
	_ort = ort;
	_id = id;
	_preisStrategie = PreisStrategie::itoPS(typ);

	if (id >= _number)
		_number = id + 1;
}


void Kunde::setzeName(string n) {
	_name = n;
}

void Kunde::setzeOrt(string o) {
	_ort = o;
}

void Kunde::setzePStrat(PreisStrategie *ps) {

	_preisStrategie = ps;
}


void Kunde::ausleihen(AusleihPos *apos) {
	_ausleihen.push_back(apos);
}

void Kunde::rueckgabe(AusleihPos *apos) {
	vector<AusleihPos *>::iterator iter;

	for(iter = _ausleihen.begin(); iter != _ausleihen.end(); iter++) {
		if(*iter == apos)
			break;
	}

	if(iter == _ausleihen.end())
		throw "ERROR: no such AusleihPos found!!";

	_ausleihen.erase(iter);
}

vector<AusleihPos *> Kunde::holeAusleihen() {
	return _ausleihen;
}

int Kunde::ident() {
	return _id;
}

int Kunde::getTyp() {
	return _preisStrategie->typ();
}

string Kunde::toString() {
	ostringstream os;

	os << _id << ":" << _name << ":" << _ort << ":" << _preisStrategie->typ();

	return os.str();
}


Kunde Kunde::parse(string kunde) {
	string idStr, name, ort, typStr;
	int id, typ;
	Tokenizer tok(kunde, ':');

	id = atoi((tok.getSubstr()).c_str());
	name = tok.getSubstr();
	ort = tok.getSubstr();
	typ = atoi((tok.getSubstr()).c_str());


	Kunde k(name, ort, typ, id);

	return k;
}


int Kunde::preis(CD cd, Date tag) {
	return _preisStrategie->preis(cd, tag);
}

string Kunde::name() {
	return _name;
}

string Kunde::ort() {
	return _ort;
}
