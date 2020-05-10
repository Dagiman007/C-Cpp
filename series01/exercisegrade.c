#include <stdio.h>

int main(){

    int numOfMarkedEx[10];
    int total = 0;
    double percentage;

    int i;
    for(i = 0;i < 10; i++){
        printf("Enter the number of marked exercises from sheet %d :", i + 1);
        scanf("%d", &numOfMarkedEx[i]);
    }

    int j;
    for(j = 0; j < 10; j++)
        total += numOfMarkedEx[j];

    percentage = ((double)total / 80.0) * 100.0;

    printf('\n');

    if(percentage >= 50){
        printf("Percentage = %lf ,enough for a positive final grade", percentage);
    }else{
        printf("percentage = %lf not enough for a positive final grade", percentage);
    }

    return 0;
}
