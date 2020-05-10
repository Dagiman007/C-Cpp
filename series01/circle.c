#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846 /* define the constant pi */

int main(){

    double radius, area;

    /* prompt the user to enter the radius */
    printf("Please enter the radius of the circle: ");
    scanf("%lf", &radius);

    /* compute the area */
    area = PI * pow(radius, 2);

    /* display the result */
    printf("The area of the circle is %lf", area);

    return 0;
}
