#include <stdio.h>

int fibonacci(int);

int main(){
    int index;

    printf("Enter the index: ");
    scanf("%d", &index);

    printf("The fibonacci number for that index is %d", fibonacci(index));
}

int fibonacci(int n){
    if(n <= 1){
        return n;
    }

    int fibonacciNumber = 1;
    int previousNumber = 0;

    for(int i = 2; i <= n; ++i){
        int temp = fibonacciNumber;
        fibonacciNumber += previousNumber;
        previousNumber = temp;
    }
    return fibonacciNumber;
}
