#include <stdio.h>

int main(){

    double num1, num2, num3;
    double temp;

    printf("Enter the first number: ");
    scanf("%lf", &num1);
    printf("Enter the second number: ");
    scanf("%lf", &num2);
    printf("Enter the third number: ");
    scanf("%lf", &num3);

    printf("The numbers in descending order: ");
    if(num1 < num2)
        if(num1 < num3)
            if(num2 < num3)
                printf("%lf  %lf  %lf", num3, num2, num1);
            else
                printf("%lf  %lf  %lf", num2, num3, num1);
        else
            printf("%lf  %lf  %lf", num2, num1, num3);
    else
        if(num2 < num3)
            if(num1 < num3)
                printf("%lf  %lf  %lf", num3, num1, num2);
            else
                printf("%lf  %lf  %lf", num1, num3, num2);
        else
            printf("%lf  %lf  %lf", num1, num2, num3);


}
