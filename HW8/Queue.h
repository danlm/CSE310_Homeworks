// Assignment 8
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: This class implement a minimum heap
// and a priority queue.

#include <iostream> //to use cout
#include <string> //to use strings
#include <cstdlib>

using namespace std;

struct Item
{
   int index;
   int key;
};

//class Queue will contains a queue of nodes
class Queue
 {
  private:
     struct Item * heap;
     int size;

  public:
     Queue(int num);
     ~Queue();
     bool isEmpty();
     bool existsInQueue(int index);
     struct Item getMin();
     struct Item extractMin();
     void heapify(int num);
     void decreaseKey(int index, int newKey);  
     void printQueue(string *);
 };


//Constructor to initialize class level variables
Queue::Queue(int num)
 {
   heap = new struct Item[num+1];
   size = num;
   //"100" is used as untraversed
    for (int i=0; i<=num; i++)
    {        
		heap[i].key = 100;
		heap[i].index = i - 1;
	}
 }

//Destructor to remove all nodes
Queue::~Queue()
 {
   delete [] heap;
 }

//It checks if the queue is empty or not, and return true if it is, 
//false otherwise.
bool Queue::isEmpty()
 {
   if (size <= 0)
    return true;
   else
    return false;
 }
 
 //It checks if the item with the specified index is still in the queue, or already extracted.
bool Queue::existsInQueue(int index)
 {
   	for (int i=1; i<=size; i++)
    	{
        		if (heap[i].index == index)
		{
			return true;
		}
	}
	return false;
 }

//It returns the node with the smallest key without modifying heap (NULL if queue is empty)
struct Item Queue::getMin()
 {
	return heap[1];
 }

//It removes the node with the smallest key from the heap, and restores the heap property
//(NULL if queue is empty)
struct Item Queue::extractMin()
 {
    struct Item min = heap[1];
    heap[1] = heap[size];
    size--;
    /* Remove all reference to orignal items
    heap[size].index = -1;
    heap[size].key = 100;*/
    
    heapify(1);
    return min;
 }

// Edits the heap to maintain minimum heap property - push down larger items to proper place
void Queue::heapify(int num)
{
	int left = 2*num;
	int right = 2*num + 1;
	int small = num;

	// First compare left parent
	if (left <= size)
	{
		if (heap[left].key < heap[num].key)
		{
			small = left;
		}
	}
	
	// Next compare right parent
	if (right <= size)
	{
		if (heap[right].key < heap[small].key)
		{
			small = right;
		}
	}
	
	if (small != num)
	{
		struct Item temp = heap[small];
    		heap[small] = heap[num];
    		heap[num] = temp;
    		heapify(small); //Keep heapifying until entire tree is done
	}
}

// Moving up small items in the queue
void Queue::decreaseKey(int index, int newKey)
{
	for (int i=1; i<=size; i++)
    	{
        	if (heap[i].index == index)
		{
			if (newKey >= heap[i].key)
			{
				cout << "\nError. New key greater than old key." << endl;
				return;
			}
			else
			{
				heap[i].key = newKey;
				while((i > 1) && (heap[i/2].key > heap[i].key))
				{
					struct Item temp = heap[i];
    					heap[i] = heap[i/2];
    					heap[i/2] = temp;
    					i = i/2;	
				}
				return;
			}
		}
	}
}

//It prints the content of the queue
void Queue::printQueue(string * names2)
 {
   //If it is empty
   if (size <= 0) 
   {
    cout << "The list is empty\n";
   }
   else  //if it is not empty
    {
        for (int i=1; i<=size; i++)
        {
            cout << "\n " << names2[heap[i].index] << " " << heap[i].key << endl;
        }
    }
 } 
 
