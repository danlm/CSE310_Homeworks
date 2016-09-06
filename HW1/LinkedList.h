// Assignment #1
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: To be completed

#include <iostream> //to use cout
#include <string> //to use strings

using namespace std;

//struct Book represents some book information
struct Book
 {
  string title;
  string isbn;
  struct Book * next;
 };

//class LinkedList will contains a linked list of books
class LinkedList
 {
  private:
     struct Book * head;

  public:
     LinkedList();
     ~LinkedList();
     bool addElement(string title, string isbn);
     bool removeElement(string isbn);
     void printList();
 };

//Constructor 
//It sets head to be NULL to create an empty linked list
LinkedList::LinkedList()
 {
   head = NULL;
 }

//Destructor
//Description: ...... to be completed
LinkedList::~LinkedList()
 {
    //Set up a counter
	int counter = 0;
	struct Book * current = head;
	struct Book * temp;
	while (current)
	{
		++counter;
		temp = current->next;
		delete current;
		current = temp;
	}
	cout << "\nThe number of deleted books is: " << counter << endl;
 }

//Description: .... to be completed
bool LinkedList::addElement(string newTitle, string newISBN)
 {
    //Create new entry
	struct Book * newEntry;
	newEntry = new Book;

	newEntry->title = newTitle;
	newEntry->isbn = newISBN;
	
	//find its place
	if(!head){
		head = newEntry;
		return true;
	}
	else if(newTitle.compare(head->title) == 0)//DO NOT duplicate the head
	{
		delete newEntry;		
		return false;
	}
	else if(newTitle.compare(head->title) > 0)//Comes first in alphabetical order
	{
		newEntry->next = head;
		head = newEntry;
		return true;
	}
	else 
	{
		struct Book *prev,*temp;
		prev = head;
		temp = prev->next;
		while(temp){
			if(temp->title.compare(newTitle) == 0) // Matches an existing entry
			{
				delete newEntry;				
				return false;
			}
			else if(temp->title.compare(newTitle) < 0) //New entry comes before current entry
			{
				newEntry->next = temp;
				prev->next = newEntry;
				return true;
			}
			prev = prev->next;
			temp = temp->next;
		}
		prev->next = newEntry; // Add to the end of the list
		return true;
	}
 }

//Description: .... to be completed
bool LinkedList::removeElement(string someISBN)
 {
    //To be complete
	if(!head){
		return false;
	}
	else if(head->isbn.compare(someISBN) == 0)
	{
		struct Book * temp = head;
		head = head->next;
		delete temp;
		return true;
	}
	else 
	{
		struct Book *prev,*temp;
		prev = head;
		temp = prev->next;
		while(temp){	
			if(temp->isbn.compare(someISBN) == 0) // Matches an existing entry
			{
				prev->next = temp->next;
				delete temp;
				return true;
			}
			prev = prev->next;
			temp = temp->next;
		}
	}
	return false;
 } 

//Description: .... to be completed
void LinkedList::printList()
 {
   //Start from head, and print info for each node
   struct Book * temp = head;
   while(temp){
	   cout << "\nBook Title: " << temp->title << endl;
	   cout << "Book ISBN: " << temp->isbn << endl;
	   temp = temp->next;
   }
 }

