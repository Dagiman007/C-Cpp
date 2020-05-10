#ifndef _SYMMETRICMATRIX_
#define _SYMMETRICMATRIX_
#include "squareMatrix.hpp"
#include "lowerTriangularMatrix.hpp"  // for Ex4
#include <cassert>
#include <iostream>

class SymmetricMatrix : public SquareMatrix {

public:
  // constructors, destructor, type cast from Matrix
  SymmetricMatrix();
  SymmetricMatrix(int n, double init=0);
  SymmetricMatrix(const SymmetricMatrix&);
  ~SymmetricMatrix();
  SymmetricMatrix(const Matrix&);

  // assignment operator
  SymmetricMatrix& operator=(const SymmetricMatrix&);

  // read and write entries with matrix access A(j,k)
  virtual const double& operator()(int j, int k) const;
  virtual double& operator()(int j, int k);

  //////////Exercise 4///////////////////////////
  const LowerTriangularMatrix computeCholesky() const;
};

#endif
