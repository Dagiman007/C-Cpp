#include <stdio.h>
#include <math.h>
#include <assert.h>

double f(double);
double secant(double (*f)(double), double, double, double);

int main()
{
    double x0,x1, tau;

    printf("Enter the first initial guess point: \n");
    scanf("%lf", &x0);
    printf("Enter the second initial guess point: \n");
    scanf("%lf", &x1);

    printf("Enter tolerance: \n");
    scanf("%lf", &tau);
    assert(tau > 0);

    double (*fn)(double) = &f;

    double xn = secant(fn, x0, x1, tau);
    printf("The root is %lf", xn);

}

double secant(double (*f)(double),  double x0, double x1, double tau){
    double fx0, fx1,fdx0, xn, fxn;

    do{
        fx0 = (*f)(x0);
        fx1 = (*f)(x1);

        if(fx0 == fx1){
            printf("Method can not be used\n");
            break;
        }

        xn = x1 - fx1*((x0 - x1)/(fx0 - fx1));
        fxn = (*f)(xn);

        if(fxn - fx1 <= tau){
            printf("Result may be wrong!!!!!!!!!!!\n\n");
            break;
        }
        x0 = xn;
        x0 = x1;
        x1 = xn;

    }while(tau >= (fabs(xn-x1)) || fabs(fxn) > tau);

    return xn;
}

double f(double x)
{
    return pow(x,3) - 2*pow(x,2) + x -3;
}



