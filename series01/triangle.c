#include <stdio.h>
#include <math.h>

int main(){

    float edge1, edge2, edge3;
    printf("Enter the length of edge 1: ");
    scanf("%f",&edge1);
    printf("Enter the length of edge 2: ");
    scanf("%f",&edge2);
    printf("Enter the length of edge 3: ");
    scanf("%f",&edge3);

    if(edge1 == edge2 && edge1== edge3)
        printf("The triangle is equilateral.");
    else if(edge1 == edge2 || edge1 == edge3 || edge2 == edge3)
        printf("The triangle is isosceles triangle.");
    else
        printf("The triangle is scalene.");

    if(pow(edge1, 2) == pow(edge2, 2) + pow(edge3,2) || pow(edge2, 2) == pow(edge3, 2) + pow(edge1,2) ||
       pow(edge3, 2) == pow(edge2, 2) + pow(edge1,2)){
            printf("The triangle is right angled.");
       }
    if((edge1 == edge2 + edge3)||(edge2 == edge1 + edge3)||(edge3 == edge2 + edge1)){
        printf("The triangle is a one-dimensional degenerate.");
    }else if(edge1 > edge2 + edge3 || edge2 > edge1 + edge3 || edge3 > edge2 + edge1 ){
        printf("Impossible. No triangle with the data you entered.");
    }




}
