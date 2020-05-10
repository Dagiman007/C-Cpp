#include <stdio.h>

double scalarProduct(double v1[], double v2[]);
void vectorProduct(double v1[], double v2[]);

int main(){
    double vector1[3];
    double vector2[3];

    printf("Enter vector 1: ");
    int i;
    for(i = 0;i < 3;i++){
        scanf("%lf", &vector1[i]);
    }

    printf("Enter vector 2: ");
    int j;
    for(j = 0; j < 3; j++){
        scanf("%lf", &vector2[j]);
    }

    printf("The scalar product is %lf \n", scalarProduct(vector1, vector2));
    vectorProduct(vector1, vector2);
}

double scalarProduct(double v1[], double v2[]){
    double product = 0;
    int i;
    for(i = 0;i < 3; i++){
        product += (v1[i] * v2[i]);
    }
    return product;
}

void vectorProduct(double v1[], double v2[]){
    double product[3];
    product[0] = v1[1]*v2[2] - v1[2]*v2[1];
    product[1] = v1[2]*v2[0] - v1[0]*v2[2];
    product[2] = v1[0]*v2[1] - v1[2]*v2[0];

    printf("The vector product of the two vector is ");
    printf("(%lf ,%lf , %lf)", product[0], product[1], product[2]);

}
