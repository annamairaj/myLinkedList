//Name: Anna Mairaj
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

// Constructor to create a list object
llist::llist() : Front(nullptr), Rear(nullptr), Count(0) {
    cout << "... in llist constructor..." << endl;
}

// Destructor to destroy all nodes
llist::~llist() {
    cout << ".... in llist destructor..." << endl;
    while (!isEmpty()) {
        el_t temp;
        deleteFront(temp); // Deleting all nodes by calling deleteFront
    }
}

// PURPOSE: Checks if the list is empty
// PARAMETER: None
bool llist::isEmpty() {
    return (Front == nullptr && Rear == nullptr && Count == 0);
}

// PURPOSE: Displays all elements in the list
// PARAMETER: None
void llist::displayAll() {
    if (isEmpty()) {
        cout << "[ empty ]" << endl; // Special case for empty list
        return;
    }

    Node* current = Front; // Pointer to traverse the list
    cout << "[ ";
    while (current != nullptr) { // Loop through the list
        cout << current->Elem; // Print the element
        current = current->Next; // Move to the next node
        if (current != nullptr) cout << " "; // Space between elements
    }
    cout << "]" << endl; // End the display
}

// PURPOSE: Adds an element to the rear of the list
// PARAMETER: NewNum - the element to be added to the rear
void llist::addRear(el_t NewNum) {
    // Case 1: Special case for the very first node
    if (isEmpty()) {
        Front = new Node; // Create a new node
        Front->Elem = NewNum; // Set the element
        Front->Next = nullptr; // Next points to null
        Rear = Front; // Front and Rear point to the same node
        Count++; // Increment count
    } 
    // Case 2: Regular case to add a new node at the rear
    else {
        Rear->Next = new Node; // Create a new node
        Rear = Rear->Next; // Move rear pointer
        Rear->Elem = NewNum; // Set the element
        Rear->Next = nullptr; // Next points to null
        Count++; // Increment count
    }
}

// PURPOSE: Adds an element to the front of the list
// PARAMETER: NewNum - the element to be added to the front
void llist::addFront(el_t NewNum) {
    // Case 1: Special case for the very first node
    if (isEmpty()) {
        Front = new Node; // Create a new node
        Front->Elem = NewNum; // Set the element
        Front->Next = nullptr; // Next points to null
        Rear = Front; // Front and Rear point to the same node
        Count++; // Increment count
    } 
    // Case 2: Regular case to add a new node at the front
    else {
        Node* newNode = new Node; // Create a new node
        newNode->Elem = NewNum; // Set the element
        newNode->Next = Front; // New node points to the old front
        Front = newNode; // Update front to the new node
        Count++; // Increment count
    }
}

// PURPOSE: Deletes the front element of the list
// PARAMETER: OldNum - reference to store the deleted element
void llist::deleteFront(el_t& OldNum) {
    // Case 1: Error case if the list is empty
    if (isEmpty()) {
        throw Underflow(); // Throw an exception
    }
    
    // Case 2: Special case if there is only one node
    if (Front == Rear) {
        OldNum = Front->Elem; // Store the element to be removed
        delete Front; // Delete the only node
        Front = Rear = nullptr; // Set front and rear to nullptr
        Count = 0; // Update count
    } 
    // Case 3: Regular case to delete the front node
    else {
        OldNum = Front->Elem; // Store the element to be removed
        Node* Second = Front->Next; // Pointer to the second node
        delete Front; // Delete the front node
        Front = Second; // Update front to the second node
        Count--; // Decrement count
    }
}

// PURPOSE: Deletes the rear element of the list
// PARAMETER: OldNum - reference to store the deleted element
void llist::deleteRear(el_t& OldNum) {
    // Case 1: Error case if the list is empty
    if (isEmpty()) {
        throw Underflow(); // Throw an exception
    }
    
    // Case 2: Special case if there is only one node
    if (Front == Rear) {
        OldNum = Rear->Elem; // Store the element to be removed
        delete Rear; // Delete the only node
        Front = Rear = nullptr; // Set front and rear to nullptr
        Count = 0; // Update count
    } 
    // Case 3: Regular case to delete the rear node
    else {
        Node* current = Front; // Pointer to traverse the list
        while (current->Next != Rear) { // Move to the second last node
            current = current->Next;
        }
        OldNum = Rear->Elem; // Store the element to be removed
        delete Rear; // Delete the rear node
        Rear = current; // Update rear to the second last node
        Rear->Next = nullptr; // Set new rear's next to nullptr
        Count--; // Decrement count
    }
}

// Utility function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp) {
    // Moves temp J-1 times to go to the Jth node (assumes J is valid)
    temp = Front; // Start from the front
    for (int K = 1; K < J; K++) {
        temp = temp->Next; // Move to the next node
    }
}

// PURPOSE: Deletes the Ith element of the list
// PARAMETER: I - the position of the element to be deleted
//            OldNum - reference to store the deleted element
void llist::deleteIth(int I, el_t& OldNum) {
    // Case 1: Error case if I is out of range
    if (I < 1 || I > Count) {
        throw OutOfRange(); // Throw an exception
    }
    
    // Case 2: Special case if deleting the first element
    if (I == 1) {
        deleteFront(OldNum); // Delegate to deleteFront
    } 
    // Case 3: Special case if deleting the last element
    else if (I == Count) {
        deleteRear(OldNum); // Delegate to deleteRear
    } 
    // Case 4: Regular case for deleting an element in between
    else {
        Node* current = Front; // Pointer to traverse the list
        Node* previous = nullptr; // Pointer to the previous node
        for (int K = 1; K < I; K++) { // Move to the Ith node
            previous = current; // Keep track of previous node
            current = current->Next;
        }
        OldNum = current->Elem; // Store the element to be removed
        previous->Next = current->Next; // Bypass the current node
        delete current; // Delete the current node
        Count--; // Decrement count
    }
}

// PURPOSE: Inserts an element at the Ith position of the list
// PARAMETER: I - the position to insert the new element
//            newNum - the element to be inserted
void llist::insertIth(int I, el_t newNum) {
    // Case 1: Error case if I is out of range
    if (I < 1 || I > Count + 1) {
        throw OutOfRange(); // Throw an exception
    }
    
    // Case 2: Special case for inserting at the front
    if (I == 1) {
        addFront(newNum); // Delegate to addFront
    } 
    // Case 3: Special case for inserting at the rear
    else if (I == Count + 1) {
        addRear(newNum); // Delegate to addRear
    } 
    // Case 4: Regular case for inserting in between
    else {
        Node* newNode = new Node; // Create a new node
        newNode->Elem = newNum; // Set the element
        Node* previous = nullptr; // Pointer to keep track of the previous node
        moveTo(I - 1, previous); // Move to the (I-1)th node
        newNode->Next = previous->Next; // Link new node to the next node
        previous->Next = newNode; // Link previous node to the new node
        Count++; // Increment count
    }
}

