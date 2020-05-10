#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
//using namespace std;

class Quaternion
{
    private:
        double a,b,c,d;
    public:
        Quaternion(double a=0,double b=0,double c=0,double d=0);
        virtual ~Quaternion();

        double getA() const; double getB() const; double getC() const; double getD() const;

        void setA(double);
        void setB(double);
        void setC(double);
        void setD(double);
        Quaternion(const Quaternion& obj);
        Quaternion& operator=(const Quaternion& q);

        double norm();
        const Quaternion operator-() const;
        const Quaternion operator~() const;


};
const Quaternion operator+(const Quaternion&, const Quaternion&);
const Quaternion operator*(const Quaternion&, const Quaternion&);
std::ostream& operator<<(std::ostream& output, const Quaternion& q);

#endif // QUATERNION_H
