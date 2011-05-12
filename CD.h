#ifndef CD_H
#define CD_H
#include<string>
#include<list>
#include"AusleihPos.h"

using namespace std;

class AusleihPos;

class CD{
private:
	int static _number;
	int _id;
	int _typ;
	int _basispreis;
	int _strafeProTag;
	int _dauer;
	string _titel;
	string _interpret;
	AusleihPos *ausleihe;
public:
	int ident();
	string titel();
	string interpret();
	void setzeTyp(int typ);
	int holeTyp();
	void ausleihen(AusleihPos *apos);
	AusleihPos* holeAusleihen();
	int preis(int dauer);
	CD parse(string cd);
	string toString();
	CD();
	~CD();
	CD(int typ,int basispreis,int strafeProTag, int dauer, string titel, string interpret);
	CD(const CD& rhs);
	CD operator=(const CD& CD);
	bool operator==(const CD& CD);
	bool operator<(const CD& CD);
};



#endif
