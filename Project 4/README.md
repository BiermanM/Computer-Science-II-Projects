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
* Thisincludesfunctionsthatadd,delete,orsearchthetree
* Expressions consist of simple polynomial terms - the highest degree will be +/- 10
* Ifmultipletermsincludethesameexponent,combinethoseterms
* Therewillbenoexponentsof-1
 Exponents will be represented by the ^ character.
 Do not assume that the expression will be in order from highest to lowest exponent.
 All coefficients will be integers.
 The | (pipe) character will be used to represent the integral symbol
 If an integral is definite, there will be a number before and after the | character
o ∫𝑏𝑥𝑑𝑥=a|bxdx 𝑎
o Theendpointsoftheintervalforthedefiniteintegralwillbeintegervalues
 The variable will always be ‘x’ and the integral will always end with dx
 There will always be a space before the first term of the integral and before dx
o Donotassumetherewillbespacesanywhereelseintheexpression
 If a term has no coefficient, it is assumed to be 1
 Comment your code generously. Refer to the grading rubric for more details
 Use as few variables as possible. Don’t waste memory holding a calculation just so you can print it out
one time.
User Interface: There will be no user interface for this program. All I/O will be performed with files
