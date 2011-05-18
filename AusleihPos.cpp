#include "AusleihPos.h"
#include <sstream>

Date* AusleihPos::getDate()
{
    return _tagDerAusleihe;
}

AusleihPos AusleihPos::parse(string a)
{

}
string AusleihPos::toString()
{
	ostringstream os;
	os << _tagDerAusleihe->toString()<<" "<<endl;//kunde.toString()<<endl;
	return os.str();
}
AusleihPos::AusleihPos(Kunde *kunde,CD *cd,Date *tagderAusleihe)
{
    _kunde=kunde;
    _tagDerAusleihe=tagderAusleihe;
    _cd=cd;
}
AusleihPos::~AusleihPos()
{
}
/*AusleihPos::AusleihPos(const CD& rhs)
{
}
AusleihPos AusleihPos::operator=(CD)
{
}
AusleihPos AusleihPos::operator==(CD)
{
}
AusleihPos AusleihPos::operator<(CD)
{
}*/
