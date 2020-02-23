// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title 		 : PlayLists.h
// Course 		 : Computational Problem Solving II (CPET-321)
// Developer 	 : Brian Zarzuela
// Date 		 : Fall 2019 (2191)
// Description   : Header file for PlayLists.cpp
//
// Last Modified : 19 September 2019
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef PLAYLISTS_H_
#define PLAYLISTS_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

// Song struct for storing each song's seven (7) data fields:
// NOTE: Keys for performer and genre type below
// - performer:
//		F) Female
//		M) Male
//		D) Duo
//		G) Group
// - genre:
//		1) latin
//		2) country
//		3) hip-hop / rap
//		4) jazz
//		5) dance / electronic
//		6) r & b
//		7) pop
//		8) rock
struct song
{
	string name;	// song name
	string artist;
	int ranking;	// billboard top 100 ranking
	int year;		// year released
	int decade;
	char performer;
	int genre;
	song *next_addr;
};

struct playlist
{
	string name;		// play-list name
	song *next_addr;	// first song in play-list
};

// Maximum number of play-lists to be created by the user
const int MAX = 5;

// Play-list array declaration for storing MAX number of play-lists heads
extern struct playlist *playlists[MAX];

song *Read();

playlist *Create(string playlist_name, song *head);

void Save(song *head);

void Display(song *head);

// Modify split into two functions:
// Insert() and Delete()
song *Insert(song *head, song *playlist);

song *Delete(song *playlist);

#endif /* PLAYLISTS_H_ */
