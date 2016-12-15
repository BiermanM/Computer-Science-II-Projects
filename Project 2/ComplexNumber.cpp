/*
    Assignment: Project #2
    Author:     Matthew Bierman
    NetID:      mbb160030
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 3, 2016 at 11:59pm
*/

#include "ComplexNumber.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

// default constructor
ComplexNumber::ComplexNumber()
{
    realNumberComponent = 0;
    imaginaryNumberComponent = 0;
}

// overloaded constructor
ComplexNumber::ComplexNumber(double rnc, double inc)
{
    realNumberComponent = rnc;
    imaginaryNumberComponent = inc;
}

// copy constructor
ComplexNumber::ComplexNumber(ComplexNumber& num)
{
    realNumberComponent = num.realNumberComponent;
    imaginaryNumberComponent = num.imaginaryNumberComponent;
}

// real number component accessor
// Parameters: none
// Return: real number component
double ComplexNumber::getRealNumberComponent() const
{
    return realNumberComponent;
}

// imaginary number component accessor
// Parameters: none
// Return: imaginary number component
double ComplexNumber::getImaginaryNumberComponent() const
{
    return imaginaryNumberComponent;
}

// real number component mutator
// Parameters: real number component
// Return: none
void ComplexNumber::setRealNumberComponent(double rnc)
{
    realNumberComponent = rnc;
}

// imaginary number component mutator
// Parameters: imaginary number component
// Return: none
void ComplexNumber::setImaginaryNumberComponent(double inc)
{
    imaginaryNumberComponent = inc;
}

// overloaded addition operator
// Parameters: complex number object
// Return: new complex number
ComplexNumber ComplexNumber::operator+(const ComplexNumber& num) const
{
    ComplexNumber sum;

    sum.realNumberComponent = realNumberComponent + num.realNumberComponent;                        // real = real1 + real2
    sum.imaginaryNumberComponent = imaginaryNumberComponent + num.imaginaryNumberComponent;         // imaginary = imaginary1 + imaginary2

    return sum;
}

// overloaded subtraction operator
// Parameters: complex number object
// Return: new complex number
ComplexNumber ComplexNumber::operator-(const ComplexNumber& num) const
{
    ComplexNumber difference;

    difference.realNumberComponent = realNumberComponent - num.realNumberComponent;                 // real = real1 - real2
    difference.imaginaryNumberComponent = imaginaryNumberComponent - num.imaginaryNumberComponent;  // imaginary = imaginary1 - imaginary2

    return difference;
}

// overloaded multiplication operator
// Parameters: complex number object
// Return: new complex number
ComplexNumber ComplexNumber::operator*(const ComplexNumber& num) const
{
    ComplexNumber product;

    product.realNumberComponent = realNumberComponent * num.realNumberComponent;
    product.imaginaryNumberComponent = realNumberComponent * num.imaginaryNumberComponent;
    product.imaginaryNumberComponent += imaginaryNumberComponent * num.realNumberComponent;         // imaginary = (real1 * imaginary2) + (imaginary1 * real2)
    product.realNumberComponent -= imaginaryNumberComponent * num.imaginaryNumberComponent;         // real = (real1 * real2) - (imaginary1 * imaginary2)

    return product;
}

// overloaded division operator
// Parameters: complex number object
// Return: new complex number
ComplexNumber ComplexNumber::operator/(const ComplexNumber& num) const
{
    ComplexNumber quotient;
    double denominator;

    denominator = (num.realNumberComponent * num.realNumberComponent) - (num.imaginaryNumberComponent * num.imaginaryNumberComponent);

    quotient.realNumberComponent = realNumberComponent * num.realNumberComponent;
    quotient.imaginaryNumberComponent = realNumberComponent * num.imaginaryNumberComponent * -1;
    quotient.imaginaryNumberComponent += imaginaryNumberComponent * num.realNumberComponent;
    quotient.realNumberComponent += imaginaryNumberComponent * num.imaginaryNumberComponent;

    quotient.realNumberComponent /= denominator;                                                        // real = ((real1 * real2) + (imarginary1 * imaginary2)) / (real2^2 * imaginary2^2)
    quotient.imaginaryNumberComponent /= denominator;                                                   // imaginary = ((imaginary1 * real2) - (real1 * imaginary2)) / (real2^2 * imaginary2^2)

    return quotient;
}

// overloaded less than comparator
// Parameters: complex number object
// Return: boolean
bool ComplexNumber::operator<(const ComplexNumber& num) const
{
    if (sqrt(pow(realNumberComponent, 2) + pow(imaginaryNumberComponent, 2)) < sqrt(pow(num.realNumberComponent, 2) + pow(num.imaginaryNumberComponent, 2)))        // sqrt(real1^2 + imaginary1^2) < sqrt(real2^2 + imaginary2^2)
        return true;
    else
        return false;
}

// overloaded greater than comparator
// Parameters: complex number object
// Return: boolean
bool ComplexNumber::operator>(const ComplexNumber& num) const
{
    if (sqrt(pow(realNumberComponent, 2) + pow(imaginaryNumberComponent, 2)) > sqrt(pow(num.realNumberComponent, 2) + pow(num.imaginaryNumberComponent, 2)))        // sqrt(real1^2 + imaginary1^2) > sqrt(real2^2 + imaginary2^2)
        return true;
    else
        return false;
}

// overloaded equal to comparator
// Parameters: complex number object
// Return: boolean
bool ComplexNumber::operator==(const ComplexNumber& num) const
{
    if (realNumberComponent == num.realNumberComponent && imaginaryNumberComponent == num.imaginaryNumberComponent)         // real1 = real2 and imaginary1 = imaginary2
        return true;
    else
        return false;
}

// overloaded not equal to comparator
// Parameters: complex number object
// Return: boolean
bool ComplexNumber::operator!=(const ComplexNumber& num) const
{
    if (realNumberComponent == num.realNumberComponent && imaginaryNumberComponent == num.imaginaryNumberComponent)         // real1 != real2 or imaginary1 != imaginary2
        return false;
    else
        return true;
}

// overloaded stream insertion operator
// Parameters: stream insertion, complex number object
// Return: stream insertion
ostream& operator<<(ostream& cout, const ComplexNumber& num)
{
    if (num.getRealNumberComponent() == 0)
    {
        if (num.getImaginaryNumberComponent() == 0)
            cout << "0";                                                // 0
        else
        {
            if (num.getImaginaryNumberComponent() == 1)
                cout << "i";                                            // i
            else if (num.getImaginaryNumberComponent() == -1)
                cout << "-i";                                           // -i
            else
                cout << num.getImaginaryNumberComponent() << "i";       // bi or -bi
        }
    }
    else
    {
        cout << num.getRealNumberComponent();                           // a or -a
        if (num.getImaginaryNumberComponent() > 0)
            cout << "+";

        if (num.getImaginaryNumberComponent() == -1)
            cout << "-i";                                               // a-i or -a-i
        else if (num.getImaginaryNumberComponent() == 1)
            cout << "i";                                                // a+i or -a+i
        else if (num.getImaginaryNumberComponent() != 0)
            cout << num.getImaginaryNumberComponent() << "i";           // a+bi or -a+bi
    }
    return cout;
}

// overloaded stream extraction operator
// Parameters: stream extraction, complex number object
// Return: stream extraction
istream& operator>>(istream& cin, ComplexNumber& num)
{
    string str;
    cin >> str;

    if (str.find('i') > str.length())                                                           // if only a real number
    {
        num.setRealNumberComponent(atof(str.c_str()));                                          // real number component: a or -a
        num.setImaginaryNumberComponent(0);                                                     // imaginary number component: 0
    }

    else if (str.find('+', 1) < str.length() || str.find('-', 1) < str.length())                // if only a mixed number
    {
        int indexOfPlusMinus;
        if (str.find('+', 1) < str.length())
        {
            indexOfPlusMinus = str.find('+', 1);
            num.setImaginaryNumberComponent(atof(str.substr(indexOfPlusMinus + 1).c_str()));    // imaginary number component: b
        }

        else
        {
            indexOfPlusMinus = str.find('-', 1);
            num.setImaginaryNumberComponent(atof(str.substr(indexOfPlusMinus).c_str()));        // imaginary number component: -b
        }

        num.setRealNumberComponent(atof(str.substr(0, indexOfPlusMinus).c_str()));              // real number component: a
    }

    else                                                                                        // if only an imaginary number
    {
        num.setImaginaryNumberComponent(atof(str.substr(0, str.find('i')).c_str()));            // imaginary number component: b or -b
        num.setRealNumberComponent(0);                                                          // real number component: 0
    }

    return cin;
}
