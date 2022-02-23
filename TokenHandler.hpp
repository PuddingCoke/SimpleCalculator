#ifndef ___TOKEN__HANDLER__
#define ___TOKEN__HANDLER__

#include<string>

using std::string;

namespace TokenHandler
{
	bool isDigit(const string&);

	bool isOperator(const char&);

	bool isBracket(const char&);
};

#endif // !_TOKEN_HANDLER_H
