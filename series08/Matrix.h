#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <ctime>
#include <iomanip>

class Matrix
{
    private:
        int n;
        double* coeff;
        char type;
    public:
        Matrix();
        Matrix(int n, char type);
        Matrix(int n, char type, double value);
        Matrix(int n, char type, double lb, double ub);
        virtual ~Matrix();

        int getN();
        void setN(int n);
        char getType();
        void setType(char type);
        void set(int k, double value);
        double get(int k);

        void scanMatrix(int n, char type);
        void printMatrix();

        double columnSumNorm();
        double rowSumNorm();
        double frobeniusNorm();

        double trace();
        bool isDiagonal();
        bool isSymmetric();
        bool isSkewSymmetric();

};

#endif // MATRIX_H
