// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : clock12.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Implementation of class clock12
//                 See clock12.h for class description
//
// Last Modified : 1 November 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "clock12.h"

clock12::clock12(int hours, int minutes, int seconds, char meridiem)
{
	this->hours = hours % 12;
	this->minutes = minutes;
	this->seconds = seconds;
	this->meridiem = toupper(meridiem);
}

void clock12::setTime(int hours, int minutes, int seconds, char meridiem)
{
	this->hours = hours % 12;
	this->minutes = minutes;
	this->seconds = seconds;
	this->meridiem = toupper(meridiem);
}

clock12::operator clock18()
{
	clock18 clock;

	if (meridiem == 'A')
		return ( clock18(hours, minutes, seconds) );
	else
	{
		if (hours < 6)
			return ( clock18(hours + 12, minutes, seconds) );
		else
			return ( clock18(hours - 18, minutes, seconds) );
	}

}

ostream& operator<<(ostream& out, const clock12& clock)
{
	if (clock.hours < 10)
		cout << "0";
	cout << clock.hours << ":";

	if (clock.minutes < 10)
		cout << "0";
	cout << clock.minutes << ":";

	if (clock.seconds < 10)
		cout << "0";
	cout << clock.seconds;

	if (clock.meridiem == 'A')
		cout << " AM";
	else
		cout << " PM";

	return out;
}

istream& operator>>(istream& in, clock12& clock)
{
	cin >> clock.hours;
	cin >> clock.minutes;
	cin >> clock.seconds;
	cin >> clock.meridiem;
	return in;
}
