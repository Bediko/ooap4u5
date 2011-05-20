#include"Verleih.h"
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

void Verleih::lesenAusDatei(string name)
{
    ifstream file;
    file.open(name.c_str());
    CD *cd,*cd2;
    Kunde kunde,*kunde2;
    AusleihPos *apos;
    ostringstream os;
    if(name=="cds.txt")
    {
        while(!file.eof())
        {
            os<<file;
            cd=cd->parse(os.str());
            _cds.insert(cd->ident(),cd);
        }
    }
}
void schreibenInDatei(string name);
int kundenAnlegen(string name, string ort, int typ);
void kundenEntfernen(int id);
void kundeBearbeiten(int id, string name, string ort, int typ);
Kunde * getKunde(int id);
string kundeInfo();
int cdAnlegen(string titel, string interpret, int typ);
void cdEntfernen(int id);
void cdTypSetzen(int id, int typ);
void cdsVerleihen(int kundeID, list<int> cdIDs,Date tag);
int cdsZuruecknehmen(list<int> ids, Date tag);
CD * getCD(int id);
string cdInfo();
string kundenliste();
string cdliste();
string ausleihliste();
