# Project 3 Instructions - Tie Fighter Patrols Strike Back
## Objectives
* Implement a linked list using classes in C++
* Implement basic inheritance by creating a doubly linked list
* Implement input validation
* Perform sorting and search algorithms in a linked list

##Problem
Darth Vader wants to check that his TIE fighter pilots are patrolling adequately-sized regions of the galaxy. He has files of data that contain the patrol coordinates for each of his pilots. With the fear of being force choked, you have agreed to write a program that analyzes the data and determines the size of the area patrolled by the pilots.

##Class Details
* BaseNode class
  * Must be abstract
  * Attributes
    * Pilot name
    * Patrol area
  * Methods
    * Default constructor
    * Overloaded constructor
    * Copy constructor
    * Accessors
    * Mutators
* DoubleLinkNode
  * Derived from BaseNode
  * Attributes
    * Next pointer
    * Prev pointer
  * Methods
    * Default constructor
    * Overloaded constructor
      * Calls overloaded BaseNode constructor
    * Copy constructor
      * Calls BaseNode copy constructor
    * Accessors
    * Mutators
* Linked List
  * Attributes
    * Head pointer (points to beginning of list)
    * Tail pointer (points to end of list)
  * Default constructor
  * Overloaded constructor
    * Takes node and assigns head to point at the node passed in
  * Destructor
    * Recursively delete linked list 
  * Accessor
  * Mutator
  * Overloaded `<<` operator
    * Display the entire linked list
  * Sort
    * Sort the linked list in ascending order by name (alphabetical) or area (numerical)
    * Only 1 sort function
    * You will have to figure out how to make a single function work in both cases
    * You may implement any sorting algorithm you prefer
    * The sort implementation must rearrange the nodes rather than swap contents

## Details
* The area of the shape can be calculated with the following formula:

    <a href="https://www.codecogs.com/eqnedit.php?latex=\dpi{120}&space;\frac{1}{2}&space;\left&space;|&space;\sum_{i=0}^{n-2}&space;(&space;x_{i&plus;1}&space;&plus;&space;x_{i}&space;)(&space;y_{i&plus;1}&space;-&space;y_{i}&space;)&space;\right&space;|" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\dpi{120}&space;\frac{1}{2}&space;\left&space;|&space;\sum_{i=0}^{n-2}&space;(&space;x_{i&plus;1}&space;&plus;&space;x_{i}&space;)(&space;y_{i&plus;1}&space;-&space;y_{i}&space;)&space;\right&space;|" title="\frac{1}{2} \left | \sum_{i=0}^{n-2} ( x_{i+1} + x_{i} )( y_{i+1} - y_{i} ) \right |" /></a>
* Store each pilot’s information (name and area) in a node in the linked list
* Add each new node to the end of the linked list
* The number of pilots in each file is unknown
* The number of coordinates for each pilot is unknown
* Comment your code generously. Refer to the grading rubric for more details
* Use as few variables as possible. Don’t waste memory holding a calculation just so you can print
it out one time

##User Interface
There will be no user interface for this program. All I/O will be performed with files

##Input
* There will be 2 input files
* The pilot information will come from a file named `pilot_routes.txt`
  * Read this file first
  * Each line in the file will contain the pilot’s first name followed by a list of coordinates
  * There will be a new line at the end of each line except for the last line
  * The pilot’s name may be multiple words
  * The coordinates will be separated by spaces
  * Each line in the file will represent a different pilot
  * There will be a space between each pair of coordinates
  * There will be a comma between the x and y coordinates
  * The first and last set of coordinates will always be the same
* A second input file will search and sort the data
  * Read this file second
  * The name of the file will be `commands.txt`
  * Each line of the file will contain a command
  * Valid commands:
    * `sort<space><area/pilot>`
      * sort the linked list on the given criteria
    * `<pilot name>`
      * Search the linked list for the given pilot
    * `<number>`
      * Search the linked list for the given area

##Input Validation
* Each file may contain invalid input
* If a line in the file contains invalid input, ignore that line
* Invalid input can contain the following:
  * In `pilot_routes.txt`
    * No space between pilot name and coordinates
    * Invalid characters (in name or coordinates)
    * Commas in wrong place
    * Spaces in wrong place
  * In `commands.txt`
    * Invalid characters in commands
    * Unknown commands
    * Unknown sort criteria

## Output
* Output will be written to two files
* As you process `commands.txt` record the results of the commands in a file named `results.txt`
* If a search is performed, write the results of the search to `results.txt`
  * Output format: `<value><found/not found>`
* No output when a sort is performed
* After processing `commands.txt`, write the linked list to a file named `pilot_areas.txt`
  * Output format:
    * `<pilot name><tab><area>`
  * The area will be rounded to 2 decimal places
  * Each pilot’s data will be written on a separate line


## *Extra Credit*: Implement a binary search
* The first command in the test case file will be a sort
* All searches will be based on the previous sort command
* Use pointers for left, right and middle
* You may find it useful to create some variables to track the size of the list and where the midpoint will be
* You must use the search if implemented
  * Identify the line where the function call is made in the comment below
* Add a comment at the top of your program
  * `//BINARY SEARCH LINES ### - ###, CALL LINE ###`
  * Fill in `###` with line numbers
