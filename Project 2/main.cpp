/*
    Assignment: Project #2
    Author:     Matthew Bierman
    NetID:      mbb160030
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 3, 2016 at 11:59pm
*/

#include "ComplexNumber.h"
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

// verifies that there are no illegal characters in any complex numbers or operands
// Parameters: operand or complex number as a string, boolean that is true if the string is an operand, otherwise it is a complex number
// Return: boolean
bool verify(string str, bool isOperand)
{
    if (isOperand)
	{
	    if (str.length() < 3 && (str == "+" || str == "-" || str == "*" || str == "/" || str == "<" || str == ">" || str == "=" || str == "/="))    // Verifies that the operand is only a comparator or an operator
            return true;
        else
            return false;
	}

    else
	{
	    for (unsigned int index = 0; index < str.length(); index++)
        {
            if (!(str[index] == '0' || str[index] == '1' || str[index] == '2' || str[index] == '3' || str[index] == '4'                                 // verifies that the complex number contains only numbers, periods, plus signs, minus signs, and 'i's
               || str[index] == '5' || str[index] == '6' || str[index] == '7' || str[index] == '8' || str[index] == '9'
               || str[index] == '.' || str[index] == '+' || str[index] == '-' || str[index] == 'i'))
                return false;
        }

        if (str.find('i') < str.length() && str[str.length() - 1] != 'i')                                                                               // verifies any complex number that has an imaginary component does not have anything else after the 'i'
            return false;

        return true;

	}
}

// finds the length of the longest equation in the complex.txt file (used to determine the spacing of the columns in results.txt)
// Parameters: ifstream
// Return: int
int longestEquation(ifstream& inFile)
{
    int count = 0;
    string line;

    while (!inFile.eof())
    {
        getline(inFile, line);
        if (line.length() > (unsigned) count)
            count = line.length();
    }

    inFile.close();
    inFile.open("complex.txt");

    return count;
}

// verifies that there is no more than one period per number in the equation
// Parameters: string
// Return: bool
bool noExtraPeriods(string str)
{
    if (str[0] == '-')
        str = str.substr(1);
    string strPart1, strPart2;
    if (str.find('-') < str.length())                                                                                                             // If the real and imaginary numbers are separated by a minus sign
    {
        strPart1 = str.substr(0, str.find('-'));
        strPart2 = str.substr(str.find('-') + 1);
    }
    else if (str.find('+') < str.length())                                                                                                        // If the real and imaginary numbers are separated by a plus sign
    {
        strPart1 = str.substr(0, str.find('+'));
        strPart2 = str.substr(str.find('+') + 1);
    }
    else                                                                                                                                          // If there is only a real number or only an imaginary number
    {
        strPart1 = str;
        strPart2 = "";
    }

    int periodCount1 = 0;                                                                                                                         // counts the number of periods in the string
    for (unsigned int index = 0; index < strPart1.length(); index++)                                                                              // uses unsigned int to prevent the error of comparing ints to unsigned ints
    {
        if (strPart1[index] == '.')
            periodCount1++;
    }

    int periodCount2 = 0;                                                                                                                         // counts the number of periods in the string
    for (unsigned int index = 0; index < strPart2.length(); index++)                                                                              // uses unsigned int to prevent the error of comparing ints to unsigned ints
    {
        if (strPart2[index] == '.')
            periodCount2++;
    }


    if (periodCount1 < 2 && periodCount2 < 2)
        return true;
    else
        return false;
}

int main()
{
    ifstream inFile("complex.txt");                                                                                                               // Opens the input file "complex.txt"

    if (inFile)                                                                                                                                   // Program will end if "complex.txt" cannot be found
    {
	int longestEq = longestEquation(inFile);
	
        ofstream outFile("results.txt");                                                                                                          // Opens the output file "results.txt"
        while (!inFile.eof())                                                                                                                     // loops until it reaches the end of the file
        {
            string line, operand, originalLine;
            ComplexNumber firstComplexNumber, secondComplexNumber;
            getline(inFile, line);                                                                                                                // gets the entire line from the input
            originalLine = line;

            int spaceCount = 0;                                                                                                                   // counts the number of spaces in the string
            for (unsigned int index = 0; index < line.length(); index++)                                                                          // uses unsigned int to prevent the error of comparing ints to unsigned ints
            {
                if (line[index] == ' ')
                    spaceCount++;
            }

            if (spaceCount == 2)                                                                                                                  // equation is only valid if there are three separated pieces
            {
                stringstream ss;
                ss << line;
                ss >> firstComplexNumber;

                if (verify(line.substr(0, line.find(' ')), false) && noExtraPeriods(line.substr(0, line.find(' '))))                              // verifies the first complex number is valid
                {
                    ss >> operand;
                    line = line.substr(line.find(' ') + 1);                                                                                       // removes the first complex number from the string
                    if (verify(line.substr(0, line.find(' ')), true))                                                                             // verifies the operand is valid
                    {
                        ss >> secondComplexNumber;
                        line = line.substr(line.find(' ') + 1);                                                                                   // removes the operand from the string

                        if (verify(line, false) && noExtraPeriods(line))                                                                          // verifies the second complex number is valid
                        {
                            outFile << left << setw(longestEq + 2) << originalLine;                                                               // prints the original equation

                            outFile << setprecision(2);                                                                                           // sets all floating point values to 2 decimal places

                            if (operand == "+")
                                outFile << (firstComplexNumber + secondComplexNumber);                                                            // addition
                            else if (operand == "-")
                                outFile << (firstComplexNumber - secondComplexNumber);                                                            // subtraction
                            else if (operand == "*")
                                outFile << (firstComplexNumber * secondComplexNumber);                                                            // multiplication
                            else if (operand == "/")
                                outFile << (firstComplexNumber / secondComplexNumber);                                                            // division
                            else if (operand == "<")                                                                                              // prints true is first complex number is less than second complex number, otherwise false
                            {
                                if (firstComplexNumber < secondComplexNumber)
                                    outFile << "true";
                                else
                                    outFile << "false";
                            }

                            else if (operand == ">")                                                                                              // prints true is first complex number is greater than second complex number, otherwise false
                            {
                                if (firstComplexNumber > secondComplexNumber)
                                    outFile << "true";
                                else
                                    outFile << "false";
                            }

                            else if (operand == "=")                                                                                              // prints true is first complex number equals second complex number, otherwise false
                            {
                                if (firstComplexNumber == secondComplexNumber)
                                    outFile << "true";
                                else
                                    outFile << "false";
                            }

                            else if (operand == "/=")                                                                                             // prints true is first complex number does not equal second complex number, otherwise false
                            {
                                if (firstComplexNumber != secondComplexNumber)
                                    outFile << "true";
                                else
                                    outFile << "false";
                            }

                            outFile << endl;

                        }
                    }
                }
            }
        }
        outFile.close();                                                                                                                          // Closes the output file
    }

    inFile.close();                                                                                                                               // Closes the input file
    return 0;
}
