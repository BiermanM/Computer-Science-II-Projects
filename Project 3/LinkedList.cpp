/*
    Assignment: Project #3
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 26, 2016 at 11:59pm

    // Binary Search Lines #237-328
*/

#include "LinkedList.h"
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

// Default constructor
// Parameters: none
// Return: none
LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}

// Overloaded constructor
// Parameters: DoubleLinkNode
// Return: none
LinkedList::LinkedList(DoubleLinkNode* n)
{
    if (head == nullptr)            // If list is empty, n becomes head
        head = n;
    else                            // Otherwise, n is inserted after head
    {
        n->setNext(head);
        n->setPrev(nullptr);
        head = n;
    }
}

// Destructor
// Parameters: none
// Return: none
LinkedList::~LinkedList()
{
    recursiveDelete(head);
}

// Head pointer accessor
// Parameters: none
// Return: DoubleLinkNode
DoubleLinkNode* LinkedList::getHead()
{
    return head;
}

// Tail pointer accessor
// Parameters: none
// Return: DoubleLinkNode
DoubleLinkNode* LinkedList::getTail()
{
    return tail;
}

// Head pointer mutator
// Parameters: DoubleLinkNode
// Return: none
void LinkedList::setHead(DoubleLinkNode* n)
{
    head = n;
}

// Tail pointer mutator
// Parameters: DoubleLinkNode
// Return: none
void LinkedList::setTail(DoubleLinkNode* n)
{
    tail = n;
}

// Overloaded stream insertion operator
// Parameters: output file stream, LinkedList
// Return: output file stream
ofstream& operator<<(ofstream& outFile, LinkedList& ll)
{
    int longestName = 0;
    DoubleLinkNode * current = ll.getHead();
    while (current != nullptr)
    {
        if (current->getPilotName().length() > (unsigned) longestName)
            longestName = current->getPilotName().length();
        current = current->getNext();
    }
    return ll.recursivePrint(outFile, ll.getHead(), longestName + 2);
}

// Insert DoubleLinkNode into list
// Parameters: DoubleLinkNode
// Return: none
void LinkedList::insert(DoubleLinkNode * n)
{
    if (head == nullptr && tail == nullptr) // If list is empty, new
    {                                       // node becomes both head and tail
        head = n;
        tail = n;
    }
    else                                    // Otheriwse, new node is added
    {                                       // to the end of the list and becomes
        n->setPrev(tail);                   // the tail
        tail->setNext(n);
        tail = n;
    }
}

// Sorts list into ascending order alphabetically or numerically
// Parameters: string
// Return: void
void LinkedList::sortList(string str)
{
    DoubleLinkNode * current = head;
    bool isInOrder = LinkedList::inOrder(str);                                                      // Checks if the list is already in order
    while(!isInOrder)                                                                               // While the list is not in order
    {
        current = head;
        
        if (str == "area")
        {
            while(current->getNext() != nullptr && current->getPatrolArea() <= current->getNext()->getPatrolArea()) // Finds a node where the node after it is smaller than it
                current = current->getNext();
        }
        else
        {
            while(current->getNext() != nullptr && current->getPilotName() <= current->getNext()->getPilotName())   // Finds a node where the node after it is smaller than it
                current = current->getNext();
        }

        while(current->getNext() != nullptr && current <= current->getNext())                       // Finds a node where the node after it is smaller than it
            current = current->getNext();

        if (current->getNext() != nullptr && ((current->getPatrolArea() > current->getNext()->getPatrolArea() && str == "area") || (current->getPilotName() > current->getNext()->getPilotName() && str == "pilot")))                          // If the two nodes need to be swapped
        {
            if (current->getPrev() == nullptr && current->getNext()->getNext() != nullptr)           // Swapping two nodes, one of which is the head of the list
            {
                current->getNext()->setPrev(nullptr);
                current->setPrev(current->getNext());
                current->setNext(current->getNext()->getNext());
                current->getPrev()->setNext(current);
                current->getNext()->setPrev(current);
                LinkedList::setHead(current->getPrev());                                             // Head is now the swapped node
            }
            else if (current->getPrev() != nullptr && current->getNext()->getNext() != nullptr)      // Swapping two nodes, neither of which are at the ends of the list
            {
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                current->setPrev(current->getNext());
                current->setNext(current->getNext()->getNext());
                current->getPrev()->setNext(current);
                current->getNext()->setPrev(current);
            }
            else if (current->getPrev() != nullptr && current->getNext()->getNext() == nullptr)      // Swapping two nodes, one of which is the tail of the list
            {
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                current->setPrev(current->getNext());
                current->setNext(nullptr);
                current->getPrev()->setNext(current);
                LinkedList::setTail(current);                                                       // Tail is now the swapped node
            }
            else if (current->getPrev() == nullptr && current->getNext()->getNext() == nullptr)      // Swapping two nodes, the two nodes are the only nodes in the list
            {
                current->setPrev(current->getNext());
                current->setNext(nullptr);
                current->getPrev()->setNext(current);
                current->getPrev()->setPrev(nullptr);
                LinkedList::setHead(current->getPrev());                                            // Head and tail are switched
                LinkedList::setTail(current);
            }
        }
        isInOrder = LinkedList::inOrder(str);                                                       // Checks if the list is now in order with the new changes
    }
}

// Checks if the list is currently in ascending order
// Parameters: string
// Return: boolean
bool LinkedList::inOrder(string str)
{
    DoubleLinkNode * current = head;
    while(current->getNext() != nullptr)
    {
        if (!isGreaterThanOrEqualTo(current->getNext(), current, str))  // if the current node is larger than the
            return false;                                               // next node, then the list is not in order
        current = current->getNext();
    }
    return true;
}

// Recursively prints the data for each DoubleLinkNode in the list, from first to last
// Parameters: output file stream, DoubleLinkNode
// Return: output file stream
ofstream& LinkedList::recursivePrint(ofstream& outFile, DoubleLinkNode* n, int columnLength)
{
    outFile << fixed << setprecision(2) << left << setw(columnLength)   // All areas are rounded to two decimal places
         << n->getPilotName() << "\t" << n->getPatrolArea() << endl;    // Prints in the format of "<Name><Tab><Area>"
    if (n->getNext() != nullptr)
        recursivePrint(outFile, n->getNext());                          // Prints the next node until it reaches the end of the list

    return outFile;
}

// Recursively deletes all DoubleLinkNodes in the list, from last to first
// Parameters: DoubleLinkNode
// Return: none
void LinkedList::recursiveDelete(DoubleLinkNode* n)
{
    if (n->getNext() != nullptr)            // Finds the tail of the list
        recursiveDelete(n->getNext());

    if (n->getPrev() != nullptr)            // Removes the previous node's link to the current node
        n->getPrev()->setNext(nullptr);
    delete n;                               // Deletes the node
}

// Checks if the first DoubleLinkNode is greater than the second DoubleLinkNode based on name or area
// Parameters: DoubleLinkNode, DoubleLinkNode, string
// Return: boolean
bool LinkedList::isGreaterThan(DoubleLinkNode* a, DoubleLinkNode* b, string str)
{
    if (str == "area")                                      // compares the two nodes by their areas
        return (a->getPatrolArea() > b->getPatrolArea());

    else                                                    // compares the two nodes by their names
        return (a->getPilotName() > b->getPilotName());
}

// Checks if the first DoubleLinkNode is greater than or equal to the second DoubleLinkNode based on name or area
// Parameters: DoubleLinkNode, DoubleLinkNode, string
// Return: boolean
bool LinkedList::isGreaterThanOrEqualTo(DoubleLinkNode* a, DoubleLinkNode* b, string str)
{
    if (str == "area")                                      // compares the two nodes by their areas
        return (a->getPatrolArea() >= b->getPatrolArea());

    else                                                    // compares the two nodes by their names
        return (a->getPilotName() >= b->getPilotName());
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

// Searches for a DoubleLinkNode containing the given name or area
// Parameters: string
// Return: string
string LinkedList::searchFor(string str)
{
    if (str.find("0") <= (unsigned) str.length() || str.find("1") <= (unsigned) str.length() || str.find("2") <= (unsigned) str.length() ||
        str.find("3") <= (unsigned) str.length() || str.find("4") <= (unsigned) str.length() || str.find("5") <= (unsigned) str.length() ||
        str.find("6") <= (unsigned) str.length() || str.find("7") <= (unsigned) str.length() || str.find("8") <= (unsigned) str.length() ||
        str.find("9") <= (unsigned) str.length())           // If the item being searched for is an area
    {
        double num = atof(str.c_str());
        int left = 0;
        int right = 0;
        DoubleLinkNode * current = head;
        while (current != nullptr)
        {
            right++;
            current = current->getNext();
        }
        right--;

        while (left <= right)
        {
            int middle = (left + right) / 2;

            DoubleLinkNode * current = head;
            for (int x = 0; x < middle; x++)
                current = current->getNext();

            if (abs(current->getPatrolArea() - num) < 0.001)
                  return str + " found";
            else if (current->getPatrolArea() > num)
                  right = middle - 1;
            else
                  left = middle + 1;
        }
        return str + " not found";
    }
    else
    {
        int left = 0;
        int right = 0;
        DoubleLinkNode * current = head;
        while (current != nullptr)
        {
            right++;
            current = current->getNext();
        }
        right--;

        while (left <= right)
        {
            int middle = (left + right) / 2;

            DoubleLinkNode * current = head;
            for (int x = 0; x < middle; x++)
                current = current->getNext();

            if (current->getPilotName() == str)
                  return str + " found";
            else if (current->getPilotName() > str)
                  right = middle - 1;
            else
                  left = middle + 1;
        }
        return str + " not found";
    }

    /*  Old searchFor function
    if (str.find("0") <= (unsigned) str.length() || str.find("1") <= (unsigned) str.length() || str.find("2") <= (unsigned) str.length() ||
        str.find("3") <= (unsigned) str.length() || str.find("4") <= (unsigned) str.length() || str.find("5") <= (unsigned) str.length() ||
        str.find("6") <= (unsigned) str.length() || str.find("7") <= (unsigned) str.length() || str.find("8") <= (unsigned) str.length() ||
        str.find("9") <= (unsigned) str.length())           // If the item being searched for is an area
    {
        double num = atof(str.c_str());
        DoubleLinkNode * current = tail;                        // Checks from the tail and works up to the top of the list
        while (current->getPrev() != nullptr)
        {
            if (num == current->getPrev()->getPatrolArea())
                return str + " found";
            current = current->getPrev();
        }
        return str + " not found";
    }
    else                                                        // Otherwise, the item being searched for is a name
    {
        DoubleLinkNode * current = tail;                        // Checks from the tail and works up to the top of the list
        while (current->getPrev() != nullptr)
        {
            if (str == current->getPrev()->getPilotName())
                return str + " found";
            current = current->getPrev();
        }
        return str + " not found";
    }
    */
}

