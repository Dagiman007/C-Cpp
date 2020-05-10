#ifndef _MATRIX_
#define _MATRIX_
#include <cmath>
#include <cassert>
#include <iostream>

class Matrix {
private:
  int m;
  int n;
  int storage;
  double* coeff;

protected:
  // methods such that subclasses can access data fields
  void allocate(int m, int n, int storage, double init);
  const double* getCoeff() const;
  double* getCoeff();
  int getStorage() const;

public:
  // constructors, destructor, assignment
  Matrix();
  Matrix(int m, int n, double init=0);
  Matrix(const Matrix&);
  ~Matrix();
  Matrix& operator=(const Matrix&);

  // return size of matrix
  int size1() const;
  int size2() const;

  // read and write entries with matrix access A(j,k)
  virtual const double& operator()(int j, int k) const;
  virtual double& operator()(int j, int k);

  // read and write storage vector A[ell]
  const double& operator[](int ell) const;
  double& operator[](int ell);

  // compute norm
  double norm() const;
};

// print matrix via output stream
std::ostream& operator<<(std::ostream& output, const Matrix&);

// matrix-matrix sum and product
const Matrix operator+(const Matrix&, const Matrix&);
const Matrix operator*(const Matrix&, const Matrix&);

#endif
