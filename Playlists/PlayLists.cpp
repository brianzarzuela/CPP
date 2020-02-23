// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : PlayLists.cpp
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : This program allows for a user to create, edit and save
//                 multiple music play-lists using the information of the
//                 top 200 from the list of 600 songs from the 60th anniversary
//                 of Billboard magazine's "Hot 100" music chart found here:
//                 https://www.billboard.com/charts/hot-100-60th-anniversary
//
//                 The song information is read out of a billboard.txt file
//                 and placed into a master-link list utilized to create up
//                 to five play-list, each stored in a separate linked-list.
//
// Last Modified : 8 October 2018
//		- Added error control
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "PlayLists.h"

int main(void)
{
	song *main_head;
	main_head = Read();

	char menu_option;
	string playlist_option;

	// Flag for determining if the user entered play-list exists
	bool playlist_exists;

	// Count for determining when the maximum
	// number of play-lists has been created
	int playlist_count = 0;

	// Create empty play-lists array
	for (int i = 0; i < MAX; i++)
	{
		playlists[i] = new playlist;
	}

	for (;;)
	{
		cout << "\nMusic Play-List Menu:" << endl;
		cout << left << setw(20) << "  (C) Create Play-List" << endl;
		cout << left << setw(20) << "  (D) Display Play-List" << endl;
		cout << left << setw(20) << "  (M) Modify Play-List" << endl;
		cout << left << setw(20) << "  (S) Save Play-List" << endl;
		cout << left << setw(20) << "  (X) Delete Play-List" << endl;
		cout << left << setw(20) << "  (Q) Exit Program" << endl;

		cout << "Option...... : ";
		cin >> menu_option; cin.ignore();

		switch(menu_option)
		{
			// Create
			case 'C':
			case 'c':
				if (playlist_count == MAX)
				{
					cout << "Maximum number of play-lists created!\n"
						 << "Please delete a play-lists before creating a new one." << endl;
					break;
				}
				cout << "Enter a name for the new play-list : ";
				getline(cin, playlist_option);
				playlists[playlist_count] = Create(playlist_option, main_head);
				cout << "Play-list " << playlists[playlist_count]->name << " created!" << endl;
				playlist_count++;
				break;

			// Display
			case 'D':
			case 'd':
			{
				cout << "Enter the name of the play-list to display : ";
				getline(cin, playlist_option);

				playlist_exists = false;
				for (int i = 0; i < MAX; i++)
				{
					if (playlist_option.compare(playlists[i]->name) == 0 )
					{
						Display(playlists[i]->next_addr);
						playlist_exists = true;
						break;
					}
				}

				if (!playlist_exists)
					cout << "Invalid play-list name entered!" << endl;

				break;
			}

			// Modify
			case 'M':
			case 'm':
			{
				cout << "Enter the name of the play-list to modify : ";
				getline(cin, playlist_option);

				playlist_exists = false;
				for (int i = 0; i < MAX; i++)
				{
					if (playlist_option.compare(playlists[i]->name) == 0 )
					{
						playlist_exists = true;
						bool flag = true;

						while(flag)
						{
							cout << "Would you like to [i]nsert or [d]elete a song? : ";
							char modify_option;
							cin >> modify_option; cin.ignore();

							if (modify_option == 'I' || modify_option == 'i')
							{
								playlists[i]->next_addr = Insert(main_head, playlists[i]->next_addr);
								flag = false;
							}
							else if (modify_option == 'D' || modify_option == 'd')
							{
								playlists[i]->next_addr = Delete(playlists[i]->next_addr);
								flag = false;
							}
							else
							{
								cout << "Invalid input, please enter (i) or (d)!" << endl;
							}
						}

						break;
					}
				}

				if (!playlist_exists)
					cout << "Invalid play-list name entered!" << endl;

				break;
			}

			// Delete
			case 'X':
			case 'x':
			{
				cout << "Enter the name of the play-list to delete : ";
				getline(cin, playlist_option);

				playlist_exists = false;
				for (int i = 0; i < MAX; i++)
				{
					if (playlist_option.compare(playlists[i]->name) == 0 )
					{
						playlist_exists = true;

						// Move any existing play-lists down in array
						for (int j = i + 1; j < MAX; j++)
						{
							playlists[i] = playlists[j];
						}

						playlist_count--;

						break;
					}
				}

				if (!playlist_exists)
					cout << "Invalid play-list name entered!" << endl;
				else
					cout << "Play-list" << playlist_option << " deleted!" << endl;

				break;
			}

			// Save (file)
			case 'S':
			case 's':
			{
				cout << "Enter the name of the play-list to delete : ";
				getline(cin, playlist_option);

				playlist_exists = false;
				for (int i = 0; i < MAX; i++)
				{
					if (playlist_option.compare(playlists[i]->name) == 0 )
					{
						playlist_exists = true;

						Save(playlists[i]->next_addr);

						break;
					}
				}

				if (!playlist_exists)
					cout << "Invalid play-list name entered!" << endl;

				break;
			}

			// Quit
			case 'Q':
			case 'q':
				cout << "Exiting program..." << endl;
				exit(1);
				break;

			default:
				cout << "Unable to perform task.\n"
					 << "Please  be sure to enter a valid input and try again." << endl;
				break;
		}
	}

	return 0;
}
