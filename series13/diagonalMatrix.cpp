#include "diagonalMatrix.hpp"
using std::cout;

DiagonalMatrix::DiagonalMatrix() {
  cout << "Diagonal: empty constructor\n";
}

DiagonalMatrix::DiagonalMatrix(int n, double init) {
  zero = 0;
  const_zero = 0;
  allocate(n, n, n, init);
  cout << "Diagonal: constructor, " << n << "\n";
}

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix& rhs) {
  int n = rhs.size();
  allocate(n, n, n, 0);
  zero = 0;
  const_zero = 0;
  for (int ell=0; ell<n; ++ell) {
    (*this)[ell] = rhs[ell];
  }
  cout << "Diagonal: copy constructor, " << n << "\n";
}

DiagonalMatrix::DiagonalMatrix(const Matrix& rhs) {
  int n = rhs.size1();
  assert (n == rhs.size2());
  allocate(n, n, n, 0);
  zero = 0;
  const_zero = 0;
  for (int j=0; j<n; ++j) {
    (*this)(j,j) = rhs(j,j);

    for (int k=0; k<j; ++k) {
      assert( rhs(j,k) == 0);
    }
    for (int k=j+1; k<n; ++k) {
      assert( rhs(j,k) == 0);
    }
  }
  cout << "type cast Matrix -> Diagonal\n";
}

DiagonalMatrix::~DiagonalMatrix() {
  cout << "Diagonal: destructor, " << size() << "\n";
}

DiagonalMatrix& DiagonalMatrix::operator=(const DiagonalMatrix& rhs) {
  if (this != &rhs) {
    int n = rhs.size();
    if (size() != n) {
      if (size() > 0) {
        delete[] getCoeff();
      }
      allocate(n, n, n, 0);
    }
    for (int ell=0; ell<n; ++ell) {
      (*this)[ell] = rhs[ell];
    }
    cout << "Diagonal: deep copy " << size() << "\n";
  }
  return *this;
}

const double& DiagonalMatrix::operator()(int j, int k) const {
  assert( j>=0 && j<size() );
  assert( k>=0 && k<size() );
  if ( j < k || j > k) {
    return const_zero;
  }
  else {
    const double* coeff = getCoeff();
    return coeff[j];
  }
}

double& DiagonalMatrix::operator()(int j, int k) {
  assert( j>=0 && j<size() );
  assert( k>=0 && k<size() );
  if ( j < k || j > k ) {
    zero = 0;
    return zero;
  }
  else {
    double* coeff = getCoeff();
    return coeff[j];
  }
}

const Vector operator|(DiagonalMatrix D, Vector b) {
  int n = D.size();
  Vector x(n);
  for (int i=0;i<n;++i) {
    x(i) = b(i)/D(i,i);
  }
  cout << "| operator: Diagonal Matrix\n";
  return x;
}

double DiagonalMatrix::det() {
  double d = 1;
  for (int i=0;i<size();++i) {
    d *= (*this)(i,i);
  }
  return d;
}
