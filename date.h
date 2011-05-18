#ifndef _DATE_H
#define _DATE_H

#include "DateFormat.h"
#include <string>

using namespace std;

class Date
{
friend class DateFormat;

protected:
	int _day, _month, _year;
	DateFormat *_nf;

public:
	Date(){};
	Date(int day, int month, int year);
	Date(int day, int month, int year, DateFormat *f);
	int getDayInYear();
	int getDayInWeek();
	int getWeekInYear();
	bool isLeapYear();
	int diff(Date d);
	int operator-(const Date& d);
	string toString();
	void setFormat(DateFormat *f);
};

#endif
