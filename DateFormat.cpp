#include <string>
#include "date.h"
#include "DateFormat.h"
#include <sstream>
#include <iostream>

using namespace std;

	int DateFormat::getDay(Date *d) {
		return d->_day;
	}
	int DateFormat::getMonth(Date *d) {
		return d->_month;
	}
	int DateFormat::getYear(Date *d) {
		return d->_year;
	}


string DateFormat::format(Date *d)
{
	ostringstream os;
	int day, month, year;
	day = this->getDay(d);
	month =  this->getMonth(d) ;
	year = this->getYear(d);
	os << day << "." << month << "." << year ;
	return os.str();
}
//------------------------------------------------------------------------------------------------
Date * DateFormat::parse(string s)
{
	Date *tmp;
	string temp;
	stringstream ss;
	string::size_type beg, end;
	int dmy[3], i=0;



	beg = s.find_first_not_of(".",0);
	end = s.find_first_of(".", beg);

	while(string::npos != beg || string::npos != end)
	{

		temp = s.substr(beg, end - beg);
        stringstream ss(temp);
        ss>>dmy[i] ;
		beg = s.find_first_not_of(".", end);
		end = s.find_first_of(".", beg);
		i++;

	}

	tmp = new Date(dmy[0],dmy[1],dmy[2]);
	tmp->setFormat(this);
	return tmp;
}
//*************************************************************************************************
string DateFormatDE::format(Date *d)
{
	ostringstream os;
	os << this->getDay(d) << "." << this->getMonth(d) <<"." << this->getYear(d);
	return os.str();
}
//------------------------------------------------------------------------------------------------
Date * DateFormatDE::parse(string s)
{
	Date *tmp;
	string temp;
	string::size_type beg, end;
	int dmy[3], i=0;

	tmp = new Date(0,0,0);
	tmp->setFormat(this);

	beg = s.find_first_not_of(".",0);
	end = s.find_first_of(".", beg);

	while(string::npos != beg || string::npos != end)
	{

		temp = s.substr(beg, end - beg);
		stringstream ss(temp);
        ss>>dmy[i] ;
		beg = s.find_first_not_of(".", end);
		end = s.find_first_of(".", beg);
		i++;

	}

	tmp = new Date(dmy[0],dmy[1],dmy[2]);
	tmp->setFormat(this);
	return tmp;
}

//*************************************************************************************************
string DateFormatEN::format(Date *d)
{
	ostringstream os;
	os << this->getMonth(d) << "/" << this->getDay(d) <<"/" << this->getYear(d);
	return os.str();
}
//------------------------------------------------------------------------------------------------
Date * DateFormatEN::parse(string s)
{
	Date *tmp;
	string temp;
	string::size_type beg, end;
	int dmy[3], i=0;

	tmp = new Date(0,0,0);
	tmp->setFormat(this);

	beg = s.find_first_not_of("/",0);
	end = s.find_first_of("/", beg);

	while(string::npos != beg || string::npos != end)
	{

		temp = s.substr(beg, end - beg);
		stringstream ss(temp);
        ss>>dmy[i] ;
		beg = s.find_first_not_of("/", end);
		end = s.find_first_of("/", beg);
		i++;

	}

	tmp = new Date(dmy[0],dmy[1],dmy[2]);
	tmp->setFormat(this);
	return tmp;
}
