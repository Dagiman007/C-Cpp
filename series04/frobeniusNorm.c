#include <stdio.h>
#include <math.h>

double frobeniusNorm(double[], int,  int);

int main(){
    int m = 3, n = 2;
    double matrix[m*n];

    printf("Enter the matrix: ");
    int i;
    for(i = 0; i < m*n; i++)
        scanf("%lf", &matrix[i]);
    double fn = frobeniusNorm(matrix, m, n);
    printf("The frobenius norm for the matrix is : %lf", fn);

}

double frobeniusNorm(double matrix[], int m,  int n){
    int i;
    double sum = 0;
    for(i = 0; i < m*n; i++)
        sum += pow(matrix[i], 2.0);

    return pow(sum, 0.5);
}
