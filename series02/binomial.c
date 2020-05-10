#include <stdio.h>

int binomial(int, int);

int main(){
    int n, k;

    printf("Enter the value of n: ");
    scanf("%d",&n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    printf("The binomial coefficient is %d", binomial(n, k));
}

int binomial(int n, int k){
    if(n == k || k == 0){
        return 1;
    }else{
        return binomial(n -1, k) + binomial(n -1, k - 1);
    }
}
