#include <stdio.h>


int main(){

    float L;
    float x, y;

    do{
        printf("Enter the length of the square (must be positive): ");
        scanf("%f", &L);
    }while(L < 0);

    printf("Enter the value of x coordinate: ");
    scanf("%f", &x);
    printf("Enter the value y coordinate: ");
    scanf("%f", &y);



    if(x < 0 || y < 0 || x > L || y > L){
        printf("The point is outside the square.");
    }else if(x == L && y <= L){
        printf("The point lies on the right boundary of the square");
    }else if(x == 0 && y <= L){
        printf("The point lies on the left boundary of the square.");
    }else if(x <= L && y == L){
        printf("The point lies on the top boundary of the square.");
    }else if(x <= L && y == 0){
        printf("The point lies on the bottom boundary of the square.");
    }else if(x > 0 && y > 0 && x < L && y < L){
        printf("The point lies inside the square.");
    }else{
        printf("The point lies outside the square.");
    }

    return 0;
}
