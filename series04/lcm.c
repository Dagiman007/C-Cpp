#include <stdio.h>

int lcm(int, int);

int main(){
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    printf("The lcm of the two number is %d", lcm(a,b));
}

int lcm(int a, int b){
    int lcm;
    if(a > b)
        lcm = a;
    else
        lcm = b;

    while(1){
        if(lcm % a == 0 && lcm % b == 0)
            break;
        lcm++;
    }

    return lcm;
}
