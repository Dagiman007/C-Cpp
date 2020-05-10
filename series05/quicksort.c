#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


void quickSort(double*, int);
void quickSortHelper(double*, int, int);
void swap(int*, int*);

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
    quickSort(x, n);

    printf("The array sorted: ");
    for(i = 0; i < n;i++)
        printf("%lf ", *(x + i));
}

void quickSort(double* x, int n){
    quickSortHelper(x, 0, n);
}

void quickSortHelper(double* x, int low, int high){
    int i = low, j = high - 1;
    int pivot = *(x + (i + (j - i)/2));

    while(i <= j){
        while(*(x + i) < pivot){
            i++;
        }
        while(*(x + j) > pivot){
            j--;
        }

        if(i <= j){
            swap(&i, &j);
            i++;
            j--;
        }
    }

    if(low < j)
        quickSortHelper(x, low, j);
    if(i < high)
        quickSortHelper(x, i, high);
}

void swap(int* x, int* y){
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
