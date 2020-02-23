// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : ContactList.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Header file for ContactList.cpp containing all the
//                 prototypes for the functions in ContactList_functions.cpp
//                 as well as the contact struct definition.
//
// Last Modified : 19 September 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef CONTACTLIST_H_
#define CONTACTLIST_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

// Contact struct for storing each contact's four (4) data fields.
// Note: ice stands for In-Case-of-Emergency and is a flag that indicates
//		 that the contact should be called in case of an emergency.
//		 More than one contact can have the ICE flag.
struct contact
{
	string name;
	string cell_number;
	string email_address;
	bool ICE;
	contact *next_addr;
};

contact *Read();

void Show(contact *head);

contact *Delete(contact *head, int position);

contact *Insert(contact *head, int position);

contact *Update(contact *head, int position);

void Toggle(contact *head, int position);

void Write(contact *head);

#endif /* CONTACTLIST_H_ */
