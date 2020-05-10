#ifndef HEADER_FILE
#define HEADER_FILE

Factorization* computePrimeFactorization(int N);
int recomposeInteger(Factorization* factorization);
void setNumOfPrimeFactors(Factorization* factorization, int n);
void setPrimeFactors(Factorization* factorization, int* primeFactors);
void setMultiplicity(Factorization* factorization,int* m);
int getNumOfPrimeFactors(Factorization* factorization);
int* getPrimeFactors(Factorization* factorization);
int* getMultiplicties(Factorization* factorization);

#endif

