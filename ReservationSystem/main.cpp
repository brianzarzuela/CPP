// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : main.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Implementation of a car-pool reservation system for the
//				   RIT Rowing Team. Of the 33 members, 9 are drivers and
//				   represented as instances of their vehicles which are of
//				   user-defined type Pickup, Compact, or Sedan. All 9 cars
//				   are stored in three separate arrays by type. The remaining
//                 24 members are provided in the file 'seat_credits.txt'
//				   along with the credits they have available for placing a
//				   reservation.
//
//				   Design constraints:
//				   - Reservations can be made by selecting a seat
//				   - Seats are assigned the following credit values:
//						- (5) for frontseats
//						- (3) for backseats in compacts
//						- (2) for backseats in sedans
//						- (1) for middleseats
//				  - Seat availability for all vehicles can be displayed
//				  - Reservations can be modified or deleted
//				  - A list of passengers for a specific car may be printed
//				  - A manifest of all reservations for all vehicles may be
//					printed but requires the administrator password
//
// Last Modified : 5 December 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "cars.h"
#include "members.h"

//Administrative password for printing the reservation manifest
const string ADMIN_KEY = "admin";

// Three arrays for storing the 9 cars
// Array format used for indexing
Pickup pickups[3] = {Pickup(), Pickup(), Pickup()};
Compact compacts[3] = {Compact(), Compact(), Compact()};
Sedan sedans[3] = {Sedan(), Sedan(), Sedan()};

// Tracks the current reservation number
int reservation_count = 0;

// 'Database' for storing reservations
reservation reservations[24];

// Member list
member members[24];

member* current;	 // Pointer to the current member being referenced
int member_position; // Position of current member in list
string firstname, lastname, fullname;

// User interface variables
bool flag;
int input, option;
string password;

// Function prototypes
void displayMembers();
void displayAssignments();
bool createReservation(int);
void deleteReservation(int);

int main()
{
	// All vehicles are assigned colors
	pickups[0].setColor('P');
	pickups[1].setColor('Y');
	pickups[2].setColor('R');
	compacts[0].setColor('G');
	compacts[1].setColor('B');
	compacts[2].setColor('Y');
	sedans[0].setColor('R');
	sedans[1].setColor('G');
	sedans[2].setColor('B');

	// Member credit list read and saved at the start of the program
	read(members);

	// Menu displaying loop
	for (;;)
	{
		cout << "\nReservation System Main Menu:\n"
			 << "  (1) Create a reservation\n"
			 << "  (2) Modify a reservation\n"
			 << "  (3) Delete a reservation\n"
			 << "  (4) Print reservation manifest\n"
			 << "  (5) Display vehicle assignments\n"
			 << "  (6) Display member list\n"
			 << "  (7) Print vehicle assignment\n"
			 << "  (8) Exit program\n"
			 << "Option : ";
		cin >> input; cin.ignore();

		switch (input)
		{
			// Create a reservation
			case 1:
				cout << "Enter the passenger's name : ";
				cin >> firstname; cin.ignore();
				cin >> lastname; cin.ignore();
				member_position = indexOf(members, firstname, lastname);

				if (member_position == -1)	// Exit to main menu if name entered does not exist in member list
				{
					cout << "Member does not exist!" << endl;
					break;
				}
				else if (members[member_position].credits == 0)	// Exit to main menu if the member exists but has no credits
				{
					cout << "Member does not have any credits!" << endl;
					break;
				}
				else
				{
					// Member exists and has >= 1 credits
					// current is updated to point to correct member object in list
					current = &members[member_position];
					fullname = current->firstname + " " + current->lastname;

					if(current->reserved)
						cout << "Member has already reserved a seat!" << endl;
					else
						flag = createReservation(reservation_count);	// Attempt to create a reservation

					// Reservation count only updated if a 'new' reservation is created
					// does not update if a reservation was modified
					if (flag)
					{
						reservation_count++;
						current->reserved = true;
					}

					break;
				}

			// Modify a reservation
			case 2:
				cout << "Enter a reservation number : ";
				cin >> input; cin.ignore();
				if (input >= 0 && input <= reservation_count) // Check that the reservation exists
				{
					// Clear the current reservation
					deleteReservation(input);
					cout << "\nCurrent reservation cleared!" << endl;

					// Reprompt user until a new reservation is successfully made
					// to replace the cleared out current one (prevents leaving an empty reservation)
					do
					{
						flag = createReservation(input);
					} while (!flag);
				}
				else
					cout << "Reservation does not exist!" << endl;
				break;

			// Delete a reservation
			case 3:
				cout << "Enter a reservation number : ";
				cin >> input; cin.ignore();
				if (input >= 0 && input <= reservation_count) // Check that the reservation exists
				{
					// Clear the reservation
					deleteReservation(input);

					// Shift the reservation database to replace the empty reservation
					for (int i = input; i < 23; i++)
					{
						reservations[i] = reservations[i+1];
					}

					// Adjust the reservation count
					reservation_count--;

					cout << "\nReservation deleted!" << endl;
				}
				else
					cout << "Reservation does not exist!" << endl;
				break;

			// Print rservation manifest
			// Requires admin verification
			case 4:
				cout << "Enter admin password : ";
				cin >> password; cin.ignore();

				if (password == ADMIN_KEY)	// Admin key defined at top of program
				{
					printManifest(pickups, compacts, sedans);
					cout << "Reservation manifest created!" << endl;
				}
				else
					cout << "Invalid password entered!" << endl;

				break;

			// Display all vehicle assignments
			case 5:
				displayAssignments();
				break;

			// Display member list
			case 6:
				displayMembers();
				break;

			// Print specific vehicle assignment
			case 7:
				displayAssignments();
				cout << "Select a car number : ";
				cin >> input; cin.ignore();

				if (input >= 1 && input <=3) 					// Print from pickup array
					pickups[input-1].printAssignment();
				else if (input <= 6)							// Print from compact array
					compacts[(input-1) % 3].printAssignment();
				else if (input <= 9)							// Print from sedan array
					sedans[(input-1) % 3].printAssignment();
				else
					cout << "Invalid operation entered!" << endl;

				break;

			// Exit program
			case 8:
				// Member credit list updated and saved at end of program
				write(members);

				cout << "Program Terminated" << endl;
				exit(2);
				break;

			// Invalid menu option entered
			default:
				cout << "Unable to perform task." << endl
					 << "Please be sure to enter a valid input and try again." << endl;
				break;
		}
	}

	return 0;
}


// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// displayAssignments()
//
//		input 		: n/a
//		output		: n/a
//		description : prints the each vehicle array on a seperate line.
//					  see class output stream overload functions in 'cars.h'
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void displayAssignments()
{
	cout << "\n" << pickups << endl;
	cout << compacts << endl;
	cout << sedans << endl;
}

void displayMembers()
{
	cout << "\nRIT Crew Members"  << right << setw(12) << "Credits";
	cout << "    RIT Crew Members"  << right  << setw(13) << "Credits"<<endl;

	for (int i = 0; i < 12; i++)
	{
		cout << right << setw(4)  << (i + 1) << ") ";
		cout << left  << setw(18) << members[i].firstname + " " + members[i].lastname;
		cout << left << setw(9) << members[i].credits;

		cout << right << setw(4)  << (i + 13) << ") ";
		cout << left  << setw(18) << members[i + 12].firstname + " " + members[i + 12].lastname;
		cout << left << setw(8) << members[i + 12].credits<<endl;
	}
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// deleteReservation()
//
//		input 		: position in database of reservation to delete
//		output		: n/a
//		description : deletes the reservation from the database, restores
//					  the credits to the member, and clears the seat
//					  assignment for the vehicle
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void deleteReservation(int index)
{
	// Find member associated with the reservation to be deleted
	member_position = indexOf(members, reservations[index].passenger);
	current = &members[member_position];

	if (reservations[index].carID <= 3)	// If the reservation was for a pickup
	{
		// Clear the reservation for the pickup matching the car ID of the reservation
		pickups[(reservations[index].carID) -1].clearFrontseat();

		// Member gets there frontseat credits restored
		current->credits += 5;
	}
	else if (reservations[index].carID <= 6)  // If the reservation was for a compact
	{
		// Clear the reservation for the compact matching the car ID based on seat assignment
		if (reservations[index].seat == "frontseat")
		{
			compacts[((reservations[index].carID) -1) % 3].clearFrontseat();

			// Member gets there frontseat credits restored
			current->credits += 5;
		}
		else
		{
			compacts[((reservations[index].carID) -1) % 3].clearBackseat(reservations[index].passenger);

			// Member gets there compact backseat credits restored
			current->credits += 3;
		}
	}
	else	// Reservation was for a sedan
	{
		// Clear the reservation for the sedan matching the car ID based on seat assignment
		if (reservations[index].seat == "frontseat")
		{
			sedans[((reservations[index].carID) -1) % 3].clearFrontseat();

			// Member gets there frontseat credits restored
			current->credits += 5;
		}
		else if (reservations[index].seat == "middleseat")
		{
			sedans[((reservations[index].carID) -1) % 3].clearMiddleseat();

			// Member gets there middleseat credits restored
			current->credits += 1;
		}
		else
		{
			sedans[((reservations[index].carID) -1) % 3].clearBackseat(reservations[index].passenger);

			// Member gets there sedan backseat credits restored
			current->credits += 2;
		}
	}

}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// createReservation()
//
//		input 		: position index of reservation in database
//		output		: reservation flag
//		description : prompts user to select a method for selecting a seat.
//					  user can either select by category or select a specific
//					  seat. error message printed if no seat is available
//					  matching the user's preferences, if a seat is available
//					  check to see if a user's credit balance is enough and
//					  if so create the reservation for the correct vehicle,
//					  charge the user's credit balance, and update the
//					  reservation database at the provided index
//					  true is returned if a reservation is made successfully
//					  otherwise returns false.
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool createReservation(int reservation_index)
{
	displayAssignments();

	cout << "Would you like to:\n"
		 << "  (1) Select seat by category\n"
		 << "  (2) Select specific seat\n"
		 << "Option : ";
	cin >> input; cin.ignore();

	// Select by category
	if (input == 1)
	{
		// Categories seperated by seat credit value
		cout << "\nSelect a category:\n"
			 << "  (1) Front seat\n"
			 << "  (2) Compact back seat\n"
			 << "  (3) Sedan back seat\n"
			 << "  (4) Middle seat\n"
			 << "Option : ";
		cin >> input; cin.ignore();

		if (input == 1) // Front seat reservation
		{
			if (current->credits >= 5) // Check if member has enough credits
			{
				for (int i = 0; i < 9; i++)
				{
					if (i < 3)
						pickups[i].reserveFrontseat(reservations, reservation_index, fullname, (i + 1), flag);
					else if (i < 6)
						compacts[i%3].reserveFrontseat(reservations, reservation_index, fullname, (i + 1), flag);
					else
						sedans[i%3].reserveFrontseat(reservations, reservation_index, fullname, (i + 1), flag);

					// If a reservation is successfully made, update the member credits
					if (flag)
					{
						current->credits -= 5;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
				}

				// Exit if no seat is found
				if (!flag)
					cout << "No seats available!" << endl;
			}
			else
				cout << "Not enough credits!" << endl;
		}
		else if (input == 2) // Back compact seat reservation
		{
			if (current->credits >= 3)  // Check if member has enough credits
			{
				for (int i = 0; i < 3; i++)
				{
					compacts[i].reserveBackseat(reservations, reservation_index, fullname, (i + 4), flag);
					if (flag)
					{
						current->credits -= 3;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
				}

				if (!flag)
					cout << "No seats available!" << endl;
			}
			else
				cout << "Not enough credits!" << endl;
		}
		else if (input == 3) // Back sedan seat reservation
		{
			if (current->credits >= 2)  // Check if member has enough credits
			{
				for (int i = 0; i < 3; i++)
				{
					sedans[i].reserveBackseat(reservations, reservation_index, fullname, (i + 7), flag);

					if (flag)
					{
						current->credits -= 2;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
				}

				if (!flag)
					cout << "No seats available!" << endl;
			}
			else
				cout << "Not enough credits!" << endl;
		}
		else if (input == 4) // Middle seat reservation
		{
			if (current->credits >= 1)  // Check if member has enough credits
			{
				for (int i = 0; i < 3; i++)
				{
					sedans[i].reserveMiddleseat(reservations, reservation_index, fullname, (i + 7), flag);

					if (flag)
					{
						current->credits -= 1;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
				}

				if (!flag)
					cout << "No seats available!" << endl;
			}
			else
				cout << "Not enough credits!" << endl;
		}
		else
			cout << "Invalid option entered!" << endl;
	}

	// Select specific seat
	else if (input == 2)
	{
		cout << "Select a car number : ";
		cin >> input; cin.ignore();

		if (input >= 1 && input <= 3) // Create pickup reservation
		{
			if (current->credits >= 5)  // Check if member has enough credits
			{
				pickups[input-1].reserveFrontseat(reservations, reservation_index, fullname, input, flag);

				if (flag)
				{
					current->credits -= 5;
					cout << "\nReservation #" << reservation_index << " created!" << endl;
					return true;
				}
				else
					cout << "Seat is already taken!" << endl;
			}
			else
				cout << "Not enough credits!" << endl;
		}
		else if (input <= 6) // Create compact reservation
		{
			cout << "\nSelect a seat :\n"
				 << "  (1) Front seat\n"
				 << "  (2) Back seat\n"
				 << "Option : ";
			cin >> option; cin.ignore();

			if (option == 1)
			{
				if (current->credits >= 5)  // Check if member has enough credits
				{
					compacts[((input-1) % 3)].reserveFrontseat(reservations, reservation_index, fullname, input, flag);

					if (flag)
					{
						current->credits -= 5;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
					else
						cout << "Seat is already taken!" << endl;
				}
				else
					cout << "Not enough credits!" << endl;
			}
			else if (option == 2)
			{
				if (current->credits >= 3)  // Check if member has enough credits
				{
					compacts[((input-1) % 3)].reserveBackseat(reservations, reservation_index, fullname, input, flag);

					if (flag)
					{
						current->credits -= 3;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
					else
						cout << "Seat is already taken!" << endl;
				}
				else
					cout << "Not enough credits!" << endl;
			}
			else
				cout << "Invalid option entered!" << endl;
		}
		else if (input <= 9) // Create sedan reservation
		{
			cout << "\nSelect a seat :\n"
				 << "  (1) Front seat\n"
				 << "  (2) Back seat\n"
				 << "  (3) Middle seat\n"
				 << "Option : ";
			cin >> option; cin.ignore();

			if (option == 1)
			{
				if (current->credits >= 5)  // Check if member has enough credits
				{
					sedans[((input-1) % 3)].reserveFrontseat(reservations, reservation_index, fullname, input, flag);

					if (flag)
					{
						current->credits -= 5;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
					else
						cout << "Seat is already taken!" << endl;
				}
				else
					cout << "Not enough credits!" << endl;
			}
			else if (option == 2)
			{
				if (current->credits >= 2)  // Check if member has enough credits
				{
					sedans[((input-1) % 3)].reserveBackseat(reservations, reservation_index, fullname, input, flag);

					if (flag)
					{
						current->credits -= 2;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
					else
						cout << "Seat is already taken!" << endl;
				}
				else
					cout << "Not enough credits!" << endl;
			}
			else if (option == 3)
			{
				if (current->credits >= 1)  // Check if member has enough credits
				{
					sedans[((input-1) % 3)].reserveMiddleseat(reservations, reservation_index, fullname, input, flag);

					if (flag)
					{
						current->credits -= 1;
						cout << "\nReservation #" << reservation_index << " created!" << endl;
						return true;
					}
					else
						cout << "Seat is already taken!" << endl;
				}
				else
					cout << "Not enough credits!" << endl;
			}
			else
				cout << "Invalid option entered!" << endl;
		}
		else
			cout << "Invalid option entered!" << endl;
	}
	// Default error message
	else
		cout << "Invalid option entered!" << endl;

	return false;
}
