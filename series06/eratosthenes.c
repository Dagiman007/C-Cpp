#include <stdio.h>
#include <stdlib.h>
#include "eratosthenes.h"

struct _Eratosthenes_{
    int nmax;
    int numOfPrimes;
    int* primes;
};
typedef struct _Eratosthenes_ Eratosthenes;
int main(){
    Eratosthenes* e = doEratosthenesSieve(100);

    int np = e->numOfPrimes;
    int i;
    for(i = 0;i < np;i++){
        printf("%d ", (e->primes));
    }
}

Eratosthenes* doEratosthenesSieve(int nmax){
    int i,j, flag;
    int k = 0;
    Eratosthenes* er;
    er->nmax = nmax;
    int* notPrimes = malloc(nmax*sizeof(int));
    int* primes = malloc(nmax*sizeof(int));

    for(i = 2;i<nmax;i++){
        for(j = i*2;j<nmax;j+=i){
            *(notPrimes + k) = j;
            k++;
        }
    }
    k = 0;
    for(i = 2;i<nmax;i++){
        flag = 0;
        for(j = 0;j<nmax;j++){
            if(*(notPrimes + j) == i){
                flag = 1;
                break;
            }

        }
        if(flag != 1){
            *(primes + k) = i;
            k++;
        }
    }
    er->primes = primes;
    er->numOfPrimes = sizeof(*primes)/sizeof(int);
    return er;
}

void setNmax(Eratosthenes* eratosthenes, int nmax){
    eratosthenes->nmax = nmax;
}
void setNumOfPrimes(Eratosthenes* eratosthenes, int numOfPrimes){
    eratosthenes->numOfPrimes = numOfPrimes;
}
void setPrimes(Eratosthenes* eratosthenes, int* primes){
    eratosthenes->primes = primes;
}

int getNmax(Eratosthenes* eratosthenes){
    return eratosthenes->nmax;
}
int getNumOfPrimes(Eratosthenes* eratosthenes){
    return eratosthenes->numOfPrimes;
}
int* getPrimes(Eratosthenes* eratosthenes){
    return eratosthenes->primes;
}
