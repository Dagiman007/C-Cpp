#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct _Eratosthenes_ Eratosthenes;

Eratosthenes* doEratosthenesSieve(int nmax);
void setNmax(Eratosthenes* eratosthenes, int nmax);
void setNumOfPrimes(Eratosthenes* eratosthenes, int numOfPrimes);
void setPrimes(Eratosthenes* eratosthenes, int* primes);
int getNmax(Eratosthenes* eratosthenes);
int getNumOfPrimes(Eratosthenes* eratosthenes);
int* getPrimes(Eratosthenes* eratosthenes);

#endif

