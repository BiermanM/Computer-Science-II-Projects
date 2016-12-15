/*
    Assignment: Project #5
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   December 10, 2016 at 11:59pm
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "LinkedList.h"
using namespace std;

class Graph
{
private:
    int size;                       // Size of graph
    LinkedList * graph;             // Adjacency list of vertices
public:
    Graph();                        // Default constructor
    Graph(int);                     // Overloaded constructor
    ~Graph();                       // Destructor
    int getSize();                  // Size accessor
    void setSize(int);              // Size mutator
    LinkedList* getGraph();         // Graph accessor
    void setGraph(LinkedList*);     // Graph mutator
    void depthFirstTraversal(int);  // Depth first traversal
    void dft(int, bool*);           // Recursive depth first traversal
};

#endif // GRAPH_H
