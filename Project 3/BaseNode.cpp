/*
    Assignment: Project #3
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 26, 2016 at 11:59pm
*/

#include "BaseNode.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
// Parameters: none
// Return: none
BaseNode::BaseNode()
{
    pilotName = "";
    patrolArea = 0;
}

// Overloaded constructor
// Parameters: string, string
// Return: none
BaseNode::BaseNode(string pN, double pA)
{
    pilotName = pN;
    patrolArea = pA;
}

// Copy constructor constructor
// Parameters: BaseNode
// Return: none
BaseNode::BaseNode(BaseNode *otherNode)
{
    pilotName = otherNode->pilotName;
    patrolArea = otherNode->patrolArea;
}

// Destructor
// Parameters: none
// Return: none
BaseNode::~BaseNode(){ }

// Pilot name accessor
// Parameters: none
// Return: string
string BaseNode::getPilotName()
{
    return pilotName;
}

// Patrol area accessor
// Parameters: none
// Return: double
double BaseNode::getPatrolArea()
{
    return patrolArea;
}

// Pilot name mutator
// Parameters: string
// Return: none
void BaseNode::setPilotName(string s)
{
    pilotName = s;
}

// Patrol area mutator
// Parameters: double
// Return: none
void BaseNode::setPatrolArea(double d)
{
    patrolArea = d;
}
