#ifndef _LOWERTRIANGULARMATRIX_
#define _LOWERTRIANGULARMATRIX_
#include "squareMatrix.hpp"
#include "vector.hpp"
#include <cassert>
#include <iostream>

class LowerTriangularMatrix : public SquareMatrix {
private:
  double zero;
  double const_zero;

public:
  // constructors, destructor, type cast from Matrix
  LowerTriangularMatrix();
  LowerTriangularMatrix(int n, double init=0);
  LowerTriangularMatrix(const LowerTriangularMatrix&);
  ~LowerTriangularMatrix();
  LowerTriangularMatrix(const Matrix&);

  // assignment operator
  LowerTriangularMatrix& operator=(const LowerTriangularMatrix&);

  // read and write entries with matrix access A(j,k)
  virtual const double& operator()(int j, int k) const;
  virtual double& operator()(int j, int k);

  /************* Exercise 8*******************/
  // determinant
  double det();
};

/************************Exercise 6 ****************************/
// Forward Substitution
const Vector operator|(LowerTriangularMatrix, Vector); //can't use const or & because A and b changes

#endif
