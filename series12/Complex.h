#ifndef COMPLEX_H
#define COMPLEX_H

#include "Quaternion.h"


class Complex : public Quaternion
{
    private:

    public:
        Complex(double a = 0, double b = 0);
        virtual ~Complex();

        operator double() const;
        Complex(Quaternion q);
};

std::ostream& operator<<(std::ostream& output, const Complex& q);
const Complex operator+(const Complex& q1, const Complex& q2);
const Complex operator*(const Complex& q1, const Complex& q2);

#endif // COMPLEX_H
