#ifndef _DATE_H_
#define _DATE_H_


#include "DateFormat.h"
#include <sstream>
using namespace std;

class Date {

protected:
	int _day, _month, _year;
	DateFormat *_df;

public:
	
	Date(int d = 0, int m = 0, int y = 0);

	int getDayInYear();
	int getDayInWeek();
	int getWeekInYear();
	bool isLeapYear();
	int diff(Date d);
	string toString();

	int getDay();
	int getMonth();
	int getYear();
	string getNameOfDay(int day);

	void setDateFormat(DateFormat *f);

	int operator-(const Date& d);
	bool operator==(const Date& d);
};


#endif