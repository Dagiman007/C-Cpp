#ifndef _SQUAREMATRIX_
#define _SQUAREMATRIX_
#include "matrix.hpp"
#include "vector.hpp"
#include <cassert>
#include <iostream>

class SquareMatrix : public Matrix {
  public:
    // constructors, destructor, type cast from Matrix
    SquareMatrix();
    SquareMatrix(int n,double init=0);
    SquareMatrix(const SquareMatrix&);
    ~SquareMatrix();
    SquareMatrix(const Matrix&);

    // further members
    int size() const;

    //additional member for gaussian elimination (Ex 5)
    void swapRows(int, int);

    //Exercise 7
    SquareMatrix subMatrix(int i, int j);
    virtual double det(int i=0);  //determinant along row 0
};

  const Vector operator|(SquareMatrix, Vector); //can't use const or & because A and b changes

#endif
