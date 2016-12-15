/*
    Assignment: Project #5
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   December 10, 2016 at 11:59pm
*/

#ifndef BASENODE_H
#define BASENODE_H

#include <string>
using namespace std;

class BaseNode
{
private:
    int adjVertex;                  // Adjacent vertex
    int edgeWeight;                 // Weight of edge
public:
    BaseNode();                     // Default constructor
    BaseNode(int, int);             // Overloaded constructor
    BaseNode(BaseNode*);            // Copy constructor
    virtual ~BaseNode() = 0;        // Destructor
    int getAdjVertex();             // Adjacent vertex accessor
    int getEdgeWeight();            // Edge weight accessor
    void setAdjVertex(int);         // Adjacent vertex mutator
    void setEdgeWeight(int);        // Edge weight mutator
};

#endif // BASENODE_H
