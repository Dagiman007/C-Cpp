#include "UpperTriangularMatrix.hpp"
using std::cout;
using std::ostream;


UpperTriangularMatrix::UpperTriangularMatrix(int n, double init) {
   assert(n>=0);
   dim = n;
   int N = ((n*(n+1))/2);
   if (n == 0) {
     coeff = (double*) 0;
   }
   else {
     coeff = new double[N];
     for (int j=0; j<N; ++j) {
       coeff[j] = init;
     }
  }
}

UpperTriangularMatrix::UpperTriangularMatrix(const UpperTriangularMatrix& rhs) {
  dim = rhs.dim;
  if (dim == 0) {
    coeff = (double*) 0;
  }
  else {
    int N = ((dim*(dim+1))/2);
    coeff = new double[N];
    for (int j=0; j<N; ++j) {
      coeff[j] = rhs.coeff[j];
    }
  }
}


UpperTriangularMatrix& UpperTriangularMatrix::operator=(const UpperTriangularMatrix& rhs) {
  if (this != &rhs) {
    if (dim != rhs.dim) {
       if (dim > 0) {
         delete[] coeff;
       }
       dim = rhs.dim;
       if (dim > 0) {
         int N = ((dim*(dim+1))/2);
         coeff = new double[N];
         for (int j=0; j<N; ++j) {
           coeff[j] = rhs.coeff[j];
         }
       }
       else {
         coeff = (double*) 0;
       }
     }
  }
  return *this;
}


UpperTriangularMatrix::~UpperTriangularMatrix() {
   if (dim > 0) {
     delete[] coeff;
   }
}


int UpperTriangularMatrix::size() const {
  return dim;
}

const double& UpperTriangularMatrix::operator()(int j, int k) const {
  assert(j>=0 && j<dim);
  assert(k>=0 && k<dim);
  if (k < j) {
        return 0;
  }
  else {
    int tmp = (k*(k-1))/2;
    int l = j+k+tmp;
    return coeff[l];
  }
}

double& UpperTriangularMatrix::operator() (int j, int k) {
  assert(j>=0 && j<dim);
  assert(k>=0 && k<dim);
  if (k < j) {
      double temp = 0;
        return temp;
  }
  else {
    int tmp = (k*(k-1))/2;
    int l = j+k+tmp;
    return coeff[l];
  }
}


std::ostream& operator<<(std::ostream& output, const UpperTriangularMatrix& mat) {
  int dim = mat.size();
  if (dim == 0) {
    return output << 0;
  }
  else {
    for (int j=0;j<dim;++j) {
      output << "\n";
      for (int k=0;k<dim;++k) {
        if (k<j) {
          output << 0 << " ";
        }
        else {
          output << mat(j,k) << " ";
        }
      }
    }
    return output;
 }
}


double UpperTriangularMatrix::columnSumNorm() const {
  UpperTriangularMatrix mat(*this);
  double maxk = 0;
  for(int k = 0;k<dim;k++){
    double sum = 0;
    for(int j = 0;j<dim;j++){
      if (k<j) continue;
      sum += fabs(mat(j,k));
    }
    if (sum > maxk) maxk = sum;
  }
  return maxk;
}

double UpperTriangularMatrix::rowSumNorm() const{
  UpperTriangularMatrix mat(*this);
  double maxj = 0;
  for(int j = 0;j<dim;j++){
    double sum = 0;
    for(int k = 0;k<dim;k++){
      if (k<j) continue;
      sum += fabs(mat(j,k));
    }
    if (sum > maxj) maxj = sum;
  }
  return maxj;
}

const UpperTriangularMatrix operator+(const UpperTriangularMatrix& rhs1, const UpperTriangularMatrix& rhs2) {
   assert(rhs1.size() == rhs2.size());
     UpperTriangularMatrix r(rhs1);
     for (int j=0; j<r.size(); ++j) {
       for (int k=0; k<r.size(); ++k) {
         if (k<j) continue;
         r(j,k) += rhs2(j,k);
       }
     }
     return r;
   }

const UpperTriangularMatrix operator*(const UpperTriangularMatrix& rhs1, const UpperTriangularMatrix& rhs2) {
  assert(rhs1.size() == rhs2.size());
    UpperTriangularMatrix c(rhs1.size());
    for (int i=0; i<c.size(); ++i) {
      for (int j=0; j<c.size(); ++j) {
        if (j<i) continue;
        for (int k=0; k<c.size(); ++k) {
          if (k<i || j<k) continue;
          c(i,j) += rhs1(i,k)*rhs2(k,j);
        }
      }
    }
    return c;
  }

const Vector operator*(const UpperTriangularMatrix& rhs1, const Vector& x) {
   assert(rhs1.size() == x.size());
   Vector b(x.size());
   for (int j=0;j<rhs1.size();++j) {
     for (int k=0;k<rhs1.size();++k) {
       if (k<j) continue;
       b[j] += rhs1(j,k)*x[k];
     }
   }
   return b;
   }

const Vector operator|(const UpperTriangularMatrix& rhs1, const Vector& b) {
  assert(rhs1.size() == b.size());
  int n = rhs1.size();
  for (int i=0;i<n;++i) {
    assert(rhs1(i,i) != 0);
  }
  Vector x(n);
  for (int j=n-1;j>=0;--j) {
    double sum = 0;
    for (int k=j+1;k<n;++k) {
      if (k<j) continue;
      sum += rhs1(j,k)*x[k];
    }
    x[j] = (1/rhs1(j,j))*(b[j]-sum);
  }
  return x;
}
