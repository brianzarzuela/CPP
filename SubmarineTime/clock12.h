// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : clock12.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   :
//
// Last Modified : 1 November 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef CLOCK12_H_
#define CLOCK12_H_

#include "clock18.h"
class clock18;

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class clock12
{
	private:
		int hours, minutes, seconds;
		char meridiem;	// Accepts 'A' for AM and 'P' for PM

	public:
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// clock12()
		//
		//		input 		: three integer values representing hours, minutes, and
		//                    seconds respectively
		//		output		: n/a
		//		description : default construction function with default values 0
		//                    for the three data members
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		clock12(int = 0, int = 0, int = 0, char = 'A');

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// setTime()
		//
		//		input 		: three integer values representing hours, minutes, and
		//                    seconds respectively
		//		output		: n/a
		//		description : member function that allows the clock's three data
		//                    members (hours, minutes, seconds) to be set
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void setTime(int, int, int, char);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (<<)
		//
		//		input 		: ostream object and clock12 object passed by reference
		//		output		: ostream object passed by reference
		//		description : overloaded operator function for the extract operator
		//                    (<<) for the ostream that allows the clock value to be
		//                    written directly using the cout operation in this format:
		//                    hh : mm : ss
		//                    Where hh is hourss, mm is minutess, and ss is secondss
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend ostream& operator<<(ostream&, const clock12&);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (>>)
		//
		//		input 		: istream object and clock12 object passed by reference
		//		output		: istream object passed by reference
		//		description : overloaded operator function for the insertion operator
		//                    (<<) for the istream that allows the clock value to be
		//                    read directly using the cin operation in this format:
		//                    hh mm ss
		//                    Where hh is hourss, mm is minutess, and ss is secondss
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend istream& operator>>(istream&, clock12&);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator (clock18)
		//
		//		input 		: n/a
		//		output		: clock18
		//		description : overloaded conversion operator that converts a clock12
		//                    object to a clock18 (18-hour clock) object
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		operator clock18();
};

#endif /* CLOCK12_H_ */
