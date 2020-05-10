#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void bubbleSort(double*, int);

int main(){
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    double *ptr = (double*) malloc(n*sizeof(double));

    printf("Enter elements one by one: \n");
    for(i = 0;i < n; i++){
        scanf("%lf", ptr + i);
    }
    bubbleSort(ptr, n);

    printf("The array sorted: ");
    for(i = 0; i < n;i++)
        printf("%lf ", *(ptr + i));

    free(ptr);

    return 0;

}

void bubbleSort(double* x, int n){
    int needNextPass = 1, i;
    double temp;
    while(n > 1 && needNextPass == 1){
        needNextPass = 0;

        for(i = 0;i < n-1;i++){
            if(*(x + i) > *(x + i + 1)){
                temp = *(x + i);
                *(x + i) = *(x + i+1);
                *(x + i+1) = temp;

                needNextPass = 1;
            }
        }
    }
}
