#include <stdio.h>
#include <math.h>

void curveSketching(float, float, float);

int main(){
    float a, b, c;

    printf("Enter the coefficients of a + bx + cx*x in order: ");
    scanf("%f %f %f", &a, &b, &c);

    curveSketching(a, b, c);
}

void curveSketching(float a, float b, float c){
    if(c == 0){
        printf("The curve with the specified constants is a Straight line.\n");
    }else{
        printf("The curve is a parabola.\n");
    }

    float yIntercept = a;
    float discriminant = b*b - 4*a*c;

    if(discriminant < 0){
        printf("The curve crosses the y axis at %f but doesn't cross the x axis\n", yIntercept);
    }else if(discriminant == 0){
        printf("The curve crosses the y axis at %f and the x axis at %f \n", yIntercept, (-1*b/2*c));
    }else if(discriminant > 0 && c != 0){
        float xIntercept1 = (-1*b - sqrt(discriminant))/2*c;
        float xIntercept2 = (-1*b + sqrt(discriminant))/2*c;

        printf("The curve crosses the y axis at %f", yIntercept);
        printf(" But it crosses the x axis two times, at %f and %f \n", xIntercept1, xIntercept2);
    }else{
        printf("The line crosses the y axis at %f and x axis at %f \n", a, -1*a/b);
    }

    if(c != 0){
        float temp = -1*b/(2*c);
        float extrema = a + b*(temp) + c*(temp*temp);
        if(c >0)
            printf("The minimum value is %f", extrema);
        else
            printf("The maximum value is %f", extrema);
    }


}
