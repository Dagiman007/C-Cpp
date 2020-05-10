#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>


class Polynomial
{
    private:
        int n;
        double* coeff;
    public:
        Polynomial();
        Polynomial(int n);
        Polynomial(const Polynomial &obj);
        int degree () const;
        Polynomial& operator=(const Polynomial& p);

        void setCoeff(int k, double value);
        double& get(int k);
        double& get(int)const;

        const double& operator [](int j) const;
        double& operator [](int j);

        double computeIntegral(double alpha, double beta);
        double computeZero(double x0, double tau);

        double operator ()(const int&, const double&);
        Polynomial operator ()(const int&);
        double operator()(const double&);


        ~Polynomial();

};
std::ostream &operator<<(std::ostream& output, const Polynomial& p);

const Polynomial operator+(const Polynomial&, const Polynomial& );
const Polynomial operator+(const Polynomial&,const double );
const Polynomial operator+(const double, const Polynomial&);

const Polynomial operator*(const Polynomial&,const Polynomial&);
const Polynomial operator*(const Polynomial&,const double);
const Polynomial operator*(const double, const Polynomial&);

const bool operator==(const Polynomial& p, const Polynomial& q);



#endif // POLYNOMIAL_H
