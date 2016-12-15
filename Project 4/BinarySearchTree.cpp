/*
    Assignment: Project #4
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   November 16, 2016 at 11:59pm

    //TRIG FUNCTIONS
*/

#include <string>
#include <sstream>
#include <stdlib.h>
#include "BinarySearchTree.h"
using namespace std;

// Default constructor
// Parameters: none
BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

// Overloaded constructor
// Parameters: Node
BinarySearchTree::BinarySearchTree(Node * n)
{
    root = n;                               // sets node from parameter to root
}

// Copy constructor
// Parameters: BinarySearchTree (by reference)
BinarySearchTree::BinarySearchTree(BinarySearchTree& bst)
{
    root = bst.getRoot();
}

// Destructor
// Parameters: none
BinarySearchTree::~BinarySearchTree()
{
    BinarySearchTree::recursiveDelete(root);    // calls the function to recursively delete the tree
}

// Recursive destructor
// Parameters: Node
// Return: none
void BinarySearchTree::recursiveDelete(Node * n)
{
    if (n != nullptr)                                       // postorder traversal
    {                                                       // starts deleting at leftmost leaf in tree
        BinarySearchTree::recursiveDelete(n->getLeft());
        BinarySearchTree::recursiveDelete(n->getRight());
        delete n;
        n = nullptr;
    }
}

// Root accessor
// Parameters: none
// Return: Node
Node* BinarySearchTree::getRoot()
{
    return root;
}

// Root mutator
// Parameters: Node
// Return: none
void BinarySearchTree::setRoot(Node * n)
{
    root = n;
}

// Insert Node into tree
// Parameters: int, int, Node
// Return: none
void BinarySearchTree::insertNode(int coeff, int exp, Node * current)
{
    if (root == nullptr)                                                        // if tree is empty
        root = new Node(coeff, exp);
    else if (exp == current->getExponent())                                     // if new node has same exponent as current node
        current->setCoefficient(current->getCoefficient() + coeff);             // combine coefficients
     else if (exp < current->getExponent() && current->getLeft() == nullptr)    // if new node has smaller exponent than current
        current->setLeft(new Node(coeff, exp));                                 // but current has no left tree, set new node as
                                                                                // left tree
    else if (exp > current->getExponent() && current->getRight() == nullptr)    // if new node has larger exponent than current
        current->setRight(new Node(coeff, exp));                                // but current has no right tree, set new node as
                                                                                // right tree
    else if (exp < current->getExponent())                                      // if new node has smaller exponent than current
        BinarySearchTree::insertNode(coeff, exp, current->getLeft());           // and current has a left tree, set current to
                                                                                // left tree
    else                                                                        // if new node has larger exponent than current
        BinarySearchTree::insertNode(coeff, exp, current->getRight());          // and current has a right tree, set current to
                                                                                // right tree
}

// Converts a double to a string
// Parameters: double
// Return: string
string doubleToString(double d)
{
    stringstream ss;
    ss << d;
    return ss.str();
}

// Get new coefficient after finding the anti-derivative
// Parameters: int, int
// Return: string
string getNewCoeff(int numerator, int denominator)
{
    string s = "(";
    int tempNum = numerator;                            // save the original numerator
    int tempDen = denominator;                          // save the original denominator
    while (true)                                        // finds the greatest common divisor
    {
        tempNum %= tempDen;
        if (tempNum == 0)
        {
            numerator /= tempDen;
            denominator /= tempDen;
            s += doubleToString(numerator) + "/"        // puts number back into fraction form
              + doubleToString(denominator) + ")";
            break;
        }
        tempDen %= tempNum;
        if (tempDen == 0)
        {
            numerator /= tempNum;
            denominator /= tempNum;
            s += doubleToString(numerator) + "/"        // puts number back into fraction form
              + doubleToString(denominator) + ")";
            break;
        }
    }

    if (numerator == 0)                                 // fraction is 0 if numerator is 0
        return "0";
    else if (numerator == (denominator * -1))           // if numerator is the same as the
        return "-1";                                    // opposite of the denominator, the
                                                        // fraction is -1
    else if (denominator == 1)                          // if number is over 1, fraction is
        return doubleToString(numerator);               // the numerator
    else if (denominator == -1)                         // if number is over -1, fraction is
        return doubleToString(numerator * -1);          // the opposite of the numerator
    else if (numerator == denominator)                  // if the numerator and denominator
        return "1";                                     // are the same, fraction is 1
    else                                                // if fraction doesn't need to be
        return s;                                       // modified, fraction stays the same
}

// Find anti-derivatives of trig functions
// Parameters: string, string
// Return: string
string BinarySearchTree::appendTrig(string original, string trigList)
{
    if (trigList == "")                                                     // if no trig functions in the equation
        return original;
    else                                                                    // if equation has trig functions
    {
        string result;
        while (trigList != "")
        {
            string temp = trigList.substr(0, trigList.find(';'));

            int coeff = atoi(temp.substr(0, temp.find(',')).c_str());       // coeff is first item in list
            temp = temp.substr(temp.find(',') + 1);
            int insideCoeff = atoi(temp.substr(0, temp.find(',')).c_str()); // insideCoeff is second item in list
            temp = temp.substr(temp.find(',') + 1);
            string trig = temp;                                             // trig is third item in list
            temp = "";

            if (trig == "sin")                                              // anti-derivate of sine is -cosine
                result += getNewCoeff(coeff * -1, insideCoeff) + "cos " + doubleToString(insideCoeff) + "x + ";
            else if (trig == "cos")                                         // anti-derivative of cosine is sine
                result += getNewCoeff(coeff, insideCoeff) + "sin " + doubleToString(insideCoeff) + "x + ";
            else                                                            // anti-derivative of secant^2 is tangent
                result += getNewCoeff(coeff, insideCoeff) + "tan " + doubleToString(insideCoeff) + "x + ";

            if (trigList.find(';') > trigList.length())                      // if no other parts to the equation
                trigList = "";                                               // after current part, end loop
            else
                trigList = trigList.substr(trigList.find(';') + 1);          // remove current part from equation
        }

        result = original.substr(0, original.find('C')) + result + "C";     // result is now original list, trig list, and + C

        for (unsigned int x = 0; x < result.length(); x++)
        {
            if (result.substr(x, 2) == "/-")                                     // moves negative to outside the coefficient if it is
            {                                                                    // part of the denominator
                result = result.substr(0, x).substr(0, result.substr(0, x).find_last_of('('))
                  + "-(" + result.substr(result.find('(') + 1, result.find('/') - (result.find('(') + 1))
                  + "/" + result.substr(x + 2);
                x = 0;
            }
            if (x < result.length() - 1 && (result.substr(x, 2) == "1c"         // changes 1x to x, 1sin to sin, 1cos to cos, 1tan to tan
                || result.substr(x, 2) == "1s" || result.substr(x, 2) == "1x"
                || result.substr(x, 2) == "1t"))
                result = result.substr(0, x) + result.substr(x + 1);
            if (x < result.length() - 2 && result.substr(x, 3) == "+ -")        // changes + -<part> to - <part>
                result = result.substr(0, x) + "- " + result.substr(x + 3);
        }

        return result;
    }
}

// Recursive inorder traversal of tree
// Parameters: Node, string
// Return: string
string BinarySearchTree::inorderTraversal(Node* n, string str)
{
    if (n != nullptr)                                                               // inorder traversal
    {                                                                               // gets parts of equation from greatest to least exponent
        str = inorderTraversal(n->getRight(), str);

        string coeff = getNewCoeff(n->getCoefficient(), n->getExponent() + 1);      // simplifies the coefficient if it's a fraction
        if (coeff == "1")                                                           // changes 1x to x
            str += "x^" + doubleToString(n->getExponent() + 1) + " + ";
        else if (coeff != "0")                                                      // if coefficient is 0, don't add part to equation
            str += coeff + "x^" + doubleToString(n->getExponent() + 1) + " + ";

        str = inorderTraversal(n->getLeft(), str);
    }

    return str;
}

// Recursively search for Node in tree
// Parameters: Node, Node
// Return: bool
bool BinarySearchTree::searchNode(Node * n, Node * current)
{
    if (current == nullptr)                                                                                     // if tree is empty
        return false;
    else if (n->getCoefficient() == current->getCoefficient() && n->getExponent() == current->getExponent())    // if node is found
        return true;
    else if (n->getExponent() < current->getExponent())                                                         // if current node is greater than the node's exponent
        BinarySearchTree::searchNode(n, current->getLeft());                                                    // continue searching on the left tree of node
    else                                                                                                        // if current node is less than the node's exponent
        BinarySearchTree::searchNode(n, current->getRight());                                                   // continue searching on the right tree of node

    return false;
}
