#include <stdio.h>
#include <math.h>
#include <assert.h>

double f(double);
double fprime(double);
double newton(double (*f)(double), double (*fprime)(double), double, double);

int main()
{
    double x0, tau;

    printf("Enter initial guess point: \n");
    scanf("%lf", &x0);

    printf("Enter tolerance: \n");
    scanf("%lf", &tau);
    assert(tau > 0);

    double (*fn)(double) = &f;
    double (*fnp)(double) = &fprime;

    double xn = newton(fn, fnp, x0, tau);
    printf("The root is %lf", xn);

}

double newton(double (*f)(double), double (*fprime)(double), double x0, double tau){
    double fx0, fdx0, xn, fxn;

    do{
        fx0 = (*f)(x0);
        fdx0 = (*fprime)(x0);

        if(fdx0 == 0){
            break;
        }

        xn = x0 - (fx0/fdx0);
        fxn = (*f)(xn);

        if((*fprime)(xn) <= tau){
            printf("Result may be wrong!!!!!!!!!!!");
            break;
        }
        x0 = xn;

    }while(tau <= (fabs(xn-x0)) || fabs(fxn) > tau);

    return xn;
}

double f(double x)
{
    return pow(x,3) - 2*pow(x,2) + x -3;
}
double fprime(double x)
{
    return 3*pow(x,2)- 4*x + 1;
}


