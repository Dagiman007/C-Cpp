#include "Complex.h"

Complex::Complex(double a, double b){
    setA(a); setB(b); setC(0); setD(0);
}

Complex::~Complex(){
}

std::ostream& operator<<(std::ostream& output, const Complex& q){
    output << q.getA() << " + " << q.getB() << "i";

    return output;
}

const Complex operator+(const Complex& q1, const Complex& q2){
    return Complex(q1.getA()+q2.getA(),
                      q1.getB()+q2.getB()
                      );
}
const Complex operator*(const Complex& q1, const Complex& q2){
    double a1,a2,b1,b2;
    a1 = q1.getA(); a2 = q2.getA();
    b1 = q1.getB(); b2 = q2.getB();
    return Complex(a1*a2 - b1*b2,
                      a1*b2 + b1*a2
                      );
}
Complex::operator double() const{
    return getA();
}
Complex::Complex(Quaternion q){
    setA(q.getA());
    setB(q.getB());
}
