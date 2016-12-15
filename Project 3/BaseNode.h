/*
    Assignment: Project #3
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 26, 2016 at 11:59pm
*/

#ifndef BASENODE_H
#define BASENODE_H

#include <string>

using namespace std;

class BaseNode
{
private:
    string pilotName;               // Name of the pilot
    double patrolArea;              // Total area patrolled by the pilot
public:
    BaseNode();                     // Default constructor
    BaseNode(string, double);       // Overloaded constructor
    BaseNode(BaseNode*);            // Copy constructor
    virtual ~BaseNode() = 0;        // Destructor
    string getPilotName();          // Pilot name accessor
    double getPatrolArea();         // Patrol area accessor
    void setPilotName(string);      // Pilot name mutator
    void setPatrolArea(double);     // Patrol area mutator
};

#endif // BASENODE_H
