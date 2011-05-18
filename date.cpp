#include "date.h"
#include <iostream>
#include <string>
#include <ctime>
//------------------------------------------------------------------------------------------------
Date::Date(int day, int month, int year, DateFormat *f)
{
	_day = day;
	_month = month;
	_year = year;
	_nf = f;
}
//------------------------------------------------------------------------------------------------
Date::Date(int day, int month, int year)
{
	DateFormat *f;
	f = new DateFormat;

	_day = day;
	_month = month;
	_year = year;
	_nf = f;
}
//------------------------------------------------------------------------------------------------
int Date::getDayInYear()
{
	int tage = 0;
	int monat = _month -1;
	int monate[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if(this->isLeapYear() == true)
		monate[1]++;

	for(int i=0;i<monat;i++)
		tage += monate[i];

	tage += _day;

	return tage;
}
//------------------------------------------------------------------------------------------------
int Date::getDayInWeek()
{
	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime( &rawtime );
	timeinfo->tm_year = _year - 1900;
	timeinfo->tm_mon = _month - 1;
	timeinfo->tm_mday = _day;


	mktime (timeinfo);

	return timeinfo->tm_wday;
}
//------------------------------------------------------------------------------------------------
int Date::getWeekInYear()
{
	int tmp, i=0;
	tmp = this->getDayInYear();
	while(tmp>0)
	{
		tmp = tmp-7;
		i++;
	}
	return i;

}
//------------------------------------------------------------------------------------------------
bool Date::isLeapYear()
{
	if (_year%4==0 && _year%100!=0 || _year%400==0)
	{
		return true;
	} else {
		return false;
	}
}
//------------------------------------------------------------------------------------------------
int Date::diff(Date d)
{
	int alt, neu;
	neu = this->getDayInYear();
	alt = d.getDayInYear();
	if (this->_year == d._year)
		return neu-alt;
	else
	{

		int diff, days=0;
		diff = this->_year-d._year  ;

		for(int i=0; i <= diff-1; i++)
		{
			this->_year += i;
			if(this->isLeapYear())
				if(d._month > 2)
					days++;
			days += 365;
			this->_year -= i;
		}

		if(this->isLeapYear())
		{
			if(this->_month >= 2)
				if(this->_day >= 29)
					days = days + neu - alt -1;
		}
		else days = days + neu - alt;
		return days;
	}

}
//------------------------------------------------------------------------------------------------
string Date::toString()
{
	return _nf->format(this);
}
//------------------------------------------------------------------------------------------------
void Date::setFormat(DateFormat *f)
{
	delete _nf;
	_nf = f;
}
//------------------------------------------------------------------------------------------------

int Date::operator-(Date d)
{
	return diff(d);
}