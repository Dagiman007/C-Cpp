#include "SymmetricMatrix.hpp"
// #include <cmath>
using std::cout;

SymmetricMatrix::SymmetricMatrix() {
  cout << "Symmetric: empty constructor\n";
}

SymmetricMatrix::SymmetricMatrix(int n, double init) {
  allocate(n, n, n*(n+1)/2, init);
  cout << "Symmetric: constructor, " << n << "\n";
}

SymmetricMatrix::SymmetricMatrix(const SymmetricMatrix& rhs) {
  int n = rhs.size();
  allocate(n, n, n*(n+1)/2, 0);
  for (int ell=0; ell<n*(n+1)/2; ++ell) {
    (*this)[ell] = rhs[ell];
  }
  cout << "Symmetric: copy constructor, " << n << "\n";
}

SymmetricMatrix::SymmetricMatrix(const Matrix& rhs) {
  int n = rhs.size1();
  assert (n == rhs.size2());
  allocate(n, n, n*(n+1)/2, 0);
  for (int j=0; j<n; ++j) {
    for (int k=0; k<=j; ++k) {
      (*this)(j,k) = rhs(j,k);
    }
    for (int k=j+1; k<n; ++k) {
      assert( rhs(j,k) == rhs(k,j) );
    }
  }
  cout << "type cast Matrix -> Symmetric\n";
}

SymmetricMatrix::~SymmetricMatrix() {
  cout << "Symmetric: destructor, " << size() << "\n";
}

SymmetricMatrix& SymmetricMatrix::operator=(const SymmetricMatrix& rhs) {
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
    cout << "Symmetric: deep copy " << size() << "\n";
  }
  return *this;
}

const double& SymmetricMatrix::operator()(int j, int k) const {
  assert( j>=0 && j<size() );
  assert( k>=0 && k<size() );
  if ( j < k ) {
    const double* coeff = getCoeff();
    return coeff[j+k*(k+1)/2];
  }
  else {
    const double* coeff = getCoeff();
    return coeff[j*(j+1)/2+k];
  }
}

double& SymmetricMatrix::operator()(int j, int k) {
  assert( j>=0 && j<size() );
  assert( k>=0 && k<size() );
  if ( j < k ) {
    double* coeff = getCoeff();
    return coeff[j+k*(k+1)/2];
  }
  else {
    double* coeff = getCoeff();
    return coeff[j*(j+1)/2+k];
  }
}

const LowerTriangularMatrix SymmetricMatrix::computeCholesky() const {
  int n = size();
  LowerTriangularMatrix L(n,0);

  for (int k=0;k<n;k++) {
    cout << "k = " << k << "\n";

    double sum1 = 0;
    for (int i=0;i<k;i++){
      cout << "L(i,k) =" << L(k,i) << "\n";
      sum1 += L(k,i)*L(k,i);
    }
    cout << sum1 << "\n";
    L(k,k) = sqrt((*this)(k,k) - sum1);

    for (int j=k+1;j<n;++j){
      double sum2 = 0;
      for (int i=0;i<k;i++){
        sum2 += L(j,i)*L(k,i);
      }
      L(j,k) = ((*this)(j,k) - sum2)/L(k,k);
    }
    cout << "\n" << L << "\n";
  }
  return L;
}
