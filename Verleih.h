
#ifndef __VERLEIH_H__
#define __VERLEIH_H__

#include "CD.h"
#include "AusleihPos.h"
#include "Kunde.h"
#include <map>
#include <vector>

class Verleih {
protected:
	map<int, CD *> _cds;
	map<int, Kunde *> _kunden;
	vector<AusleihPos *> _ausleihen;

public:

	void leseAusDatei(string name);
	void schreibeInDatei(string name);
	int kundeAnlegen(string name, string ort, int typ);
	void kundeEntfernen(int id);
	void kundeBearbeiten(int id, string name, string ort, int typ);
	Kunde *getKunde(int id);
	int cdAnlegen(string titel, string interpret, int typ);
	void cdEntfernen(int id);
	void cdTypSetzen(int id, int typ);
	void cdsVerleihen(int kundeID, vector<int> cdIDs, Date tag);
	int cdsZuruecknehmen(vector<int> ids, Date tag);
	CD *getCD(int id);
	string cdInfo(int id);
	string kundeInfo(int id);

	string kundenliste();
	string cdliste();
	string ausleihliste();

	string sucheCDnachTitel(string titel);
	string sucheCDnachInterpret(string interpret);
	string sucheCDnachTyp(int typ);

	string sucheKundeNachName(string name);
	string sucheKundeNachOrt(string ort);
	string sucheKundeNachTyp(int typ);
};



#endif
