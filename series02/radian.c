#include <stdio.h>
#include <math.h>

float radian(float);

int main(){
    float degree;

    printf("Enter the measure of the angle in degrees: ");
    scanf("%f", &degree);

    printf("The angle in radian equals %f", radian(degree));
}

float radian(float degree){
    float psi;
    if(degree < 0)
        degree = -1*degree;
    psi = degree * (M_PI / 180);

    if(psi >= 0 && psi < (2 * M_PI)){
        return psi;
    }else{
        int n;
        float temp = psi / (2 * M_PI);
        n = (int) temp;
        return psi - n * (2 * M_PI);
    }
}
