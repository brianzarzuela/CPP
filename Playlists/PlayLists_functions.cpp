// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : PlayLists_functions.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : The function file for PlayLists.cpp containing all
//                 function definitions for:
//                 - Create()
//                 - Display()
//                 - Insert()
//                 - Delete()
//                 - Save()
//                 - Read()
//
// Last Modified : 8 October 2019
// 		- Added error control
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "PlayLists.h"

struct playlist *playlists[MAX];

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Read()
//
//		input 		: n/a
//		output		: a pointer to the head of the master linked-list
//		description : reads the content of the file "billboard.txt" and
//					  builds the master linked-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
song *Read()
{
	ifstream inFile;

	inFile.open("billboard.txt");

	if (inFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit(1);
	}

	song *current, *head;

	current = new song;
	head = current;

	do
	{
		getline(inFile, current->name);
		getline(inFile, current->artist);
		inFile >> current->ranking; inFile.ignore();
		inFile >> current->year; inFile.ignore();
		inFile >> current->decade; inFile.ignore();
		inFile >> current->performer; inFile.ignore();
		inFile >> current->genre; inFile.ignore();

		if (inFile.eof())
		{
			current->next_addr = NULL;
			break;
		}
		else
		{
			current->next_addr = new song;
			current = current->next_addr;
		}
	}
	while (true);

	inFile.close();

	return (head);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Save()
//
//		input 		: a pointer to the first song of the play-list
//		output		: void
//		description : prompts the user to enter a name to call the file to
//					  save the play-list to (appends .txt extension to name)
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Save(song *head)
{
	song *current = head;

	ofstream outFile;

	string filename;

	cout << "Enter a name to call the file : ";
	getline(cin, filename);

	filename = filename + ".txt";
	outFile.open(filename);

	while (current != NULL)
	{
		outFile << current->name << endl;
		outFile << current->artist << endl;
		outFile << current->ranking << endl;
		outFile << current->year << endl;
		outFile << current->decade << endl;
		outFile << current->performer << endl;
		outFile << current->genre << endl;

		current = current->next_addr;
	}

	outFile.close();

	cout << "Play-list saved to file " << filename << endl;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Display()
//
//		input 		: a pointer to the head of the billboard song list
//		output		: void
//		description : displays the context of the play-list to the screen
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void Display(song *head)
{
	song *current = head;

	int count = 1;

	cout << "Play-list:" << endl;

	while (current != NULL)
	{
		cout << right << setw(4) << count++ << ". ";
		cout << current->name << endl;
		cout << "      " << current->artist << endl;
		cout << "      " << current->year << " | ";

		switch(current->genre)
		{
			case 1:
				cout << "Latin"; break;
			case 2:
				cout << "Country"; break;
			case 3:
				cout << "Hip-Hop/Rap"; break;
			case 4:
				cout << "Jazz"; break;
			case 5:
				cout << "Dance/Electronic"; break;
			case 6:
				cout << "R&B"; break;
			case 7:
				cout << "Pop"; break;
			case 8:
				cout << "Rock"; break;
			default: break;	// do nothing
		}

		cout << " | ";

		switch(current->performer)
		{
			case 'F':
				cout << "Female"; break;
			case 'M':
				cout << "Male"; break;
			case 'D':
				cout << "Duo/Group"; break;
		}

		cout << endl;

		current = current->next_addr;
	}
	cout << endl;

	return;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Create()
//
//		input 		: the string name of the play-list to display and a
//                    pointer to the head of the billboard song list
//		output		: play-list node pointing to the head of the linked-list
//		description : creates a play-list node and gives it the user entered
//                    name. the node then points to a linked-list of songs
//                    decided by the users preference
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
playlist *Create(string playlist_name, song *head)
{
	// Maximum number of songs in a user created play-list
	const int PLAYLIST_SIZE = 20;

	playlist *playlist_head = new playlist;
	playlist_head->name = playlist_name;

	song *cursor = head;
	song *current = new song;
	playlist_head->next_addr = current;

	cout << "Play-list " << playlist_name << " created!" << endl;

	int i = 0;	// indexing variable
	int option; // user input value
	bool error = false; // flag to denote when to use error statements

	do
	{
		cout << "\nHow would you like to populate your play-list?\n"
			 << "  (1) By ranking in the top 200 list\n"
			 << "  (2) By decade\n"
			 << "  (3) By performer type\n"
			 << "  (4) By genre\n";
		cout << "Option...... : ";
		cin >> option; cin.ignore();

	} while (option < 1 || option > 4);

	switch (option)
	{
		// Ask user for a ranking, the song in that position from the
		// billboard list will be added to their play-list
		// Repeat this process until the song limit is reached
		case 1 :
			for (i = 0; i < PLAYLIST_SIZE; i++)
			{
				error = false;
				do
				{
					if (error)
						cout << "\nInvalid input!" << endl;

					cout << "\nEnter a ranking : ";
					cin >> option; cin.ignore();

					error = true;
				} while (option < 1 || option > 200);

				cursor = head;

				// Find song at that ranking
				for (int k = 1; k < option; k++)
				{
					cursor = cursor->next_addr;
				}

				current->name = cursor->name;
				current->year = cursor->year;
				current->genre = cursor->genre;
				current->artist = cursor->artist;
				current->decade = cursor->decade;
				current->ranking = cursor->ranking;
				current->performer = cursor->performer;

				cout << current->name << " added!" << endl;

				if (i == PLAYLIST_SIZE - 1)
				{
					current->next_addr = NULL;
				}
				else
				{
					current->next_addr = new song;
					current = current->next_addr;
				}
			}
			break;

		// Fill the play-list with songs that match
		// the user entered decade
		case 2:
			do
			{
				if (error)
					cout << "\nInvalid input!" << endl;

				cout << "\nEnter a decade : ";
				cin >> option; cin.ignore();
				error = true;
			} while (option != 50 && option != 60 && option != 70 && option != 80 &&
					 option != 90 && option != 00 && option != 10);

			i = 0;
			while(i < PLAYLIST_SIZE)
			{
				if (cursor->decade == option)
				{
					current->name = cursor->name;
					current->year = cursor->year;
					current->genre = cursor->genre;
					current->artist = cursor->artist;
					current->decade = cursor->decade;
					current->ranking = cursor->ranking;
					current->performer = cursor->performer;

					if (i == PLAYLIST_SIZE - 1)
					{
						current->next_addr = NULL;
					}
					else
					{
						current->next_addr = new song;
						current = current->next_addr;
					}

					i++;
				}

				cursor = cursor->next_addr;
			}
			break;

		// Fill the play-list with songs that match
		// the user entered performer type
		case 3:
			char type;

			do
			{
				if (error)
					cout << "\nInvalid input!" << endl;

				cout << "\nEnter a performer type " <<
						"\n (F)emale, (M)ale, (D)uo/Group : ";
				cin >> type; cin.ignore();

				error = true;
			} while (toupper(type) != 'F' && toupper(type) != 'M' && toupper(type) != 'D');

			i = 0;
			while(i < PLAYLIST_SIZE)
			{
				if (cursor->performer == toupper(type))
				{
					current->name = cursor->name;
					current->year = cursor->year;
					current->genre = cursor->genre;
					current->artist = cursor->artist;
					current->decade = cursor->decade;
					current->ranking = cursor->ranking;
					current->performer = cursor->performer;

					if (i == PLAYLIST_SIZE - 1)
					{
						current->next_addr = NULL;
					}
					else
					{
						current->next_addr = new song;
						current = current->next_addr;
					}

					i++;
				}

				cursor = cursor->next_addr;
			}
			break;

		case 4:
			int genre_option;

			do
			{
				if (error)
					cout << "\nInvalid input!" << endl;

				cout << "\n  (1) Latin" <<
						"\n  (2) Country" <<
						"\n  (3) Hip-Hop/Rap" <<
						"\n  (4) Jazz" <<
						"\n  (5) Dance/Electronic" <<
						"\n  (6) R&B" <<
						"\n  (7) Pop" <<
						"\n  (8) Rock" <<
						"\nEnter a genre using the list above : ";
				cin >> genre_option; cin.ignore();

				error = true;
			} while(genre_option < 1 || genre_option > 8);

			i = 0;
			while(i < PLAYLIST_SIZE)
			{
				if (cursor->genre == genre_option)
				{
					current->name = cursor->name;
					current->year = cursor->year;
					current->genre = cursor->genre;
					current->artist = cursor->artist;
					current->decade = cursor->decade;
					current->ranking = cursor->ranking;
					current->performer = cursor->performer;

					if (i == PLAYLIST_SIZE - 1)
					{
						current->next_addr = NULL;
					}
					else
					{
						current->next_addr = new song;
						current = current->next_addr;
					}

					i++;
				}

				cursor = cursor->next_addr;
			}
			break;

		default: break; // do nothing
	}

	return playlist_head;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Insert()
//
//		input 		: a pointer to the head of the master linked-list and a
//                    pointer to the first song of the song play-list to be
//                    modified
//		output		: a pointer to the first song of the play-list
//		description : prompts user for the song to be added using its ranking
//                    from the billboard list and the position it should be
//                    placed in the play-list
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
song *Insert(song *head, song *playlist)
{
	song *cursor = head;
	song *current, *previous, *temp = new song;
	int position, ranking;

	bool error; // flag to denote when to use error statements

	current = playlist;

	error = false;
	do
	{
		if (error)
			cout << "\nInvalid input!" << endl;

		cout << "\nSong ranking from the billboard list to be inserted : ";
		cin >> ranking; cin.ignore();

		error = true;
	} while (ranking < 1 || ranking > 200);

	error = false;
	do
	{
		if (error)
			cout << "\nInvalid input!" << endl;

		cout << "\nPosition in play-list to insert song : ";
		cin >> position; cin.ignore();

		error = true;
	} while (position < 1 || position > 20);

	for (int i = 1; i < ranking; i++)
	{
		cursor = cursor->next_addr;
	}

	temp->name = cursor->name;
	temp->year = cursor->year;
	temp->genre = cursor->genre;
	temp->artist = cursor->artist;
	temp->decade = cursor->decade;
	temp->ranking = cursor->ranking;
	temp->performer = cursor->performer;

	if (position == 1)
	{
		temp->next_addr = current;
		playlist = temp;
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

	cout << "\nSong inserted!" << endl;

	return (playlist);
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Delete()
//
//		input 		: a pointer to the first song of the song play-list to
//                    be modified
//		output		: a pointer to the first song of the play-list
//		description : prompts user for the song for a position in the
//                    play-list and deletes the song at that position
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
song *Delete(song *playlist)
{
	song *current, *previous;
	int position;

	current = playlist;

	bool error = false; // flag to denote when to use error statements

	do
	{
		if (error)
			cout << "\nInvalid input!";

		cout << "\nPosition in play-list to delete song : ";
		cin >> position; cin.ignore();

		error = true;
	} while (position < 1 || position > 20);

	if (position == 1)
	{
		playlist = current->next_addr;
	}
	else
	{
		for (int i = 1; i < position; i++)
		{
			previous = current;
			current = current->next_addr;
		}
		previous->next_addr = current->next_addr;
	}

	delete(current);

	cout << "\nSong deleted!" << endl;

	return(playlist);
}
