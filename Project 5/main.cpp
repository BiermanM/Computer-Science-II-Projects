/*
    Assignment: Project #5
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   December 10, 2016 at 11:59pm
*/

#include "Graph.h"
#include "DoubleLinkNode.h"
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

// An object that stores the name and path length of each pilot
struct pilotPatrol
{
    string name;
    int path;           // if pilot's path is invalid, the path length will be -1
};

// Converts a double to a string
// Parameters: double
// Return: string
string intToString(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

// Creates a graph
// Parameters: ifstream, Graph, int*, int
// Return: none
void createGalaxy(ifstream& inFile, Graph& g, int * indexArr, int indexArrLength)
{
    inFile.open("galaxy.txt");                                                                              // Opens galaxy.txt for input
    string str;

    for (int x = 0; x < g.getSize(); x++)
    {
        getline(inFile, str);

        if (str.find(' ') > str.length())                                                                   // Removes the source vertex from the string
            str = "";
        else
            str = str.substr(str.find(' ') + 1);

        while (str.length() > 0)                                                                            // For every destination vertex
        {
            int adjV = atoi(str.substr(0, str.find(',')).c_str());                                          // The adjacent vertex is the number before the comma in the pair
            for (int x = 0; x < indexArrLength; x++)                                                        // Finds the index in indexArr that is associated to the adjacent vertex
            {
                if (adjV == indexArr[x])
                {
                    adjV = x;
                    break;
                }
            }
            int edgeW = atoi(str.substr(str.find(',') + 1, str.find(' ') - (str.find(',') + 1) ).c_str());  // The edge weight is the number after the comma in the pair
            g.getGraph()[x].insert(new DoubleLinkNode(nullptr, nullptr, adjV, edgeW));                      // Create a DoubleLinkNode with the adjacent vertex and edge weight,
                                                                                                            // and insert the node into the graph

            if (str.find(' ') > str.length())                                                               // Remove the destination vertex from the string
                str = "";
            else
                str = str.substr(str.find(' ') + 1);
        }
    }
    inFile.close();                                                                                         // Closes galaxy.txt
}

// Finds the length of the pilot's path
// Parameters: Graph, string, int*, int
// Return int
int findPath(Graph& g, string path, int * indexArr, int indexArrLength)
{
    LinkedList ll;

    while (path.length() > 0)                                       // Moves the path vertices into a Linked List
    {
        int num = atoi(path.substr(0, path.find(" ")).c_str());     // Gets the first destination vertex
        bool isInGraph =  false;
        for (int x = 0; x < indexArrLength; x++)                    // Finds the index in indexArr that is associated to the adjacent vertex
        {
            if (num == indexArr[x])
            {
                num = x;
                isInGraph = true;                                   // Keeps track of whether or not the destination is actually a vertex in the graph
                break;
            }
        }
        if (isInGraph == false)                                     // If the destination vertex is not a vertex in the graph, use the largest integer to signify that it is invalid
            num = INT_MAX;
        ll.insert(new DoubleLinkNode(nullptr, nullptr, num, 0));    // Create a DoubleLinkNode with the vertex and insert the node into the Linked List
        if (path.find(" ") > path.length())                         // Removes that vertex from the string
            path = "";
        else
            path = path.substr(path.find(" ") + 1);
    }

    bool isValid = true;
    int pathLength = 0;
    DoubleLinkNode * current = ll.getHead();
    while (current != nullptr)                                      // Searching for the pilot's path
    {
        if (current->getAdjVertex() > g.getSize())                  // if the vertex is invalid, end the search
        {
            isValid = false;
            break;
        }
        else if (current->getNext() == nullptr)                     // End the search when the end of the path is reached
            break;
        else
        {
            bool isADestinationVert = false;
            DoubleLinkNode * current2 = g.getGraph()[current->getAdjVertex()].getHead();
            while (current2 != nullptr)                             // Searches through the adjacent vertices of the node that is currently being visited in the pilot's path
            {
                if (current->getNext()->getAdjVertex() == INT_MAX || current2->getAdjVertex() == INT_MAX)   // End the search if there is an invalid vertex
                    break;
                else if (current2->getAdjVertex() != current->getNext()->getAdjVertex())                    // Move to another adjacent vertex if it is not the one we're looking for
                    current2 = current2->getNext();
                else                                                                                        // If the adjacent vertex is found, end the search
                {
                    isADestinationVert = true;
                    break;
                }
            }

            if (isADestinationVert == true)                         // If the adjacent vertex was found, move to the next vertex in the pilot's path
            {
                current = current->getNext();
                pathLength += current2->getEdgeWeight();            // Add the weight of the edge between the source and destination vertex to the running total
            }
            else                                                    // If the adjacent vertex was not found, the pilot's path is invalid
            {
                isValid = false;
                break;
            }
        }
    }

    if (isValid == false)                                           // If the pilot's path is invalid, the path length is -1
        pathLength = -1;

    return pathLength;                                              // Otherwise, the path length is the running total of edges between vertices in the pilot's path
}

// Sorts the pilots from smallest to largest path length
// Parameters: pilotPatrol*, int
// Return: none
void bubbleSort(pilotPatrol * pp, int arrLength)
{
    for (int x = 0; x < arrLength - 1; x++)                                                                     // For each pilot
    {
        while (pp[x].path > pp[x + 1].path || (pp[x].path == pp[x + 1].path && pp[x].name > pp[x + 1].name))    // If one pilot has a longer path
        {                                                                                                       // length than the pilot after him,
            pilotPatrol temp = pp[x];                                                                           // swap the two pilots
            pp[x] = pp[x + 1];                                                                                  // If the pilots have the same path
            pp[x + 1] = temp;                                                                                   // length, then swap if one pilot's
                                                                                                                // name is more than the pilot after
            x = 0;
        }
    }
}

int main()
{
    ifstream inFile("galaxy.txt");                                          // Opens galaxy.txt for input
    if (inFile)                                                             // If galaxy.txt exists
    {
        int numLines = 0;
        string str;

        while (!inFile.eof())                                               // Gets the number of vertices in the graph
        {
            getline(inFile, str);
            numLines++;
        }
        inFile.close();                                                     // Closes galaxy.txt

        Graph g(numLines);                                                  // Creates a graph with a size of the number of vertices in the input file
        int * indexArr = new int[numLines];                                 // An array that holds each vertex
        int indexArrLength = numLines;

        inFile.open("galaxy.txt");                                          // Opens galaxy.txt for input
        for (int x = 0; x < indexArrLength; x++)                            // Stores the vertex of each line in the array indexArr
        {
            getline(inFile, str);
            indexArr[x] = atoi(str.substr(0, str.find(' ')).c_str());
        }
        inFile.close();                                                     // Closes galaxy.txt

        createGalaxy(inFile, g, indexArr, indexArrLength);                  // Creates a graph using galaxy.txt, graph g, array indexArr, and the length of indexArr


        inFile.open("pilot_routes.txt");                                    // Opens pilot_routes.txt for input
        if (inFile)                                                         // If pilot_routes.txt exists
        {
            str = "";
            numLines = 0;

            while (!inFile.eof())                                           // Gets the number of pilots
            {
                getline(inFile, str);
                numLines++;
            }
            inFile.close();                                                 // Closes pilot_routes.txt for input

            pilotPatrol * patrols = new pilotPatrol[numLines];              // An array of objects that contain the pilot's name and the pilot's path length

            inFile.open("pilot_routes.txt");
            for (int x = 0; x < numLines; x++)                              // Gets name of each pilot and finds if their path is valid
            {
                getline(inFile, str);
                patrols[x].name = str.substr(0, str.find_last_not_of("0123456789- ") + 1);                                              // Finds the substring that doesn't contain numbers and sets it to the pilot's name
                patrols[x].path = findPath(g, str.substr(str.find_last_not_of("0123456789- ") + 2), indexArr, indexArrLength);          // Finds the substring that doesn't contain letters, finds the path length, and sets it to the pilot's path length
            }
            inFile.close();                                                 // Closes pilot_routes.txt for input

            bubbleSort(patrols, numLines);                                  // Sorts the pilots by path length

            int longestName = 0;
            int longestPath = 0;
            for (int x = 0; x < numLines; x++)                              // Finds column sizes needed for output
            {
                if (patrols[x].name.length() > (unsigned) longestName)      // Finds the longest name
                    longestName = patrols[x].name.length();
                if (patrols[x].path > longestPath)                          // Finds the longest path length
                    longestPath = intToString(patrols[x].path).length();
            }

            ofstream outFile("patrols.txt");                                // Opens patrols.txt for output
            for (int x = 0; x < numLines; x++)
            {
                outFile << left;                                            // Sets the output to left justified
                if (patrols[x].path != -1)                                  // If the pilot's path length is valid
                    outFile << setw(longestName + 3) << patrols[x].name     // In the format <name>   <path length>   valid
                            << setw(longestPath + 3) << patrols[x].path
                            << "valid" << endl;
                else                                                        // If the pilot's path length is invalid
                    outFile << setw(longestName + longestPath + 6)          // In the format <name>   invalid
                            << patrols[x].name << "invalid" << endl;
            }
            outFile.close();                                                // Closes patrols.txt
        }
    }

    return 0;
}
