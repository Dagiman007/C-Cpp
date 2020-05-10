#include <stdio.h>

void quadrant(double, double);

int main(){
    double x, y;

    printf("Enter the value of x coordinate: ");
    scanf("%lf", &x);
    printf("Enter the value of y coordinate: ");
    scanf("%lf", &y);

    quadrant(x, y);
}

void quadrant(double x, double y){
    if(x == 0 && y == 0){
        printf("The point lies at the origin.");
    }else if(x != 0 && y == 0){
        printf("The point lies on the x-axis.");
    }else if(x == 0 && y != 0){
        printf("The point lies on the y-axis");
    }else if(x > 0 && y > 0){
        printf("The point is on the first quadrant.");
    }else if(x < 0 && y > 0){
        printf("The point is on the second quadrant.");
    }else if(x < 0 && y < 0){
        printf("The point is on the third quadrant.");
    }else if(x > 0 && y < 0){
        printf("The point is on the fourth quadrant.");
    }
}
