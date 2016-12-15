/*
    Assignment: Project #4
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   November 16, 2016 at 11:59pm

    //TRIG FUNCTIONS
*/

#include "Node.h"
using namespace std;

// Default constructor
// Parameters: none
Node::Node()
{
    coefficient = 0;
    exponent = 0;
    left = nullptr;
    right = nullptr;
}

// Overloaded constructor
// Parameters: int, int
Node::Node(int coeff, int exp)
{
    coefficient = coeff;
    exponent = exp;
    left = nullptr;
    right = nullptr;
}

// Copy constructor
// Parameters: Node
Node::Node(Node* n)
{
    coefficient = n->getCoefficient();
    exponent = n->getExponent();
    left = n->getLeft();
    right = n->getRight();
}

// Coefficient accessor
// Parameters: none
// Return: int
int Node::getCoefficient()
{
    return coefficient;
}

// Exponent accessor
// Parameters: none
// Return: int
int Node::getExponent()
{
    return exponent;
}

// Left child accessor
// Parameters: none
// Return: Node
Node* Node::getLeft()
{
    return left;
}

// Right child accessor
// Parameters: none
// Return: Node
Node* Node::getRight()
{
    return right;
}

// Coefficient mutator
// Parameters: int
// Return: none
void Node::setCoefficient(int coeff)
{
    coefficient = coeff;
}

// Exponent mutator
// Parameters: int
// Return: none
void Node::setExponent(int exp)
{
    exponent = exp;
}

// Left child mutator
// Parameters: Node
// Return: none
void Node::setLeft(Node * l)
{
    left = l;
}

// Right child mutator
// Parameters: Node
// Return: none
void Node::setRight(Node * r)
{
    right = r;
}
