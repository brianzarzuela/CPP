// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : errorChecking.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Error checking program for managing user inputs
//                 Modified to be used with programs instantiating LineType
//
// Last Modified : 27 October 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "errorChecking.h"

LineType W, X, Y, Z;

void selectCoefficients(float &a, float &b, float &c)
{
	bool flag;

	do
	{
		cout << "a = ";
		cin >> a;
		if (cin.fail())
		{
			cin.clear(); cin.ignore(999, '\n'); flag = true;
			cout << "Sorry, that was not a valid number. Try again." << endl;
		}
		else
			flag = false;
	} while(flag);

	do
	{
		cout << "b = ";
		cin >> b;
		if (cin.fail())
		{
			cin.clear(); cin.ignore(999, '\n'); flag = true;
			cout << "Sorry, that was not a valid number. Try again." << endl;
		}
		else
			flag = false;
	} while(flag);

	do
	{
		cout << "c = ";
		cin >> c;
		if (cin.fail())
		{
			cin.clear(); cin.ignore(999, '\n'); flag = true;
			cout << "Sorry, that was not a valid number. Try again." << endl;
		}
		else
			flag = false;
	} while(flag);
}

LineType* selectLine(char &ltr)
{
	LineType *ptr;
	char line;
	bool flag;

	do
	{
		cout << "Choose a line W, X, Y, or Z : ";
		cin >> line; cin.ignore();
		if (toupper(line) == 'W')
		{
			ptr = &W;
			ltr = 'W';
			flag = false;
		}
		else if (toupper(line) == 'X')
		{
			ptr = &X;
			ltr = 'X';
			flag = false;
		}
		else if (toupper(line) == 'Y')
		{
			ptr = &Y;
			ltr = 'Y';
			flag = false;
		}
		else if (toupper(line) == 'Z')
		{
			ptr = &Z;
			ltr = 'Z';
			flag = false;
		}
		else
		{
			cout << "Sorry, the option you entered was invalid." << endl;
			flag = true;
		}
	} while (flag);

	return ptr;
}

LineType* selectLine()
{
	LineType *ptr;
	char line;
	bool flag;

	do
	{
		cout << "Choose a line W, X, Y, or Z : ";
		cin >> line; cin.ignore();
		if (toupper(line) == 'W')
		{
			ptr = &W;
			flag = false;
		}
		else if (toupper(line) == 'X')
		{
			ptr = &X;
			flag = false;
		}
		else if (toupper(line) == 'Y')
		{
			ptr = &Y;
			flag = false;
		}
		else if (toupper(line) == 'Z')
		{
			ptr = &Z;
			flag = false;
		}
		else
		{
			cout << "Sorry, the option you entered was invalid." << endl;
			flag = true;
		}
	} while (flag);

	return ptr;
}


