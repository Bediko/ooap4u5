

#include "AusleihPos.h"
#include "Verleih.h"
#include "Tokenizer.h"

AusleihPos::AusleihPos(CD c, Kunde k, Date d) {
	_cd = c;
	_kunde = k;
	_tagDerAusleihe = d;

	_kunde.ausleihen(this);
	_cd.ausleihen(this);
}


AusleihPos AusleihPos::parse(string a) {
	string kunde, cd, tag;
	Tokenizer tok(a, ';');

	cd = tok.getSubstr();
	kunde = tok.getSubstr();
	tag = tok.getSubstr();


	AusleihPos apos(CD::parse(cd), Kunde::parse(kunde), *DateFormatDE::parse(tag));

	return apos;
}

Kunde *AusleihPos::getKunde() {
	return &_kunde;
}

CD *AusleihPos::getCD() {
	return &_cd;
}

Date AusleihPos::getDate() {
	return _tagDerAusleihe;
}

string AusleihPos::toString() {
	stringstream os;

	os << _cd.toString() << ";" << _kunde.toString() << ";" <<  _tagDerAusleihe.toString();

	return os.str();
}

int AusleihPos::identCD() {
	return _cd.ident();
}

int AusleihPos::identKunde() {
	return _kunde.ident();
}