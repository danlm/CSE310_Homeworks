// Assignment 8
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: This program displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream>
#include <string>
#include <cstdlib>
#include "Graph.h"
using namespace std;

bool extractData(string, Graph *);

int main()
   {
       // local variables, can be accessed anywhere from the main method
       string line;
       Graph * graph1;
       bool success = false, notDone = true;
       string sizeStr, nextLine;
       int size;
       
       getline(cin, sizeStr);
       size = atoi(sizeStr.c_str());

       //instantiate a Graph object
       graph1 = new Graph(size);
       getline(cin,nextLine, '\n'); //process a blank line
       do  
        {
          getline(cin, line, '\n'); //read in one line including edges and their weight 
   
          //process the information in each line to populate the graph
          success = extractData(line, graph1);

          if (success == false)
             notDone = false;
        } while (notDone);
	
       //perform prim's algorithm
       graph1->prim();

       delete graph1;

       return 0;
   }

 //extractData uses the parameter string containing 
 //a from node, and its adjacent nodes with their weight,
 //to extract information and store the edge information
 //to the second paramer graph
 bool extractData(string line, Graph * graph1)
  {
   //The string line does not have information that we need
   if (line.length() < 3)
    return false;

   string startNode = "";
   string endNode = "";
   string weightStr = "";
   int startIndex, endIndex, weight = 0;
   int i = 0;
   //if a character is of alphabet
   //create the startNode (fromNode)
   while ( i < line.length() && 
           ((line.at(i) >= 65 && line.at(i) <= 90)
         || (line.at(i) >= 97 && line.at(i) <= 122)) )
    {
      startNode.push_back(line.at(i));
      i++;
    }

   try
    {
     //get the index for the start node
     startIndex = (static_cast<int> (startNode.at(0))) - 65;
    }
   catch(...)
    {
     startIndex = -1;
    }

   //keep reading characters until the end of the line
   do 
    {   
      endNode = "";
      weightStr = "";

      //keep skipping none alphabet
      while (i < line.length() && isalpha(line.at(i)) == false)
       {
         i++;
       }
    
      //get an end node until a slash
      while (i < line.length() && line.at(i) != '/')
      {
        endNode.push_back(line.at(i));
        i++;
      }

     try
      {
       //get the index of the end node
       endIndex = (static_cast<int> (endNode.at(0))) - 65;
      }
     catch(...)
      {
       endIndex = -1;
      }
 
     i++; //skip '/'

     //keep reading until a space
     while (i < line.length() && line.at(i) != ' ')
      {
        weightStr.push_back(line.at(i));
        i++;
      }

     try
      {
       //convert a string containing number into a number
       weight = atoi(weightStr.c_str());
      }
     catch(...)
      {
       weight = 0;
      }

     if (i < line.length()) 
      i++; //skip a space ' '

     //Add an edge using the information 
     graph1->insertEdge(startIndex, endIndex, weight, startNode);
   } while (i < line.length()); 
   //end of while loop for length
 
   return true;
  }
 
