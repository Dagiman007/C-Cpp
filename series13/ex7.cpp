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


   double d1 = A.det();
   cout << "A =" << A;
   cout << "det(A) = " << d1 << "\n";

   SquareMatrix P(n,1);
   P(0,0) = 2;
   P(1,0) = 4;
   P(2,0) = -2;
   P(1,1) = -6;
   P(2,1) = 7;
   P(1,2) = 0;
   P(2,2) = 2;

   double d2 = P.det();
   cout << "P =" << P;
   cout << "det(P) = " << d2 << "\n";


   return 0;
}
