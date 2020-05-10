#include "Quaternion.h"
#include "Complex.h"

using namespace std;
int main(){
    Quaternion q1(1,1,1,-1);
    Quaternion q2(-1,1,2,4);

    cout << "Q1 = " << q1 << endl;
    cout << "Q2 = " << q2 << endl;
    cout << "Q1 + Q2 = " << q1+q2 << endl;
    cout << "Q1 * Q2 = " << q1*q2 << endl;
    cout << "-Q1 = " << -q1 << endl;
    cout << "~Q2 = " << ~q2 << endl;
    cout << "||Q1||" << q1.norm() << endl;

    Complex c1(1,2);
    Complex c2(2,1);
    cout << "C1 = " << c1 << endl;
    cout << "C2 = " << q2 << endl;
    cout << "C1 + C2 = " << c1+c2 << endl;
    cout << "C1 * C2 = " << c1*c2 << endl;
    cout << "-C1 = " << -c1 << endl;
    cout << "~C2 = " << ~c2 << endl;
    cout << "||C1||" << c1.norm() << endl;
    cout << Complex(q1) << endl;
    cout << double(c1) << endl;

}

