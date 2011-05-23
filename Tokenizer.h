#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <string>
using namespace std;

class Tokenizer {

private:
	size_t _beg, _end;
	char _token;
	string _str;
	int _count;

public:
	Tokenizer(string str, char tok);

	string getSubstr();
	int getNumberOfSubstrLeft();
	bool hasMoreSubstr();

};

#endif