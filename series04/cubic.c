#include <stdio.h>
#include <math.h>

double cubeRoot(double, double);

int main(){
    double x, p;

    printf("Enter a number: ");
    scanf("%lf", &x);
    printf("Enter precision: ");
    scanf("%lf", &p);

    double cube = cubeRoot(x, p);
    printf("Cube root of the number with the algorithm: %lf\n", cube);
    printf("Cube root of the number with cbrt function: %lf\n", cbrt(x));
}

double cubeRoot(double x, double precision){
    int isNumberNegative = 0;
    if(x < 0){
        isNumberNegative = 1;
        x = -1*x;
    }
    double start = 0, end = x;
    double mid, error;

    do{
        mid = (start + end) / 2;
        if(x > mid*mid*mid)
            error = x - mid*mid*mid;
        else
            error = mid*mid*mid - x;
        if(error <= precision){
            if(isNumberNegative == 1)
                return -1*mid;
            else
                return mid;
        }
        if((mid*mid*mid) > x)
            end = mid;
        else
            start = mid;
    }while(x > mid);
}
