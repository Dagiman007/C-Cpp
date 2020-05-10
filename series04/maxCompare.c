#include <stdio.h>

int maxCompare(double[], double[], int);

int main(){
    int n = 8;
    int i;
    double a[8], b[8];
    printf("Enter the first vector: ");
    for(i = 0; i < 8; i++)
        scanf("%lf", &a[i]);
    printf("Enter the second vector: ");
    for(i = 0;i < 8; i++)
        scanf("%lf",&b[i]);

    int result = maxCompare(a, b, 8);
    printf("The max compare is %d", result);
}

int maxCompare(double a[], double b[], int n){
    int maxCount = 0;
    double maxa = a[0];
    double maxb = b[0];
    int i;
    for(i = 1; i < n; i++){
        if(a[i] > maxa)
            maxa = a[i];
        if(b[i] > maxb)
            maxb = b[i];
    }
    if(maxa != maxb)
        return 0;

    for(i = 0; i < n; i++){
        double max = maxa;
        if(a[i] == max && b[i] == max)
            maxCount++;
    }

    return 2*maxCount;
}
