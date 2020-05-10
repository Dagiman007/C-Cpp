#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insertionSort(double* , int );

int main(){
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    assert(n > 0);
    double *ptr = (double*) malloc(n*sizeof(double));

    printf("Enter elements one by one: \n");
    for(i = 0;i < n; i++){
        scanf("%lf", ptr + i);
    }
    insertionSort(ptr, n);

    printf("The array sorted: ");
    for(i = 0; i < n;i++)
        printf("%lf ", *(ptr + i));
}

void insertionSort(double* x, int n){
    int i, k , currentMinIndex;
    double currentElement;
    for(i = 1;i < n ; i++){
        currentElement = *(x + i);
        k = i - 1;

        while(k >= 0 && *(x + k) > currentElement){
            *(x + k + 1) = *(x + k);
            k -= 1;
        }
        *(x + k + 1) = currentElement;

    }
}

