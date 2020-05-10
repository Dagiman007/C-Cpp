#include <stdio.h>


int main()
{
    double length, width;
    double area = 0.0;

    /* prompt the user to enter the length and width of the rectangle */
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &length);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &width);

    area = length * width;  /* compute the area */

    /* display the result */
    printf("The area of the rectangle is ");
    printf("%lf", area);

    return 0;
}
