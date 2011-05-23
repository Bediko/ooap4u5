

#include "CD.h"
#include "Tokenizer.h"
#include <sstream>
using namespace std;

int CD::_number = 1;

CD::CD() {
	_titel = "";
	_interpret = "";
	_typ = 0;
	_id = 0;
	_ausleihe = NULL;
}

CD::CD(string titel, string interpret, int typ) {
	
	if (titel.find(":") == titel.npos)
		_titel = titel;
	else
		throw "ERROR: invalid input";

	_interpret = interpret;
	_id = CD::_number++;
	_typ = typ;
	_ausleihe = NULL;

	setzeTyp(typ);
}

CD::CD(string titel, string interpret, int typ, int id) {

	_titel = titel;
	_interpret = interpret;
	_id = id;
	_typ = typ;
	_ausleihe = NULL;

	setzeTyp(typ);

	if (id >= _number)
		_number = id + 1;
}

void CD::setzeTyp(int typ) {
	_typ = typ;

	if (typ == CD::NORMAL) {
		_dauer = 4;
		_basispreis = 200;
		_strafeProTag = 100;
	} else if (typ == CD::ANGEBOT) {
		_dauer = 10;
		_basispreis = 100;
		_strafeProTag = 40;
	} else if (typ == CD::BESTSELLER) {
		_dauer = 1;
		_basispreis = 200;
		_strafeProTag = 500;
	} else
		throw "ERROR: no such CD-type found!!";
}


int CD::ident() {
	return _id;
}


void CD::ausleihen(AusleihPos *apos) {
	if(!this->holeAusleihe()) {
		_ausleihe = apos;
	}
	else {
		throw "ERROR: CD already loan";
	}
}

void CD::rueckgabe() {
	_ausleihe = NULL;
}


AusleihPos *CD::holeAusleihe() {
	return this->_ausleihe;
}

string CD::toString() {
	ostringstream os;

	os << _id << ":" << _titel << ":" << _interpret << ":" << _typ;

	return os.str();

}


CD CD::parse(string cd) {
	string idStr, titel, interpret, typStr;
	int id, typ;
	Tokenizer tok(cd, ':');

	id = atoi((tok.getSubstr()).c_str());
	titel = tok.getSubstr();
	interpret = tok.getSubstr();
	typ = atoi((tok.getSubstr()).c_str());

	

	CD neueCD(titel, interpret, typ, id);

	return neueCD;
}

int CD::preis(int dauer) {

	if(dauer <= _dauer)
		return _basispreis;
	else {
		dauer -= _dauer;
		return (_basispreis + (dauer * _strafeProTag));
	}
}

string CD::titel() {
	return _titel;
}

string CD::interpret() {
	return _interpret;
}

int CD::holeTyp() {
	return _typ;
}
