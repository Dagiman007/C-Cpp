#ifndef VECTOR
#define VECTOR
#include "matrix.hpp"
#include <cassert>
#include <iostream>

class Vector : public Matrix {
public:
  // constructors, destructor, and type cast Matrix to Vector
  Vector();
  Vector(int m, double init=0);
  Vector(const Vector&);
  ~Vector();
  Vector(const Matrix&);

  // return size of vector
  int size() const;
  void swapRows(int, int);
  // read and write coefficients with access x(j)
  const double& operator()(int j) const;
  double& operator()(int j);
};

#endif
