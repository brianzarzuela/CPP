// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : ContactList.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : This program reads, writes, displays, and modifies the
//                 information in a phone's contact list. The information
//                 for each contact consists of four (4) data fields:
//                 - name
//                 - cell number
//                 - email address
//                 - in case of emergency
//                 The contacts are stored in a file named "contacts.txt"
//                 and its contents are stored in a linked-list data structure.
//                 This program utilizes a menu driven user interface.
//
// Last Modified : 19 September 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ContactList.h"

int main()
{
	contact *main_head;

	int position;

	char input;

	main_head = Read();

	// Menu displaying loop
	// In response to an illegal input that is not (R, W, S, I, D, U, T, or Q)
	// an error message is issued and the menu is redisplayed.
	// NOTE: This is an infinite for loop and is only exited when option
	//		 (Q)uit is executed
	for (;;)
	{
		cout << "\nContact List Menu:" << endl;
		cout << left << setw(20) << "  (R)ead File";
		cout << left << setw(20) << "(W)rite File";
		cout << left << setw(20) << "(S)how Contacts";
		cout << left << setw(20) << "(I)nsert Contact" << endl;
		cout << left << setw(20) << "  (D)elete Contact";
		cout << left << setw(20) << "(U)pdate Contact";
		cout << left << setw(20) << "(T)oggle ICE";
		cout << left << setw(20) << "(Q)uit\n" << endl;

		cout << "Option...... : ";
		cin >> input; cin.ignore();

		switch (input)
		{
			case 'R':
			case 'r':
				main_head = Read();
				break;
			case 'W':
			case 'w':
				Write(main_head);
				break;
			case 'S':
			case 's':
				Show(main_head);
				break;
			case 'I':
			case 'i':
				cout << "Insert Contact Info at Position : ";
				cin >> position; cin.ignore();
				main_head = Insert(main_head, position);
				break;
			case 'D':
			case 'd':
				cout << "Delete Contact Info at Position : ";
				cin >> position; cin.ignore();
				main_head = Delete(main_head, position);
				break;
			case 'U':
			case 'u':
				cout << "Update Contact Info at Position : ";
				cin >> position; cin.ignore();
				main_head = Update(main_head, position);
				break;
			case 'T':
			case 't':
				cout << "Toggle Contact ICE flag at Position : ";
				cin >> position; cin.ignore();
				Toggle(main_head, position);
				break;
			case 'Q':
			case 'q':
				cout << "Exiting Program..." << endl;
				exit(2);
				break;
			default:
				cout << "Unable to perform task." << endl
					 << "Please be sure to enter a valid input and try again." << endl;
				break;
		}
	}

	return 0;
}
