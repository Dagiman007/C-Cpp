#include <stdio.h>

void swap(double*, double*);

int main(){
    double x, y;
    printf("Enter two number: ");
    scanf("%lf", &x);
    scanf("%lf", &y);

    printf("Before swapping: [%lf, %lf]\n", x, y);
    swap(&x, &y);
    printf("After swapping: [%lf, %lf]", x, y);
}

void swap(double* x, double* y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
