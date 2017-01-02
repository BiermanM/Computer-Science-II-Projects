/*
    Assignment: Project #3
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 26, 2016 at 11:59pm
*/

#include "DoubleLinkNode.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
// Parameters: none
// Return: none
DoubleLinkNode::DoubleLinkNode()
               :BaseNode()              // calls the BaseNode's default constructor
{
    next = nullptr;
    prev = nullptr;
}

// Overloaded constructor
// Parameters: pointer, pointer, string, double
// Return: none
DoubleLinkNode::DoubleLinkNode(DoubleLinkNode *n, DoubleLinkNode *p, string pN, double pA)
               :BaseNode(pN, pA)        // calls the BaseNode's overloaded constructor
{
    next = n;
    prev = p;
}

// Copy constructor
// Parameters: DoubleLinkNode
// Return: none
DoubleLinkNode::DoubleLinkNode(DoubleLinkNode *otherDLNode)
               :BaseNode(otherDLNode)   // calls the BaseNode's copy constructor
{
    next = otherDLNode->getNext();
    prev = otherDLNode->getPrev();
}

// Destructor
// Parameters: none
// Return: none
DoubleLinkNode::~DoubleLinkNode(){ }

// Next pointer accessor
// Parameters: none
// Return: DoubleLinkNode
DoubleLinkNode* DoubleLinkNode::getNext()
{
    return next;
}

// Previous pointer accessor
// Parameters: none
// Return: DoubleLinkNode
DoubleLinkNode* DoubleLinkNode::getPrev()
{
    return prev;
}

// Next pointer mutator
// Parameters: DoubleLinkNode
// Return: none
void DoubleLinkNode::setNext(DoubleLinkNode* n)
{
    next = n;
}

// Previous pointer mutator
// Parameters: DoubleLinkNode
// Return: none
void DoubleLinkNode::setPrev(DoubleLinkNode* p)
{
    prev = p;
}
