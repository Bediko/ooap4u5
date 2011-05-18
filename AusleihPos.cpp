#include "AusleihPos.h"
#include <sstream>
AusleihPos AusleihPos::parse(string a)
{

}
string AusleihPos::toString()
{
	ostringstream os;
	os << tagDerAusleihe->toString()<<" "<<endl;//kunde.toString()<<endl;
	return os.str();
}
AusleihPos::AusleihPos()
{
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
