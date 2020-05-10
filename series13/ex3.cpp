#include "matrix.hpp"
#include "squareMatrix.hpp"
#include "SkewSymmetricMatrix.hpp"
#include "vector.hpp"

using std::cout;

int main() {
   int n = 3;
   SquareMatrix A(n,1);
   cout << "A =" << A;

   SkewSymmetricMatrix B(n);
   for (int ell=0; ell<n*(n-1)/2; ++ell) {
      B[ell] = 2;
   }

   cout << "B =" << B;

   Matrix C = A + B;
   cout << "C =" << C;

   SkewSymmetricMatrix D(n);
   for (int ell=0; ell<n*(n-1)/2; ++ell) {
     D[ell] = ell;
   }
   cout << "D =" << D;

   D = D + B;
   cout << "D =" << D;

   SkewSymmetricMatrix E = D;
   cout << "E = " << E;

   A = D;
   cout << "A =" << A;



   return 0;
}
