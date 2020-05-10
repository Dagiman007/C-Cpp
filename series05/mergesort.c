#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void mergeSort(double*, int n);
void swap(double*, double*);

int main(){
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    assert(n > 0);
    double *x = (double*) malloc(n*sizeof(double));

    printf("Enter elements one by one: \n");
    for(i = 0;i < n; i++){
        scanf("%lf", x + i);
    }
    mergeSort(x, 0, n-1);

    printf("The array sorted: ");
    for(i = 0; i < n;i++)
        printf("%lf ", *(x + i));
}

void mergeSort(double* x, low, high){
    int mid, i, j, k;

    if(low < high){
        mid = (low + high) / 2;

        mergeSort(x, low, mid);
        mergeSort(x, mid+1, high);

    }
}

void swap(double* x, double* y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
