/*
    Assignment: Project #5
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   December 10, 2016 at 11:59pm
*/

#include "LinkedList.h"
using namespace std;

// Default constructor
// Parameters: none
// Return: none
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

// Overloaded constructor
// Parameters: DoubleLinkNode
// Return: none
LinkedList::LinkedList(DoubleLinkNode* n)
{
    if (head == nullptr)            // If list is empty, n becomes head
        head = n;
    else                            // Otherwise, n is inserted after head
    {
        n->setNext(head);
        n->setPrev(nullptr);
        head = n;
    }
}

// Copy constructor
// Parameters: LinkedList
// Return: none
LinkedList::LinkedList(LinkedList* ll)
{
    head = ll->getHead();
    tail = ll->getTail();
}

// Destructor
// Parameters: none
// Return: none
LinkedList::~LinkedList()
{
    recursiveDelete(head);
}

// Head pointer accessor
// Parameters: none
// Return: DoubleLinkNode
DoubleLinkNode* LinkedList::getHead()
{
    return head;
}

// Tail pointer accessor
// Parameters: none
// Return: DoubleLinkNode
DoubleLinkNode* LinkedList::getTail()
{
    return tail;
}

// Head pointer mutator
// Parameters: DoubleLinkNode
// Return: none
void LinkedList::setHead(DoubleLinkNode* n)
{
    head = n;
}

// Tail pointer mutator
// Parameters: DoubleLinkNode
// Return: none
void LinkedList::setTail(DoubleLinkNode* n)
{
    tail = n;
}

// Insert DoubleLinkNode into list
// Parameters: DoubleLinkNode
// Return: none
void LinkedList::insert(DoubleLinkNode * n)
{
    if (head == nullptr && tail == nullptr) // If list is empty, new
    {                                       // node becomes both head and tail
        head = n;
        tail = n;
    }
    else                                    // Otheriwse, new node is added
    {                                       // to the end of the list and becomes
        n->setPrev(tail);                   // the tail
        tail->setNext(n);
        tail = n;
    }
}

// Recursively deletes all DoubleLinkNodes in the list, from last to first
// Parameters: DoubleLinkNode
// Return: none
void LinkedList::recursiveDelete(DoubleLinkNode* n)
{
    if (n->getNext() != nullptr)            // Finds the tail of the list
        recursiveDelete(n->getNext());

    if (n->getPrev() != nullptr)            // Removes the previous node's link to the current node
        n->getPrev()->setNext(nullptr);
    delete n;                               // Deletes the node
}

