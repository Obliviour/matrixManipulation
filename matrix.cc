//Created by Victor Barr Matrix.cc
//TODO fix print function to use strings and use lengths from strings
// fix other small errors
#include "matrix.h"
//class Matrix::Matrix {
Matrix::Matrix(int r, int c): row(r), col(c)
{
    if (r == 0 && c == 0 ) cPtr = NULL;
    else cPtr = new Complex [row*col];
    for (int i = 0; i < row*col; i++) {
        *(cPtr+ i) = Complex(); }
}

Matrix::Matrix(const Matrix & cp):row(cp.getRow()), col(cp.getCol()) {
    if (row == 0 && col == 0) cPtr = NULL;
    else cPtr = new Complex [row*col];
    for (int i = 0; i < row*col; i++) {
        cPtr[i] = cp.getPtr()[i]; }
    }

Matrix::~Matrix() {
    delete[] cPtr; }


int Matrix::getRow() const { return row; }
int Matrix::getCol() const { return col; }
Complex* Matrix::getPtr() const { return cPtr; }

void Matrix::setRow(const int r) { row = r; }
void Matrix::setCol(const int c) { col = c; }

Complex& Matrix::operator() (int r, int c) const {
    if((r-1)*getCol()+(c-1) < getRow()*getCol()) return getPtr()[(r-1)*getCol() + (c-1)];
    else {
        std::cout << "Matrix () operator not in array bounds" << std::endl;}
}

Matrix Matrix::operator-(const Matrix& RHS) const {
    if(RHS.getRow() == getRow() && RHS.getCol() == getCol()) {
        Matrix returnThis = Matrix(getRow(),getCol());
        int i = 0;
        for (i = 0; i < getRow()*getCol(); i++) {
            *(returnThis.getPtr()+i) = *(getPtr()+ i) - *(RHS.getPtr()+ i);
        } return returnThis;
    } else {
        std::cout << "Matrix Mismatch Error!" << std::endl;
        return Matrix();
    }
}

Matrix Matrix::operator+(const Matrix& RHS) const {
    if(RHS.getRow() == getRow() && RHS.getCol() == getCol()) {
        Matrix returnThis = Matrix(getRow(),getCol());
        int i = 0;
        for (i = 0; i < getRow()*getCol(); i++) {
            *(returnThis.getPtr()+i) = *(getPtr()+i) + *(RHS.getPtr()+i);
        } return returnThis;
    } else {
        std::cout << "Matrix Mismatch Error!" << std::endl;
        return Matrix();
    }
}

Matrix Matrix::operator*( const Matrix& RHS) const {


    if(RHS.getRow() == getCol()) {
        //std::cout<<(*this)(2,3); //this will print 7 + 0j which is good
        //std::cout<<(RHS(2,3)); //this will print 7 + 0j which is also good
        Matrix returnThis = Matrix(getRow(),RHS.getCol());
        int i; int j; int k;
        //std::cout<<(*this)(2,3); //this will print 0 + 0j
        //std::cout<<(*this)(2,3); //this will print 0 + 0j
        for( i = 1; i <= returnThis.getRow(); i++) {
            for (j = 1; j <= returnThis.getCol(); j++) {
                for (k = 1; k <= returnThis.getCol(); k++) {
//std::cout<<"LHS" << (*this)(i,j) << "  RHS" << RHS(j,k) << std::endl; //all zero
                   Complex tmp = (*this)(i,j) * RHS(j,k);
//std::cout<<"Complex tmp" << i << j << tmp << std::endl; //all zero
                   returnThis(i,k) = returnThis(i,k) + tmp;
                }
            }
        }
        return returnThis;
    } else {
        std::cout << "Matrix Mismatch Error!" << std::endl;
        return Matrix();}
}

Matrix Matrix::operator*(const Complex& RHS) const {
        Matrix returnThis = Matrix(getRow(),getCol());
        for(int i = 0; i < getRow() * getCol(); i++) {
            returnThis.getPtr()[i] = RHS * getPtr()[i];
        }
        return returnThis;
}

Matrix Matrix::operator~() {
    Matrix returnThis = Matrix(getRow(),getCol());
    for (int i = 1; i <= getRow(); i++)
        for (int j = 1; j <= getCol(); j++)
            returnThis(j,i) = (*this)(i,j);
    return returnThis;
}

Matrix Matrix::operator&() {
    Matrix returnThis = Matrix(getRow(),getCol());
    for (int i = 0; i < getRow() * getCol();i++)
        *(returnThis.getPtr()+i) = ~(*(getPtr()+i));
    returnThis.transpose();
    return returnThis;
}

void Matrix::transpose() {
    *this = ~(*this);
}

void Matrix::printMatrix() {
    std::cout << (*this); //use the ostream operator
}

Matrix& Matrix::operator=(const Matrix & RHS) {
	setRow(RHS.getRow());
	setCol(RHS.getCol());
	delete[] cPtr;
	cPtr = (new Complex[getRow() * getCol()]);
	for(int i = 0; i < getRow() * getCol(); ++i) {
		getPtr()[i] = RHS.getPtr()[i]; }
	return *this;
}


//} //End class

std::ostream& operator<< (std::ostream& output, const Matrix& RHS) {
    if (RHS.getRow() == 0 && RHS.getCol() == 0) {
        output << "This matrix has zero elements" << std::endl;
        return output;
    }
    for(int i = 1; i <= RHS.getRow(); i++) {
        for(int j = 1; j <= RHS.getCol(); j++) {
            std::ostringstream tmp;
            if ((RHS(i,j)).getNaN()) {
                (tmp) << "NaN";
            } else if ((RHS(i,j)).getim() == 0) {
            (tmp) << std::setprecision(6) <<std::fixed << (RHS(i,j)).getre();
            } else if  ((RHS(i,j)).getre() == 0){
            (tmp) << std::setprecision(6) <<std::fixed << (RHS(i,j)).getim()<< "j";
            } else {
            (tmp) << std::setprecision(6) <<std::fixed << (RHS(i,j)).getre()
            << " + " << (RHS(i,j).getim()) << "j";
            }
            output << std::left <<std::setw(30) << (tmp).str();
        }
        output << "\n";
    } return output;
}




Matrix operator*(Complex LHS, Matrix& RHS) {
    Matrix returnThis = Matrix(RHS.getRow(),RHS.getCol());
    for (int i = 0; i < RHS.getRow() * RHS.getCol(); i++) {
        returnThis.getPtr()[i] = LHS * RHS.getPtr()[i]; }
    return returnThis;
}
