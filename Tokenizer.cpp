

#include "Tokenizer.h"


Tokenizer::Tokenizer(string str, char tok) {
	size_t iter;
	
	_str = str;
	_token = tok;
	_beg = 0;
	_end = _str.find_first_of(_token);
	_count = 0;

	for (iter = _beg; iter != _str.npos; _count++)
		iter = _str.find_first_of(_token, iter + 1);
}


string Tokenizer::getSubstr() {
	string out;

	if (_count != 0) {
		out = _str.substr(_beg, _end - _beg);
		_beg = _str.find_first_not_of(_token, _end);
		_end = _str.find_first_of(_token, _beg);
		_count--;
	}
	else
		throw "ERROR: no more tokens";

	return out;
}

int Tokenizer::getNumberOfSubstrLeft() {
	return _count;
}

bool Tokenizer::hasMoreSubstr() {
	return (_count > 0);
}