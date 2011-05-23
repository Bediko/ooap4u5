
#include "DateFormat.h"
#include "Date.h"
#include <iomanip>

// ************************************** DateFormat **************************************************************************

string DateFormat::getNameOfDay(int index) {
	string days[7] = {"So", "Mo", "Di", "Mi", "Do", "Fr", "Sa"};

	return days[index];
}

string DateFormat::format(Date *d) {
	ostringstream os;
	
	os << setfill('0') << setw(2) << d->getDay() << "-" << setw(2) << d->getMonth() << "-" << d->getYear();

	return os.str();
}



// ******************************************* DateFormatDE *****************************************************************

string DateFormatDE::getNameOfDay(int index) {
	string days[7] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

	return days[index];
}

string DateFormatDE::format(Date *d) {
	ostringstream os;
	
	os << setfill('0') << setw(2) << d->getDay() << "." << setw(2) << d->getMonth() << "." << d->getYear();

	return os.str();
}

Date *DateFormatDE::parse(string s) {
	istringstream is(s);
	int day, month, year;
	char temp;

	is >> day >> temp >> month >> temp >> year;

	return new Date(day, month, year);
}



// *********************************** DateFormatEN ************************************************************************

string DateFormatEN::getNameOfDay(int index) {
	string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	return days[index];
}

string DateFormatEN::format(Date *d) {
	ostringstream os;
	
	os << setfill('0') << setw(2) << d->getMonth() << "/" << setw(2) << d->getDay() << "/" << d->getYear();

	return os.str();
}

Date *DateFormatEN::parse(string s) {
	istringstream is(s);
	int day, month, year;
	char temp;

	is >> month >> temp >> day >> temp >> year;

	return new Date(day, month, year);
}