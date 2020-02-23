// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : clock18.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   :
//
// Last Modified : 1 November 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef CLOCK18_H_
#define CLOCK18_H_

#include "clock12.h"
class clock12;

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class clock18
{
	private:
		int hours, minutes, seconds;

	public:
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// clock18()
		//
		//		input 		: three integer values representing hours, minutes, and
		//                    seconds respectively
		//		output		: n/a
		//		description : default construction function with default values 0
		//                    for the three data members
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		clock18(int = 0, int = 0, int = 0);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// clock18(long)
		//
		//		input 		: long integer value for time in seconds
		//		output		: n/a
		//		description : construction function that converts a long integer
		//                    equal to time in seconds to a clock18 object
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		clock18(long);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// setTime()
		//
		//		input 		: three integer values representing hours, minutes, and
		//                    seconds respectively
		//		output		: n/a
		//		description : member function that allows the clock's three data
		//                    members (hours, minutes, seconds) to be set
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void setTime(int, int, int);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (<<)
		//
		//		input 		: ostream object and clock18 object passed by reference
		//		output		: ostream object passed by reference
		//		description : overloaded operator function for the extract operator
		//                    (<<) for the ostream that allows the clock value to be
		//                    written directly using the cout operation in this format:
		//                    hh : mm :: ss
		//                    Where hh is hours, mm is minutes, and ss is seconds
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend ostream& operator<<(ostream&, const clock18&);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (>>)
		//
		//		input 		: istream object and clock18 object passed by reference
		//		output		: istream object passed by reference
		//		description : overloaded operator function for the insertion operator
		//                    (<<) for the istream that allows the clock value to be
		//                    read directly using the cin operation in this format:
		//                    hh mm ss
		//                    Where hh is hours, mm is minutes, and ss is seconds
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend istream& operator>>(istream&, clock18&);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (++) prefix
		//
		//		input 		: n/a
		//		output		: clock18 object passed by reference
		//		description : overloaded prefix increment operator (++) that
		//                    increments the time by one second (++clock18)
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		clock18& operator++();

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (++) postfix
		//
		//		input 		: int for invoking the this function instead of prefix
		//		output		: clock18 object passed by reference
		//		description : overloaded postfix increment operator (++) that
		//                    increments the time by one second (clock18++)
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		clock18& operator++(int);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (==)
		//
		//		input 		: clock18 object
		//		output		: boolean, true or false
		//		description : overloaded equality operator (==) that returns true
		//                    if two clock18 values are equal, otherwise false
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		bool operator==(clock18);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (<)
		//
		//		input 		: clock18 object
		//		output		: boolean, true or false
		//		description : overloaded less-than operator (<) that returns true
		//                    if this clock18 value is less than the second value,
		//                    otherwise false
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		bool operator< (clock18);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (>)
		//
		//		input 		: clock18 object
		//		output		: boolean, true or false
		//		description : overloaded greater-than operator (>) that returns true
		//                    if this clock18 value is greater than the second value,
		//                    otherwise false
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		bool operator> (clock18);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (long)
		//
		//		input 		: n/a
		//		output		: long
		//		description : overloaded conversion operator that converts a clock18
		//                    object to a long integer equivalent in seconds
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		operator long();

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (clock12)
		//
		//		input 		: n/a
		//		output		: clock12
		//		description : overloaded conversion operator that converts a clock18
		//                    object to a clock12 (12-hour clock) object
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		operator clock12();
};

#endif /* CLOCK18_H_ */
