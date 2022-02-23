#include"TokenHandler.hpp"

bool TokenHandler::isDigit(const string& str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
		{
			return false;
		}
	}
	return true;
}

bool TokenHandler::isOperator(const char& ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return true;
	return false;
}

bool TokenHandler::isBracket(const char& ch)
{
	if (ch == '(' || ch == ')')
		return true;
	return false;
}
