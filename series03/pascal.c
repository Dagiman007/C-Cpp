#include <stdio.h>

int main(){
    int rows, number = 1, i, j, k;

    printf("Enter rows : ");
    scanf("%d", &rows);

    for(i = 0; i < rows; i++){
        for(j = 1; j <= (rows - i); j++){
            printf("   ");
        }
        for(k = 0; k <= i; k++){
            if(k == 0 || i == 0)
                number = 1;
            else
                number = number*(i - k + 1)/k;

            printf("%4d ", number);
        }
        printf("\n");
    }

    return 0;

}

