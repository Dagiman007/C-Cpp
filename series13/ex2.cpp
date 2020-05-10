#include "matrix.hpp"
#include "squareMatrix.hpp"
#include "SymmetricMatrix.hpp"
#include "lowerTriangularMatrix.hpp"
#include "vector.hpp"


using std::cout;

int main() {
   int n = 3;
   SquareMatrix A(n,1);
   cout << "A =" << A;

   SymmetricMatrix B(n);
   for (int ell=0; ell<n*(n+1)/2; ++ell) {
      B[ell] = 2;
   }

   cout << "B =" << B;
   Matrix C = A + B;
   cout << "C =" << C;

   SymmetricMatrix D(n);
   for (int ell=0; ell<n*(n+1)/2; ++ell) {
     D[ell] = ell;
   }
   cout << "D =" << D;

   D = D + B;
   cout << "D =" << D;

   SymmetricMatrix E = D;
   cout << "E = " << E;

   B = D;
   cout << "B =" << B;


   return 0;
}
