## Project 1 – Tie Fighter Patrols
# Objectives
* Implement basic file I/O in C++
* Manipulate single dimension arrays
* Implement basic programming constructs in C++

# Problem
Darth Vader wants to check that his TIE fighter pilots are patrolling adequately-sized regions of the galaxy. He has files of data that contain the patrol coordinates for each of his pilots. With the fear of being force choked, you have agreed to write a program that analyzes the data and determines the size of the area patrolled by the pilots.

# Details
* The area of the shape can be calculated with the following formula:

    <a href="https://www.codecogs.com/eqnedit.php?latex=\dpi{120}&space;\frac{1}{2}&space;\left&space;|&space;\sum_{i=0}^{n-2}&space;(&space;x_{i&plus;1}&space;&plus;&space;x_{i}&space;)(&space;y_{i&plus;1}&space;-&space;y_{i}&space;)&space;\right&space;|" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\dpi{120}&space;\frac{1}{2}&space;\left&space;|&space;\sum_{i=0}^{n-2}&space;(&space;x_{i&plus;1}&space;&plus;&space;x_{i}&space;)(&space;y_{i&plus;1}&space;-&space;y_{i}&space;)&space;\right&space;|" title="\frac{1}{2} \left | \sum_{i=0}^{n-2} ( x_{i+1} + x_{i} )( y_{i+1} - y_{i} ) \right |" /></a>
* Store the coordinates in a pair of parallel arrays
* The number of pilots in each file is unknown
* Each pilot will have no more than 15 coordinates
* At least 3 functions other than main must be defined
* No indirect recursion
* Comment your code generously. Refer to the grading rubric for more details
* Use as few variables as possible. Don’t waste memory holding a calculation just so you can print it out one time

# User Interface
There will be no user interface for this program. All I/O will be performed with a files

# Input
* All input will come from a file named pilot_routes.txt
* Each line in the file will contain the pilot’s first name followed by a list of coordinates
* There will be a new line after each line except for the last line
* The pilot’s name will be a single word
* The coordinates will be separated by spaces
* Each line in the file will represent a different pilot
* There will be a space between each pair of coordinates
* There will be a comma between the x and y coordinates
* The first and last set of coordinates will always be the same. See the sample below

# Output
* All output will be written to a file named pilot_areas.txt
* Output format:
  * &lt;pilot name>&lt;tab>&lt;area>
* The area will be rounded to 2 decimal places
* Each pilot’s data will be written on a separate line

# Samples
* Input Line: `Han 4,0 4,7.5 7,7.5 7,3 9,0 7,0 4,0`
* Output Line: `Han   25.50`
