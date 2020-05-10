#include "matrix.hpp"
using std::cout;
using std::ostream;

void Matrix::allocate(int m, int n, int storage, double init) {
  assert(m>=0);
  assert(n>=0);
  assert(storage>=0 && storage<=m*n);
  this->m = m;
  this->n = n;
  this->storage = storage;
  if (storage>0) {
    coeff = new double[storage];
    for (int ell=0; ell<storage; ++ell) {
      coeff[ell] = init;
    }
  }
  else {
    coeff = (double*) 0;
  }
}

const double* Matrix::getCoeff() const {
  return coeff;
}

double* Matrix::getCoeff() {
  return coeff;
}

int Matrix::getStorage() const {
  return storage;
}

Matrix::Matrix() {
  m = 0;
  n = 0;
  storage = 0;
  coeff = (double*) 0;
  // cout << "Matrix: empty constructor\n";
}

Matrix::Matrix(int m, int n, double init) {
  allocate(m,n,m*n,init);
  // cout << "Matrix: constructor, " << m << " x " << n << "\n";
}

Matrix::Matrix(const Matrix& rhs) {
  m = rhs.m;
  n = rhs.n;
  storage = m*n;
  if (storage > 0) {
    coeff = new double[storage];
    for (int k=0; k<n; ++k) {
      for (int j=0; j<m; ++j) {
        (*this)(j,k) = rhs(j,k);
      }
    }
  }
  else {
    coeff = (double*) 0;
  }
  // cout << "Matrix: copy constructor, " << m << " x " << n << "\n";
}

Matrix::~Matrix() {
  if (storage > 0) {
    delete[] coeff;
  }
  // cout << "Matrix: destructor, " << m << " x " << n << "\n";
}

Matrix& Matrix::operator=(const Matrix& rhs) {
  if (this != &rhs) {
    if ( (m != rhs.m) || (n != rhs.n) ) {
      if (storage > 0) {
        delete[] coeff;
      }
      m = rhs.m;
      n = rhs.n;
      storage = m*n;
      if (storage > 0) {
        coeff = new double[storage];
      }
      else {
        coeff = (double*) 0;
      }
    }
    for (int k=0; k<n; ++k) {
      for (int j=0; j<m; ++j) {
        (*this)(j,k) = rhs(j,k);
      }
    }
    // cout << "Matrix: deep copy, " << m << " x " << n << "\n";
  }
  return *this;
}

int Matrix::size1() const {
  return m;
}

int Matrix::size2() const {
  return n;
}

const double& Matrix::operator()(int j, int k) const {
  assert(j>=0 && j<m);
  assert(k>=0 && k<n);
  return coeff[j+k*m];
}

double& Matrix::operator()(int j, int k) {
  assert(j>=0 && j<m);
  assert(k>=0 && k<n);
  return coeff[j+k*m];
}

const double& Matrix::operator[](int ell) const {
  assert( ell>=0 && ell<storage );
  return coeff[ell];
}

double& Matrix::operator[](int ell) {
  assert( ell>=0 && ell<storage );
  return coeff[ell];
}

double Matrix::norm() const {
  double norm = 0;
  for (int k=0; k<n; ++k) {
    for (int j=0; j<m; ++j) {
      norm = norm + (*this)(j,k) * (*this)(j,k);
    }
  }
  return sqrt(norm);
}

ostream& operator<<(ostream& output, const Matrix& A) {
  output << "\n";
  for (int j=0; j<A.size1(); j++) {
    for (int k=0; k<A.size2(); k++) {
      output << " " << A(j,k);
    }
    output << "\n";
  }
  return output;
}

const Matrix operator+(const Matrix& A, const Matrix& B) {
  int m = A.size1();
  int n = A.size2();
  assert(m == B.size1() );
  assert(n == B.size2() );
  Matrix sum(m,n);
  for (int k=0; k<n; ++k) {
    for (int j=0; j<m; ++j) {
      sum(j,k) = A(j,k) + B(j,k);
    }
  }
  return sum;
}

const Matrix operator*(const Matrix& A, const Matrix& B) {
  int m = A.size1();
  int n = A.size2();
  int p = B.size2();
  double sum = 0;
  assert(n == B.size1() );
  Matrix product(m,p);
  for (int i=0; i<m; ++i) {
    for (int k=0; k<p; ++k) {
      sum = 0;
      for (int j=0; j<n; ++j) {
        sum = sum + A(i,j)*B(j,k);
      }
      product(i,k) = sum;
    }
  }
  return product;
}
