// Complex.cc by Victor Barr

#include "complex.h"

//class Complex::Complex {
    //Constructor that includes all 3 types required
    Complex::Complex(const double r, const double i, const bool N):
        re(r), im(i), NaN(N) {}
    //Various Accessor and Mutators 
    bool Complex::getNaN() const {
        return NaN; }
    void Complex::setNaN(bool n) { NaN = n; }
    
    double Complex::getim() const {
        return im; }
    void Complex:: setim(double i) {
        im = i; }
        
    double Complex:: getre() const {
        return re; }
    void Complex:: setre(double r) {re = r;}
    
    void Complex:: setComplex(double const r, double const i) 
    {
        re = r; im = i;
    }
    //Member Overloading Operators
    Complex Complex::operator+ (const Complex& RHS) const {
        if(RHS.getNaN() || getNaN()) return getNaN() ? RHS : *this;
        return Complex(getre() + RHS.getre(),
                    getim() + RHS.getim());
    }
    Complex Complex::operator- (const Complex& RHS) const {
        if(RHS.getNaN() || getNaN()) return getNaN()?Complex()-RHS : *this;
        return Complex(getre() - RHS.getre(),
                    getim() - RHS.getim());
    }
    Complex Complex::operator* (const Complex& RHS) const {
        //if(RHS.getNaN()
        double angle = ang(getre(),getim()) + ang(RHS.getre(), RHS.getim());
        double ma = mag(getre(),getim()) * mag(RHS.getre(),RHS.getim());
        return Complex(ma*cos(angle),ma*sin(angle));
    }
    Complex Complex::operator/ (const Complex& RHS) const {
        if(RHS.getre()==0) return Complex(0,0,1);
        double angle = ang(getre(),getim()) - ang(RHS.getre(), RHS.getim());
        double ma = mag(getre(),getim()) / mag(RHS.getre(),RHS.getim());
        return Complex(ma*cos(angle),ma*sin(angle));
    }
    Complex Complex:: operator~ () {
        return Complex(getre(),0 - getim()); 
    }
    //Misc Methods
    double Complex::ang(const double x, const double y) const {
        return atan2(y,x); }
    double Complex::mag(const double x, const double y) const {
        return sqrt(x*x + y*y); }
    void Complex::displayPolar() const {
        if(getNaN()) std::cout << "NaN" << std::endl;
        else 
        {
            std::cout << std::setprecision(6) << std::fixed << mag(getre(),getim()) 
                    << " < " << ang(getre(),getim())
                    << std::endl; } 
    }
    void Complex::displayRect() const {
        if(getNaN()) std::cout << "NaN" << std::endl;
        else {
            std::cout << std::setprecision(6) << std::fixed << getre() 
                    << " + " << getim() 
                    << "j\n"; }
    }
    
//}

//Global Overloading Operators even though friend
std::ostream & operator<<(std::ostream& output, const Complex& RHS) {
    if(RHS.getNaN()) output << "NaN";
    else { 
        output << std::setprecision(6) << std::fixed << RHS.getre() << " + ";
        output << std::setprecision(6) << std::fixed << RHS.getim() << "j";
    }
    return output;
}
    
