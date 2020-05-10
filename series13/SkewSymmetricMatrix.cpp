#include "SkewSymmetricMatrix.hpp"
using std::cout;

SkewSymmetricMatrix::SkewSymmetricMatrix() {
  cout << "Symmetric: empty constructor\n";
}

SkewSymmetricMatrix::SkewSymmetricMatrix(int n, double init) {
  zero = 0;
  const_zero = 0;
  allocate(n, n, n*(n-1)/2, init);
  cout << "Symmetric: constructor, " << n << "\n";
}

SkewSymmetricMatrix::SkewSymmetricMatrix(const SkewSymmetricMatrix& rhs) {
  int n = rhs.size();
  allocate(n, n, n*(n-1)/2, 0);
  zero = 0;
  const_zero = 0;
  for (int ell=0; ell<n*(n-1)/2; ++ell) {
    (*this)[ell] = rhs[ell];
  }
  cout << "Symmetric: copy constructor, " << n << "\n";
}

SkewSymmetricMatrix::SkewSymmetricMatrix(const Matrix& rhs) {
  int n = rhs.size1();
  assert (n == rhs.size2());
  allocate(n, n, n*(n-1)/2, 0);
  zero = 0;
  const_zero = 0;
  for (int k=0; k<n; ++k) {
    for (int j=0; j<k; ++j) {
      (*this)(j,k) = rhs(j,k);
    }
    for (int j=k; j<n; ++j) {
      assert( rhs(j,k) == -rhs(k,j)||rhs(j,k) == rhs(k,j) );
    }
  }
  cout << "type cast Matrix -> Symmetric\n";
}

SkewSymmetricMatrix::~SkewSymmetricMatrix() {
  cout << "Symmetric: destructor, " << size() << "\n";
}

SkewSymmetricMatrix& SkewSymmetricMatrix::operator=(const SkewSymmetricMatrix& rhs) {
  if (this != &rhs) {
    int n = rhs.size();
    if (size() != n) {
      if (size() > 0) {
        delete[] getCoeff();
      }
      allocate(n, n, n*(n-1)/2, 0);
    }
    for (int ell=0; ell<n*(n-1)/2; ++ell) {
      (*this)[ell] = rhs[ell];
    }
    cout << "Symmetric: deep copy " << size() << "\n";
  }
  return *this;
}

const double& SkewSymmetricMatrix::operator()(int j, int k) const {
  assert( j>=0 && j<size() );
  assert( k>=0 && k<size() );
  if ( j < k ) {
    const double* coeff = getCoeff();
    return coeff[j+k*(k-1)/2];
  }
  else if (j==k) {
    return const_zero;
  }
  else {
    const double* coeff = getCoeff();
    return coeff[j*(j-1)/2+k];
  }
}

double& SkewSymmetricMatrix::operator()(int j, int k) {
  assert( j>=0 && j<size() );
  assert( k>=0 && k<size() );
  if ( j < k ) {
    double* coeff = getCoeff();
    return coeff[j+k*(k-1)/2];
  }
  else if (j==k) {
    zero = 0;
    return zero;
  }
  else {
    double* coeff = getCoeff();
    return coeff[j*(j-1)/2+k];
  }
}
