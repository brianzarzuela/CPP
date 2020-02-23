// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : members.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : The information for each member includes:
//				   - first name
//				   - last name
//				   - amount of credits
//				   - single reservation per trip flag
//				   List of members are populated using read() and can be
//				   populated into a file using write(). A member can be found
//				   from the list using indexOf().
//
// Last Modified : 5 December 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "members.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// read()
//
//		input 		: an array of member instances
//		output		: n/a
//		description : reads the content of the file "seat_credit.txt" and
//					  populates the array
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void read(member members[24])
{
	ifstream inFile;

	inFile.open("seat_credits.txt");

	if (inFile.fail())
	{
		cout << "\nCrew member credit file 'seat_credits.txt' did not successfully open...\nProgram terminated." << endl;
		exit(1);
	}

	int i = 0;
	string firstname, lastname;

	do
	{
		inFile >> members[i].firstname; inFile.ignore();
		inFile >> members[i].lastname; inFile.ignore();
		inFile >> members[i].credits; inFile.ignore();
		members[i].reserved = false;
		i++;

	} while(!inFile.eof());

	inFile.close();
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// write()
//
//		input 		: an array of member instances
//		output		: n/a
//		description : writes the content of the member array into the file
//					  "seat_credits.txt" in the format:
//					  [first name] [last name] [# of credits]
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void write(member members[24])
{
	ofstream outFile;

	outFile.open("seat_credits.txt");

	for (int i = 0; i < 24; i++)
	{
		outFile << members[i].firstname << " "
				<< members[i].lastname << " "
				<< members[i].credits << endl;
	}

	outFile.close();
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// indexOf()
//
//		input 		: an array of member instances and two strings for the
//					  first name and last name of the member to be indexed
//		output		: the location in the array of the member
//		description : traverses the array and if a member is found to have
//					  the same name as the one passed in returns the index
//                    location of the member. if no member matching the name
//					  is found, an index of -1 is returned.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int indexOf(member members[24], string fname, string lname)
{

	for (int i = 0; i < 24; i++)
	{
		if (members[i].firstname == fname && members[i].lastname == lname)
			return i;
	}

	return -1;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// indexOf()
//
//		input 		: an array of member instances and one string for the
//					  full name (first last) of the member to be indexed
//		output		: the location in the array of the member
//		description : traverses the array and if a member is found to have
//					  the same name as the one passed in returns the index
//                    location of the member. if no member matching the name
//					  is found, an index of -1 is returned.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int indexOf(member members[24], string name)
{
	string fullname;

	for (int i = 0; i < 24; i++)
	{
		fullname = members[i].firstname + " " + members[i].lastname;

		if (fullname == name)
			return i;
	}

	return -1;
}
