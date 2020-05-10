#include <stdio.h>

int division(int, int);

int main(){
    int num1, num2;

    printf("Enter the first integer: ");
    scanf("%d", &num1);
    printf("Enter the second integer: ");
    scanf("%d", &num2);

    printf("The first number divided by the second without remainder is : %d", division(num1, num2));
}

int division(int num1, int num2){
    if(num2 == 0)
        return 0;
    else if(num1 - num2 == 0)
        return 1;
    else if(num1 < num2)
        return 0;
    else
        return 1 + division(num1 - num2,num2);
}
