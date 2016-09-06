// Assignment #1
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: This program displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
   {
       // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       string inputInfo;
       string title, isbn;
       string line;
       bool success = false;

       // instantiate a Linked List object
       LinkedList * list1 = new LinkedList();

       printMenu();


       do  // will ask for user input
        {
           cout << "What action would you like to perform?\n";
           cin.get(input1);
           input1 = toupper(input1);
           cin.ignore(20, '\n'); //flush the buffer
           // matches one of the case statement
           switch (input1)
            {
             case 'A':   //Add Book
               cout << "Please enter a book information:\n";
               cout << "Enter a book title:\n";
               getline(cin,title);
               
               cout << "Enter its ISBN:\n";
               getline(cin,isbn);

               success = list1->addElement(title, isbn);
     
               if (success == true)
                cout << "The book " << title << " added\n";
               else
                cout << "The book " << title << " exists\n";
               break;
             case 'D':   //Display Books
               list1->printList();
               break;
             case 'Q':   //Quit
               delete list1;
               break;
             case 'R':  //Remove Book
               cout << "Please enter a book ISBN to remove:\n";
               getline(cin,isbn);

               success = list1->removeElement(isbn);
               if (success == true)
                cout << "A book with ISBN " << isbn << " removed\n";
               else
                cout << "A book with ISBN " << isbn << " does not exist\n";
               break;
             case '?':   //Display Menu
               printMenu();
               break;
             default:
               cout << "Unknown action\n";
               break;
            }

        } while (input1 != 'Q');

      return 0;
   }


  /** The method printMenu displays the menu to a user**/
  void printMenu()
   {
     cout << "Choice\t\tAction\n";
     cout << "------\t\t------\n";
     cout << "A\t\tAdd Book\n";
     cout << "D\t\tDisplay Books\n";
     cout << "Q\t\tQuit\n";
     cout << "R\t\tRemove Book\n";
     cout << "?\t\tDisplay Help\n\n";
  }


