/*
    Assignment: Project #4
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   November 16, 2016 at 11:59pm

    //TRIG FUNCTIONS
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <string>
#include "Node.h"
using namespace std;

class BinarySearchTree
{
private:
    Node * root;                                        // Root Node of tree
public:
    BinarySearchTree();                                 // Default constructor
    BinarySearchTree(Node*);                            // Overloaded constructor
    BinarySearchTree(BinarySearchTree&);                // Copy constructor
    ~BinarySearchTree();                                // Destructor
    void recursiveDelete(Node*);                        // Recursive destructor
    Node* getRoot();                                    // Root accessor
    void setRoot(Node*);                                // Root mutator
    void insertNode(int, int, Node*);                   // Insert Node into tree
    string appendTrig(string, string);                  // Find anti-derivatives of trig functions
    string inorderTraversal(Node*, string str = "");    // Recursive inorder traversal of tree
    bool searchNode(Node*, Node*);                      // Recursively search for Node in tree
};

#endif // BINARYSEARCHTREE_H
