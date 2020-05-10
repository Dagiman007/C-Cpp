#include "Polynomial.h"

using namespace std;

Polynomial::Polynomial(){
    coeff = (double*) 0;
}
Polynomial::Polynomial(int n){
    assert(n>=0);
    coeff = new double[n+1];
    for(int i=0;i<=n;i++)
        coeff[i] = 0.0;
}
Polynomial::~Polynomial(){
    delete [] coeff;
    coeff = NULL;
}

Polynomial::Polynomial(const Polynomial &obj){
    n = obj.n;
    coeff = new double[n+1];
    for(int i=0;i<=obj.degree();i++)
        coeff[i] = obj[i];
}
Polynomial& Polynomial::operator=(const Polynomial& p){
    if(this != &p){
        this->n = p.degree();
        for(int i=0;i<=p.degree();i++)
            coeff[i] = p[i];
    }else
        cout << "Self assignment!" << endl;

    return *this;
}
int Polynomial::degree () const{
    return this->n;
}
void Polynomial::setCoeff(int k, double value){
    assert(k>=0);
    this->coeff[k] = value;
}
double& Polynomial::get(int k){
    return coeff[k];
}
double& Polynomial::get(int k)const {
    return coeff[k];
}

std::ostream& operator<<(std::ostream& output, const Polynomial& p){
    int n = p.degree();
    if (n == 0) {
      return output << 0;
    }
    else {
      output << p.get(0);   //a_0
      for (int i=1;i<=n;i++) {
        output << " + " << p.get(i) << "x^" << i;   // rest of a_n
      }
      return output;
   }
}

const double& Polynomial::operator [](int j) const{
    assert(j >=0 && j <= n);
    return coeff[j];
}

double& Polynomial::operator [](int j){
    assert(j >=0 && j<= this->degree());
    return this->coeff[j];
}

const Polynomial operator+(const Polynomial& p,const Polynomial& q){
    if (p.degree() > q.degree()){
     Polynomial r(p);
     for (int j=0; j<=q.degree(); ++j) {
       r[j] += q[j];
     }
     return r;
   }
   else {
     Polynomial r(q);
     for (int j=0; j<=p.degree(); ++j) {
       r[j] += p[j];
     }
     return r;
   }
}
const Polynomial operator+(const Polynomial& p,const double a){
    Polynomial r(p);
    r[0] += a;
    return r;
}

const Polynomial operator+(const double a,const Polynomial& p){
    return p+a;
}

const Polynomial operator*(const Polynomial& p ,const Polynomial& q){
    int n1 = p.degree();
    int n2 = q.degree();
    Polynomial r(n1+n2);
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++)
            r[i+j] += p[j]*q[j];
    }
    return r;
}
const Polynomial operator*(const Polynomial& p ,const double a){
    Polynomial r(p);
    for(int i = 0;i<r.degree();i++)
        r[i] *= a;
    return r;
}
const Polynomial operator*(const double a,const Polynomial& p){
    return p*a;
}

const bool operator==(const Polynomial& p,const Polynomial& q){
    if(p.degree() != q.degree())
        return false;
    else{
        double const EPSILON = 1e-10;
        for(int i =0;i<=p.degree();i++){
            if(fabs(p[i] - q[i]) > EPSILON)
                return false;
        }
        return true;
    }
}

double Polynomial::operator()(const int& k, const double& x){
    assert(k<=n && k>=0);
    double prod;
    Polynomial fprime(this->degree()-k);
    for(int i =0;i<(this->degree()-k+1);i++){
        prod= 1.0;
        for(int j=k;j>=1;j--)
            prod *= (i+j);
        fprime[i] = this->coeff[i]*prod;
    }
    double sum = 0.0;
    for(int i=0;i<=fprime.degree();i++)
        sum += fprime[i]*pow(x, (double)i);

    return sum;
}
Polynomial Polynomial::operator()(const int& k){
    assert(k<=n && k>=0);
    double prod;
    Polynomial fprime(this->degree()-k);
    for(int i =0;i<(this->degree()-k+1);i++){
        prod= 1.0;
        for(int j=k;j>=1;j--)
            prod *= (i+j);
        fprime[i] = this->coeff[i]*prod;
    }
    return fprime;
}
double Polynomial::operator()(const double& x){
    double sum = 0.0;
    for(int i=0;this->n;i++)
        sum += this->coeff[i]*pow(x, (double)i);

    return sum;
}

double Polynomial::computeIntegral(double alpha, double beta){
    assert(alpha < beta);
    double sum = 0;
    for(int i = 0;i<=this->degree();i++){
        double temp = coeff[i]*(pow(beta, (double)(i+1)) - pow(alpha, (double)(i+1)));
        sum += temp/(double)(i+1);
    }

    return sum;
}

double Polynomial::computeZero(double x0, double tau){
    assert(tau > 0);
    double fx0, fdx0, xn, fxn;
    Polynomial p(*this);

    do{
        fx0 = p(x0);
        fdx0 = p(1,x0);

        if(fdx0 == 0){
            break;
        }

        xn = x0 - (fx0/fdx0);
        fxn = p(xn);

        if(p(1,xn) <= tau){
            std::cout << "Result may be wrong!!!!!!!!!!!";
            break;
        }
        x0 = xn;

    }while(tau <= (fabs(xn-x0)) || fabs(fxn) > tau);

    return xn;
}

