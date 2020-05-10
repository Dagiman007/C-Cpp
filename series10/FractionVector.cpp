#include "FractionVector.h"

FractionVector::FractionVector(int n, Fraction init){
    this->n = n;
    vec = new Fraction[n];
    for(int i =0;i<n;i++)
        vec[i] = init;
}

FractionVector::~FractionVector(){
    delete [] vec;
}


FractionVector::FractionVector(const FractionVector& obj){
    vec = new Fraction[obj.getLength()];
    for(int i =0;i<n;i++)
        vec[i] = obj.getElement(i);
}

FractionVector& FractionVector::operator=(const FractionVector& f){
    n = f.getLength();
    vec = new Fraction[f.getLength()];
    for(int i =0;i<n;i++)
        vec[i] = f.getElement(i);
    return *this;
}

int FractionVector::getLength() const{
    return n;
}
Fraction FractionVector::getElement(int k)const {
    assert(k>=0 && k<= n);
    return vec[k];
}
void FractionVector::setElement(int k, Fraction f) const{
    assert(k>=0 && k<= n);
    vec[k] = f;
}
void FractionVector::insertionSort(){
    for(int i = 0;i < n ; i++){
        Fraction temp = vec[i];
        int k = i;

        while(k > 0 && vec[k-1] > temp){
            vec[k] = vec[k-1];
            k -= 1;

        }
        vec[k] = temp;
    }
}
