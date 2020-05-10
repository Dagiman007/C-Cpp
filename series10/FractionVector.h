#ifndef FRACTIONVECTOR_H
#define FRACTIONVECTOR_H

#include "Fraction.h"

class FractionVector
{
    private:
        int n;
        Fraction* vec;
    public:
        FractionVector(int, Fraction);
        virtual ~FractionVector();
        FractionVector(const FractionVector&);
        FractionVector& operator=(const FractionVector&);

        int getLength() const;
        Fraction getElement(int k)const;
        void setElement(int, Fraction) const;

        void insertionSort();
};

#endif // FRACTIONVECTOR_H
