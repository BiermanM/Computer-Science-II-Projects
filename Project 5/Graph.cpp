/*
    Assignment: Project #5
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   December 10, 2016 at 11:59pm
*/

#include "Graph.h"
#include "LinkedList.h"
using namespace std;

// Default constructor
// Parameters: none
// Return: none
Graph::Graph()
{
    size = 0;
    graph = new LinkedList[size]();
}

// Overloaded constructor
// Parameters: int
// Return: none
Graph::Graph(int num)
{
    size = num;
    graph = new LinkedList[size];
}

// Destructor
// Parameters: none
// Return: none
Graph::~Graph()
{
    size = 0;
    graph = nullptr;
}

// Size accessor
// Parameters: none
// Return: int
int Graph::getSize()
{
    return size;
}

// Size mutator
// Parameters: int
// Return: none
void Graph::setSize(int s)
{
    size = s;
}

// Graph accessor
// Parameters: none
// Return: LinkedList*
LinkedList* Graph::getGraph()
{
    return graph;
}

// Graph mutator
// Parameters: LinkedList*
// Return: none
void Graph::setGraph(LinkedList* g)
{
    graph = g;
}

// Depth first traversal
// Parameters: int
// Return: none
void Graph::depthFirstTraversal(int v)
{
    bool * visited = new bool[size];    // A temporary array of booleans for each vertex
    for (int x = 0; x < size; x++)
        visited[x] = false;             // Sets all indexes to not visited

    dft(v, visited);                    // Visits the vertex at index v of the graph
    delete [] visited;                  // Deletes the temporary array
}

// Recursive depth first traversal
// Parameters: int, bool*
// Return: none
void Graph::dft(int n, bool * visited)
{
    visited[n] = true;                                      // Visits the vertex at index n

    DoubleLinkNode * current = getGraph()[n].getHead();     // Search through the list of adjacent vertices
    while (current != nullptr)
    {
        if (visited[current->getAdjVertex()] == false)      // Visit the node if it hasn't been visited
            dft(current->getAdjVertex(), visited);

        current = current->getNext();                       // Go to the next adjacent vertex
    }
}
