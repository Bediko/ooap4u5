

#include "Verleih.h"
#include "Date.h"
#include <iostream>
#include <string>


void hauptMenue() {
	cout << "+---------------+\n";
	cout << "| Hauptmenue:   |\n";
	cout << "+---------------+\n\n";

	cout << "(1) Daten aus Datei einlesen\n";
	cout << "(2) Daten in Datei schreiben\n";
	cout << "(3) Stammdaten aendern\n";
	cout << "(4) CDs verleihen\n";
	cout << "(5) CDs zuruecknehmen (inkl. Rechnung)\n";
	cout << "(6) Infos anzeigen\n";
	cout << "(7) Kundenliste\n";
	cout << "(8) CD-Liste\n";
	cout << "(9) Ausleihliste\n\n";

	cout << "(0) Programm beenden\n";
	cout << "-------------------------\n";
	cout << "Ihre Auswahl: ";
}

void stammdatenMenue() {
	cout << "+-----------------------+\n";
	cout << "| Stammdaten pflegen:   |\n";
	cout << "+-----------------------+\n\n";

	cout << "(1) neue CD in den Katalog aufnehmen\n";
	cout << "(2) alte CD aus dem Katalog entfernen\n";
	cout << "(3) Typ der CD aendern\n";
	cout << "(4) neuen Kunden aufnehmen\n";
	cout << "(5) alten Kunden entfernen\n";
	cout << "(6) Kundendaten aendern\n\n";

	cout << "(0) zurueck\n";
	cout << "-------------------------\n";
	cout << "Ihre Auswahl: ";
}

void suchenMenue() {
	cout << "+-----------------------+\n";
	cout << "| Infos anzeigren:      |\n";
	cout << "+-----------------------+\n\n";

	cout << "(1) CD-Infos\n";
	cout << "(2) Kunden-Infos\n\n";

	cout << "(0) zurueck\n";
	cout << "-------------------------\n";
	cout << "Ihre Auswahl: ";
}

void suchenCDMenue() {
	cout << "+-----------------------+\n";
	cout << "| CD-Infos:             |\n";
	cout << "+-----------------------+\n\n";

	cout << "(1) nach Titel suchen\n";
	cout << "(2) nach Interpret suchen\n";
	cout << "(3) nach ID suchen\n";
	cout << "(4) nach Typ suchen\n\n";

	cout << "(0) zurueck\n";
	cout << "-------------------------\n";
	cout << "Ihre Auswahl: ";
}


void suchenKundeMenue() {
	cout << "+-----------------------+\n";
	cout << "| Kunden-Infos:         |\n";
	cout << "+-----------------------+\n\n";

	cout << "(1) nach Namen suchen\n";
	cout << "(2) nach Ort suchen\n";
	cout << "(3) nach ID suchen\n";
	cout << "(4) nach Kunden-Typ suchen\n\n";

	cout << "(0) zurueck\n";
	cout << "-------------------------\n";
	cout << "Ihre Auswahl: ";

}

int main() {
	Verleih verleih;
	int choiceHaupt, choiceStammd, cSuche, cSucheKu, cSucheCD;
	string titel, interpret, name, ort, temp;
	int typCD, typKunde;
	int IDkunde, IDcd;
	vector<int> cdIDs;
	string tag;
	Date *d;

	do {



		hauptMenue();
		cin >> choiceHaupt;

		switch(choiceHaupt) {

		// ------------------------ aus datei lesen --------------
		case 1:
			try {
				verleih.leseAusDatei("");
				cout << "Daten erfolgreich eingelesen" << endl;
			} catch(const char *ex) {
				cout << endl << ex << endl;
			}

			break;
		// -----------------------------------------------------------


		// ----------------------- in datei schreiben -----------------
		case 2:
			try {
				verleih.schreibeInDatei("");
			} catch(const char *ex) {
				cout << endl << ex << endl;

			}
			break;
		// ------------------------------------------------------------

		// ++++++++++++++++++++ stammdaten ändern ++++++++++++++++++++++
		case 3:
			do {

				stammdatenMenue();
				cin >> choiceStammd;

				switch(choiceStammd) {
					// ---------- cd aufnehmen --------------------
				case 1:

					getline(cin, titel);
					cout << "Titel: ";
					getline(cin, titel);
					cout << "Interpret: ";
					getline(cin, interpret);
					cout << "Typ: ";
					cin >> typCD;
					try {
						verleih.cdAnlegen(titel, interpret, typCD);
					} catch(const char *ex) {
						cout << endl << ex << endl;

					}
					break;
					// ---------------------------------------------

					// -------- cd entfernen -------------------------
				case 2:
					cout << "CD-ID: ";
					cin >> IDcd;
					try {
						verleih.cdEntfernen(IDcd);
					} catch(const char *ex) {
						cout << endl << ex << endl;

					}
					break;
					// ----------------------------------------------


					// --------- CD-Typ ändern -------------------------
				case 3:
					cout << "CD-ID: ";
					cin >> IDcd;
					cout << "CD-Typ: ";
					cin >> typCD;
					try {
						verleih.cdTypSetzen(IDcd, typCD);
					} catch(const char *ex) {
						cout << endl << ex << endl;

					}
					break;
					// -------------------------------------------------


					// -------------- Kunden aufnehmen --------------------
				case 4:
					getline(cin, name);
					cout << "Name: ";
					getline(cin, name);
					cout << "Ort: ";
					getline(cin, ort);
					cout << "Typ: ";
					cin >> typKunde;
					try {
						verleih.kundeAnlegen(name, ort, typKunde);
					} catch(const char *ex) {
						cout << endl << ex << endl;

					}
					break;
					// -----------------------------------------------------


					// ----------- kunden entfernen -----------------------
				case 5:
					cout << "Kunden-ID: ";
					cin >> IDkunde;
					try {
						verleih.kundeEntfernen(IDkunde);
					} catch(const char *ex) {
						cout << endl << ex << endl;

					}
					break;
					// ----------------------------------------------------


					// ------------ kunde ändern ----------------------------
				case 6:
					cout << "Kunden-ID: ";
					cin >> IDkunde;
					cout << "Name: ";
					getline(cin, name);
					cout << "Ort: ";
					getline(cin, ort);
					cout << "Typ: ";
					cin >> typKunde;
					try {
						verleih.kundeBearbeiten(IDkunde, name, ort, typKunde);
					} catch(const char *ex) {
						cout << endl << ex << endl;

					}
					break;
					// -----------------------------------------------------------

				default:
					cout << endl << "Error: invalid input! Please choose again!" << endl;
					break;
				}
			}	while(choiceStammd != 0);
			break;
		// *******************************************************************


		// ----------------- cds verleihen --------------------------------
		case 4:

			cout << "KundenID: ";
			cin >> IDkunde;
			do {
				cout << "CD-ID (0 zum abbrechen): ";
				cin >> IDcd;
				if(IDcd != 0)
					cdIDs.push_back(IDcd);

			} while(IDcd > 0);
			cout << "Datum: ";
			cin >> tag;
			d = DateFormatDE::parse(tag);
			try {
				verleih.cdsVerleihen(IDkunde, cdIDs, *d);
				cout << "CD erfolgreich verliehen!" << endl;
			} catch(const char *ex) {
				cout << ex << endl;
			}

			break;
		// ----------------------------------------------------


		// ---------------- cds zurücknehmen ---------------------
		case 5:
			cdIDs.clear();
			do {
				cout << "CD-ID (0 zum abbrechen): ";
				cin >> IDcd;
				if(IDcd == 0)
					break;
				cdIDs.push_back(IDcd);
			} while(IDcd > 0);
			cout << "Datum: ";
			cin >> tag;
			d = DateFormatDE::parse(tag);
			try {
				cout << "\nzu zahlender Betrag: " << verleih.cdsZuruecknehmen(cdIDs, *d) << " Cent\n";
			} catch(const char *ex) {
				cout << endl << ex << endl;
			}

			break;
		// --------------------------------------------------------------------



		// +++++++++++++++++++++ Suchen ++++++++++++++++++++++++++++++++++++
		case 6:
			do {

			suchenMenue();
			cin >> cSuche;
			switch (cSuche) {

			// ++++++++++++++++++ cd-infos +++++++++++++++++++++++++++++++++++++++++++++++
			case 1:
				do {
					string temp;
					int iTemp;

					suchenCDMenue();
					cin >> cSucheCD;
					switch (cSucheCD) {
					// --------------- titel suchen -----------------------------------
					case 1:
						getline(cin, temp);
						cout << "Titel: ";
						getline(cin, temp);
						try {
							cout << endl << verleih.sucheCDnachTitel(temp) << endl;
						} catch(const char *ex) {
							cout << endl << ex << endl;
						}

						break;
					// ----------------------------------------------------------------

					// ------------------ interpret suchen ----------------------------
					case 2:
						getline(cin, temp);
						cout << "Interpret: ";
						getline(cin, temp);
						try {
							cout << endl << verleih.sucheCDnachInterpret(temp) << endl;
						} catch(const char *ex) {
							cout << endl << ex << endl;
						}

						break;
					// ----------------------------------------------------------------

					// ------------------- id suchen ----------------------------------
					case 3:
						cout << "ID: ";
						cin >> iTemp;
						try {
							cout << endl << verleih.cdInfo(iTemp) << endl;
						} catch(const char *ex) {
							cout << endl << ex << endl;
						}

						break;
					// ----------------------------------------------------------------

					// ------------------- typ suchen ---------------------------------
					case 4:
						cout << "Typ-ID: ";
						cin >> iTemp;
						try {
							cout << endl << verleih.sucheCDnachTyp(iTemp) << endl;
						} catch(const char *ex) {
							cout << endl << ex << endl;
						}

						break;
					// ----------------------------------------------------------------

					case 0:
						break;

					default:
						cout << endl << "Error: invalid input! Please choose again!" << endl;

						break;
					}
				}while(cSucheCD != 0);
				break;
			//********************************************************************************

			// ++++++++++++++++++ kunden-infos +++++++++++++++++++++++++++++++++++++++++++++++
			case 2:
				do {
					string temp;
					int iTemp;

					suchenKundeMenue();
					cin >> cSucheKu;
					switch (cSucheKu) {
					// ----------------- name suchen -------------------------------
					case 1:
						getline(cin, temp);
						cout << "Name: ";
						getline(cin, temp);
						try {
							cout << endl << verleih.sucheKundeNachName(temp) << endl;
						} catch(const char *ex) {
							cout << endl << ex << endl;
						}

						break;
					// -------------------------------------------------------------

					// ---------------------- ort suchen ---------------------------
					case 2:
						getline(cin, temp);
						cout << "Ort: ";
						getline(cin, temp);
						try {
							cout << endl << verleih.sucheKundeNachOrt(temp) << endl;
						} catch(const char *ex) {
							cout << endl << ex << endl;
						}

						break;
					// -------------------------------------------------------------

					// ---------------------- id suchen ----------------------------
					case 3:
						cout << "ID: ";
						cin >> iTemp;
						try {
							cout << endl << verleih.kundeInfo(iTemp) << endl;
						} catch(const char *ex) {
							cout << endl << ex << endl;
						}

						break;
					// -------------------------------------------------------------

					// --------------------- kunden-typ suchen ---------------------
					case 4:
						cout << "Typ-ID: ";
						cin >> iTemp;
						try {
							cout << endl << verleih.sucheKundeNachTyp(iTemp) << endl;
						} catch(const char *ex) {
							cout << endl << ex << endl;
						}

						break;
					// -------------------------------------------------------------

					case 0:
						break;

					default:
						cout << endl << "Error: invalid input! Please choose again!" << endl;

						break;
					}
				}while(cSucheKu != 0);
				break;
			//********************************************************************************

			case 0:
				break;

			default:
				cout << endl << "Error: invalid input! Please choose again!" << endl;

				break;
			}
			}while(cSuche != 0);
			break;
		// *****************************************************************



		// -------------------- kundenliste -----------------------------------
		case 7:
			try {
				cout << "\nKundenliste\nID:Name:Ort:Typ\n---------------------------\n\n" << verleih.kundenliste() << endl;
			} catch(const char *ex) {
				cout << endl << ex << endl;
			}

			break;
		// ----------------------------------------------------------------




		// ---------------- cd-liste --------------------------------------
		case 8:
			try {
				cout << "\nCD-Liste\nID:Titel:Interpret:Typ\n---------------------------\n\n" << verleih.cdliste() << endl;
			} catch(const char *ex) {
				cout << endl << ex << endl;
			}

			break;
		// ----------------------------------------------------------------


		// --------------- ausleihliste --------------------------------------
		case 9:
			try {
				cout << "\nListe der Ausleihen\nCD-Infos;Kunden-Infos;Ausleih-Datum\n----------------------------------\n\n" << verleih.ausleihliste() << endl;
			} catch(const char *ex) {
				cout << endl << ex << endl;
			}

			break;
		// -------------------------------------------------------------------

		case 0: //beenden
			break;

		default:
			break;
		}


	} while(choiceHaupt != 0);

	return 0;
}
