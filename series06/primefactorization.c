#include <stdio.h>
#include <math.h>
#include "eratosthenes.h"

struct _Factorization_{
    int numOfPrimeFactors;
    int* primeFactors;
    int* multiplicites;
};
typedef struct _Factorization_ Factorization;

int main(){

}

Factorization* computePrimeFactorization(int N){
    Factorization f;
    Eratosthenes er = doEratosthenesSieve(N);
    f.numOfPrimeFactors = er.numOfPrimes;
    f.primeFactors = er.primes;
}

int recomposeInteger(Factorization* factorization){
    int i, num = 0;
    int n = sizeof(getNumOfPrimeFactors(factorization))/sizeof(int);
    int* pf = getPrimeFactors(factorization);
    int* mul = getMultiplicties(factorization);
    for(i = 0;i < n;i++){
        num += pow(*(pf + i), *(mul + i));
    }
    return num;
}

void setNumOfPrimeFactors(Factorization* factorization, int n){
    factorization.numOfPrimeFactors = n;
}
void setPrimeFactors(Factorization* factorization, int* primeFactors){
    factorization.primeFactors = primeFactors;
}
void setMultiplicity(Factorization* factorization,int* m){
    factorization.multiplicities = m;
}

int getNumOfPrimeFactors(Factorization* factorization){
    return factorization.numOfPrimeFactors;
}
int* getPrimeFactors(Factorization* factorization){
    return factorization.primeFactors;
}
int* getMultiplicties(Factorization* factorization){
    return factorization.multiplicities;
}
