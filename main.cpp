#include<iostream>
#include<vector>

#include"Calculator.hpp"

using namespace std;

int main(int argc,const char* argv[])
{

	string str;

	cout << ">>> ";

	if (argc < 2)
	{
		cin >> str;
	}
	else
	{
		str = argv[1];
		cout << str << "\n";
	}

	cout << ">>> " << Calculator::Cal(str) << "\n";

	return 0;

}