// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : members.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Header file for members.cpp containing all the
//                 prototypes for the functions in members.cpp
//                 as well as the member data type definition.
//
//				   The information for each member includes:
//				   - first name
//				   - last name
//				   - amount of credits
//				   - single reservation per trip flag
//				  List of members are populated using read() and can be
//				  populated into a file using write(). A member can be found
//				  from the list using indexOf().
//
// Last Modified : 5 December 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef MEMBERS_H_
#define MEMBERS_H_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// member struct tracks:
//	- passanger's name (first and last)
//	- the amount of credits they have
//	- a flag to determine whether or not they have already reserved a seat
struct member
{
	string firstname;
	string lastname;
	int credits;
	bool reserved;
};

void read(member*);

void write(member*);

int indexOf(member*, string, string);

int indexOf(member*, string);

#endif /* MEMBERS_H_ */
