/*
    Assignment: Project #3
    Author:     Matthew Bierman
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 26, 2016 at 11:59pm

    // Binary Search Call Line #250
*/

#include "BaseNode.h"
#include "DoubleLinkNode.h"
#include "LinkedList.h"

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <stdlib.h>

using namespace std;

// Calculates the area of the pilot's route given each x and y coordinate of the route
// Parameters: x coordinate array, y coordinate array
// Return: area of pilot's route
double calcArea(double xCoord[], double yCoord[])                                                               // The formula for finding the area of a shape is: 0.5 * absolute value of ( ((x(i+1) + x(i)) * (y(i+1) - y(i))) + ((x(i+2) + x(i+1)) * (y(i+2) - y(i+1))) + ... + ((x(i+(n-2)) + x(i+(n-1))) * (y(i+(n-2)) - y(i+(n-1)))) )
{                                                                                                               // Where i is any integer greater than or equal to zero, i starts at zero until it reaches n - 2, where n is the total number of coordinates
    int n = 1;                                                                                                  // The count (n) will start at 1, because the value of when n = 0 will be placed in the sum when the variable for the sum is declared and initialized
    double sum = (xCoord[1] + xCoord[0]) * (yCoord[1] - yCoord[0]);                                             // The sum of the points that make up the pilot's route is declared and initialized to when n = 0

    while (xCoord[0] != xCoord[n] || yCoord[0] != yCoord[n])                                                    // Since the first and last coordinates will be the same, this loop will traverse through each component of the x and y coordinate arrays until it reaches the last pair of coordinates
    {
        sum += (xCoord[n + 1] + xCoord[n]) * (yCoord[n + 1] - yCoord[n]);                                       // The value calculated from these two pairs of coordinates are added to the sum
        n++;                                                                                                    // Moves to the next component in each array
    }

    return abs(sum) * 0.5;                                                                                      // The absolute value is taken of the array and multiplied by 0.5, which is the area of the pilot's route. The area is returned
}

// Deallocates memory of x and y coordinate arrays
// Parameters: x coordinate array, y coordinate array
// Return: nothing
void clearArr(double xCoord[], double yCoord[], int num)
{
    delete [] xCoord;
    delete [] yCoord;
}

// Converts string of coordinates into an array of x coordinates and an array of y coordinates
// Parameters: double array, double array, string
// Return: nothing
void coordsIntoArray(double xCoords[], double yCoords[], string coords)
{
    int num = 0;
    while (coords.length() > 0)
    {
        string temp;                                            // Temp becomes one coordinate pair, in the form "<xCoordinate>,<yCoordinate>"
        if (coords.find(' ') == (unsigned) -1)                  // No need for using substring if it is the last coordinate pair in the string
        {
            temp = coords;
            coords = "";
        }
        else
        {
            temp = coords.substr(0, coords.find(' '));
            coords = coords.substr(coords.find(' ') + 1);
        }

        string tempX = "";
        string tempY = "";
        bool foundComma = false;

        for (int x = 0; x < (signed) temp.length(); x++)        // Sets tempX to everything before the comma
        {                                                       // Sets tempY to everything after the comma
            if(temp[x] == 44)
                foundComma = true;
            else if (!foundComma)
                tempX += temp[x];
            else
                tempY += temp[x];
        }

        xCoords[num] = atof(tempX.c_str());                     // Converts the substring to the left of the comma into a double
        yCoords[num] = atof(tempY.c_str());                     // Converts the substring to the right of the comma into a double

        num++;                                                  // Moves to the next element in both arrays

    }
}

// Checks both the name and coordinate list from pilot_routes.txt to verify that they are valid
// Parameters: string, string
// Return: boolean
bool firstValidationCheck(string name, string coords)
{
    if (name[name.length() - 1] != 32)                                                                                  // There can't not be a space in between the name and coordinate list
        return false;

    if (!(name[0] == 32 || (name[0] >= 65 && name[0] <= 90) || (name[0] >= 97 && name[0] <= 122)))                      // The first character of name can't be something other than spaces, lowercase letters, and uppercase letters
        return false;

    name = name.substr(0, name.length() - 1);
    if (name[name.length() - 1] == 32)                                                                                  // The last character of name can't be a space
        return false;

    for (int x = 0; x < (signed) coords.length(); x++)
    {
        if (!((coords[x] >= 44 && coords[x] <= 46) || (coords[x] >= 48 && coords[x] <= 57) || coords[x] == 32))         // Coordinates can't contain anything other than numbers, a minus sign, commas, spaces, and periods
            return false;
        else if (coords[x] == 45 && ((coords[x-1] >= 48 && coords[x-1] <= 57) || coords[x-1] == 46))                    // A minus sign can't come after a number or period
            return false;
        else if ((x == 0 && coords[x] == 44) || (x == (signed) coords.length() - 1 && coords[x] == 44))                 // A comma can't be the first or last character of a coordinate list
            return false;
        else if (x == (signed) coords.length() - 1 && coords[x] == 45)                                                  // A minus sign can't be the last character of a coordinate list
            return false;
    }

    int numCommas = 0;
    int numSpaces = 0;
    for (int x = 0; x < (signed) coords.length(); x++)                                                                  // A coordinate list can't have more than one comma per coordinate pair and can't have extra spaces
    {
        if (coords[x] == 32)
        {
            numSpaces++;
            if (coords[x-1] == 32 || coords[x-1] == 44 || coords[x+1] == 32 || coords[x+1] == 44)
                return false;
        }

        else if (coords[x] == 44)
        {
            numCommas++;
            if (coords[x-1] == 32 || coords[x-1] == 44 || coords[x+1] == 32 || coords[x+1] == 44)
                return false;
        }
    }

    if ((numSpaces + 1) != numCommas)
        return false;


    string firstCoordPair = coords.substr(0, coords.find(' '));
    string lastCoordPair = coords.substr(coords.find(' ') + 1);
    while (lastCoordPair.find(' ') != (unsigned) -1)
        lastCoordPair = lastCoordPair.substr(1);

    if (firstCoordPair != lastCoordPair)                                                                                // The last coordinate pair must be the same as the first coordinate pair
        return false;


    return true;
}

// Checks command from commands.txt to verify that they are valid
// Parameters: string
// Return: boolean
bool secondValidationCheck(string line)
{
    if (line == "sort area" || line == "sort pilot")                                                                    // Two of the valid commands are "sort area" and "sort pilot"
        return true;
    else if (line.substr(0, 4) == "sort" || line == "search" || line.substr(0, 7) == "search ")                         // Using "sort" with any criteria other than "area" and "pilot" is not valid
        return false;                                                                                                   // and using "search" to search is not valid
    
    if (line.find('-') > 0 && line.find('-') < line.length())                                                           // A command can't have a minus sign that isn't the first character
        return false;                                                                                                   // A minus sign would mean that the command is to search for an area

    bool hasNumbers = false;
    bool hasLetters = false;
    int minusSignCount = 0;
    int periodCount = 0;
    for (int x = 0; x < (signed) line.length(); x++)                                                                    // A command can only be an area or a name, meaning it can't be a command that has both letters and numbers
    {                                                                                                                   // Numbers are only valid if they contain, at most, one minus sign and one period
        if (line[x] == 45)
            minusSignCount++;
        else if (line[x] == 46)
            periodCount++;

        if (minusSignCount > 1 || periodCount > 1)
            return false;

        if (line[x] >= 48 && line[x] <= 57)
            hasNumbers = true;
        else if ((line[x] >= 65 && line[x] <= 90) || (line[x] >= 97 && line[x] <= 122))
            hasLetters = true;

        if (hasNumbers == true && hasLetters == true)
            return false;
        if (line[x] < 20 || (line[x] > 20 && line[x] < 45) || line[x] == 47 || (line[x] >= 58 && line[x] <= 64) || (line[x] >= 91 && line[x] <= 96) || line[x] > 122)
            return false;
    }
    return true;
}

// Determines which type of commands being called
// Parameters: string
// Return: bool
bool getCommandType(string line)
{
    // Returns true if the command is a sort, returns false if the command is a search
    return (line == "sort area" || line == "sort pilot");
}

int main()
{
    LinkedList lList;
    ifstream inFile1("pilot_routes.txt");                                                                               // Opens file pilot_routes.txt for input
    if (inFile1)                                                                                                        // Program will end if pilot_routes.txt cannot be found
    {
        while(!inFile1.eof())                                                                                           // For each line of pilot_routes.txt until it reaches the end of the file
        {
            string line, name, coords;
            getline(inFile1, line);

            for (int x = 0; x < (signed) line.length(); x++)
            {
                if ( !( line[x] == 32 || (line[x] >= 65 && line[x] <= 90) || (line[x] >= 97 && line[x] <= 122) ) )      // Searches for where the name ends and coordinate list begins
                {
                    name = line.substr(0, x);                                                                           // Original line is split into two variables, one for the name and another for the coordinate list
                    coords = line.substr(x);
                    break;
                }
            }


            if (firstValidationCheck(name, coords))                                                                     // Verifies name and coordinate list are both valid
            {
                name = name.substr(0, name.length() - 1);                                                               // Removes the extra space at the end of the name
                int coordCount = 0;

                for (int x = 0; x < (signed) coords.length(); x++)                                                      // Counts the number of coordinate pairs
                {
                    if (coords[x] == 44)
                        coordCount++;
                }

                double * xCoords = new double[coordCount];                                                              // Creates a dynamic array for x coordinates
                double * yCoords = new double[coordCount];                                                              // Creates a dynamic array for y coordinates

                coordsIntoArray(xCoords, yCoords, coords);                                                              // Splits coordinates into corresponding x and y coordinate arrays
                lList.insert(new DoubleLinkNode(nullptr, nullptr, name, calcArea(xCoords, yCoords)));                   // Calculates the area of the polygon formed by the coordinates and a DoubleLinkNode is created for the pilot, containing his name and patrol area
                clearArr(xCoords, yCoords, coordCount);                                                                 // Deallocates memory of x and y coordinate arrays
            }
        }
    }
    inFile1.close();                                                                                                    // Closes input file

    ifstream inFile2("commands.txt");                                                                                   // Opens file commands.txt for input
    if (inFile2)                                                                                                        // Program will end if commands.txt cannot be found
    {
        ofstream outFile1("results.txt");                                                                               // Opens results.txt for output
        while (!inFile2.eof())                                                                                          // For each line of commands.txt until it reaches the end of the file
        {
            string line;
            getline(inFile2, line);

            if (secondValidationCheck(line))                                                                            // Verifies command is valid
            {
                if (!getCommandType(line))                                                                              // If command is a search
                    outFile1 << lList.searchFor(line) << endl;                                                          // Output result to results.txt
            }
        }
        outFile1.close();                                                                                               // Close output file
    }
    inFile2.close();                                                                                                    // Closes input file

    ofstream outFile2("pilot_areas.txt");                                                                               // Opens pilot_areas.txt for output
    outFile2 << lList;                                                                                                  // Prints contents of linked list into pilot_areas.txt
    outFile2.close();                                                                                                   // Closes output file
    return 0;
}
