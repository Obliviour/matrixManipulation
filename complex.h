// complex.h by Victor Barr
// ECE 2036 Lab 4

#ifndef COMPLEX_H
#define COMPLEX_H


#include <cmath>
#include <iostream>
#include <iomanip>

class Complex {
    //Friend Methods
    friend std::ostream& operator<<(std::ostream&,const Complex&);
public:
    //Constructor that includes all of the different type of 
    Complex(const double = 0, const double = 0, const bool = 0);
    //Accesser and Mutators
    bool getNaN() const;
    void setNaN(bool);
    double getim() const;
    void setim(double);
    double getre() const;
    void setre(double);
    void setComplex(const double = 0, const double = 0);
    //Overloading Operators
    Complex operator+ (const Complex& ) const; 
    Complex operator- (const Complex& ) const;
    Complex operator* (const Complex& ) const;
    Complex operator/ (const Complex& ) const;
    Complex operator~ ( );
    //Misc Methods
    double ang(const double, const double) const;
    double mag(const double, const double) const;
    void displayPolar() const;
    void displayRect() const;
    private:
    bool NaN;
    double im;
    double re;

};





#endif
