/*
    Assignment: Project #4
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   November 16, 2016 at 11:59pm

    //TRIG FUNCTIONS
*/

#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include "Node.h"
#include "BinarySearchTree.h"
using namespace std;

// Converts a double to a string
// Parameters: double
// Return: string
string dtos(double d)
{
    stringstream ss;
    ss << d;
    return ss.str();
}

// Solve indefinite integral
// Parameters: string
// Return: string
string solveIndefinite(string str)
{
    BinarySearchTree bst;
    string trigList = "";
    while (str != "")
    {
        string temp = str.substr(0, str.find(' '));

        if (temp.find('s') < temp.length())                                     // if part contains sine,
        {                                                                       // cosine, or secant
            int coeff = 0;
            int insideCoeff = 0;
            if (temp[temp.find('s') + 1] == 'i')                                // if part is sine
            {
                if (temp.substr(0, temp.find('s')) == "")                       // if no coefficient
                    coeff = 1;
                else if (temp.substr(0, temp.find('s')) == "-")                 // if coefficient of -1
                    coeff = -1;
                else                                                            // if coefficient something other than 1 or -1
                    coeff = atoi(temp.substr(0, temp.find('s')).c_str());

                insideCoeff = atoi(temp.substr(temp.find('n') + 1, temp.find('x') - (temp.find('n') + 1)).c_str()); // gets inside coefficient
                if (insideCoeff == 0)                                           // if no inside coefficient
                    insideCoeff++;

                trigList += dtos(coeff) + "," + dtos(insideCoeff) + ",sin;";    // trig list is in the format <coeff>,<insideCoeff>,<trig>;
            }
            else if (temp[temp.find('s') + 1] == 'e')                           // if part is secant
            {
                if (temp.substr(0, temp.find('s')) == "")                       // if no coefficient
                    coeff = 1;
                else if (temp.substr(0, temp.find('s')) == "-")                 // if coefficient of -1
                    coeff = -1;
                else                                                            // if coefficient something other than 1 or -1
                    coeff = atoi(temp.substr(0, temp.find('s')).c_str());

                insideCoeff = atoi(temp.substr(temp.find('2') + 1, temp.find('x') - (temp.find('2') + 1)).c_str()); // gets inside coefficient
                if (insideCoeff == 0)                                           // if no inside coefficient
                    insideCoeff++;

                trigList += dtos(coeff) + "," + dtos(insideCoeff) + ",sec;";    // trig list is in the format <coeff>,<insideCoeff>,<trig>;
            }
            else                                                                // if part is cosine
            {
                if (temp.substr(0, temp.find('c')) == "")                       // if no coefficient
                    coeff = 1;
                else if (temp.substr(0, temp.find('c')) == "-")                 // if coefficient of -1
                    coeff = -1;
                else                                                            // if coefficient something other than 1 or -1
                    coeff = atoi(temp.substr(0, temp.find('c')).c_str());

                insideCoeff = atoi(temp.substr(temp.find('s') + 1, temp.find('x') - (temp.find('s') + 1)).c_str()); // gets inside coefficient
                if (insideCoeff == 0)                                           // if no inside coefficient
                    insideCoeff++;

                trigList += dtos(coeff) + "," + dtos(insideCoeff) + ",cos;";    // trig list is in the format <coeff>,<insideCoeff>,<trig>;
            }
        }
        else if (temp != "0")
        {
            int coeff = 0;
            int exp = 0;

            if (temp.find('x') > str.length())                          // if no variable x
                exp = 0;
            else if (temp.find('^') > str.length())                     // if no exponent
                exp = 1;
            else                                                        // if exponent something other than 1 or -1
                exp = atoi(temp.substr(temp.find('^') + 1).c_str());

            if (temp[0] == 'x')                                         // if no coefficient
                coeff = 1;
            else                                                        // if coefficient something other than 1 or -1
                coeff = atoi(temp.substr(0, temp.find('x')).c_str());

            bst.insertNode(coeff, exp, bst.getRoot());                  // add to binary search tree
        }

        if (str.find(' ') > str.length())                               // if no other parts to the equation
            str = "";                                                   // after current part, end loop
        else
        {
            str = str.substr(str.find(' ') + 1);                        // remove current part from equation

            if (str.substr(0, 2) == "+ ")                               // if next part of equation is positive,
                 str = str.substr(2);                                   // remove plus sign
            else if (str.substr(0, 3) == "- x")                         // if next part of equation is negative and
                 str = "-1" + str.substr(2);                            // has no coefficient, add -1 to it
            else                                                        // if next part of equation is negative and
                str = "-" + str.substr(2);                              // has a coefficient, remove space between
        }                                                               // - and coefficient
    }

    string s = bst.inorderTraversal(bst.getRoot());                     // get equation in order of exponent from least to greatest
    s = s.substr(0, s.length() - 3) + " + C";                           // add constant

    for (unsigned int x = 0; x < s.length(); x++)
    {
        if (x < s.length() - 1 && s[x] == '1' && s[x + 1] == 'x'        // converts all instances of 1x to x
            && s[x - 1] == ' ')
            s = s.substr(0, x) + s.substr(x + 1);
        if (s.substr(x, 2) == "/-")                                     // moves negative to outside the coefficient if it is
        {                                                               // part of the denominator
            s = s.substr(0, x).substr(0, s.substr(0, x).find_last_of('('))
              + "-(" + s.substr(s.substr(0, x).find_last_of('(') + 1, x - s.substr(0, x).find_last_of('(') - 1)
              + "/" + s.substr(x + 2);
            x = 0;
        }
        if (s.substr(x, 3) == "^1 ")                                    // converts x^1 to x
            s = s.substr(0, x) + s.substr(x + 2);
        if (s.substr(x, 3) == "+ -")                                    // converts <part> + -<part> to <part> - <part>
            s = s.substr(0, x) + "- " + s.substr(x + 3);
        if (s.substr(x, 4) == "+ (-")                                   // moves negative to outside the coefficient if it is
            s = s.substr(0, x) + "- (" + s.substr(x + 4);               // part of the numerator

    }

    if (s.substr(0, 3) == " + ")                                        // removes a + if it is at the beginning of the entire
        s = s.substr(3);                                                // equation

    for (unsigned int x = 0; x < s.length(); x++)
    {
        if (s.substr(x, 3) == "+ -")                                    // converts <part> + -<part> to <part> - <part>
            s = s.substr(0, x) + "- " + s.substr(x + 3);
        if (s.substr(x, 2) == "(-")                                     // moves negative to outside the coefficient if it is
            s = s.substr(0, x) + "-(" + s.substr(x + 2);                // part of the numerator
    }

    return bst.appendTrig(s, trigList);                                 // add anti-derivatives of trig functions to equation
}

// Solve definite integral
// Parameters: string, int, int
// Return: string
double solveDefinite(string str, int a, int b)
{
    double totalA = 0;                                                  // result of plugging a into the integral
    double totalB = 0;                                                  // result of plugging b into the integral

    str = str.substr(0, str.length() - 4);                              // removes + C from both equations because it will cancel

    if (a == b)                                                         // if integral has no range, integral equals 0
        return 0;
    else
    {
        while (str.length() > 0 || str != "")
        {
            string temp;
            if (str.find(' ') < str.length())                           // gets the first part of the equation
                temp = str.substr(0, str.find(' '));
            else
                temp = str;

            double coeff = 0;
            if (temp[0] == 'x')                                         // if part has a coefficient of 1
                coeff++;
            else if (temp[0] == '-' && temp[1] == 'x')                  // if part has a coefficient of -1
                coeff--;
            else
            {
                if (temp[0] == '(')                                     // if part has a positive fraction coefficient
                    temp = temp.substr(1, temp.find(')') - 1)
                         + temp.substr(temp.find('x'));
                else if (temp[1] == '(')                                // if part has a negative fraction coefficient
                    temp = "-" + temp.substr(2, temp.find(')') - 2)
                         + temp.substr(temp.find('x'));
                else                                                    // converts coefficient into a fraction
                    temp = temp.substr(0, temp.find('x'))
                         + "/1" + temp.substr(temp.find('x'));

                coeff = atof(temp.substr(0, temp.find('/')).c_str())   // coefficient = numerator / denominator
                      / atof(temp.substr(temp.find('/') + 1, temp.find('x')
                      - temp.find('/')).c_str());
            }

            int exp;
            if (temp.find('^') > temp.length())                         // if no exponent, exponent is 1
                exp = 1;
            else if (temp.find('x') > temp.length())                    // if no variable x, exponent is 0
                exp = 0;
            else
                exp = atoi(temp.substr(temp.find('^') + 1,              // if exponent exists
                      temp.find(' ') - (temp.find('^') + 1)).c_str());

            totalA += coeff * pow(a, exp);                              // plugs in a for x and adds the result to totalA
            totalB += coeff * pow(b, exp);                              // plugs in a for x and adds the result to totalB

            if (str.find(' ') > str.length())                           // if no other parts to the equation
                str = "";                                               // after current part, end loop
            else
            {
                str = str.substr(str.find(' ') + 1);                    // remove current part from equation

                if (str[0] == '+')                                      // if next part of equation is positive,
                    str = str.substr(2);                                // remove plus sign
                else                                                    // if next part of equation is negative,
                    str = "-" + str.substr(2);                          // remove space between - and rest of equation
            }
        }
        return totalB - totalA;                                         // definite integral = F(b) - F(a)
    }
}

int main()
{
    ifstream inFile("integrals.txt");                                                   // opens integrals.txt for input
    if (inFile)                                                                         // if integrals.txt exists
    {
        ofstream outFile("answers.txt");                                                // opens answers.txt for output
        outFile << fixed << setprecision(3);                                            // sets all results to 3 decimals

        while (!inFile.eof())                                                           // for each line in the input until
        {                                                                               // it reaches the end of the file
            string eq;
            getline(inFile, eq);                                                        // gets the entire line from the file

            for (unsigned int x = 0; x < eq.length(); x++)                              // removes any spaces from the equation
            {                                                                           // (for continuity)
                if (eq[x] == ' ' && x > eq.find(' ') && x < (eq.length() - 3))
                    eq = eq.substr(0, x) + eq.substr(x + 1);
            }

            for (unsigned int x = 0; x < eq.length(); x++)                              // adds spaces between all parts of the
            {                                                                           // equation (for continuity)
                if (x > eq.find(' ') && x < (eq.length() - 3))
                {
                    if (eq[x] == '+' && eq[x - 1] != ' ' && eq[x + 1] != ' ')           // adds spaces if + sign is between parts
                        eq = eq.substr(0, x) + " + " + eq.substr(x + 1);
                    else if (eq.substr(x, 3) == "c^2")                                  // Skips over - if currently on a secant
                        x += 3;                                                         // function
                    else if (eq[x] == '-' && eq[x - 1] != '^' && eq[x - 1] != ' '       // adds spaces if - between parts and not
                             && eq[x + 1] != ' ' && (x - eq.find('s')) > 3)             // part of an exponent or trig function
                        eq = eq.substr(0, x) + " - " + eq.substr(x + 1);
                }
            }

            if (eq.substr(0, 2) == "| ")                                                // if equation is an indefinite integral
                outFile << solveIndefinite(eq.substr(2).substr(0, eq.length() - 5))     // remove | and dx from equation
                        << endl;
            else                                                                        // if equation is a definite integral
            {                                                                           // get values for a & b, then remove
                string indef = solveIndefinite(eq.substr(eq.find(' ') + 1,              // a|b and dx from equation
                             eq.find_last_of(' ') - (eq.find(' ') + 1)));
                outFile << indef.substr(0, indef.length() - 4) << ", "                  // outputs the anti-derivative (without a
                        << eq.substr(0, eq.find(' ')) << " = " << solveDefinite(indef,  // constant), then the range, then the
                        atoi(eq.substr(0, eq.find('|')).c_str()),                       // value of the definite integral
                        atoi(eq.substr(eq.find('|') + 1).substr(0, eq.find(' ')).c_str())) << endl;
            }
        }

        outFile.close();
    }
    inFile.close();

    return 0;
}
