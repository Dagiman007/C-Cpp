#include "lowerTriangularMatrix.hpp"
using std::cout;

LowerTriangularMatrix::LowerTriangularMatrix() {
  cout << "LowerTriangular: empty constructor\n";
}

LowerTriangularMatrix::LowerTriangularMatrix(int n, double init) {
  zero = 0;
  const_zero = 0;
  allocate(n, n, n*(n+1)/2, init);
  cout << "LowerTriangular: constructor, " << n << "\n";
}

LowerTriangularMatrix::LowerTriangularMatrix(const LowerTriangularMatrix& rhs) {
  int n = rhs.size();
  allocate(n, n, n*(n+1)/2, 0);
  zero = 0;
  const_zero = 0;
  for (int ell=0; ell<n*(n+1)/2; ++ell) {
    (*this)[ell] = rhs[ell];
  }
  cout << "LowerTriangular: copy constructor, "
       << n << "\n";
}

LowerTriangularMatrix::LowerTriangularMatrix(const Matrix& rhs) {
  int n = rhs.size1();
  assert (n == rhs.size2());
  allocate(n, n, n*(n+1)/2, 0);
  zero = 0;
  const_zero = 0;
  for (int j=0; j<n; ++j) {
    for (int k=0; k<=j; ++k) {
      (*this)(j,k) = rhs(j,k);
    }
    for (int k=j+1; k<n; ++k) {
      assert( rhs(j,k) == 0);
    }
  }
  cout << "type cast Matrix -> LowerTriangular\n";
}

LowerTriangularMatrix::~LowerTriangularMatrix() {
  cout << "LowerTriangular: destructor, "
       << size() << "\n";
}

LowerTriangularMatrix& LowerTriangularMatrix::operator=(const LowerTriangularMatrix& rhs) {

  if (this != &rhs) {
    int n = rhs.size();
    if (size() != n) {
      if (size() > 0) {
        delete[] getCoeff();
      }
      allocate(n, n, n*(n+1)/2, 0);
    }
    for (int ell=0; ell<n*(n+1)/2; ++ell) {
      (*this)[ell] = rhs[ell];
    }
    cout << "LowerTriangular: deep copy "
         << size() << "\n";
  }
  return *this;
}

const double& LowerTriangularMatrix::operator()(int j, int k) const {
  assert( j>=0 && j<size() );
  assert( k>=0 && k<size() );
  if ( j < k ) {
    return const_zero;
  }
  else {
    const double* coeff = getCoeff();
    return coeff[j*(j+1)/2+k];
  }
}

double& LowerTriangularMatrix::operator()(int j, int k) {
  assert( j>=0 && j<size() );
  assert( k>=0 && k<size() );
  if ( j < k ) {
    zero = 0;
    return zero;
  }
  else {
    double* coeff = getCoeff();
    return coeff[j*(j+1)/2+k];
  }
}

const Vector operator|(LowerTriangularMatrix L, Vector b) {
  int n = L.size();
  Vector x(n);
  for (int j=0;j<n;++j) {

    double sum = 0;
    for (int k=0;k<j;++k) {
      sum += L(j,k)*x(k);
    }
    x(j) = (1/L(j,j))*(b(j)-sum);
  }
  return x;
}


double LowerTriangularMatrix::det() {
  double d = 1;
  for (int i=0;i<size();++i) {
    d *= (*this)(i,i);
  }
  return d;
}
