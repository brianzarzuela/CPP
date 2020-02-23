// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : ContactList_functions.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : The function file for ContactList.cpp containing all
//                 seven function definitions:
//                 - Read()
//                 - Write()
//                 - Show()
//                 - Insert()
//                 - Delete()
//                 - Update()
//                 - Toggle()
//
// Last Modified : 19 September 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "ContactList.h"

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Read()
//
//		input 		: n/a
//		output		: a pointer to the head of the linked-list
//		description : reads the content of the file "contacts.txt" and
//					  builds the linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
contact *Read()
{
	ifstream inFile;

	inFile.open("contacts.txt");

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit(1);
	}

	contact *current, *head;

	current = new contact;
	head = current;

	do
	{
		getline(inFile, current->name);
		getline(inFile, current->cell_number);
		getline(inFile, current->email_address);
		inFile >> current->ICE;
		inFile.ignore();

		if (inFile.eof())
		{
			current->next_addr = NULL;
			break;
		}
		else
		{
			current->next_addr = new contact;
			current = current->next_addr;
		}
	}
	while (true);

	inFile.close();

	return (head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Show()
//
//		input 		: a pointer to the head of the linked-list
//		output		: void
//		description : displays the context of the contact list to the screen
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Show(contact *head)
{
	int count = 1;

	contact *current = head;

	cout << "Contact List:" << endl;

	while (current != NULL)
	{
		cout << right << setw(4) << count++ << ")  ";
		cout << left << setw(22) << current->name;
		cout << left << setw(15) << current->cell_number;
		cout << left << setw(20) << current->email_address;
		if (current->ICE)
		{
			cout << right << setw(25) << "<--- Emergency Contact";
		}
		cout << endl;
		current = current->next_addr;
	}
	cout << endl;

	return;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Delete()
//
//		input 		: a pointer to the head of the linked-list and the
//                    position in the list where the contact information
//                    should be deleted
//		output		: a pointer to the head of the linked-list
//		description : deletes the information from the linked-list as the
//                    position entered
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
contact *Delete(contact *head, int position)
{
	contact *current, *previous;

	current = head;

	if (position == 1)
	{
		head = current->next_addr;
	}
	else
	{
		for (int i = 1; i  < position; i++)
		{
			previous = current;
			current = current->next_addr;
		}
		previous->next_addr = current->next_addr;
	}
	delete(current);
	return(head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Insert()
//
//		input 		: a pointer to the head of the linked-list and the
//                    position in the list where the contact information
//                    should be inserted
//		output		: a pointer to the head of the linked-list
//		description : prompts the user to enter the contact information and
//                    inserts this information in the linked-list at the
//                    position entered
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
contact *Insert(contact *head, int position)
{
	contact *current, *previous, *temp;

	current = head;

	string name;

	char ice_letter;

	temp = new contact;
	cout << "Contact's Name : ";
	getline(cin, name);
	size_t pos = name.find(" ");
	string first = name.substr(0, pos);
	string last = name.substr(pos+1);
	temp->name = last + ", " + first;
	cout << "Contact's Cell Number : ";
	getline(cin, temp->cell_number);
	cout << "Contact's Email Address : ";
	getline(cin, temp->email_address);
	cout << "Set as Emergency Contact? (Y)es/(N)o : ";
	cin >> ice_letter; cin.ignore();
	temp->ICE = (ice_letter == 'Y' || ice_letter == 'y');

	if (position == 1)
	{
		temp->next_addr = current;
		head = temp;
	}
	else
	{
		for (int i = 1; i < position; i++)
		{
			previous = current;
			current = current->next_addr;
		}
		temp->next_addr = current;
		previous->next_addr = temp;
	}

	return (head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Update()
//
//		input 		: a pointer to the head of the linked-list and the
//                    position in the list where the contact information
//                    should be updated
//		output		: a pointer to the head of the linked-list
//		description : prompts the user to enter the contact information and
//                    updates this information in the linked-list at the
//                    position entered
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
contact *Update(contact *head, int position)
{
	contact *current = head;

	string name;

	char ice_letter;

	for (int i = 1; i < position; i++)
	{
		// previous = current
		current = current->next_addr;
	}

	cout << "Contact's Name : ";
	getline(cin, name);
	size_t pos = name.find(" ");
	string first = name.substr(0, pos);
	string last = name.substr(pos+1);
	current->name = last + ", " + first;
	cout << "Contact's Cell Number : ";
	getline(cin, current->cell_number);
	cout << "Contact's Email Address : ";
	getline(cin, current->email_address);
	cout << "Set as Emergency Contact? (Y)es/(N)o : ";
	cin >> ice_letter; cin.ignore();
	current->ICE = (ice_letter == 'Y' || ice_letter == 'y');

	return (head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Toggle()
//
//		input 		: a pointer to the head of the linked-list and the
//                    position in the list where the ICE flag is to be
//                    toggled
//		output		: void
//		description : toggles (true->false or false->true) the ICE flag at
//                    the position entered
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Toggle(contact *head, int position)
{
	contact *current = head;

	for (int i = 1; i < position; i++)
	{
		// previous = current
		current = current->next_addr;
	}

	current->ICE = !(current->ICE);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Write()
//
//		input 		: a pointer to the head of the linked-list
//		output		: void
//		description : writes the content of the linked-list to the output
//                    file "contacts_updated.txt"
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Write(contact *head)
{
	contact *current = head;

	ofstream outFile;

	outFile.open("contacts_updated.txt");

	while (current != NULL)
	{
		outFile << current->name << endl;
		outFile << current->cell_number << endl;
		outFile << current->email_address << endl;
		outFile << current->ICE << endl;
		current = current->next_addr;
	}

	outFile.close();
}
