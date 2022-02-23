#ifndef  __CALCULATOR__
#define __CALCULATOR__

#include<iostream>
#include<string>
#include<cmath>

#include"TokenHandler.hpp"

using std::string;
using std::cout;
using std::stod;

class Calculator
{
public:

	static double Cal(const string&);

private:

	enum class Operator
	{
		Plus,Minus,Multiply,Divide
	};

	static string GetNextToken(size_t&,const string&);

};

#endif // !_CALCULATOR_H_