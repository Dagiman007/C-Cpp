#include <stdio.h>
#include <assert.h>

int sqrtBoundaries(double);

int main(){
    double x;

    printf("Enter a number\n");
    scanf("%lf",&x);
    assert(x >= 0);

    int k = sqrtBoundaries(x);
    printf("The square root of the number lies between %d and %d", k, k + 1);

    return 0;

}

int sqrtBoundaries(double x){
    int i = 1;
    while ((i*i)<=x){
        i++;
    }
    return i-1;
}
