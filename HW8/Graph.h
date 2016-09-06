// Assignment 8
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: This file defines a data structure for a graph.
// including vertices(nodes) and edges

#include <iostream> //to use cout
#include <string> //to use strings
#include "Queue.h" //to use FIFO queue
using namespace std;

class Graph
 {
  private:
    int vertexNum;
    int ** adjMatrix; 
    int * parent;
    int * key;
    Queue * queue1;
    string * names;

  public: 
    
    //Constructor create an adjacency list (an array of linked list) 
    //and initialize all variables
    Graph(int size)
     {
       vertexNum = size;
       adjMatrix = new int*[vertexNum];
       parent = new int[vertexNum];
       key = new int[vertexNum];
       queue1 = new Queue(vertexNum);
       names = new string[vertexNum];

       //"-1" is used as no information such as nil/null
       for (int i=0; i<vertexNum; i++)
        {
          adjMatrix[i] = new int[vertexNum];
          parent[i] = -1;
          key[i] = -1;
          names[i] = "none";
          for (int j=0; j<vertexNum; j++)
            adjMatrix[i][j] = -1;
        }
     }

    //Destructor
    ~Graph()
     {
          for (int j=0; j<vertexNum; j++)
              delete [] adjMatrix[j];
          delete [] adjMatrix;
          delete [] parent;
          delete [] key;
          delete [] names;
          delete queue1;
     }

    //inserts the edge into the adjacency matrix using two nodes
    //and its weight
    void insertEdge(int nodeU, int nodeV, int weight, string fromNode)
     {
      if (nodeU != -1 && nodeV != -1)
       {
         adjMatrix[nodeU][nodeV] = weight;
       }
      if (nodeU != -1)
         names[nodeU] = fromNode;
     }

    
    //deletes the edge information in the adjacency matrix
    //-1 means no edge
    void deleteEdge(int nodeU, int nodeV)
     {
      adjMatrix[nodeU][nodeV] = -1;
     }

    //prints the content of the graph
    void printGraph()
     {
	queue1->printQueue(names);       
	for (int i=0; i<vertexNum; i++)
        {
          cout << names[i] << ": \t";
          for (int j=0; j<vertexNum; j++)
           {
             cout << names[j] << "(" << adjMatrix[i][j] << ")";
             cout << "\t";
           }
          cout << endl;
        }

     }

   //prints the parent and key arrays
   void printArrays()
    {
     cout << "The array pi content:\n\n";
     for (int i=0; i<vertexNum; i++)
      {
       if (parent[i] < 0)
        cout << "pi[" << names[i] << "]= " << "none" << endl;
       else
        cout << "pi[" << names[i] << "]= " << names[parent[i]] << endl;
      }
     cout << endl;

     cout << "The array key content:\n\n";
     for (int i=0; i<vertexNum; i++)
      {
       cout << "key[" << names[i] << "]=" << key[i] << endl;
      }

     cout << endl; 
    }
 
    //This performs Prim's Algorithm to find the MST
   void prim()
    {
     cout << "\nThe minimum spanning tree produced by the Prim's algorithm consists of the following edges: \n\n";
     key[0] = 0; // Set initial distance to 0
     int total = 0; //Store the total MST weight
	 queue1->decreaseKey(0, key[0]);
	      //for each vertex in the graph which has not been visited
        while (queue1->isEmpty() == false)
        {
            struct Item u = queue1->extractMin();
	    if (u.index != 0)
	    {			
		cout << names[parent[u.index]] << " -> " << names[u.index] << " with key " << u.key << endl;
	    } 
	    total += u.key;
            for (int i = 0;i < vertexNum;i++)
            {
                //check all adjacent nodes of u
                if ((adjMatrix[u.index][i] > -1) && (queue1->existsInQueue(i)))
                {
                    if ((adjMatrix[u.index][i] < key[i]) || (key[i] < 0)) 
		    {
			     key[i] = adjMatrix[u.index][i];
		             parent[i] = u.index;
		             queue1->decreaseKey(i, key[i]);
		    }// end of if
                }
	    } //end of for

        } //end of while
 
     //print the parent and key arrays
     cout << "\nThe total weight of the minimum spanning tree is " << total << endl;
     cout << endl;
     printArrays();
    } //end of function
 };
 
