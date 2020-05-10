#include "matrix.hpp"
#include "squareMatrix.hpp"
#include "vector.hpp"
#include "diagonalMatrix.hpp"
#include "lowerTriangularMatrix.hpp"


using std::cout;

int main() {
   int n = 3;
   LowerTriangularMatrix L(n,1);
   L(0,0) = 3;
   L(1,1) = 3;
   L(2,2) = 3;

   Vector b(n,1);

   Vector x(n);
   x = L|b;
   cout << "L =" << L;
   cout << "b =" << b;
   cout << "x =" << x;


   DiagonalMatrix D(n,1);
   D(0,0) = 2;
   D(1,1) = -6;
   D(2,2) = 2;

   Vector c(n);
   c(0) = 5;
   c(1) = -2;
   c(2) = 9;

   Vector y(n);
   y = D|c;
   cout << "D =" << D;
   cout << "c =" << c;
   cout << "y =" << y;




   return 0;
}
