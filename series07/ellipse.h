#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <iostream>
#include <cmath>
using namespace std;

class ellipse
{
    private:
        double center[2];
        double a;
        double b;
    public:
        double getCenter();
        double getA();
        double getB();
        void setCenter(double x0, double x1);
        void setA(double a0);
        void setB(double b0);
        bool isInside(double x, double y);
        bool isCircle();
        void printFocalPoints();
        double getEccentricity();

};

#endif // ELLIPSE_H
