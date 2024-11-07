
// Name: Anna Mairaj
// Compiler:  g++ 
// File type: header file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;  // int for now but can change later

// A list node is defined here as a struct Node
struct Node
{
    el_t Elem;   // elem is the element stored
    Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
protected:
    Node *Front;       // pointer to the front node
    Node *Rear;        // pointer to the rear node
    int  Count;        // counter for the number of nodes

    // Utility function to move to a specified node position
    void moveTo(int, Node*&);  

public:
    // Exception handling classes 
    class Underflow {};  // thrown when attempting to access an element from an empty list
    class OutOfRange {}; // thrown when the specified node is out of range

    // Constructor to create a list object
    llist();     
    // Destructor to destroy all nodes
    ~llist();     

    // PURPOSE: Checks if the list is empty
    // PARAMETER: None
    bool isEmpty();  
    
    // PURPOSE: Displays all elements in the list
    // PARAMETER: None
    void displayAll();  

    // PURPOSE: Adds an element to the front of the list
    // PARAMETER: NewNum - the element to be added to the front
    void addFront(el_t NewNum);  
    
    // PURPOSE: Adds an element to the rear of the list
    // PARAMETER: NewNum - the element to be added to the rear
    void addRear(el_t NewNum);  

    // PURPOSE: Deletes the front element of the list
    // PARAMETER: OldNum - reference to store the deleted element
    void deleteFront(el_t& OldNum);  

    // PURPOSE: Deletes the rear element of the list
    // PARAMETER: OldNum - reference to store the deleted element
    void deleteRear(el_t& OldNum);  

    //---------------------------------------

    // PURPOSE: Deletes the Ith element of the list
    // PARAMETER: I - the position of the element to be deleted
    //            OldNum - reference to store the deleted element
    void deleteIth(int I, el_t& OldNum);  

    // PURPOSE: Inserts an element at the Ith position of the list
    // PARAMETER: I - the position to insert the new element
    //            newNum - the element to be inserted
    void insertIth(int I, el_t newNum);   

    // Copy Constructor to allow pass by value and return by value of a llist
    llist(const llist& Original);  
    
    // Overloading of = (returns a reference to a llist)
    llist& operator=(const llist& OtherOne); 
};
