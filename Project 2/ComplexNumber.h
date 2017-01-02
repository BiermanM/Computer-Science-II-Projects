/*
    Assignment: Project #2
    Author:     Matthew Bierman
    NetID:      mbb160030
    Course:     CS 2336.004 (Computer Science II)
    Instructor: Mr. Jason Smith
    Date Due:   October 3, 2016 at 11:59pm
*/

#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>

using namespace std;

class ComplexNumber
{
private:
    double realNumberComponent;                                 // real number component of the complex number
    double imaginaryNumberComponent;                            // imaginary number component of the complex number
public:
    ComplexNumber();                                            // default constructor
    ComplexNumber(double, double);                              // overloaded constructor
    ComplexNumber(ComplexNumber&);                              // copy constructor
    double getRealNumberComponent() const;                      // real number component accessor
    double getImaginaryNumberComponent() const;                 // imaginary number component accessor
    void setRealNumberComponent(double);                        // real number component mutator
    void setImaginaryNumberComponent(double);                   // imaginary number component mutator
    ComplexNumber operator+(const ComplexNumber&) const;        // overloaded addition operator
    ComplexNumber operator-(const ComplexNumber&) const;        // overloaded subtraction operator
    ComplexNumber operator*(const ComplexNumber&) const;        // overloaded multiplication operator
    ComplexNumber operator/(const ComplexNumber&) const;        // overloaded division operator
    bool operator<(const ComplexNumber&) const;                 // overloaded less than comparator
    bool operator>(const ComplexNumber&) const;                 // overloaded greater than comparator
    bool operator==(const ComplexNumber&) const;                // overloaded equal comparator
    bool operator!=(const ComplexNumber&) const;                // overloaded not equal comparator
    friend ostream& operator<<(ostream&, const ComplexNumber&); // overloaded stream insertion operator
    friend istream& operator>>(istream&, ComplexNumber&);       // overloaded stream extraction operator
};

#endif // COMPLEXNUMBER_H
