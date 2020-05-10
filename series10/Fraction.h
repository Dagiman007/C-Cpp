#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cassert>
#include <cmath>

class Fraction
{
    private:
        int p,q;
    public:
        Fraction();
        Fraction(int, int);
        virtual ~Fraction();
        Fraction(const Fraction& obj);
        Fraction& operator=(const Fraction& p);

        int getNum() const;
        int getDen() const;

        int gcd(int,int);
        void reduce();

        operator double() const;
        Fraction(double);

        const Fraction operator-() const;

};
std::ostream& operator<<(std::ostream& output, const Fraction& f);

const Fraction operator+(const Fraction&, const Fraction&);
const Fraction operator*(const Fraction&, const Fraction&);
const Fraction operator-(const Fraction&, const Fraction&);
const Fraction operator/(const Fraction&, const Fraction&);

const int compare(const Fraction&, const Fraction&);

const bool operator==(const Fraction&, const Fraction& );
const bool operator!=(const Fraction&, const Fraction& );
const bool operator>=(const Fraction&, const Fraction& );
const bool operator<=(const Fraction&, const Fraction& );
const bool operator>(const Fraction&, const Fraction& );
const bool operator<(const Fraction&, const Fraction& );

#endif // FRACTION_H
