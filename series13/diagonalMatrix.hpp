#ifndef _DiagonalMatrix_
#define _DiagonalMatrix_
#include "squareMatrix.hpp"
#include "vector.hpp"
#include <cassert>
#include <iostream>

class DiagonalMatrix : public SquareMatrix {
    private:
        double zero;
        double const_zero;

    public:
        DiagonalMatrix();
        DiagonalMatrix(int n, double init=0);
        DiagonalMatrix(const DiagonalMatrix&);
        ~DiagonalMatrix();

        DiagonalMatrix(const Matrix&);
        DiagonalMatrix& operator=(const DiagonalMatrix&);

        virtual const double& operator()(int j, int k) const;
        virtual double& operator()(int j, int k);

        double det();
};


    const Vector operator|(DiagonalMatrix, Vector);

#endif
