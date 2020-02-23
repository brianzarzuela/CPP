// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : errorChecking.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Error checking program for managing user inputs
//                 Modified to be used with programs instantiating LineType
//
// Last Modified : 27 October 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef ERRORCHECKING_H_
#define ERRORCHECKING_H_

#include "LineType.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// selectCoefficients()
//
//		input 		: three coefficients (a, b, and c) passed by reference
//		output		: n/a
//		description : updates each of the values of the variables a, b, c
//                    with a value entered by the user individually.
//                    re-prompts user if a value entered is incorrect.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void selectCoefficients(float&, float&, float&);

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// selectLine()
//
//		input 		: n/a
//		output		: pointer to a LineType object
//		description : prompts for to enter a line w, x, y, or z. pointer to
//                    the address of the line chosen is returned.
//                    re-prompts if user enters an invalid line.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LineType* selectLine();

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// selectLine()
//
//		input 		: line character passed by reference
//		output		: pointer to a LineType object
//		description : overloaded function of selectLine() that also updates
//                    the line character to know which line the user selects
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
LineType* selectLine(char&);

#endif /* ERRORCHECKING_H_ */
