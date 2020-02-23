// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : cars.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Header file containing the reservation data type definition
//				   and class definitions for Pickup, Compact, and Sedan.
//
//				   The information for each reservation includes:
//				   - the full name of the passenger (for printing)
//                 - the seat being reserved (for printing)
//                 - the vehicle color and type that they are in (for printing)
//					 formats as : color_class i.e. purple_pickup
//                 - an ID for the vehicle used for determining which array
//				     it's location for modifications to the seat assignment
//
//				   Pickup, Compact, and Sedan classes created using simple
//				   inheritance with Pickup being the base class. Each class
//				   utilizes the pair data type to represent each individual
//                 seat, more information on pair can be found on:
//				   http://www.cplusplus.com/reference/utility/pair/pair/
// 				   The first and second objects in each pair are a reservation
//				   instance and a seat state token of type char.
//
// Last Modified : 5 December 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef CARS_H_
#define CARS_H_

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#include <utility>
#include <fstream>
using namespace std;

// Reservation stub tracks:
//	- passanger's name
//	- the seat type
//	- the car they're in (color, type, and ID)
struct reservation
{
	string passenger;
	string seat;
	string car;

	// Added for easier navigation when handling multiple reservations
	int carID;
};

// Tokens for representing the current state of each seat
const char FRONT_TKN = '5';
const char MIDDLE_TKN = '1';
const char BACK_COMPACT_TKN = '3';
const char BACK_SEDAN_TKN = '2';
const char SEAT_TAKEN_TKN = 'X';

// Forward declarations
class Compact;
class Sedan;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Pickup class
//
//		description : represents a simple vehicle with a  color attribute
//					  and only one available seat.
//					  Seat can be set or cleared, a list of seat assignments
//					  can be printed, and an array of size 3 may be printed
//					  to console using the standard out stream (<<) command.
//
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Pickup
{
	protected:
		char colorLetter;	// (P)urple, (G)reen, (R)ed, (Y)ellow, (B)lue
		string color;
		// Pair used to store two related objects
		// First is the reservation object for the current seat
		// Second is a char token representing the current status of the seat
		pair <reservation, char> frontseat;

	public:
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// Pickup()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : default constructor sets the default color to purple
		//					  and initializes all seats to be unasigned and of the
		//					  appropriate type (frontseat)
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		Pickup()
		{
			colorLetter = 'P';
			color = getColor();
			frontseat.first = {"unasigned", color + "_" + "pickup", "frontseat"};
			frontseat.second = FRONT_TKN;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// setColor()
		//
		//		input 		: first letter of chosen color
		//		output		: n/a
		//		description : sets the color of the pickup to the chosen color and
		//					  updates the seat reservations to have the new color
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void setColor(char colorLetter)
		{
			this->colorLetter = colorLetter;
			color = getColor();
			frontseat.first.car = color + "_" + "pickup";
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// getColor()
		//
		//		input 		: n/a
		//		output		: string representing the color of the object
		//		description : returns the string equivalent of the color letter of
		//					  the pickup object (for use in printing and storing
		//					  information outside of the class)
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		string getColor()
		{
			if (colorLetter == 'R')
				return "red";
			else if (colorLetter == 'B')
				return "blue";
			else if (colorLetter == 'Y')
				return "yellow";
			else if (colorLetter == 'G')
				return "green";
			else
				return "purple";
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// reserveFrontseat()
		//
		//		input 		: reservation array, position in the array of the
		//					  reservation to be modified, passenger name, car ID,
		//					  and a reservation flag passed by reference
		//		output		: n/a
		//		description : if the seat status matches the empty seat token the
		//					  seat is updated to be reserved and given the passenger's
		//					  name and the car ID. This reservation is then updated
		//					  in the array and the reserved flag is set to true.
		//					  If the reservation cannot be made the flag is set false.
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void reserveFrontseat(reservation res[24], int index, string name, int carID, bool &flag)
		{
			if (frontseat.second == FRONT_TKN)
			{
				frontseat.second = SEAT_TAKEN_TKN;
				frontseat.first.passenger = name;
				frontseat.first.carID = carID;

				res[index] = frontseat.first;

				flag = true;
			}
			else
				flag =  false;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// clearFrontseat()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : frontseat is reset to it's default values
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void clearFrontseat()
		{
			frontseat.first = {"unasigned", color + "_" + "pickup", "frontseat"};
			frontseat.second = FRONT_TKN;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// output stream overload <<
		//
		//		input 		: output stream object and array of Pickup objects
		//		output		: output stream object
		//		description : format prints the three pickups from the array i.e.
		//					  1- purple   2- yellow   3- red
		//					  [-]   [5]   [-]   [5]   [-]   [X]
		//					  drivers are marked by '-' and tokens are used to
		//					  represent the seat value or if the seat is taken 'X'
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend ostream& operator<<(ostream& os, const Pickup* arr)
		{
			os << left << "1- "; os << setw(9) << setfill(' ') << arr[0].color;
			os << left << "2- "; os << setw(9) << setfill(' ') << arr[1].color;
			os << left << "3- "; os << setw(9) << setfill(' ') << arr[2].color << endl;

			os << left << "[-]   [" << arr[0].frontseat.second << "]   ";
			os << left << "[-]   [" << arr[1].frontseat.second << "]   ";
			os << left << "[-]   [" << arr[2].frontseat.second << "]" << endl;

			return os;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// printAssignment()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : prints to console the seat assignments for the pickup
		//					  and writes the assignment to a file labeled as
		//                    color_pickup where color is the color of the pickup
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void printAssignment()
		{
			cout << endl;
			cout << "frontseat  : " << frontseat.first.passenger << endl;

			ofstream outFile;
			string filename = color + "_" + "pickup.txt";
			outFile.open(filename);

			outFile << "frontseat  : " << frontseat.first.passenger << endl;

			outFile.close();
		}


		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// printManifest()
		//
		//		input 		: three arrays for Pickup, Compact, and Sedan
		//		output		: n/a
		//		description : writes all of the reservations to a file
		//					  see function for more in depth
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend void printManifest(Pickup*, Compact*, Sedan*);
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Compact class
//
//		description : derived from Pickup class and includes two additional
//					  available seats.
//					  Seat can be set or cleared, a list of seat assignments
//					  can be printed, and an array of size 3 may be printed
//					  to console using the standard out stream (<<) command.
//
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Compact : public Pickup
{
	protected:
		pair<reservation, char> backseat[2];

	public:
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// Compact()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : default constructor sets the default color to purple
		//					  and initializes all seats to be unasigned and of the
		//					  appropriate type (frontseat, backseat)
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		Compact()
		{
			colorLetter = 'P';
			color = getColor();
			backseat[0].first = {"unasigned", color + "_" + "compact", "backseat"};
			backseat[0].second = BACK_COMPACT_TKN;
			backseat[1].first = {"unasigned", color + "_" + "compact", "backseat"};
			backseat[1].second = BACK_COMPACT_TKN;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// setColor()
		//
		//		input 		: first letter of chosen color
		//		output		: n/a
		//		description : sets the color of the compact to the chosen color and
		//					  updates the seat reservations to have the new color
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void setColor(char colorLetter)
		{
			this->colorLetter = colorLetter;
			color = getColor();
			frontseat.first.car = color + "_" + "compact";
			backseat[0].first.car = color + "_" + "compact";
			backseat[1].first.car = color + "_" + "compact";
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// reserveBackseat()
		//
		//		input 		: reservation array, position in the array of the
		//					  reservation to be modified, passenger name, car ID,
		//					  and a reservation flag passed by reference
		//		output		: n/a
		//		description : if the seat status matches the empty seat token the
		//					  seat is updated to be reserved and given the passenger's
		//					  name and the car ID. This reservation is then updated
		//					  in the array and the reserved flag is set to true.
		//					  If the reservation cannot be made the flag is set false.
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void reserveBackseat(reservation res[24], int index, string name, int carID, bool &flag)
		{
			if (backseat[0].second == BACK_COMPACT_TKN)
			{
				backseat[0].second = SEAT_TAKEN_TKN;
				backseat[0].first.passenger = name;
				backseat[0].first.carID = carID;

				res[index] = backseat[0].first;

				flag = true;
			}
			else if (backseat[1].second == BACK_COMPACT_TKN)
			{
				backseat[1].second = SEAT_TAKEN_TKN;
				backseat[1].first.passenger = name;
				backseat[1].first.carID = carID;

				res[index] = backseat[1].first;

				flag = true;
			}
			else
				flag =  false;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// clearBackseat()
		//
		//		input 		: passenger name
		//		output		: n/a
		//		description : backseat containing the passenger's named is reset to
		//					  it's default values
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void clearBackseat(string name)
		{
			if (backseat[0].first.passenger == name)
			{
				backseat[0].first = {"unasigned", color + "_" + "compact", "backseat"};
				backseat[0].second = BACK_COMPACT_TKN;
			}
			else
			{
				backseat[1].first = {"unasigned", color + "_" + "compact", "backseat"};
				backseat[1].second = BACK_COMPACT_TKN;
			}
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// output stream overload <<
		//
		//		input 		: output stream object and array of Compact objects
		//		output		: output stream object
		//		description : format prints the three pickups from the array i.e.
		//					  4- green    5- blue     6- yellow
		//					  [-]   [5]   [-]   [5]   [-]   [X]
		//					  [3]   [X]   [3]   [3]   [3]   [3]
		//					  drivers are marked by '-' and tokens are used to
		//					  represent the seat value or if the seat is taken 'X'
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend ostream& operator<<(ostream& os, const Compact* arr)
		{
			os << left << "4- "; os << setw(9) << setfill(' ') << arr[0].color;
			os << left << "5- "; os << setw(9) << setfill(' ') << arr[1].color;
			os << left << "6- "; os << setw(9) << setfill(' ') << arr[2].color << endl;

			os << left << "[-]   [" << arr[0].frontseat.second << "]   ";
			os << left << "[-]   [" << arr[1].frontseat.second << "]   ";
			os << left << "[-]   [" << arr[2].frontseat.second << "]" << endl;

			os << left << "[" << arr[0].backseat[0].second << "]   [" << arr[0].backseat[1].second << "]   ";
			os << left << "[" << arr[1].backseat[0].second << "]   [" << arr[1].backseat[1].second << "]   ";
			os << left << "[" << arr[2].backseat[0].second << "]   [" << arr[2].backseat[1].second << "]" << endl;

			return os;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// printAssignment()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : prints to console the seat assignments for the compact
		//					  and writes the assignment to a file labeled as
		//                    color_compact where color is the color of the compact
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void printAssignment()
		{
			cout << endl;
			cout << "frontseat  : " << frontseat.first.passenger << endl;
			cout << "backseat   : " << backseat[0].first.passenger << endl;
			cout << "backseat   : " << backseat[1].first.passenger << endl;

			ofstream outFile;
			string filename = color + "_" + "compact.txt";
			outFile.open(filename);

			outFile << "frontseat  : " << frontseat.first.passenger << endl;
			outFile << "backseat   : " << backseat[0].first.passenger << endl;
			outFile << "backseat   : " << backseat[1].first.passenger << endl;

			outFile.close();
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// printManifest()
		//
		//		input 		: three arrays for Pickup, Compact, and Sedan
		//		output		: n/a
		//		description : writes all of the reservations to a file
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend void printManifest(Pickup*, Compact*, Sedan*);
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Sedan class
//
//		description : derived from Pickup class and includes three additional
//					  available seats.
//					  Seat can be set or cleared, a list of seat assignments
//					  can be printed, and an array of size 3 may be printed
//					  to console using the standard out stream (<<) command.
//
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class Sedan : public Compact
{
	protected:
	pair <reservation, char> middleseat;

	public:
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// Sedan()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : default constructor sets the default color to purple
		//					  and initializes all seats to be unasigned and of the
		//					  appropriate type (frontseat, backseat, middleseat)
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		Sedan()
		{
			colorLetter = 'P';
			color = getColor();
			backseat[0].first = {"unasigned", color + "_" + "sedan", "backseat"};
			backseat[0].second = BACK_SEDAN_TKN;
			backseat[1].first = {"unasigned", color + "_" + "sedan", "backseat"};
			backseat[1].second = BACK_SEDAN_TKN;
			middleseat.first = {"unasigned", color + "_" + "sedan", "middleseat"};
			middleseat.second = MIDDLE_TKN;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// setColor()
		//
		//		input 		: first letter of chosen color
		//		output		: n/a
		//		description : sets the color of the sedan to the chosen color and
		//					  updates the seat reservations to have the new color
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void setColor(char colorLetter)
		{
			this->colorLetter = colorLetter;
			color = getColor();
			frontseat.first.car = color + "_" + "sedan";
			middleseat.first.car = color + "_" + "sedan";
			backseat[0].first.car = color + "_" + "sedan";
			backseat[1].first.car = color + "_" + "sedan";
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// reserveBackseat()
		//
		//		input 		: reservation array, position in the array of the
		//					  reservation to be modified, passenger name, car ID,
		//					  and a reservation flag passed by reference
		//		output		: n/a
		//		description : if the seat status matches the empty seat token the
		//					  seat is updated to be reserved and given the passenger's
		//					  name and the car ID. This reservation is then updated
		//					  in the array and the reserved flag is set to true.
		//					  If the reservation cannot be made the flag is set false.
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void reserveBackseat(reservation res[24], int index, string name, int carID, bool &flag)
		{
			if (backseat[0].second == BACK_SEDAN_TKN)
			{
				backseat[0].second = SEAT_TAKEN_TKN;
				backseat[0].first.passenger = name;
				backseat[0].first.carID = carID;

				res[index] = backseat[0].first;

				flag = true;
			}
			else if (backseat[1].second == BACK_SEDAN_TKN)
			{
				backseat[1].second = SEAT_TAKEN_TKN;
				backseat[1].first.passenger = name;
				backseat[1].first.carID = carID;

				res[index] = backseat[1].first;

				flag = true;
			}
			else
				flag =  false;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// reserveMiddleseat()
		//
		//		input 		: reservation array, position in the array of the
		//					  reservation to be modified, passenger name, car ID,
		//					  and a reservation flag passed by reference
		//		output		: n/a
		//		description : if the seat status matches the empty seat token the
		//					  seat is updated to be reserved and given the passenger's
		//					  name and the car ID. This reservation is then updated
		//					  in the array and the reserved flag is set to true.
		//					  If the reservation cannot be made the flag is set false.
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void reserveMiddleseat(reservation res[24], int index, string name, int carID, bool &flag)
		{
			if (middleseat.second == MIDDLE_TKN)
			{
				middleseat.second = SEAT_TAKEN_TKN;
				middleseat.first.passenger = name;
				middleseat.first.carID = carID;

				res[index] = middleseat.first;

				flag = true;
			}
			else
				flag =  false;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// clearBackseat()
		//
		//		input 		: passenger name
		//		output		: n/a
		//		description : backseat containing the passenger's named is reset to
		//					  it's default values
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void clearBackseat(string name)
		{
			if (backseat[0].first.passenger == name)
			{
				backseat[0].first = {"unasigned", color + "_" + "sedan", "backseat"};
				backseat[0].second = BACK_SEDAN_TKN;
			}
			else
			{
				backseat[1].first = {"unasigned", color + "_" + "sedan", "backseat"};
				backseat[1].second = BACK_SEDAN_TKN;
			}
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// clearMiddleseat()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : middleseat is reset to it's default values
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void clearMiddleseat()
		{
			middleseat.first = {"unasigned", color + "_" + "sedan", "middleseat"};
			middleseat.second = MIDDLE_TKN;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// output stream overload <<
		//
		//		input 		: output stream object and array of Sedan objects
		//		output		: output stream object
		//		description : format prints the three sedans from the array i.e.
		//					  7- red      8- green    9- blue
		//					  [-]   [5]   [-]   [5]   [-]   [X]
		//					  [2][1][2]   [X][X][2]   [2][1][2]
		//					  drivers are marked by '-' and tokens are used to
		//					  represent the seat value or if the seat is taken 'X'
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend ostream& operator<<(ostream& os, const Sedan* arr)
		{

			os << left << "7- "; os << setw(9) << setfill(' ') << arr[0].color;
			os << left << "8- "; os << setw(9) << setfill(' ') << arr[1].color;
			os << left << "9- "; os << setw(9) << setfill(' ') << arr[2].color << endl;

			os << left << "[-]   [" << arr[0].frontseat.second << "]   ";
			os << left << "[-]   [" << arr[1].frontseat.second << "]   ";
			os << left << "[-]   [" << arr[2].frontseat.second << "]" << endl;

			os << left << "[" << arr[0].backseat[0].second << "]"
					   << "[" << arr[0].middleseat.second  << "]"
					   << "[" << arr[0].backseat[1].second << "]   ";
			os << left << "[" << arr[1].backseat[0].second << "]"
					   << "[" << arr[1].middleseat.second  << "]"
					   << "[" << arr[1].backseat[1].second << "]   ";
			os << left << "[" << arr[2].backseat[0].second << "]"
					   << "[" << arr[2].middleseat.second  << "]"
					   << "[" << arr[2].backseat[1].second << "]" << endl;

			return os;
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// printAssignment()
		//
		//		input 		: n/a
		//		output		: n/a
		//		description : prints to console the seat assignments for the sedan
		//					  and writes the assignment to a file labeled as
		//                    color_sedan where color is the color of the sedan
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		void printAssignment()
		{
			cout << endl;
			cout << "frontseat  : " << frontseat.first.passenger << endl;
			cout << "backseat   : " << backseat[0].first.passenger << endl;
			cout << "backseat   : " << backseat[1].first.passenger << endl;
			cout << "middleseat : " << middleseat.first.passenger << endl;

			ofstream outFile;
			string filename = color + "_" + "sedan.txt";
			outFile.open(filename);

			outFile << "frontseat  : " << frontseat.first.passenger << endl;
			outFile << "backseat   : " << backseat[0].first.passenger << endl;
			outFile << "backseat   : " << backseat[1].first.passenger << endl;
			outFile << "middleseat : " << middleseat.first.passenger << endl;

			outFile.close();
		}

		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		// printManifest()
		//
		//		input 		: three arrays for Pickup, Compact, and Sedan
		//		output		: n/a
		//		description : writes all of the reservations to a file
		// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		friend void printManifest(Pickup*, Compact*, Sedan*);
};

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// printManifest()
//
//		input 		: three arrays for Pickup, Compact, and Sedan
//		output		: n/a
//		description : writes all of the reservations to the file
//					  'all_reservations.txt' by car with the associated car
//					  color and type above its seat assignments
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void printManifest(Pickup pickups[3], Compact compacts[3], Sedan sedans[3])
{
	ofstream outFile;
	outFile.open("all_reservations.txt");

	for (int i = 0; i < 3; i++)
	{
		outFile << pickups[i].color + " pickup" << endl;
		outFile << "frontseat  : " << pickups[i].frontseat.first.passenger << endl;
		outFile << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		outFile << compacts[i].color + " compact" << endl;
		outFile << "frontseat  : " << compacts[i].frontseat.first.passenger << endl;
		outFile << "backseat   : " << compacts[i].backseat[0].first.passenger << endl;
		outFile << "backseat   : " << compacts[i].backseat[1].first.passenger << endl;
		outFile << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		outFile << sedans[i].color + " sedan" << endl;
		outFile << "frontseat  : " << sedans[i].frontseat.first.passenger << endl;
		outFile << "backseat   : " << sedans[i].backseat[0].first.passenger << endl;
		outFile << "backseat   : " << sedans[i].backseat[1].first.passenger << endl;
		outFile << "middleseat : " << sedans[i].middleseat.first.passenger << endl;
		outFile << endl;
	}

	outFile.close();
}

#endif /* CARS_H_ */
