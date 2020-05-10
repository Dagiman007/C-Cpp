#include <stdio.h>
#include <math.h>
#include <assert.h>

double geometricMean(double[], int);

int main(){
    int length = 10;
    double v[length];

    printf("Enter a vector of size 10 and positive: ");
    int i;
    for(i = 0; i < length; i++){
        scanf("%lf", &v[i]);
        assert(v[i] >= 0);
    }

    double gm = geometricMean(v, length);
    printf("The geometric mean for the vector is %lf", gm);
}

double geometricMean(double numbers[], int length){
    double prod = 1;
    int i;

    for(i = 0;i < length;i++)
        prod *= numbers[i];

    return pow(prod, 1.0/(double)length);
}
