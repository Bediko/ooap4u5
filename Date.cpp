

#include "Date.h"
#include <sstream>
#include <ctime>
using namespace std;

Date::Date(int d, int m, int y) {

		_day = d;
		_month = m;
		_year = y;

		_df = new DateFormatDE;
}


void Date::setDateFormat(DateFormat *f) {
	_df = f;
}

bool Date::operator==(const Date& d) {
	return ((this->_day == d._day) && (this->_month == d._month) && (this->_year == d._year));
}


int Date::operator-(const Date& d) {
	time_t currSeconds, firstDate, secondDate;
	double diffInSeconds;
	struct tm *timeData;

	time(&currSeconds);

	timeData = localtime(&currSeconds);
	timeData->tm_year = _year - 1900;
	timeData->tm_mon = _month - 1;
	timeData->tm_mday = _day;
	firstDate = mktime(timeData);

	timeData = localtime(&currSeconds);
	timeData->tm_year = d._year - 1900;
	timeData->tm_mon = d._month - 1;
	timeData->tm_mday = d._day;
	secondDate = mktime(timeData);

	diffInSeconds = difftime(firstDate, secondDate);

	return (diffInSeconds / (3600 * 24));
}

int Date::getDayInYear() {

	time_t currSeconds;
	struct tm *timeData;

	time(&currSeconds);

	timeData = localtime(&currSeconds);
	timeData->tm_year = _year - 1900;
	timeData->tm_mon = _month - 1;
	timeData->tm_mday = _day;

	mktime(timeData);

	return timeData->tm_yday + 1;
}

int Date::getDayInWeek() {
	
	time_t currSeconds;
	struct tm *timeData;

	time(&currSeconds);

	timeData = localtime(&currSeconds);
	timeData->tm_year = _year - 1900;
	timeData->tm_mon = _month - 1;
	timeData->tm_mday = _day;

	mktime(timeData);

	return timeData->tm_wday;
}



int Date::getWeekInYear() {
	
	time_t currSeconds;
	struct tm *timeData;
	int dayInWeek, diffToThursday, firstThursday;

	time(&currSeconds);

	timeData = localtime(&currSeconds);
	timeData->tm_year = _year - 1900;
	timeData->tm_mon = _month - 1;
	timeData->tm_mday = _day;

	mktime(timeData);

	//Wochentag bestimmen
	dayInWeek = timeData->tm_wday;
	
	//Differenz zum Donnerstag in der gleichen Woche bestimmen
	if (dayInWeek == 0) {
		diffToThursday = -3;
	}
	else if (dayInWeek >= 4) {
		diffToThursday = 4 - dayInWeek;
	}
	else if (dayInWeek < 4) {
		diffToThursday = 4 - dayInWeek;
	}


	//Datum des ersten Donerstags im Januar des übergebenen Jahres bestimmen
	firstThursday = (timeData->tm_yday + 1 + diffToThursday) % 7;

	if (firstThursday <= 0)
		return (timeData->tm_yday + 1 + diffToThursday) / 7;
	else
		return ((timeData->tm_yday + 1 + diffToThursday) / 7) + 1;
}

bool Date::isLeapYear() {
	if (_year % 400 == 0)
		return true;
	else if (_year % 100 == 0)
		return false;
	else if (_year % 4 == 0)
		return true;
	else
		return false;
}

int Date::diff(Date d) {
	int diff;

	diff = *this - d;
	
	if (diff < 0)
		return -diff;
	else
		return diff;

}

string Date::toString() {
	return _df->format(this);
}

int Date::getDay() {
	return _day;
}

int Date::getMonth() {
	return _month;
}

int Date::getYear() {
	return _year;
}

string Date::getNameOfDay(int day) {
	return _df->getNameOfDay(day);
}