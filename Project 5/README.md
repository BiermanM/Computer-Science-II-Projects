# Project 5 Instructions - Revenge of the Tie Fighter Patrols

## Objectives
* Implement a graph using classes in C++ 

## Problem
Darth Vader wants to check that his TIE fighter pilots are patrolling adequately-sized regions of the galaxy.  He has files of data that contain the patrol coordinates for each of his pilots.  With the fear of being force choked, you have agreed to write a program that analyzes the data and determines if the patrol path is valid. 
 
## Class Details
* Graph Class
  * Attributes
    * Size (integer)
    * Graph – array of linked lists
  * Methods
    * Constructor
    * Destructor
    * Mutators
    * Accessors
    * Traversal function
      * Breadth or depth
      * Requires vertex parameter

## Details
* You may use the linked list classes from project 3 or create a simpler linked list class
* The linked list will hold the adjacent nodes of each vertex
* There will be two input files
  * One file contains the graph information
  * One file contains the pilot patrol routes
* You must determine if a given patrol route is valid based on the graph structure
  * Does the given path exist in the graph?
* The number of pilots in each file is unknown
* The number of coordinates for each pilot is unknown
* All input will be valid.
* Comment your code generously. Refer to the grading rubric for more details
* Use as few variables as possible.  Don’t waste memory holding a calculation just so you can print it out one time

## User Interface
There will be no user interface for this program.  All I/O will be performed with files 

## Input
* There will be 2 input files
* All input will be valid
* The graph information will come from a file named `galaxy.txt`
  * Read this file first
  * Use this information to create the graph
  * Each line will contain a vertex and a list of edges with weights
    * Each edge will be represented as `<adjacent vertex><comma><weight>`
    * Line example: `1 2,9 3,3 9,1 15,5`
  * The list of vertices in the file may not be in order
  * The list of edges may not be in order
  * The graph will be connected
  * All vertices will have at least 1 edge
* The pilot information will come from a file named `pilot_routes.txt`
  * Read this file second
  * The format of this file will be different than the previous 2 maintenance projects
  * Each line in the file will contain the pilot’s name followed by a list of coordinates
    * The coordinates are just vertices
    * Each coordinate will be separated by a space
    * Example: `Sully Olvar 1 4 3 9 12 6`
    * The first vertex is the starting vertex of the patrol
    * The patrol route does not necessarily form a polygon
  * There will be a new line at the end of each line except for the last line
  * The pilot’s name may be multiple words
  * Each line in the file will represent a different pilot

## Output
* Output will be written to a file named `patrols.txt`
* Use formatting commands to create a table in the output file
  * Column 1: Pilot Name
  * Column 2: Path length
  * Column 3: valid/invalid
* Pilots will be sorted from least to greatest path length
* If the path is invalid, the path length will be blank
* Each pilot’s data will be written on a separate line
