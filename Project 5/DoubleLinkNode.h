/*
    Assignment: Project #5
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   December 10, 2016 at 11:59pm
*/

#ifndef DOUBLELINKNODE_H
#define DOUBLELINKNODE_H

#include "BaseNode.h"
using namespace std;

class DoubleLinkNode : public BaseNode
{
private:
    DoubleLinkNode * next;                                                  // DoubleLinkNode linked to the right of the current DoubleLinkNode
    DoubleLinkNode * prev;                                                  // DoubleLinkNode linked to the left of the current DoubleLinkNode
public:
    DoubleLinkNode();                                                       // Default constructor
    DoubleLinkNode(DoubleLinkNode*, DoubleLinkNode*, int, int);             // Overloaded constructor
    DoubleLinkNode(DoubleLinkNode*);                                        // Copy constructor
    ~DoubleLinkNode();                                                      // Destructor
    DoubleLinkNode* getNext();                                              // Next pointer accessor
    DoubleLinkNode* getPrev();                                              // Previous pointer accessor
    void setNext(DoubleLinkNode*);                                          // Next pointer mutator
    void setPrev(DoubleLinkNode*);                                          // Previous pointer mutator
};

#endif // DOUBLELINKNODE_H
