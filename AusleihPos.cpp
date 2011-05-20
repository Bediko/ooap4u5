#include "AusleihPos.h"
#include <sstream>
#include "tokenizer.h"

Date* AusleihPos::getDate()
{
    return _tagDerAusleihe;
}

AusleihPos * AusleihPos::parse(string a)
{

    Date * tagDerAusleihe;
    CD *cd;
    Kunde *kunde;
    tagDerAusleihe=new Date(0,0,0);
    tagDerAusleihe->setFormat(new DateFormatDE());
    Tokenizer tok(a,":,\n");
    tagDerAusleihe=tagDerAusleihe->parse(tok.nextToken());
    kunde=kunde->parse(tok.nextToken());
    cd=cd->parse(tok.nextToken());
    return new AusleihPos(kunde,cd,tagDerAusleihe);

}
string AusleihPos::toString()
{
	ostringstream os;
	os << _tagDerAusleihe->toString()<<":"<<_kunde->toString()<<":"<<_cd->toString()<<endl;
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
