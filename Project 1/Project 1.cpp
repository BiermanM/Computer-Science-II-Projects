/*
    Assignment: Project #1
    Author:     Matthew Bierman
    NetID:      mbb160030
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   September 14, 2016 at 11:59pm
*/

#include <string>                                                                                               // Used for the name of the pilot
#include <fstream>                                                                                              // Used for inputting a pilot's name and coordinates from a file and outputting the same pilot's name and total area patrolled by the pilot to a different file
#include <cmath>                                                                                                // Used in the formula to solve for the total area patrolled by the pilot
#include <iomanip>                                                                                              // Used for setting the area to two decimal places when being outputted

using namespace std;

// Retrieves x and y coordinates from the input file and stores them in their respective arrays
// Parameters: x coordinate array, y coordinate array, input file stream (pilot_routes.txt)
// Return: nothing
void getCoords(double xCoord[], double yCoord[], ifstream& inFile)
{
    int index = 0;                                                                                              // Starting at the first component of each array
    while (inFile.peek() != '\n' && !inFile.eof())                                                              // Continues to take input from the file until it reaches the end of the line or the end of the file
    {
        inFile >> xCoord[index];                                                                                // Since the coordinates are in the format of 'x,y' (without single quotes), the first number is taken as the x coordinate
        inFile.ignore();                                                                                        // Comma is skipped over
        inFile >> yCoord[index];                                                                                // The second number is taken as the y coordinate
        index++;                                                                                                // Moves to the next component in each array
    }
}

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

// Removes all coordinates from both x and y coordinate arrays
// Parameters: x coordinate array, y coordinate array
// Return: nothing
void clearArr(double xCoord[], double yCoord[])
{
    for (int n = 0; n < 15; n++)                                                                                // Goes through each component of both arrays and sets the values to 0
    {
        xCoord[n] = 0;
        yCoord[n] = 0;
    }
}

int main()
{
    ifstream inFile("pilot_routes.txt");                                                                        // Opens file pilot_routes.txt for input
    if (inFile)                                                                                                 // Program will end if pilot_routes.txt cannot be found
    {
        ofstream outFile("pilot_areas.txt");                                                                    // Opens/Creates file pilot_areas.txt for output

        while (!inFile.eof())                                                                                   // Looks at each line in the input file until it reaches the end of the file
        {
            string pilotName;                                                                                   // Declares a variable to store the name of the pilot
            inFile >> pilotName;                                                                                // Takes the first part of the line of the input file and stores it as the pilot's name

            double xCoord[15];                                                                                  // Declares an array of size 15 to hold all x coordinates, since there is a maximum number of 15 coordinates for each pilot
            double yCoord[15];                                                                                  // Declares an array of size 15 to hold all y coordinates, Since there is a maximum number of 15 coordinates for each pilot

            getCoords(xCoord, yCoord, inFile);
            outFile << pilotName << "\t" << fixed << setprecision(2) << calcArea(xCoord, yCoord) << endl;       // Prints the pilot's name and total area of their route, with the area set to 2 decimal places
            clearArr(xCoord, yCoord);                                                                           // Removes all coordinates from their respective arrays
        }

        outFile.close();                                                                                        // Closes the output file
    }

    inFile.close();                                                                                             // Closes the input file

    return 0;
}
