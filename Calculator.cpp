#include"Calculator.hpp"

double Calculator::Cal(const string& str)
{
	if (TokenHandler::isDigit(str))//是数字直接返回
	{
		return stod(str);
	}

	double res = 0;

	double tempRes = 0;

	Operator curOperator = Operator::Plus;

	size_t i = 0;

	if (str[0] == '-')
	{
		curOperator = Operator::Minus;
		i++;
	}

	for (; i < str.size(); i++)
	{

		switch (curOperator)
		{
		case Calculator::Operator::Plus:
			cout << "+ ";
			break;
		case Calculator::Operator::Minus:
			cout << "- ";
			break;
		case Calculator::Operator::Multiply:
			cout << "* ";
			break;
		case Calculator::Operator::Divide:
			cout << "/ ";
			break;
		}

		string token = GetNextToken(i, str);

		if (token[0] == '(')
		{
			token = token.substr(1, token.size() - 2);
		}

		cout << token << "\n";

		double calResult = Cal(token);

		switch (curOperator)
		{
		case Calculator::Operator::Plus:
			tempRes += calResult;
			break;
		case Calculator::Operator::Minus:
			tempRes -= calResult;
			break;
		case Calculator::Operator::Multiply:
			tempRes *= calResult;
			break;
		case Calculator::Operator::Divide:
			tempRes /= calResult;
			break;
		}

		if (i == str.size())//运算结束
		{
			res += tempRes;
			return res;
		}

		if (str[i] == '+')
		{
			if (curOperator == Operator::Multiply || curOperator == Operator::Divide)
			{
				res += tempRes;
				tempRes = 0;
			}
			else
			{
				res += tempRes;
				tempRes = 0;
			}
			curOperator = Operator::Plus;
		}
		else if (str[i] == '-')
		{
			if (curOperator == Operator::Multiply || curOperator == Operator::Divide)
			{
				res += tempRes;
				tempRes = 0;
			}
			else
			{
				res += tempRes;
				tempRes = 0;
			}
			curOperator = Operator::Minus;
		}
		else if (str[i] == '*')
		{
			if (curOperator == Operator::Plus)
			{
				tempRes = calResult;
			}
			else if (curOperator == Operator::Minus)
			{
				tempRes = -calResult;
			}
			curOperator = Operator::Multiply;
		}
		else if (str[i] == '/')
		{
			if (curOperator == Operator::Plus)
			{
				tempRes = calResult;
			}
			else if (curOperator == Operator::Minus)
			{
				tempRes = -calResult;
			}
			curOperator = Operator::Divide;
		}

	}

	return res;

}

string Calculator::GetNextToken(size_t& curIndex, const string& str)
{
	size_t i;

	for (i = curIndex; i < str.size(); i++)
	{
		if (TokenHandler::isOperator(str[i]))
		{
			size_t temp = curIndex;
			curIndex = i;
			return str.substr(temp, i - temp);
		}
		else if (TokenHandler::isBracket(str[i]))
		{
			for (int brCount = 1; brCount > 0;)
			{
				i++;
				if (str[i] == '(')
				{
					brCount++;
				}
				else if (str[i] == ')')
				{
					brCount--;
				}
			}
		}
	}

	size_t temp = curIndex;
	curIndex = i;
	return str.substr(temp, i - temp);
}


