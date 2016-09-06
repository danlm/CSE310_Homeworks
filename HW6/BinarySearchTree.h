// Assignment #6
// Name: Daniel Martin
// ASU Email Address: dlmart11@asu.edu
// Description: To be completed

#include <iostream> //to use cout
#include <string> //to use strings

using namespace std;

//PhoneInfo represents a combination of firstname, lastname, and phonenumber
class PhoneInfo
 {
  private: 
    string firstname, lastname, phonenumber;
    PhoneInfo * left, * right, * parent;

  public:
    //The following three functions are constructors
    PhoneInfo()
     { 
      firstname = "?";
      lastname = "?";
      phonenumber = "?";
      parent = NULL;
      left = NULL;
      right = NULL;
     }

    PhoneInfo(string firstname1, string lastname1, string phonenumber1)
     {
      phonenumber = phonenumber1;
      firstname = firstname1;
      lastname = lastname1;
      parent = NULL;
      left = NULL;
      right = NULL;
     }
     PhoneInfo(string firstname1, string lastname1)
     {
       phonenumber = "?";
       firstname = firstname1;
       lastname = lastname1;
       parent = NULL;
       left = NULL;
       right = NULL;
     }
    //The following three functions are accessor functions
    PhoneInfo * getLeft()
     {
      return left;
     }

    PhoneInfo * getRight()
     {
      return right;
     }

    PhoneInfo * getParent()
     {
      return parent;
     }
     
    string getfirstname()
     {
         return firstname;
     }
    string getlastname()
     {
         return lastname;
     }
    string getphonenumber()
     {
         return phonenumber;
     }
    //The following three functions are mutator functions
    void setLeft(PhoneInfo * other)
     {
       left = other;
     }

    void setRight(PhoneInfo * other)
     {
       right = other;
     }

    void setParent(PhoneInfo * other)
     {
       parent = other;
     }

     //The print method prints the firstname, lastname, and phonenumber
    void print()
     {
         cout << firstname << " " << lastname << " with phone number of " << phonenumber << endl;
     }

   //you can add more functions
   
   //See whether the current info is greater or less than other
   int compareInfo(PhoneInfo * other)
   {
   	int result = 0;
   	//cout << "\n" << this->lastname.compare(other->lastname) << endl;
   	if (this->lastname.compare(other->lastname) < 0){ // If the other lastname comes after alphabetically
   		result = 1;
   	}
   	else if (this->lastname.compare(other->lastname) > 0){ // If the other lastname comes before alphabetically
   		result = -1;
   	}
   	else // They are equal, so use first name
   	{
   		//cout << "\n" << this->firstname.compare(other->firstname) << endl;
   		if (this->firstname.compare(other->firstname) < 0){ // If the other firstname comes after alphabetically
   			result = 1;
   		}
   		else if (this->firstname.compare(other->firstname) > 0){ // If the other lastname comes before alphabetically
   			result = -1;
   		}	
   	}
   	//cout << "\n" << result << endl;
   	return result;
   }
   
   int compareInfo(string firstname1, string lastname1) // overloaded comparison - in case you only have name info
   {
   	int result = 0;
   	//cout << "\n" << this->lastname.compare(lastname) << endl;
   	if (this->lastname.compare(lastname1) < 0){ // If the other lastname comes after alphabetically
   		result = 1;
   	}
   	else if (this->lastname.compare(lastname1) > 0){ // If the other lastname comes before alphabetically
   		result = -1;
   	}
   	else // They are equal, so use first name
   	{
   		//cout << "\n" << this->firstname.compare(firstname) << endl;
   		if (this->firstname.compare(firstname1) < 0){ // If the other firstname comes after alphabetically
   			result = 1;
   		}
   		else if (this->firstname.compare(firstname1) > 0){ // If the other lastname comes before alphabetically
   			result = -1;
   		}	
   	}
   	//cout << "\n" << result << endl;
   	return result;
   }
 }; //end of PhoneInfo class

//class BinarySearchTree will contains cities
class BinarySearchTree
 {
  private:
     PhoneInfo * root;

  public:
     BinarySearchTree();
     ~BinarySearchTree();
     bool isEmpty();
     void inOrderTreePrint();
     void preOrderTreePrint();
     void postOrderTreePrint();
     void inOrderTreeWalk(PhoneInfo *);
     void preOrderTreeWalk(PhoneInfo *);
     void postOrderTreeWalk(PhoneInfo *);
     PhoneInfo * treeMinimum();
     PhoneInfo * treeMaximum();
     PhoneInfo * treeSuccessor(string,string);
     PhoneInfo * treePredecessor(string,string);
     PhoneInfo * treeSearch(string, string);
     bool treeInsert(string,string,string);
     void transplant(PhoneInfo *, PhoneInfo *);
     bool treeDelete(string,string);
     int treeDestruct(PhoneInfo *);
 };

//The constructor initialize the root to be NULL
BinarySearchTree::BinarySearchTree()
 {
  root = NULL;
 }

//The destructor should delete all nodes in the tree 
//and perform garbage collections starting from leaves (bottom-up order). 
//The destructor should also print “The number of nodes deleted: X” 
//where X is the number of nodes deleted
BinarySearchTree::~BinarySearchTree()
 {
	cout << "\n" << "The number of nodes deleted: " << this->treeDestruct(this->root) << endl;
 }


//isEmpty() return true if the tree is empty, false otherwise
bool BinarySearchTree::isEmpty()
 {
   if (root == NULL)
    return true;
   else
    return false; 
 }

//prints all nodes using in-order starting from root
//and in-order walk function
void BinarySearchTree::inOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    inOrderTreeWalk(root);
    cout << "\n";
   }
 }

//it prints all nodes using pre-order starting from root
//and pre-order walk function
void BinarySearchTree::preOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    preOrderTreeWalk(root);
    cout << "\n";
   }
 }

//it prints all nodes using post-order starting from root
//and post-order walk
void BinarySearchTree::postOrderTreePrint()
 {
  if (isEmpty())
    cout << "tree is empty" << endl;
  else
   {
    cout << "\n";
    postOrderTreeWalk(root);
    cout << "\n";
   }
 }

//print nodes under the parameter x using in-order
void BinarySearchTree::inOrderTreeWalk(PhoneInfo * x)
 {
	if (x != NULL) {
		this->inOrderTreeWalk(x->getLeft());
		x->print();
		this->inOrderTreeWalk(x->getRight());
	}
 }

//print nodes under the parameter x using pre-order
void BinarySearchTree::preOrderTreeWalk(PhoneInfo * x)
 {
	if (x != NULL) {
		x->print();
		this->preOrderTreeWalk(x->getLeft());
		this->preOrderTreeWalk(x->getRight());
	}
 }

//print nodes under the parameter x using post-order
void BinarySearchTree::postOrderTreeWalk(PhoneInfo * x)
 {
	if (x != NULL) {
		this->postOrderTreeWalk(x->getLeft());
		this->postOrderTreeWalk(x->getRight());
		x->print();
	}
 }

//Using the strint parameter of firstname and lastname, it returns 
//its phonenumber information (node) within the tree if found
//return NULL if not found
PhoneInfo * BinarySearchTree::treeSearch(string firstname, string lastname)
 {
	PhoneInfo *x = this->root;
	while ((x != NULL) && (x->compareInfo(firstname, lastname) != 0)) {
		switch (x->compareInfo(firstname, lastname)) {
		 	case -1:
				x = x->getLeft();
				break;
			case 1:
				x = x->getRight();
				break;
		}
	}
	return x;
 }


//Searches and returns the node with the minimum key within the tree
PhoneInfo * BinarySearchTree::treeMinimum()
 {
	PhoneInfo *x = this->root;
	while (x->getLeft() != NULL) {
		x = x->getLeft();
	}
	return x;
 }

//Searches and returns the node with the maximum key within the tree
PhoneInfo * BinarySearchTree::treeMaximum()
 {
	PhoneInfo *x = this->root;
	while (x->getRight() != NULL) {
		x = x->getRight();
	}
	return x;
 }

//Searches and returns the successor of the parameters firstname and lastname
PhoneInfo * BinarySearchTree::treeSuccessor(string firstname, string lastname)
 {
	PhoneInfo *x = this->treeSearch(firstname, lastname);
	if (x != NULL){
		if (x->getRight() != NULL){
			x = x->getRight();
			while (x->getLeft() != NULL) {
				x = x->getLeft();
			}
		}
		else{
			PhoneInfo *y =x->getParent();
			while ((y != NULL) && (x == y->getRight())) {
				x = y;
				y = y->getParent();
			}
			return y;
		}
	}
	return x;
 }

//Searches and returns the predecessor of the parameter firstname and lastname
PhoneInfo * BinarySearchTree::treePredecessor(string firstname, string lastname)
 {
	PhoneInfo *x = this->treeSearch(firstname, lastname);
	if (x != NULL){
		if (x->getLeft() != NULL){
			x = x->getLeft();
			while (x->getRight() != NULL) {
				x = x->getRight();
			}
		}
		else{
			PhoneInfo *y =x->getParent();
			while ((y != NULL) && (x == y->getLeft())) {
				x = y;
				y = y->getParent();
			}
			return y;
		}
	}
	return x;
 }

//It inserts the parameter firstname, lastname phonenumber
//and returns true if successful, false otherwise
bool BinarySearchTree::treeInsert(string firstname, string lastname, string phonenumber)
 {
	PhoneInfo *z = new PhoneInfo(firstname, lastname, phonenumber);
	PhoneInfo *y = NULL;
	PhoneInfo *x = this->root;
	while (x != NULL) {
		y = x;
		if (y->compareInfo(z) < 0) {
			x = x->getLeft();	
		}
		else {
			x = x->getRight();
		}
	}
	z->setParent(y);
	if (y == NULL){
		this->root = z;
	}
	else{
		if (y->compareInfo(z) < 0) {
			y->setLeft(z);	
		}
		else {
			y->setRight(z);
		}
	}
 }

//It replaces one subtree rooted at node u with
//the sub tree rooted at node v within the tree
void BinarySearchTree::transplant(PhoneInfo * u, PhoneInfo * v)
 {
	if (u->getParent() == NULL) {
		this->root = v;
	}
	else if (u == u->getParent()->getLeft()) {
		u->getParent()->setLeft(v);
	}
	else {
		u->getParent()->setRight(v);
	}
	
	if(v != NULL) {
		v->setParent(u->getParent());
	}
 }

//It deletes the node specified by the parameters firstname and lastname
//and deletes and returns true if it is found in the tree
//It returns false if not found
bool BinarySearchTree::treeDelete(string firstname, string lastname)
 {
	// Find the node to be deleted
	bool nodeFound = false;
	PhoneInfo *z = this->treeSearch(firstname, lastname);
	
	// Delete if node is found
	if (z != NULL) {
		nodeFound = true;
		if (z->getLeft() == NULL){
			this->transplant(z, z->getRight());
		}
		else if (z->getRight() == NULL){
			this->transplant(z, z->getLeft());
		}
		else{
			PhoneInfo *y = this->treeSuccessor(z->getfirstname(), z->getlastname());
			
			if (z != y->getParent()) {
				this->transplant(y, y->getRight());
				y->setRight(z->getRight());
				y->getRight()->setParent(y);
			}
			
			this->transplant(z,y);
			y->setLeft(z->getLeft());
			y->getLeft()->setParent(y);
		}
	}
	
	return nodeFound;
 }


//You can add more functions

// Recursive helper function for destructor
int BinarySearchTree::treeDestruct(PhoneInfo *x) 
{
	int deleted = 0;
	if (x != NULL) {
		deleted += this->treeDestruct(x->getLeft());
		deleted += this->treeDestruct(x->getRight());
		delete x;
		++deleted;
	}
	return deleted;
}


