#include <string>
#include "liste.h"
using namespace std;

class Tokenizer {
private :
	unsigned int _pos;
	Liste<string> _tokens;

public :
	Tokenizer(string data, string separators);
	int countTokens();
	string nextToken();
	bool hasMoreTokens();
};
