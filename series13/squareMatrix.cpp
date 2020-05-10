#include <cmath>
#include "squareMatrix.hpp"
using std::cout;

SquareMatrix::SquareMatrix() {
  // cout << "SquareMatrix: empy constructor\n";
}

SquareMatrix::SquareMatrix(int n, double init) : Matrix(n,n,init) {
  // cout << "SquareMatrix: constructor, " << size() << "\n";
};

SquareMatrix::SquareMatrix(const SquareMatrix& rhs) : Matrix(rhs) {
  // cout << "SquareMatrix: copy constructor, " << size() << "\n";
}

SquareMatrix::~SquareMatrix() {
  // cout << "SquareMatrix: destructor, " << size() << "\n";
}

SquareMatrix::SquareMatrix(const Matrix& rhs) : Matrix(rhs) {
  assert(size1() == size2());
  // cout << "type cast Matrix -> SquareMatrix\n";
}

int SquareMatrix::size() const {
  return size1();
}

void SquareMatrix::swapRows(int i, int p) {
  assert( i>=0 && i<size() );
  assert( p>=0 && p<size() );
  SquareMatrix M = (*this);
  cout << "Swap row " << i << " and row " << p << "\n";
  for (int j=0;j<size();++j) {
    (*this)(i,j) = M(p,j);
    (*this)(p,j) = M(i,j);
  }
}

const Vector operator|(SquareMatrix A, Vector b){
  int n = A.size();
  double m = 0;
  for (int i=0;i<n-1;++i) {
    double max = fabs( A(i,i) );
    int ind = i;
    for (int p=i+1;p<n;++p) {
      if ( fabs( A(p,i) ) > max) {
        max = fabs(A(p,i));
        ind = p;
      }
    }
    if (ind!=i) {
      A.swapRows(i,ind);
      b.swapRows(i,ind);
    }
    assert(A(i,i)!=0);
    for (int j=i+1;j<n;++j) {
      m = A(j,i)/A(i,i);
      for (int k=0;k<n;++k) {
        A(j,k) = A(j,k) - m*A(i,k);
      }
      b(j) = b(j) - m*b(i);
    }
    cout << "A(" << i+1 << ") = " << A << "\n";
  }
    Vector x(n);
    for (int j=n-1;j>=0;--j) {
    double sum = 0;
    for (int k=j+1;k<n;++k) {
      sum += A(j,k)*x[k];
    }
    x[j] = (1/A(j,j))*(b(j)-sum);
  }
  cout << "Gaussian Elimination\n";
  return x;
}

SquareMatrix SquareMatrix::subMatrix(int i, int j) {
  int n = size();
  SquareMatrix R(n-1);
  int k1 = 0;
  for (int k=0; k<n; ++k) {
    if (j==k) continue;
    int l1 = 0;
    for (int l=0; l<n; ++l) {
      if (i==l) continue;
      R(l1,k1) = (*this)(l,k);
      l1++;
    }
    k1++;
  }
  return R;
}

double SquareMatrix::det(int i) {
  SquareMatrix A = (*this);
  if (A.size() == 2) {
    return A(0,0)*A(1,1)-A(1,0)*A(0,1);
  }

  else {
    int n = size();
    double sum = 0;
    int sign;

    for (int j=0;j<n;++j) {
      if ((i+j)%2 == 0) {
        sign = 1;
      }
      else {
        sign = -1;
      }

      sum += sign*A(i,j)*(A.subMatrix(i,j)).det(i);
    }
    return sum;
  }
}
