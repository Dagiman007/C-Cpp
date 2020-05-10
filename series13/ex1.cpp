#include "matrix.hpp"
#include "squareMatrix.hpp"
#include "diagonalMatrix.hpp"
#include "vector.hpp"

using std::cout;

int main() {
   int n = 3;

   SquareMatrix A(n,1);
   cout << "A =" << A;

   DiagonalMatrix B(n);
   for (int ell=0; ell<n; ++ell) {
      B[ell] = 2;
   }
   B(0,n-1) = 10;
   cout << "B =" << B;

   Matrix C = A + B;
   cout << "C =" << C;

   DiagonalMatrix D(n);
   for (int ell=0; ell<n; ++ell) {
     D[ell] = ell;
   }
   cout << "D =" << D;

   D = D + B;
   cout << "--\n";
   cout << "D =" << D;

   DiagonalMatrix E = D;
   cout << "E = " << E;

   B = D;
   cout << "B =" << B;

   return 0;
}
