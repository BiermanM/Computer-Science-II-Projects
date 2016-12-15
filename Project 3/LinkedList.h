/*
    Assignment: Project #3
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 26, 2016 at 11:59pm
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "DoubleLinkNode.h"
#include <fstream>

using namespace std;

class LinkedList
{
private:
    DoubleLinkNode * head;                                                      // first pointer of linked list
    DoubleLinkNode * tail;                                                      // last pointer of linked list
public:
    LinkedList();                                                               // Default constructor
    LinkedList(DoubleLinkNode*);                                                // Overloaded constructor
    ~LinkedList();                                                              // Destructor
    DoubleLinkNode* getHead();                                                  // Head pointer accessor
    DoubleLinkNode* getTail();                                                  // Tail pointer accessor
    void setHead(DoubleLinkNode*);                                              // Head pointer mutator
    void setTail(DoubleLinkNode*);                                              // Tail pointer mutator
    friend ofstream& operator<<(ofstream&, LinkedList&);                        // Overloaded stream insertion operator
    void insert(DoubleLinkNode*);                                               // Insert DoubleLinkNode into list
    void sortList(string);                                                      // Sort list into ascending order alphabetically or numerically
    bool inOrder(string);                                                       // Checks if the list is currently in ascending order
    ofstream& recursivePrint(ofstream&, DoubleLinkNode*);                       // Recursively prints the data for each DoubleLinkNode in the list, from first to last
    void recursiveDelete(DoubleLinkNode*);                                      // Recursively deletes all DoubleLinkNodes in the list, from last to first
    bool isGreaterThan(DoubleLinkNode*, DoubleLinkNode*, string);               // Checks if the first DoubleLinkNode is greater than the second DoubleLinkNode based on name or area
    bool isGreaterThanOrEqualTo(DoubleLinkNode*, DoubleLinkNode*, string);      // Checks if the first DoubleLinkNode is greater than or equal to the second DoubleLinkNode base on name or area
    string searchFor(string);                                                   // Searches for a DoubleLinkNode containing the given name or area
};

#endif // LINKEDLIST_H
