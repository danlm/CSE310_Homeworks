// Assignment #5
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: Hash Table functions

#include <iostream> //to use cout
#include <string> //to use strings
#include <iomanip> //for the display function

using namespace std;

//struct Book represents some book information
class Book
 {
   public:
      string isbn;
      string title;
      string publisher;
      int collisions;
 };

//class HashTable will contains a HashTable of books
class HashTable
 {
  private:
     int size;
     Book* array;
     
  public:
     HashTable(int size);
     ~HashTable();
     bool insertElement(string someISBN, string someTitle, string somePublisher);
     void searchElement(string someISBN);
     void changeElement(string someISBN, string someTitle);
     int calculateHash(string someISBN, int trial);
     void printTable();
};

//Constructor 
//It sets up an empty array of specified size
HashTable::HashTable(int size)
 {
   this->size = size;
   this->array = new Book[size];
   for (int i = 0; i < size; i++){
      this->array[i] = Book();
      this->array[i].isbn = "none";
      this->array[i].title = "none";
      this->array[i].publisher = "none";
      this->array[i].collisions = 0;
   }
 }

//Destructor
//Description: Deletes the dynamic array.
HashTable::~HashTable()
 {
    delete [] array;
 }

//Description: Inserting a Book into the table
bool HashTable::insertElement(string someISBN, string someTitle, string somePublisher)
 {
  	int i = 0;
  	int j = 0;
  	do
  	{
  	     j = calculateHash(someISBN, i);
  	     if (this->array[j].isbn == "none"){
		this->array[j].isbn = someISBN;
		this->array[j].title = someTitle;
		this->array[j].publisher = somePublisher;
		this->array[j].collisions = i;
		return true;
  	     }
  	     ++i;	
  	}while (i < this->size);
  	return false;
 }
 
 //Description: Searching for a Book in the table
void HashTable::searchElement(string someISBN)
 {	
	bool found = false;
  	for (int i = 0; i < this->size; i++)
    	{
  	    /*int j = calculateHash(someISBN, i);	 
	    if (this->array[j].isbn == someISBN){
  	     	return &(this->array[j]);
  	    } */
	    if (this->array[i].isbn == someISBN){
  	     	cout << this->array[i].isbn << " is for the title: " << this->array[i].title << " by the publisher " << this->array[i].publisher << endl;
		found = true;
		break;
  	    }
  	}
  	if(!found){
	  cout << someISBN << " not found" << endl;
	}
 }
 
  //Description: Changing the title of a Book in the table
void HashTable::changeElement(string someISBN, string someTitle)
 {
  	bool found = false;
  	for (int i = 0; i < this->size; i++)
    	{
  	    /*int j = calculateHash(someISBN, i);	 
	    if (this->array[j].isbn == someISBN){
  	     	return &(this->array[j]);
  	    } */
	    if (this->array[i].isbn == someISBN){
  	     	cout << this->array[i].title << " with isbn " << this->array[i].isbn << " updated" << endl;
		found = true;
		break;
  	    }
  	}
  	if(!found){
	  cout << someISBN << " not found" << endl;
	}
 }
 
   //Description: Calculate the hash of a potential array element
int HashTable::calculateHash(string someISBN, int trial)
 {
  	int hash = 0;
  	int key = 0;
  	for (int i = 0; i < someISBN.length(); i++)
    	{
        	char x = someISBN.at(i);
        	key += int(x);
    	}
    	// First hash function
  	hash = key % this->size;
  	
  	// Second hash function
  	hash += (trial * (1 + (key % (this->size)-2)));
	hash %= this->size;
	if (hash < 0){
	  hash += this->size;
	}
  	//cout << hash << endl;
  	return hash;
 }
 
   //Description: Display the contents of the table
void HashTable::printTable()
 {
  	int counter = 0;
  	cout << fixed;
    	cout << setw(6) << left << "Index" << setw(11) << "Collisions" << setw(18) << "ISBN" << setw(30) << "Publisher" << setw(30) << "title" << endl;
  	for (int i=0; i<this->size; i++) {
	  cout << setw(6) << left << i << setw(11) << this->array[i].collisions << setw(18) << this->array[i].isbn << setw(30) << this->array[i].publisher << setw(30) << this->array[i].title << endl;
  	}
  	 cout << "\n";
 }
 