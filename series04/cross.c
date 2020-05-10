#include <stdio.h>
#include <assert.h>

void cross(int);

int main(){
    int n;
    printf("Enter a number between 2 and 9: ");
    scanf("%d", &n);
    cross(n);

    return 0;
}

void cross(int n){
    assert(n >= 2 && n <= 9);

    int i, j;

    for(i = 1; i <= n; i++){
        for(j = 1; j<i; j++)
            printf(" ");
        printf("%d", i);

        for(j=1; j <= ((n-i)*2 - 1); j++)
            printf(" ");

        if(i != n)
            printf("%d", i);

        printf("\n");
    }
    for(i = n-1; i>=1; i--)
    {
        for(j=1; j<i; j++)
            printf(" ");

        printf("%d", i);

        for(j=1; j <= ((n-i)*2 - 1); j++)
            printf(" ");

        printf("%d", i);
        printf("\n");
    }

}
