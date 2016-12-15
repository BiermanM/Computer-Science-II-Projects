/*
    Assignment: Project #5
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   December 10, 2016 at 11:59pm
*/

#include "BaseNode.h"
using namespace std;

// Default constructor
// Parameters: none
// Return: none
BaseNode::BaseNode()
{
    adjVertex = 0;
    edgeWeight = 0;
}

// Overloaded constructor
// Parameters: int, int
// Return: none
BaseNode::BaseNode(int aV, int eW)
{
    adjVertex = aV;
    edgeWeight = eW;
}

// Copy constructor
// Parameters: BaseNode
// Return: none
BaseNode::BaseNode(BaseNode *otherNode)
{
    adjVertex = otherNode->adjVertex;
    edgeWeight = otherNode->edgeWeight;
}

// Destructor
// Parameters: none
// Return: none
BaseNode::~BaseNode(){ }

// Adjacent vertex accessor
// Parameters: none
// Return: int
int BaseNode::getAdjVertex()
{
    return adjVertex;
}

// Edge weight accessor
// Parameters: none
// Return: int
int BaseNode::getEdgeWeight()
{
    return edgeWeight;
}

// Adjacent vertex mutator
// Parameters: int
// Return: none
void BaseNode::setAdjVertex(int num)
{
    adjVertex = num;
}

// Edge weight mutator
// Parameters: int
// Return: none
void BaseNode::setEdgeWeight(int num)
{
    edgeWeight = num;
}
