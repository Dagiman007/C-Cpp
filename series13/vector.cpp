#include "vector.hpp"
using std::cout;

Vector::Vector() {
  cout << "Vector: empty constructor\n";
}

Vector::Vector(int m, double init) : Matrix(m,1,init) {
  cout << "Vector: constructor, " << m << "\n";
}

Vector::Vector(const Vector& rhs) : Matrix(rhs) {
  cout << "Vector: copy constructor, " << size() << "\n";
}

Vector::Vector(const Matrix& rhs) : Matrix(rhs) {
  assert(rhs.size2() == 1);
  cout << "type cast Matrix -> Vector\n";
}

Vector::~Vector() {
  cout << "Vector: destructor, " << size() << "\n";
}

int Vector::size() const {
  return this->size1();
}

const double& Vector::operator()(int j) const {
  assert( j>=0 && j<size() );
  return (*this)[j];
}

double& Vector::operator()(int j) {
  assert( j>=0 && j<size() );
  return (*this)[j];
}

void Vector::swapRows(int i, int p) {
  assert( i>=0 && i<size() );
  assert( p>=0 && p<size() );
  double tmp = (*this)(i);
  (*this)(i) = (*this)(p);
  (*this)(p) = tmp;

}
