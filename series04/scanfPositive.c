#include <stdio.h>

double scanfPositive();

int main(){
    double x;

    x = scanfPositive();

    printf("Perfect! you entered a positive number %lf", x);
}

double scanfPositive(){
    double x;
    do{
        printf("Enter a positive number: ");
        scanf("%lf", &x);
    }while(x <= 0);

    return x;
}
