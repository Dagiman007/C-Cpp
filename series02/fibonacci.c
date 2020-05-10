#include <stdio.h>

int fibonnaci(int);

int main(){
    int index;

    printf("Enter an index for a Fibonnaci number: ");
    scanf("%d", &index);

    printf("The fibonnaci number X%d is %d", index, fibonnaci(index));
}

int fibonnaci(int index){
    if(index == 0)
        return 0;
    else if(index == 1)
        return 1;
    else
        return fibonnaci(index - 1) + fibonnaci(index - 2);
}
