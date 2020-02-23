// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : LineType.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Main file instantiating objects of class LineType
//                 See LineType.h for class description
//
// Last Modified : 27 October 2019
//   - added error checking
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "errorChecking.h"

int main(void)
{
	char option;
	char line1, line2;
	LineType *ptr1, *ptr2;
	float a, b, c;

	for(;;) // Creates endless loop for displaying menu
	{
		cout << "\nMain Menu \nDirections: Choose a numerical option from the following." << endl;
		cout << " (1) Set \n (2) Display \n (3) Slope \n (4) Equal \n (5) Parallel \n (6) Perpendicular \n (7) Intersection \nEnter Q to Quit" << endl;
		cout << "Option : ";
		cin >> option; cin.ignore();

		switch(option)
		{
			case '1' :
				cout << "Which line would you like to set?" << endl;
				ptr1 = selectLine();
				cout << "What would you like to set your coefficients to?" << endl;
				selectCoefficients(a, b, c);
				(*ptr1).setCoefficient(a, b, c);
				break;

			case '2' :
				cout << "Which line would you like to display?" << endl;
				ptr1 = selectLine();
				(*ptr1).displayLine();
				break;

			case '3' :
				cout << "Which line would you like to calculate the slope of?" << endl;
				ptr1 = selectLine();
				(*ptr1).lineSlope();
				break;

			case '4' :
				cout << "Selecting your first line" << endl;
				ptr1 = selectLine(line1);
				cout << "Selecting your second line" << endl;
				ptr2 = selectLine(line2);
				if ((*ptr1) == (*ptr2))
					cout << line1 << " and " << line2 << " are EQUAL" << endl;
				else
					cout << line1 << " and " << line2 << " are NOT EQUAL" << endl;
				break;

			case '5':
				cout << "Selecting your first line" << endl;
				ptr1 = selectLine(line1);
				cout << "Selecting your second line" << endl;
				ptr2 = selectLine(line2);
				if ((*ptr1) || (*ptr2))
					cout << line1 << " and " << line2 << " are PARALLEL" << endl;
				else
					cout << line1 << " and " << line2 << " are NOT PARALLEL" << endl;
				break;

			case '6':
				cout << "Selecting your first line" << endl;
				ptr1 = selectLine(line1);
				cout << "Selecting your second line" << endl;
				ptr2 = selectLine(line2);
				if ((*ptr1) && (*ptr2))
					cout << line1 << " and " << line2 << " are PERPINDICULAR" << endl;
				else
					cout << line1 << " and " << line2 << " are NOT PERPINDICULAR" << endl;
				break;

			case '7':
				cout << "Selecting your first line" << endl;
				ptr1 = selectLine(line1);
				cout << "Selecting your second line" << endl;
				ptr2 = selectLine(line2);
				if ((*ptr1) || (*ptr2))
					cout << line1 << " and " << line2 << " are PARALLEL\nNo intersection exists" << endl;
				else
					(*ptr1).lineInterestion((*ptr2));
				break;

			case 'Q' :
			case 'q' :
				cout << "Goodbye!" << endl;
				exit(1);  // Terminates program
				break;

			default :
				cout << "Sorry, but that option was invalid.\nPlease enter an option from the menu (1 - 7) or Q to Quit" << endl;
				break;
		}
	}

	return 0;
}
