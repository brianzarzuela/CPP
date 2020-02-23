// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : errorChecking.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Error checking program for managing user inputs
//                 Modified to be used with Submarine Times program
//                 instantiating clock12 and clock18
//
// Last Modified : 3 November 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef ERRORCHECKING_H_
#define ERRORCHECKING_H_

#include "clock18.h"
#include "clock12.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// selectTimes()
//
//		input 		: four clock18 objects passed by reference representing
//                    start time, end time, watch start time, and watch end
//                    time respectively
//		output		: n/a
//		description : updates each of the times with a value read by the
//                    user through the insertion operator (>>)
//                    re-prompts user if a value entered is incorrect.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void selectTimes(clock18&, clock18&, clock18&, clock18&);

#endif /* ERRORCHECKING_H_ */
