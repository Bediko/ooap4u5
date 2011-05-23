#ifndef _DATEFORMAT_H_
#define _DATEFORMAT_H_

#include <sstream>
using namespace std;

class Date;

class DateFormat {
protected:
	

public:
	virtual string getNameOfDay(int index);
	static Date *parse(string s);
	virtual string format(Date *d);
};




class DateFormatDE : public DateFormat {
protected:
	

public:
	string getNameOfDay(int index);
	string format(Date *d);
	static Date *parse(string s);
};




class DateFormatEN : public DateFormat {
protected:
	

public:
	string getNameOfDay(int index);
	string format(Date *d);
	static Date *parse(string s);
};


#endif