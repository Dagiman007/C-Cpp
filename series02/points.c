#include <stdio.h>

void points(float,float,float,float,float,float);

int main(){
    float x, y, u, v, a, b;

    printf("Enter the coordinate of the first point (x,y): ");
    scanf("%f %f",&x, &y);
    printf("Enter the coordinate of the second point (u,v): ");
    scanf("%f %f",&u, &v);
    printf("Enter the coordinate of the third point (a,b): ");
    scanf("%f %f",&a, &b);

    points(x, y, u, v, a, b);
}

void points(float x,float y,float u,float v,float a,float b){
    float slope1, slope2, slope3;

    slope1 = (v - y) / (u - x);
    slope2 = (b - y) / (a - x);
    slope3 = (b - v) / (a - u);

    if(slope1 == slope2 && slope1 == slope3 && slope2 == slope3){
        printf("The points lie on the same line.");
    }else{
        printf("The points are not collinear.");
    }
}
