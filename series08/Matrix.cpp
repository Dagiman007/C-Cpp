#include "Matrix.h"
using namespace std;
Matrix::Matrix(){
    this->type = 'F';
    coeff = (double*) 0;
}
Matrix::Matrix(int n, char type){
    assert(n>0);
    this->type = type;
    int s;
    if(this->type == 'F')
        s = n*n;
    else if(this->type == 'U' || this->type =='L')
        s = n*(n+1)/2;

    assert(coeff != (double*) 0);
    coeff = (double*) malloc(s*sizeof(double));
    for (int i=0; i<s; i++) {coeff[i]= 0;}
}
Matrix::Matrix(int n, char type, double value){
    assert(n>0);
    this->type = type;
    int s;
    if(this->type == 'F')
        s = n*n;
    else if(this->type == 'U' || this->type =='L')
        s = n*(n+1)/2;

    assert(coeff != (double*) 0);
    coeff = (double*) malloc(s*sizeof(double));
    for (int i=0; i<s; i++)
        coeff[i]= value;
}

Matrix::Matrix(int n, char type, double lb, double ub){
    assert(n>0);
    this->type = type;
    int s;
    if(this->type == 'F')
        s = n*n;
    else if(this->type == 'U' || this->type =='L')
        s = n*(n+1)/2;

    assert(coeff != (double*) 0);
    coeff = (double*) malloc(s*sizeof(double));
    srand(time(0));
    double rnd;
    for (int i=0; i<s; i++){
        rnd = (ub - lb)*((double)rand() /(double)RAND_MAX) + lb;
        coeff[i] = rnd;
    }
}

int Matrix::getN(){
    return this->n;
}
void Matrix::setN(int n){
    assert(n>0);
    this->n = n;
}
char Matrix::getType(){
    return this->type;
}
void Matrix::setType(char type){
    this->type = type;
}
void Matrix::set(int k, double value){
    int s;
    if(this->type == 'U' || this->type == 'L')
        s = n*(n+1)/2;
    else
        s = n*n;
    assert(k >= 0 && k < s);
    coeff[k] = value;
}
double Matrix::get(int k){
    int s;
    if(this->type == 'U' || this->type == 'L')
        s = n*(n+1)/2;
    else
        s = n*n;
    assert(k >= 0 && k < s);
    return coeff[k];
}
Matrix::~Matrix(){ free(coeff);}

void Matrix::scanMatrix(int n, char type){
    int s;
    this->n = n;
    if(type == 'U' || type == 'L')
        s = n*(n+1)/2;
    else
        s = n*n;
    for(int i = 0; i < s;i++){
        cin >> coeff[i];
    }
}

void Matrix::printMatrix(){
    if(this->type == 'L'){
        int s = n*(n+1)/2;
        int k = n;
        for(int i = 0;i < n;i++){
            for(int j=0;j<=i;j++){
                cout << setw(5) << coeff[i+j*n];
            }
        }
    }else if(this->type == 'U'){
        int s = n*(n+1)/2;
        int k =1;
        for(int i = 0;i < n;i+=k){
            for(int j=n;j<s;j++){
                cout << setw(5) << coeff[i+j];
                j++;
            }
            k++;
        }
    }else{
        for(int i = 0;i < n;i++){
            for(int j = n;j<n*n;j+=n){
                cout << setw(5) << coeff[i+j];
            }
            cout << '\n';
        }
    }
}

double Matrix::columnSumNorm(){
    double sum = 0;
    double max = 0;
    if(this->type == 'U'){
        for(int i = 0;i<n;i++){
            for(int j =0;j<i;j++){
                sum += abs(coeff[i+j]);
            }
            if(sum > max)   max = sum;
        }
    }else if(this->type == 'L'){
        int k =0;
        for(int i = 0;i<n-k;i++){
            for(int j =0;j<i;j++){
                sum += abs(coeff[i+j]);
            }
            if(sum > max)   max = sum;
            k++;
        }
    }else{
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                sum += abs(coeff[i+j]);
            }
            if(sum > max)
                max = sum;
        }
    }
    return max;
}
double Matrix::rowSumNorm(){
    double sum = 0;
    double max = 0;
    if(this->type == 'U'){
        int k=1;
        for(int i = 0;i<n;i+=k){
            for(int j =0;j<n;j++){
                sum += abs(coeff[i+j]);
            }
            if(sum > max)   max = sum;
        k++;
        }
    }else if(this->type == 'L'){
        int k =0;
        for(int i = 0;i<n-k;i++){
            for(int j =0;j<i;j++){
                sum += abs(coeff[i+j+j*n]);
            }
            if(sum > max)   max = sum;
            k++;
        }
    }else{
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                sum += abs(coeff[i+j]);
            }
            if(sum > max)
                max = sum;
        }
    }
    return max;
}
double Matrix::frobeniusNorm(){
    double sum = 0;
    int s;
    if(this->type == 'U' || this->type == 'L')
        s = n*(n+1)/2;
    else
        s = n*n;
    for(int i = 0; i < s; i++)
        sum += pow(coeff[i], 2.0);

    return sqrt(sum);
}

double Matrix::trace(){
    double sum = 0;
    int k = 1;
    if(this->type == 'U'){
        for(int i = 0;i<n;i+=k)
            sum += coeff[i];
        k++;
    }else if(this->type == 'L'){
        for(int i = 0;i<n;i+=k)
            sum += coeff[i];
        k++;
    }else{
        for(int i = 0;i < n;i=i+i*n)
            sum += coeff[i];
    }
    return sum;
}
bool Matrix::isDiagonal(){
    if(this->type == 'U'){
        for(int i = 1;i<n;i++)
            for(int j = 0;j<i;j++)
                if(coeff[i+j] != 0)
                    return false;
        return true;
    }else if(this->type == 'L'){
        for(int i = 1;i<n;i++)
            for(int j = i;j<n;j++)
                if(coeff[i+j] != 0)
                    return false;
        return true;
    }else{
        for(int i = 1;i < n*n;i=i+n+1)
            if(n%i==0)
                continue;
            else
                if(coeff[i]!=0)
                    return false;
        return true;

    }
}
bool Matrix::isSymmetric(){
    if(this->type == 'U' || this->type == 'L'){
        if(isDiagonal())
            return true;
        else
            return false;

    }else{
        int k = 1;
        for(int i = 1;i < n;i++)
            for(int j = i;j < n;j++)
                if(coeff[i+j]!= coeff[i+j+j*(n-k)])
                    return false;
            k++;
        return true;
    }
}
bool Matrix::isSkewSymmetric(){
    if(this->type == 'U' || this->type == 'L'){
        if(!isDiagonal())
            return false;
        else{
            for(int i = 0;i<n;i++)
                if(coeff[i] != 0)
                    return false;
            return true;
        }

    }else{
        int k = 1;
        for(int i = 1;i < n;i++)
            for(int j = i;j < n;j++)
                if(coeff[i+j]!= -1*coeff[i+j+j*(n-k)])
                    return false;
            k++;

        return true;

    }
}

