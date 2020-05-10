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

   double d1 = L.det();
   cout << "L =" << L;
   cout << "det(L) = " << d1 << "\n";


   DiagonalMatrix D(n,1);
   D(0,0) = 2;
   D(1,1) = -6;
   D(2,2) = 2;

   double d2 = D.det();
   cout << "D =" << D;
   cout << "det(D) = " << d2 << "\n";



   return 0;
}
