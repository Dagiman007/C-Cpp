#ifndef _SKEWSYMMETRICMATRIX_
#define _SKEWSYMMETRICMATRIX_
#include "squareMatrix.hpp"
#include <cassert>
#include <iostream>

class SkewSymmetricMatrix : public SquareMatrix {
private:
  double zero;
  double const_zero;
  double minus;
  double const_minus;
public:
  // constructors, destructor, type cast from Matrix
  SkewSymmetricMatrix();
  SkewSymmetricMatrix(int n, double init=0);
  SkewSymmetricMatrix(const SkewSymmetricMatrix&);
  ~SkewSymmetricMatrix();
  SkewSymmetricMatrix(const Matrix&);

  // assignment operator
  SkewSymmetricMatrix& operator=(const SkewSymmetricMatrix&);

  // read and write entries with matrix access A(j,k)
  virtual const double& operator()(int j, int k) const;
  virtual double& operator()(int j, int k);
};
#endif
