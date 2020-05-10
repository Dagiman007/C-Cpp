#include "matrix.hpp"
#include "squareMatrix.hpp"
#include "vector.hpp"

using std::cout;

int main() {
   int n = 3;
   SquareMatrix A(n,1);
   A(0,0) = 3;
   A(1,1) = 3;
   A(2,2) = 3;

   Vector b(n,1);

   Vector x(n);
   x = A|b;
   cout << "A =" << A;
   cout << "b =" << b;
   cout << "x =" << x;


   SquareMatrix P(n,1);
   P(0,0) = 2;
   P(1,0) = 4;
   P(2,0) = -2;
   P(1,1) = -6;
   P(2,1) = 7;
   P(1,2) = 0;
   P(2,2) = 2;

   Vector c(n);
   c(0) = 5;
   c(1) = -2;
   c(2) = 9;

   Vector y(n);
   y = P|c;
   cout << "P =" << P;
   cout << "c =" << c;
   cout << "y =" << y;


   /* Solution:
   1. x = [0.2; 0.2; 0.2]

   2. Should swap row 0 and 1
      y = [ 1; 1; 2]
   */


   return 0;
}
