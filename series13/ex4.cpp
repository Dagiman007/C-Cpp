#include "matrix.hpp"
#include "squareMatrix.hpp"
#include "lowerTriangularMatrix.hpp"
#include "SymmetricMatrix.hpp"
#include "vector.hpp"


using std::cout;

int main() {
   int n = 3;
   SymmetricMatrix A(n,1);
   A(0,0) = 3;
   A(1,1) = 3;
   A(2,2) = 3;

   cout << "A =" << A;

   cout << "*** init B\n";
   LowerTriangularMatrix B(3,0);
   B = A.computeCholesky();
   cout << "B = " << B;
   cout << "--\n";

   /* Solution:
    [ 1.73205   0.00000   0.00000
   0.57735   1.63299   0.00000
   0.57735   0.40825   1.58114]
   */

   return 0;
}
