// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : main.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Main file instantiating objects of class clock12 and
//                 clock18 to implement an 18-hour work day clock, as used
//                 by the US Navy submarines prior to 2016, with conversion
//                 to the 12-hour meridiem clock
//                 See clock12.h and clock18 for class descriptions
//
// Last Modified : 3 November 2019
//  - added error checking
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "errorChecking.h"

int main(void)
{
	clock18 startTime, endTime, watchStart, watchEnd;
	clock12 watchStart_12, watchEnd_12;

	selectTimes(startTime, endTime, watchStart, watchEnd);

	cout << endl;

	// Time elapse loop at one second increments
	while (startTime < endTime)
	{
		cout << startTime << " ";

		if (startTime < watchStart)
			cout << "Sleeping" << endl;
		else if (startTime >= watchStart && startTime <= watchEnd)
			cout << "On Watch" << endl;
		else
			cout << "Off-Duty" << endl;

		startTime++;
	}

	cout << endl;

	watchStart_12 = watchStart;
	watchEnd_12 = watchEnd;

	// Print summary report containing the following information:
	// - watch start time in 18-hour and 12-hour format
	// - watch end time in 18-hour and 12-hour format
	// - total watch time in hh:mm:ss
	cout << "Watch Start " << watchStart << " or " << watchStart_12 << endl;
	cout << "Watch End   " << watchEnd << " or " << watchEnd_12 << endl;
	cout << "Total watch time : " << clock18(watchEnd - watchStart) << endl;

	return 0;
}
