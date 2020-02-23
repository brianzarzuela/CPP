// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : errorChecking.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Error checking program for managing user inputs
//                 Modified to be used with Submarine Times program
//                 instantiating clock12 and clock18
//
// Last Modified : 3 November 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "errorChecking.h"

void selectTimes(clock18& startTime, clock18& endTime, clock18& watchStart, clock18& watchEnd)
{
	bool flag = true;

	do
	{
		cout << "Enter start time value (hh mm ss) : ";
		cin >> startTime;

		if (cin.fail())
		{
			cin.clear(); cin.ignore(999, '\n');
			cout << "Sorry, please enter a valid time." << endl;
		}
		else
			flag = false;
	} while(flag);

	flag = true;

	do
	{
		cout << "Enter end time value (hh mm ss) : ";
		cin >> endTime;

		if (cin.fail())
		{
			cin.clear(); cin.ignore(999, '\n');
			cout << "Sorry, please enter a valid time." << endl;
		}
		else if (endTime < startTime)
			cout << "Sorry, please enter a value greater than start time." << endl;
		else
			flag = false;

	} while (flag);

	flag = true;

	do
	{
		cout << "Enter watch start time (hh mm ss) : ";
		cin >> watchStart;

		if (cin.fail())
		{
			cin.clear(); cin.ignore(999, '\n');
			cout << "Sorry, please enter a valid time." << endl;
		}
		else if (watchStart < startTime || watchStart > endTime)
			cout << "Sorry, watch start must be between start time and end time." << endl;
		else
			flag = false;

	} while (flag);

	flag = true;

	do
	{
		cout << "Enter watch end value (hh mm ss) : ";
		cin >> watchEnd;

		if (cin.fail())
		{
			cin.clear(); cin.ignore(999, '\n');
			cout << "Sorry, please enter a valid time." << endl;
		}
		else if (watchEnd < watchStart || watchEnd < startTime || watchEnd > endTime)
			cout << "Sorry, watch end must be between start time and end time and must be greater than watch start." << endl;
		else
			flag = false;

	} while (flag);
}

