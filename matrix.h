//Created by Victor Barr Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include<iomanip>
#include<iostream>
#include<sstream>
#include "complex.h"
#include<string>


class Matrix;
std::ostream& operator<< (std::ostream&, const Matrix &);
Matrix operator*(Complex, Matrix &);

class Matrix {
friend std::ostream& operator<< (std::ostream &, const Matrix &);
friend Matrix operator* (Complex&, Matrix &);

public:
    Matrix(int = 0, int = 0);
    Matrix(const Matrix &);
    ~Matrix();
    int getRow() const;
    int getCol() const;
    Complex* getPtr() const;

    void setRow(const int);
    void setCol(const int);

    Complex& operator()(int, int) const;
    Matrix operator-(const Matrix&) const;
    Matrix operator+(const Matrix&) const;
    Matrix operator*(const Matrix&) const;
    Matrix operator*(const Complex&) const;
    Matrix operator~();
    Matrix operator&();
    Matrix& operator=(const Matrix&);
    void transpose();
    void printMatrix();
private:
    int row;
    int col;
    Complex* cPtr;
};



#endif
