#include <stdio.h>

int binomial(int, int, int);
int binom1(int, int);
int binom2(int, int);
int binom3(int, int);

int main(){
    int n, k;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);

    printf("############## The binomial coefficient ########\n");
    printf("With type 1 --> %d\n", binomial(n, k, 1));
    printf("With type 2 --> %d\n", binomial(n, k, 2));
    printf("With type 3 --> %d\n", binomial(n, k, 3));

    return 0;
}

int factorial(int n){
    if(n > 0)
        return n*factorial(n - 1);
    else
        return 1;
}

int binomial(int n, int k, int type){
    int temp;
    switch(type){
        case 1:
            temp = binom1(n, k);
            break;
        case 2:
            temp =  binom2(n, k);
            break;
        case 3:
            temp = binom3(n, k);
            break;
    }
    return temp;
}

int binom1(int n, int k){
    return factorial(n)/(factorial(k)*factorial(n - k));
}

int binom2(int n, int k){
    int numerator = 1, denominator = 1;
    if(n < k){
        return (0);
    }else{
        for(int i = 1; i <= k; i++)
            denominator *= i;
        for(int j = n - k + 1;j <= n; j++)
            numerator *= j;
        return numerator/denominator;
    }

}

int binom3(int n, int k){
    if(n == k || k == 0){
        return 1;
    }else{
        return binom3(n -1, k) + binom3(n -1, k - 1);
    }
}
