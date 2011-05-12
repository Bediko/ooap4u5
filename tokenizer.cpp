#include "tokenizer.h"
using namespace std;

Tokenizer::Tokenizer(string data, string sep) {
	_pos = 0;
	string::size_type beg, end;

	beg = data.find_first_not_of(sep, 0);
	end = data.find_first_of(sep, beg);
	while (string::npos != beg || string::npos != end) {
		string s = data.substr(beg, end - beg);

		_tokens.append(s);
		beg = data.find_first_not_of(sep, end);
		end = data.find_first_of(sep, beg);
	}
}



string Tokenizer::nextToken() {
	return _tokens.getValueAt(_pos++);
}



