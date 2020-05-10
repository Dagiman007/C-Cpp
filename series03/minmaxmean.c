#include <stdio.h>

void minmaxmean(double[], int);

int main(){
    double x[5];

    printf("Enter a vector (of length 5): \n");
    int i;
    for(i = 0;i<5;i++){
        scanf("%lf", &x[i]);
    }

    minmaxmean(x, 5);
}

void minmaxmean(double x[], int dim){
    double min = x[0];
    double max = x[0];
    double sum = 0;
    int i,j,k;

    for(i = 1;i < dim; i++){
        if(x[i] < min)
            min = x[i];
        if(x[i] > max)
            max = x[i];
    }
    for(j = 0;j < dim; j++){
        sum += x[j];
    }

    double mean = sum / dim;

    printf("The maximum is %lf, the minimum is %lf and the mean is %lf", max, min, mean);

}
