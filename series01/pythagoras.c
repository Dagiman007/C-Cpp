#include <stdio.h>
#include <math.h>


int main(){

    unsigned int num1, num2, num3;
    int triple = 0;

    /* prompt the user to enter the numbers */
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);
    printf("Enter the third number: ");
    scanf("%d", &num3);

    /* check if the numbers are pythagoras triples */
    if(pow(num1, 2) == (pow(num2, 2) + pow(num3,2)))
        triple = 1;
    else if(pow(num2, 2) == (pow(num3, 2) + pow(num1,2)))
        triple = 1;
    else if(pow(num3, 2) == (pow(num2, 2) + pow(num1,2)))
        triple = 1;

    if(triple == 1)
        printf("The numbers are pythagorean triples.");
    else
        printf("The numbers are not pythagorean triples.");

    return 0;
}
