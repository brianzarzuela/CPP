// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : LineType.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Class LineType is a user created ADT that represents a
//                 line in the Cartesian plane in the standard form:
//                 ax + by = c
//
// Last Modified : 27 October 2019
//   - added documentation
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef LineType_H_
#define LineType_H_

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;

class LineType
{
	private:
		float a, b, c; // Represents the line's coefficients
	public:
		LineType(float = 1.0, float = 1.0, float = 1.0);
		void setCoefficient(float, float, float);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// displayLine()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : displays a line in its standard form: ax + by = c
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void displayLine();

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// lineSlope()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : calculates and displays the line's slope = -a/b
		//                    horizontal lines have slope of 0
		//                    vertical lines have slope of infinity
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void lineSlope();

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator ==
		//
		//		input 		: LineType object
		//		output		: boolean value
		//		description : overloads the C++ operator == and returns true if
		//                    two lines are equal, determined by:
		//                    a1 = Ka2, b1 = Kb2, c1 = Kc2 where K is a real number
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		bool operator==(LineType);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator ||
		//
		//		input 		: LineType object
		//		output		: boolean value
		//		description : overloads the C++ operator || and returns true if
		//                    two lines are parallel, determined by:
		//                    both lines have the same slope
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		bool operator||(LineType);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// operator &&
		//
		//		input 		: LineType object
		//		output		: boolean value
		//		description : overloads the C++ operator == and returns true if
		//                    two lines are perpendicular, determined by:
		//                    the product of the slopes is -1 or
		//                    either line is horizontal and the other vertical
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		bool operator&&(LineType);

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// lineIntersection()
		//
		//		input 		: LineType object
		//		output		: n/a
		//		description : calculates and displays the point of intersection
		//                    between two lines
		//                    NOTE: should not be applied to parallel lines
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void lineInterestion(LineType);
};

#endif /* LineType_H_ */
