/*
    Assignment: Project #4
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   November 16, 2016 at 11:59pm

    //TRIG FUNCTIONS
*/

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
private:
    int coefficient;            // coefficient of the variable
    int exponent;               // exponent of the variable
    Node * left;                // left child of the Node
    Node * right;               // right child of the Node
public:
    Node();                     // default constructor
    Node(int, int);             // overloaded constructor
    Node(Node*);                // copy constructor
    int getCoefficient();       // coefficient accessor
    int getExponent();          // exponent accessor
    Node* getLeft();            // left child accessor
    Node* getRight();           // right child accessor
    void setCoefficient(int);   // coefficient mutator
    void setExponent(int);      // exponent mutator
    void setLeft(Node*);        // left child mutator
    void setRight(Node*);       // right child mutator
};

#endif // NODE_H
