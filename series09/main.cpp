#include <iostream>
#include "Polynomial.h"

using namespace std;

int main(){
    int n1, n2, index;
    double alpha,beta, x0,tau;

    cout << "Enter degree of the first polynomial: ";
    cin >> n1;
    Polynomial p(n1);
    double value1, value2;
    for(int i =0;i<=n1;i++){
        cout << "Enter coefficient of x^" << i << " : ";
        cin >> value1;
        p.setCoeff(i, value1);
    }
    cout << "\n\nEnter degree of second polynomial: " << endl;
    cin >> n2;
    Polynomial q(n2);
    for(int i =0;i<=n2;i++){
        cout << "Enter coefficient of x^" << i << " : ";
        cin >> value2;
        q.setCoeff(i, value2);
    }

    cout << p << endl;
    cout << q << endl;
    Polynomial sum1;
    Polynomial sum2;
    Polynomial prod1;
    Polynomial prod2;
    sum1 = p+q;
    sum2 = 2+p;
    prod1 = p*q;
    prod2 = 3*p;

    cout << "p + q = " << sum1 << endl;
    cout << "2+p = " << sum2 << endl;
    cout << "p*q = " << prod1 << endl;
    cout << "3*p = " << prod2 << endl;
    cout << "Coefficient of x" << p[1] << endl;
    if(p==q)
        cout << "The Polynomials are equal." << endl;
    else
        cout << "The polynomials are different" << endl;
    cout << "Definite Integral of P from 0 to 2: " << p.computeIntegral(0,2) << endl;
    cout << "Approximate zero of q: " << q.computeZero(0,1e-5) << endl;

    return 0;
}
