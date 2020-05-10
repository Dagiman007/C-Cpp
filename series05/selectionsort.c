#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void selectionSort(double* , int );

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
    selectionSort(ptr, n);

    printf("The array sorted: ");
    for(i = 0; i < n;i++)
        printf("%lf ", *(ptr + i));
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
