#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void cut(double*, int*, double, double);
void selectionSort(double*, int);
int main(){
    int* n;
    int i;
    double cmin, cmax;

    printf("Enter the number of elements: ");
    scanf("%d", n);
    assert(*n > 0);
    double *x = (double*) malloc(*n*sizeof(double));

    printf("Enter elements one by one: \n");
    for(i = 0;i < *n; i++){
        scanf("%lf", x + i);
    }

    printf("Enter cmin: ");
    scanf("%lf", &cmin);
    printf("Enter cmax: ");
    scanf("%lf", &cmax);

    printf("The original vector: ");
    for(i = 0;i < *n; i++){
        printf("%lf ", *(x + i));
    }
    cut(x, n, cmin, cmax);
    printf("The new vector: ");
    for(i = 0;i < *n; i++){
        printf(" %lf ", *(x + i));
    }
}

void cut(double* x, int* n, double cmin, double cmax){
    int i, j, k;
    //selectionSort(x, *n);
    for(i = 0;i < *n; i++){
        for(j = i; j < *n;){
            if(*(x + j) < cmin || *(x + j) > cmax){
                for(k = j;k < *n;k++){
                    *(x + k) = *(x + k + 1);
                }
                (*n)--;
            }else{
                j++;
            }
        }
    }
}

void selectionSort(double* x, int n){
    int i,j , currentMinIndex;
    double currentMin;
    for(i = 0;i < n - 1; i++){
        currentMin = *(x + i);
        currentMinIndex = i;

        for(j = i + 1; j < n; j++){
            if(currentMin > *(x + j)){
                currentMin = *(x + j);
                currentMinIndex = j;
            }
        }
        if(currentMinIndex != i){
            *(x + currentMinIndex) = *(x + i);
            *(x + i) = currentMin;
        }
    }
}
