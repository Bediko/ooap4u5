#ifndef VERLEIH_H
#define VERLEIH_H
#include<string>
#include"dictionary.h"
#include"date.h"
#include"CD.h"
#include"Kunde.h"

using namespace std;

class Verleih{
private:
	Dictionary<CD*> _cds;
	Dictionary<Kunde*> _kunden;
	Dictionary<AusleihPos*> _ausleihen;
public:
	void lesenAusDatei(string name);
	void schreibenInDatei(string name);
	int kundenAnlegen(string name, string ort, int typ);
	void kundenEntfernen(int id);
	void kundeBearbeiten(int id, string name, string ort, int typ);
	Kunde * getKunde(int id);
	string kundeInfo();
	int cdAnlegen(string titel, string interpret, int typ);
	void cdEntfernen(int id);
	void cdTypSetzen(int is, int typ);
	void cdsVerleihen(int kundeID, list<int> cdIDs,Date tag);
	int cdsZuruecknehmen(list<int> ids, Date tag);
	CD * getCD(int id);
	string cdInfo();
	string kundenliste();
	string cdliste();
	string ausleihliste();
};



#endif
