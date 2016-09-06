// Assignment #5
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: Hash Table driver

/*
Hash function = (h1 + h2) mod size
where h1 = key % size  [key = sum of ASCII values in string]
and   h2 = trial * (1 + (key % (size-2)))
A condition was included at the end to deal with C++'s ability to return negative mod values.
if (hash < 0){
	  hash += size;
	}
*/

#include "HashTable.h"
#include <sstream>
#include <iostream> //to use cout
#include <string> //to use strings

using namespace std;

int main ()
{
	int tableSize;
	cin >> tableSize;
	HashTable *sample = new HashTable(tableSize);
	string testISBN;
	string testTitle;
	string testPublisher;
	string status;
	bool didInsert = false;
	Book *current;
	char split_char = '/';
	
	cin.ignore(20, '\n');
	getline(cin, status);
	if (status == "Insertion"){
		getline(cin, status);
		while (status != "Search"){
			istringstream split(status);
			getline(split, testISBN, split_char);
			getline(split, testTitle, split_char);
			getline(split, testPublisher, split_char);
			didInsert = sample->insertElement(testISBN, testTitle, testPublisher);
			if(!didInsert){
			  cout << "Error. Could not insert " << testTitle << ". Table full." << endl;
			}
			getline(cin, status);
		}
		sample->printTable();
	} 
	if (status == "Search"){
		getline(cin, status);
		while (status != "Change"){
			testISBN = status;
			sample->searchElement(testISBN);
			getline(cin, status);
		}
	} 
	if (status == "Change"){
		getline(cin, status);
		while (status != "Display"){
			istringstream split(status);
			getline(split, testISBN, split_char);
			getline(split, testTitle, split_char);
			sample->changeElement(testISBN, testTitle);
			getline(cin, status);
		}
	}
	cout << "\n";
	sample->printTable(); 
}


