
#ifndef __CD_H__
#define __CD_H__

#include <vector>
#include <string>
using namespace std;

class AusleihPos;


class CD {
protected:
	static int _number;
	int _id;
	string _titel;
	string _interpret;
	int _typ;
	int _basispreis;
	int _strafeProTag;
	int _dauer;
	AusleihPos *_ausleihe;

public:
	static const int NORMAL = 1;
	static const int ANGEBOT = 2;
	static const int BESTSELLER = 3;

	CD();
	CD(string titel, string interpret, int typ);
	CD(string titel, string interpret, int typ, int id);
	int ident();
	string titel();
	string interpret();
	void setzeTyp(int typ);
	int holeTyp();
	void ausleihen(AusleihPos *apos);
	void rueckgabe();
	AusleihPos *holeAusleihe();
	int preis(int dauer);
	static CD parse(string cd);

	string toString();
};



#endif