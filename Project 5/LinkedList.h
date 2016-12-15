/*
    Assignment: Project #5
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   December 10, 2016 at 11:59pm
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "DoubleLinkNode.h"
using namespace std;

class LinkedList
{
private:
    DoubleLinkNode * head;                                                      // first pointer of linked list
    DoubleLinkNode * tail;                                                      // last pointer of linked list
public:
    LinkedList();                                                               // Default constructor
    LinkedList(DoubleLinkNode*);                                                // Overloaded constructor
    LinkedList(LinkedList*);                                                    // Copy constructor
    ~LinkedList();                                                              // Destructor
    DoubleLinkNode* getHead();                                                  // Head pointer accessor
    DoubleLinkNode* getTail();                                                  // Tail pointer accessor
    void setHead(DoubleLinkNode*);                                              // Head pointer mutator
    void setTail(DoubleLinkNode*);                                              // Tail pointer mutator
    void insert(DoubleLinkNode*);                                               // Insert DoubleLinkNode into list
    void recursiveDelete(DoubleLinkNode*);                                      // Recursively deletes all DoubleLinkNodes in the list, from last to first
};

#endif // LINKEDLIST_H
