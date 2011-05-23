
#include "Verleih.h"
#include "Kunde.h"
#include <fstream>
using namespace std;


void Verleih::schreibeInDatei(string name) {
	ofstream f;
	map<int, Kunde *>::iterator iterKu;
	map<int, CD *>::iterator iterCD;
	vector<AusleihPos *>::iterator iterAu;


	//Kundendaten speichern
	f.open("Kunden.txt");

	if(!f.is_open())
		throw "ERROR: could not open file Kunden.txt";

	for(iterKu = _kunden.begin(); iterKu != _kunden.end(); iterKu++) {
		f << (*iterKu).second->toString() << endl;
	}

	f.close();



	f.open("CDs.txt");

	if(!f.is_open())
		throw "ERROR: could not open file CDs.txt";

	for(iterCD = _cds.begin(); iterCD != _cds.end(); iterCD++) {
		f << (*iterCD).second->toString() << endl;
	}

	f.close();



	f.open("Ausleihen.txt");

	if(!f.is_open())
		throw "ERROR: could not open file Ausleihen.txt";

	for(iterAu = _ausleihen.begin(); iterAu != _ausleihen.end(); iterAu++) {
		f << (*iterAu)->toString() << endl;
	}

	f.close();
}


void Verleih::leseAusDatei(string name) {
	ifstream f;
	string temp;
	Kunde *k, *pK;
	CD *cd, *pCD;
	AusleihPos *apos;
	int id;

	// ------- Kunden einlesen ---------------
	f.open("Kunden.txt");
	if(!f.is_open())
		throw "ERROR: could not open file Kunden.txt";

	while(!f.eof()) {
		getline(f, temp);
		if(temp != "") {
			k = new Kunde(Kunde::parse(temp));
			_kunden.insert(pair<int, Kunde *>(k->ident(), k));
		}
	}
	f.close();

	// ------------ CDs einlesen ----------
	f.open("CDs.txt");
	if(!f.is_open())
		throw "ERROR: could not open file CDs.txt";

	while(!f.eof()) {
		getline(f, temp);
		if(temp != "") {
			cd = new CD(CD::parse(temp));
			_cds.insert(pair<int, CD *>(cd->ident(), cd));
		}
	}
	f.close();


	// -------------- AusleihPositionen einlesen -------------------------
	f.open("Ausleihen.txt");
	if(!f.is_open())
		throw "ERROR: could not open file Ausleihen.txt";

	while(!f.eof()) {
		getline(f, temp);
		if(temp != "") {
			apos = new AusleihPos(AusleihPos::parse(temp));

			_ausleihen.push_back(apos);
			//Ausleihe beim Kunden merken
			id = apos->identKunde();
			k = (*_kunden.find(id)).second;
			k->ausleihen(apos);

			//Ausleihe bei der CD merken
			id = apos->identCD();
			cd = (*_cds.find(id)).second;
			cd->ausleihen(apos);
		}
	}
	f.close();
}


int Verleih::kundeAnlegen(string name, string ort, int typ) {
	int id;

	Kunde *k = new Kunde(name, ort, typ);
	id = k->ident();
	_kunden.insert(pair<int, Kunde *>(id, k));

	return id;
}


void Verleih::kundeEntfernen(int id) {
	map<int, Kunde *>::iterator iter;
	vector<AusleihPos *> ausleihen;


	iter = _kunden.find(id);

	ausleihen = (*iter).second->holeAusleihen();

	if(!(ausleihen.empty()))
		throw "ERROR: Kunde has even more CDs!!!!";

	if(iter == _kunden.end())
		throw "ERROR: KundenID does not exist. erased nothing!!";

	delete (*iter).second;
	_kunden.erase(iter);
}


string Verleih::kundenliste() {
	ostringstream os;

	map<int, Kunde *>::iterator iter;

	for(iter = _kunden.begin(); iter != _kunden.end(); iter++) {
		os << (*iter).second->toString() << endl;
	}

	return os.str();
}


Kunde *Verleih::getKunde(int id) {
	Kunde *k;
	map<int, Kunde *>::iterator iter;

	iter = _kunden.find(id);

	if(iter == _kunden.end())
		throw "ERROR: no such KundenID found!!";

	k = (*iter).second;

	return k;
}



void Verleih::kundeBearbeiten(int id, string name, string ort, int typ) {
	map<int, Kunde *>::iterator iter;
	PreisStrategie *ps;

	ps = PreisStrategie::itoPS(typ);

	iter = _kunden.find(id);

	if(iter == _kunden.end())
		throw "ERROR: KundenID not found!!";

	(*iter).second->setzeName(name);
	(*iter).second->setzeOrt(ort);
	(*iter).second->setzePStrat(ps);

}


int Verleih::cdAnlegen(string titel, string interpret, int typ) {
	int id;

	CD *cd = new CD(titel, interpret, typ);
	id = cd->ident();
	_cds.insert(pair<int, CD *>(id, cd));

	return id;
}


void Verleih::cdEntfernen(int id) {
	map<int, CD *>::iterator iter;
	AusleihPos *apos;

	iter = _cds.find(id);

	apos = (*iter).second->holeAusleihe();

	if(apos != NULL)
		throw "ERROR: cd is even loan!!!";

	if(iter == _cds.end())
		throw "ERROR: No such cdID found!!";

	_cds.erase(iter);
}


void Verleih::cdTypSetzen(int id, int typ) {
	map<int, CD *>::iterator iter;

	iter = _cds.find(id);

	if(iter == _cds.end())
		throw "ERROR: No such cdID found!!";

	(*iter).second->setzeTyp(typ);
}


string Verleih::cdliste() {
	map<int, CD *>::iterator iter;
	ostringstream os;

	for(iter = _cds.begin(); iter != _cds.end(); iter++) {
		os << (*iter).second->toString() << endl;
	}

	return os.str();
}

CD *Verleih::getCD(int id) {
	map<int, CD *>::iterator iter;
	CD *cd;

	iter = _cds.find(id);

	if(iter == _cds.end())
		throw "ERROR: No such cdID found!!";

	cd = (*iter).second;

	return cd;
}


void Verleih::cdsVerleihen(int kundeID, vector<int> cdIDs, Date tag) {

	map<int, Kunde *>::iterator iterKunde;
	map<int, CD *>::iterator iterCD;
	vector<int>::iterator iterAnzahl;

	//Kunden raussuchen
	iterKunde = _kunden.find(kundeID);

	if(iterKunde == _kunden.end())
		throw "ERROR: No such KundenID found!!";

	for(iterAnzahl = cdIDs.begin(); iterAnzahl != cdIDs.end(); iterAnzahl++) {
		//CD raussuchen
		iterCD = _cds.find(*iterAnzahl);
		if(iterCD == _cds.end())
			throw "ERROR: No such cdID found!!";

		if((*iterCD).second->holeAusleihe() == NULL) {
			//AusleihPos erstellen und einfügen
			AusleihPos *apos = new AusleihPos(*(*iterCD).second, *(*iterKunde).second, tag);
			_ausleihen.push_back(apos);
			(*iterCD).second->ausleihen(apos);
			(*iterKunde).second->ausleihen(apos);

		}
		else
			throw "ERROR: CD already loan!!";
	}

}


int Verleih::cdsZuruecknehmen(vector<int> ids, Date tag) {
	int preis = 0, id;
	vector<int>::iterator iter;
	map<int, CD *>::iterator iterCD;
	map<int, Kunde *>::iterator iterKunde;
	vector<AusleihPos *>::iterator iterAusleihen, toDel;
	Kunde *k;
	CD *cd;
	AusleihPos *apos;

	for(iter = ids.begin(); iter != ids.end(); iter++) {

		//CD raussuchen
		iterCD = _cds.find(*iter);
		if(iterCD == _cds.end())
			throw "ERROR: No such cdID found!!";
		cd = (*iterCD).second;

		//AusleihPos raussuchen
		apos = cd->holeAusleihe();
		if (apos == NULL)
			throw "ERROR: no such AusleihPos found!!";

		//dazugehörigen Kunden raussuchen
		id = apos->getKunde()->ident();
		iterKunde = _kunden.find(id);
		if(iterKunde == _kunden.end())
			throw "ERROR: No such cdID found!!";
		k = (*iterKunde).second;

		preis += k->preis(*cd, tag);

		//freigeben
		cd->rueckgabe();
		k->rueckgabe(apos);
		for(iterAusleihen = _ausleihen.begin(); iterAusleihen != _ausleihen.end(); iterAusleihen++) {
			if((*iterAusleihen) == apos) {
				toDel = iterAusleihen;
				break;
			}
		}
		if(toDel != _ausleihen.end()) {
			delete (*toDel);
			_ausleihen.erase(toDel);
		}
		else
			throw "ERROR: AusleihPos not found!!";
	}


	return preis;
}



string Verleih::ausleihliste() {
	ostringstream os("");
	vector<AusleihPos *>::iterator iter;

	for(iter = _ausleihen.begin(); iter != _ausleihen.end(); iter++) {
		os << (*iter)->toString() << endl;
	}

	return os.str();
}

string Verleih::sucheCDnachTitel(string titel) {
	ostringstream os;

	for(map<int, CD *>::iterator iter = _cds.begin(); iter != _cds.end(); iter++) {
		if((*iter).second->titel() == titel) {
			os << cdInfo((*iter).second->ident()) << endl;
		}
	}

	if(os.str() == "")
		throw "ERROR: no such Titel found!!";

	return os.str();
}

string Verleih::sucheCDnachInterpret(string interpret) {
	ostringstream os;

	for(map<int, CD *>::iterator iter = _cds.begin(); iter != _cds.end(); iter++) {
		if((*iter).second->interpret() == interpret) {
			os << cdInfo((*iter).second->ident()) << endl;
		}
	}
	if(os.str() == "")
		throw "ERROR: no such Interpret found!!";

	return os.str();
}


string Verleih::sucheCDnachTyp(int typ) {
	ostringstream os;

	for(map<int, CD *>::iterator iter = _cds.begin(); iter != _cds.end(); iter++) {
		if((*iter).second->holeTyp() == typ) {
			os << cdInfo((*iter).second->ident()) << endl;
		}
	}
	if(os.str() == "")
		throw "ERROR: no such Typ found!!";

	return os.str();
}

string Verleih::sucheKundeNachName(string name) {
	ostringstream os;

	for(map<int, Kunde *>::iterator iter = _kunden.begin(); iter != _kunden.end(); iter++) {
		if((*iter).second->name() == name) {
			os << kundeInfo((*iter).second->ident()) << endl;
		}
	}
	if(os.str() == "")
		throw "ERROR: no such Name found!!";

	return os.str();
}


string Verleih::sucheKundeNachOrt(string ort) {
	ostringstream os;

	for(map<int, Kunde *>::iterator iter = _kunden.begin(); iter != _kunden.end(); iter++) {
		if((*iter).second->ort() == ort) {
			os << kundeInfo((*iter).second->ident()) << endl;
		}
	}
	if(os.str() == "")
		throw "ERROR: no such Ort found!!";

	return os.str();
}

string Verleih::sucheKundeNachTyp(int typ) {
	ostringstream os;

	for(map<int, Kunde *>::iterator iter = _kunden.begin(); iter != _kunden.end(); iter++) {
		if((*iter).second->getTyp() == typ) {
			os << kundeInfo((*iter).second->ident()) << endl;
		}
	}
	if(os.str() == "")
		throw "ERROR: no such typ found!!";

	return os.str();
}


string Verleih::kundeInfo(int id) {
	Kunde *k;
	ostringstream os;
	vector<AusleihPos *> ausleihen;
	vector<AusleihPos *>::iterator iterAus;

	if(_kunden.find(id) != _kunden.end())
		k = (*_kunden.find(id)).second;
	else
		throw "ERROR: no such KundenID found";

	os << endl << k->toString() << endl << "Ausleihen: \n";
	ausleihen = k->holeAusleihen();

	for(iterAus = ausleihen.begin(); iterAus != ausleihen.end(); iterAus++) {
		os << (*iterAus)->toString() << endl;
	}

	return os.str();
}



string Verleih::cdInfo(int id) {
	CD *cd;
	ostringstream os;

	if(_cds.find(id) != _cds.end())
		cd = (*_cds.find(id)).second;
	else
		throw "ERROR: no such CD-ID found";

	os << cd->toString() << "\tverfuegbar: ";
	if(cd->holeAusleihe() == NULL)
		os << "ja\n";
	else
		os << "nein\n";

	return os.str();
}

