#ifndef _VECTOR_
#define _VECTOR_
#include <cmath>
#include <cassert>
#include <iostream>

class Vector {
    private:
        int dim;
        double* coeff;

    public:
        Vector();
        Vector(int dim, double init=0);
        Vector(const Vector&);
        ~Vector();
        Vector& operator=(const Vector&);

        int size() const;
        const double& operator[](int k) const;
        double& operator[](int k);
        double norm() const;
 };

 std::ostream& operator<<(std::ostream& output, const Vector& p);
 const Vector operator+(const Vector&, const Vector&);
 const Vector operator*(const double, const Vector&);
 const Vector operator*(const Vector&, const double);
 const double operator*(const Vector&, const Vector&);

#endif
