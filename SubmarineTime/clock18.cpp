// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : clock18.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Implementation of class clock18
//                 See clock18.h for class description
//
// Last Modified : 1 November 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "clock18.h"

clock18::clock18(int hours, int minutes, int seconds)
{
	this->hours = hours % 18;
	this->minutes = minutes;
	this->seconds = seconds;
}

clock18::clock18(long time)
{
	hours = (time / 3600) % 18;
	minutes = (time % 3600) / 60;
	seconds = time % 60;
}

void clock18::setTime(int hours, int minutes, int seconds)
{
	this->hours = hours % 18;
	this->minutes = minutes;
	this->seconds = seconds;
}

ostream& operator<<(ostream& out, const clock18& clock)
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

	return out;
}

istream& operator>>(istream& in, clock18& clock)
{
	cin >> clock.hours;
	cin >> clock.minutes;
	cin >> clock.seconds;
	return in;
}

// Prefix increment operator
clock18& clock18::operator++()
{
	seconds++;

	if(seconds >= 60)
	{
		minutes += seconds / 60;
		seconds %= 60;

		if(minutes >= 60)
		{
			hours += minutes / 60;
			minutes %= 60;

			if(hours >= 18)
			{
				hours = 0;
			}
		}
	}

	return *this;
}

// Postfix increment operator
clock18& clock18::operator ++(int)
{
	++*this;

	if(seconds >= 60)
	{
		minutes += seconds / 60;
		seconds %= 60;

		if(minutes >= 60)
		{
			hours += minutes / 60;
			minutes %= 60;

			if(hours >= 18)
			{
				hours = 0;
			}
		}
	}

	return *this;
}

clock18::operator clock12()
{
	clock12 clock;

	if (hours < 12)
		return ( clock12(hours, minutes, seconds, 'A') );
	else
		return ( clock12(hours - 6, minutes, seconds, 'P') );
}

bool clock18::operator ==(clock18 clock)
{
	if ( (long)*this == (long)clock )
		return true;
	else
		return false;
}

bool clock18::operator <(clock18 clock)
{
	if ( (long)*this < (long)clock )
		return true;
	else
		return false;
}

bool clock18::operator >(clock18 clock)
{
	if ( (long)*this > (long)clock )
		return true;
	else
		return false;
}

clock18::operator long()
{
	long time;
	time = (hours * 3600) + (minutes * 60) + seconds;
	return time;
}
