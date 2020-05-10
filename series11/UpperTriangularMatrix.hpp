#ifndef _UPPER_TRIANGULAR_MATRIX_
#define _UPPER_TRIANGULAR_MATRIX_

#include <cmath>
#include <cassert>
#include <iostream>
#include "vector.hpp"

 class UpperTriangularMatrix {
   private:
      int dim;
      double* coeff;
   public:
     UpperTriangularMatrix(int n = 0, double init = 0);
     UpperTriangularMatrix(const UpperTriangularMatrix& rhs);
     UpperTriangularMatrix& operator=(const UpperTriangularMatrix& rhs);
     ~UpperTriangularMatrix();

     int size() const;

     const double& operator()(int j, int k) const;
     double& operator() (int j, int k);

      double columnSumNorm() const;
      double rowSumNorm() const;

 };

 std::ostream& operator<<(std::ostream& output, const UpperTriangularMatrix& mat);
 const UpperTriangularMatrix operator+(const UpperTriangularMatrix&, const UpperTriangularMatrix&);
 const UpperTriangularMatrix operator*(const UpperTriangularMatrix&, const UpperTriangularMatrix&);
 const Vector operator*(const UpperTriangularMatrix&, const Vector&);
 // multiplication of upper triangular matrices
 const Vector operator|(const UpperTriangularMatrix&, const Vector&);
#endif
