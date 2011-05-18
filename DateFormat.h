#ifndef _DATEFORMAT_H
#define _DATEFORMAT_H

#include <string>
using namespace std;

class Date;

class DateFormat {
public:
	int getDay(Date *d);
	int getMonth(Date *d); 
	int getYear(Date *d);
    virtual string format(Date *d);
    virtual Date * parse(string s);
};
//------------------------------------------------------------------------------------------------
class DateFormatDE : public DateFormat
{
public:
    string format(Date *d);
    Date * parse(string s);
};
//------------------------------------------------------------------------------------------------
class DateFormatEN : public DateFormat
{
public:
    string format(Date *d);
    Date * parse(string s);
};

#endif

