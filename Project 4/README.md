# Project 4 Instructions - Preventing a Paradox
## Objectives
* Create a binary search tree class in C++
* Implement insert and traversal algorithms for a binary tree

## Problem
Doc Brown has gotten himself in a jam. The software he uses to evaluate integrals has become corrupt and he is in need of assistance. Without this software, his quantum physics calculations will be incorrect, possibly creating time paradox of epic proportions! Doc Brown is enlisting your assistance in the matter. Your future may depend on it.

## Class Details
* Node class
  * Attributes
    * Coefficient
    * Exponent
    * Left pointer
    * Right pointer
  * Methods
    * Default constructor
    * Overloaded constructor
    * Copy constructor
    * Accessors
    * Mutators
* Binary Search Tree
  * Attributes
    * Root pointer
  * Default constructor
  * Overloaded constructor
    * Takes node and assigns head to point at the node passed in
  * Destructor
    * Recursively delete tree
  * Accessors
  * Mutators
  * Insert
  * Search

## Details
* All traversals of the tree will be done recursively
  * This includes functions that add, delete, or search the tree
* Expressions consist of simple polynomial terms -- the highest degree will be +/- 10
  * If multiple terms include the same exponent, combine those terms
  * There will be no exponents of -1
* Exponents will be represented by the `^` character.
* Do not assume that the expression will be in order from highest to lowest exponent.
* All coefficients will be integers.
* The `|` (pipe) character will be used to represent the integral symbol
* If an integral is definite, there will be a number before and after the `|` character
  * <a href="https://www.codecogs.com/eqnedit.php?latex=\int_{b}^{a}&space;x\;&space;dx&space;=&space;a|b\;&space;x\;&space;dx" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\int_{b}^{a}&space;x\;&space;dx&space;=&space;a|b\;&space;x\;&space;dx" title="\int_{b}^{a} x\; dx = a|b\; x\; dx" /></a>
  * The endpoints of the interval for the definite integral will be integer values
* The variable will always be `x` and the integral will always end with `dx`
* There will always be a space before the first term of the integral and before `dx`
  * Do not assume there will be spaces anywhere else in the expression
* If a term has no coefficient, it is assumed to be 1
* Comment your code generously. Refer to the grading rubric for more details
* Use as few variables as possible. Don’t waste memory holding a calculation just so you can print it out
one time

## User Interface
There will be no user interface for this program. All I/O will be performed with files

## Input
* All expressions will be read from a file named `integrals.txt`
* There is no limit to the number of expressions that can be in the file
* Each expression will be on a separate line
* Example Input:
  * `| 3x^2 + 2x + 1 dx`
  * `1|4 x^-2 +3x+4 dx`
  * `-2|2 x^3 – 4x dx`

## Output
* All output will be written to a file named `answers.txt`
* Each anti-derivative will be printed to a separate line
  * Definite integrals will also include the interval and value (see examples below)
  * Values will be to 3 decimal places
* Use the `^` character to represent exponents
* Order the terms from greatest to least exponent
* Fractions will be simplified
  * All fractions will be enclosed in parentheses
* Add  `+ C`  to the anti-derivative for indefinite integrals
* Example Output (based on input above):
  * `x^3 + x^2 + x + C`
  * `(3/2)x^2 + 4x -x^-1, 1|4 = 35.250`
  * `(1/4)x^4 – 2x^2, -2|2 = 0`

## *Extra Credit*: Evaluate expressions with trigonometric functions
* Possible trigonometric functions:
  * `sin x`
  * `cos x`
  * `sec^2 x`
* Expressions may contain any number of trigonometric functions
* Trig functions may contain coefficients
  * Possibly before the trig function and before the variable
* The trig anti-derivatives will be listed at the end of the expression in the order encountered
  * Consider a path of nodes extending from the right pointer of the smallest exponent node
* Consider that some expressions may contain trig functions with like terms
* Add a comment at the top of your program
  * `//TRIG FUNCTIONS`
* Example Input:
  * `| sin x + cos x dx`
  * `| 1 – cos 4x dx`
  * `| 3x^4 – 6x^2 + 2sin 10x dx`
* Example Output:
  * `-cos x + sin x + C`
  * `x – (1/4)sin 4x + C`
  * `(3/5)x^5 – 2x^3 – (1/5)cos 10x + C`
