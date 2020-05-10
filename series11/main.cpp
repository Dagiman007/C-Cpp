#include "UpperTriangularMatrix.hpp"
#include "vector.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main() {

 UpperTriangularMatrix upper1;
 UpperTriangularMatrix upper2(3,3);
 UpperTriangularMatrix upper3(upper2);
 UpperTriangularMatrix upper4(4,4);


 upper1 = upper4;

 cout << "size of upper3 = " << upper3.size() << endl;

 upper2(2,2) = 5.1;
 upper2(1,2) = 41;
 upper2(0,2) = 13;
 upper2(1,1) = 2;
 upper2(0,1) = 1;
 upper2(0,0) = 1;

 cout << "upper2(0,0) = " << upper2(0,0) << endl;
 cout << "upper2(0,1) = " << upper2(0,1) << endl;


 cout << "Matrix 4 = " << upper2 << endl;

 cout << "||upper2||_1 = " << upper2.columnSumNorm() << endl;
 cout << "||upper2||_inf = " << upper2.rowSumNorm() << endl;

 cout << "upper2 + upper 3 = " << upper2+upper3 << endl;
 cout << "upper2 * upper 3 = " << upper2*upper3 << endl;

 Vector v1(3,1);
 cout << "vec1 = " << v1 << endl;
 cout << "upper2 * vec1 = " << upper2*v1 << endl;

 Vector vec3(4,1);
 Vector v2 = upper3|vec3;
 cout << "upper3 | vec3 = " << v2 << endl;
 return 0;
}
