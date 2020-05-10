#include "Quaternion.h"

Quaternion::Quaternion(double a,double b,double c,double d){
    this->a = a; this->b = b; this->c = c; this->d = d;
}
Quaternion::~Quaternion(){
}

double Quaternion::getA()const{ return a; }
double Quaternion::getB()const{ return b; }
double Quaternion::getC()const{ return c; }
double Quaternion::getD()const{ return d; }

void Quaternion::setA(double a) { this-> a = a; }
void Quaternion::setB(double b) { this-> b = b; }
void Quaternion::setC(double c) { this-> c = c; }
void Quaternion::setD(double d) { this-> d = d; }

Quaternion::Quaternion(const Quaternion& obj){
    a = obj.getA(); b = obj.getB(); c = obj.getC(); d = obj.getD();
}
Quaternion& Quaternion::operator=(const Quaternion& q){
    this->a = q.getA();
    this->b = q.getB();
    this->c = q.getC();
    this->d = q.getD();
    return *this;
}

double Quaternion::norm(){
    return a*a + b*b + c*c + d*d;
}

const Quaternion Quaternion::operator-() const{
    return Quaternion(-1*a, -1*b, -1*c, -1*d);
}

const Quaternion Quaternion::operator~() const{
    return Quaternion(a, -1*b, -1*c, -1*d);
}

const Quaternion operator+(const Quaternion& q1, const Quaternion& q2){
    return Quaternion(q1.getA()+q2.getA(),
                      q1.getB()+q2.getB(),
                      q1.getC()+q2.getC(),
                      q1.getD()+q2.getD());
}
const Quaternion operator*(const Quaternion& q1, const Quaternion& q2){
    double a1,a2,b1,b2,c1,c2,d1,d2;
    a1 = q1.getA(); a2 = q2.getA();
    b1 = q1.getB(); b2 = q2.getB();
    c1 = q1.getC(); c2 = q2.getC();
    d1 = q1.getD(); d2 = q2.getD();
    return Quaternion(a1*a2 - b1*b2 - c1*c2 - d1*d2,
                      a1*b2 + b1*a2 + c1*d2 - d1*c2,
                      a1*c2 -b1*d2 + c1*a2 + d1*b2,
                      a1*d2 + b1*c2 - c1*b2 + d1*a2
                      );
}

std::ostream& operator<<(std::ostream& output, const Quaternion& q){
    output << q.getA() << " + " << q.getB() << "i + " << q.getC() << "j + " << q.getD() << "k";

    return output;
}
