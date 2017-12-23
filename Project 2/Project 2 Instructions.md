# Project 2 Instructions - Whovian Complex Numbers
## Objectives
* Implement basic class concepts in C++
* Create different types of constructors
* Implement overloaded operators for a class

## Problem
The TARDIS has been infected by a virus which means it is up to the Doctor to manually enter calculations into the TARDIS interface. Unfortunately, most of the calculations necessary to make the TARDIS work properly involve complex numbers. Doctor Who has asked you to create a program that will analyze complex number expressions so that he can quickly enter the information into the TARDIS.

## Details
* Single complex number class
* Attributes:
  * Real
  * Imaginary
* Methods
  * Default constructor
  * Overloaded constructor
  * Copy constructor
  * Accessors
  * Mutators
  * Overloaded operators
    * Arithmetic (`+`, `-`, `*`, `/`)
    * Relational (`<`, `>`, `==`, `!=`)
    * I/O (`<<`, `>>`)
* The overloaded input operator will read an entire complex number and parse it
  * Store each part of the complex number in the correct attribute of the class
* The overloaded output operator will print out the complex number in one of the formats below
* Both the real and imaginary parts may be floating point values
* Validate that each complex number contains no invalid characters
  * The only valid letter in a complex number is `i` (lower case)
* Validate that each expression contains a valid operator
* If a line contains invalid data, ignore the line
* Complex numbers may be represented in 3 ways
  * Real + imaginary
    * `<number><+ or -><number>i`
  * Real only
    * `<number>`
  * Imaginary only
    * `<number>i`
* Numbers may be positive or negative
* Results for arithmetic operators will be numerical
* Results for relational operators will be Boolean
* Calculating less/greater than will be determined by analyzing the modulus (or absolute value) of
each complex number
* Comment your code generously. Refer to the grading rubric for more details
* Use as few variables as possible. Don’t waste memory holding a calculation just so you can print
it out one time

## User Interface
There will be no user interface for this program. All I/O will be performed with a files

## Input
* All input will come from a file named `complex.txt`
* Each line in the file will contain an expression to be evaluated
* Line format: `<complex number><space><operator><space><complex number>`
* Possible operators
  * `+` (add)
  * `–` (subtract)
  * `*` (multiply)
  * `/` (divide)
  * `<` (less than)
  * `>` (greater than)
  * `=` (equal)
  * `/=` (not equal)
* There will always be spaces around the operator
* There will be a newline at the end of each line except for the last line

## Output
* All output will be written to a file named `results.txt`
* Format all output into a table with 2 columns
  * Column 1: original expression
  * Column 2: value
* All values in the columns will be left justified
* Numerical values will be rounded to 2 decimal places
* Relational operators should evaluate to true or false
* Each expression will be listed on separate lines
