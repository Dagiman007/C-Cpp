#include <stdio.h>
#include <math.h>

double partialSum(long);
double partialSum1(long);

int main(){
    long count;

    printf("Enter index: ");
    scanf("%ld", &count);

    printf("The partial sum with method 1 is %lf \n\n", partialSum(count));
    printf("The partial sum with method 2 is %lf \n\n", partialSum1(count));

}

double partialSum(long n){
    double pi = 0;
    double k = 1;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0)
            pi = pi + (1 / k);
        else
            pi = pi - (1 / k);
        k += 2;
    }

    return pi * 4;
}

double partialSum1(long n){
    if (n==0)
        return 4;
    else return 4*pow(-1,n)/(2*n+1)+partialSum1(n-1);
}
