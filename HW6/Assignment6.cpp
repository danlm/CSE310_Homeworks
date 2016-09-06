// Assignment #6
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: This program displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream> //to use cin and cout
#include <string> //to use strings
#include <cstdlib> //to use string functions
#include "BinarySearchTree.h"

using namespace std;

void printMenu();

int main()
   {
       // instantiate a Binary Tree object
       BinarySearchTree * tree1 = new BinarySearchTree();

       char input1;
       bool success = false;
       string line, inputStr, firstname, lastname, phonenumber;
       PhoneInfo * temp; //it will be used to hold a returned the input info

       printMenu();

       do  // will ask for user input
        {
           cout << "What action would you like to perform?\n";
           cin.get(input1);
           input1 = toupper(input1);
           cin.ignore(20, '\n'); //flush the buffer
           // matches one of the case lastnamement
           switch (input1)
            {
             case 'A':   //Inorder Print
               tree1->inOrderTreePrint();               
               break;
             case 'B':   //Preorder Print
               tree1->preOrderTreePrint(); 
               break;
             case 'C':   //Postorder Print
               tree1->postOrderTreePrint(); 
               break;
             case 'D':   //Tree Minimum
               temp = tree1->treeMinimum();
               if (temp == NULL)
                 cout << "tree is empty" << endl;
               else
                {
                 cout << "The first person is ";
                 temp->print();
                 cout  << endl;
                }
               break;
             case 'E':   //Tree Maximum
               cout << "The last person is ";
               temp = tree1->treeMaximum();
               if (temp == NULL)
                 cout << "tree is empty" << endl;
               else
                {
                 temp->print(); 
                 cout << endl;
                }
               break;
             case 'F':   //Tree Predecessor
               cout << "Please enter a firstname and a lastname to find its predecessor:\n";
               cout << "Enter a firstname\n";
               getline(cin,firstname);
               cout << "Enter a lastname\n";
               getline(cin,lastname);

               temp = tree1->treePredecessor(firstname, lastname);
               if (temp == NULL)
                 cout << firstname << " "
                      << lastname << " does not have any predecessor\n";
               else
                {
                 cout << "The predecessor of "
                      << firstname << " "<< lastname << " is ";
                 temp->print();
                 cout << endl; 
                }
               break;
             case 'G':   //Tree Successor
               cout << "Please enter a firstname and a lastname to find its successor:\n";
               cout << "Enter a firstname\n";
               getline(cin,firstname);
               cout << "Enter a lastname\n";
               getline(cin,lastname);

               temp = tree1->treeSuccessor(firstname, lastname);
               if (temp == NULL)
                   cout << firstname << " "
                   << lastname << " does not have any successor\n";
               else
                {
                    cout << "The successor of "
                    << firstname << " "<< lastname << " is ";
                    temp->print();
                    cout << endl;
                }
               break;
             case 'H':   //Tree Search
               cout << "Please enter a firstname and a lastname to search:\n";
               cout << "Enter a firstname\n";
               getline(cin,firstname);
               cout << "Enter a lastname\n";
               getline(cin,lastname);

               temp = tree1->treeSearch(firstname, lastname);
               if (temp != NULL)
                   cout << firstname << " "<< lastname << " has phonenumber of "
                        << temp->getphonenumber() << "\n";
               else
                   cout << firstname << " "<< lastname
                        << " not found\n";
               break;
             case 'I':   //Tree Insert
               cout << "Please enter a firstname/lastname/phonenumber to insert:\n";
               cout << "Enter a firstname\n";
               getline(cin,firstname);
               cout << "Enter a lastname\n";
               getline(cin,lastname);
               cout << "Enter a phonenumber\n";
               getline(cin,phonenumber);

               success = tree1->treeInsert(firstname,lastname,phonenumber);

               if (success == true)
                 cout << firstname << " "<< lastname << " with phonenumber of "
                      << phonenumber << " inserted\n";
               else
                 cout << firstname << " "<< lastname << " with phonenumber of "
                      << phonenumber << " not inserted\n";
               break;
             case 'J':  //Tree Delete
               cout << "Please enter a firstname and a lastname to delete:\n";
               cout << "Enter a firstname\n";
               getline(cin,firstname);
               cout << "Enter a lastname\n";
               getline(cin,lastname);
                    
               success = tree1->treeDelete(firstname, lastname);
               if (success == true)
                  cout << firstname << " "<< lastname << " deleted\n";
               else
                  cout << firstname << " "<< lastname << " not deleted\n";
               break;
             case 'Q':   //Quit
               delete tree1;
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
     cout << "A\t\tInorder Print\n";
     cout << "B\t\tPreorder Print\n";
     cout << "C\t\tPostorder Print\n";
     cout << "D\t\tTree Minimum\n";
     cout << "E\t\tTree Maximum\n";
     cout << "F\t\tTree Predecessor\n";
     cout << "G\t\tTree Successor\n";
     cout << "H\t\tTree Search\n";
     cout << "I\t\tTree Insert\n";
     cout << "J\t\tTree Delete\n";
     cout << "Q\t\tQuit\n";
     cout << "?\t\tDisplay Help\n\n";
  }


