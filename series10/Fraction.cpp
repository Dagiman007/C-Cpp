#include "Fraction.h"

Fraction::Fraction(){
   p = 0;
   q = 1;
}
Fraction::Fraction(int p, int q){
    assert(q != 0);
    if(q < 0){
        this->p = -1*p;
        this->q = std::abs(q);
    }else{
        this->p = p;
        this->q = q;
    }
}
Fraction::~Fraction(){
}
Fraction::Fraction(const Fraction& obj){
    this->p = obj.p;
    this->q = obj.q;
}
Fraction& Fraction::operator=(const Fraction& f){
    this->p = f.p;
    this->q = f.q;
    return *this;
}
int Fraction::gcd(int p,int q){
    int n1, n2;
    int gcd=1;int k=1;
    n1 = std::abs(p);
    n2 = std::abs(q);
    while(k<=n1 && k<= n2){
        if(n1%k == 0 && n2%k ==0)
            gcd = k;
        k += 1;
    }
    return gcd;
}
void Fraction::reduce(){
    int divisor = (p != 0) ? gcd(p,q) : 1;
    this->p = p/divisor;
    this->q = q/divisor;
}
int Fraction::getNum() const{
    return p;
}
int Fraction::getDen()const{
    return q;
}
Fraction::operator double() const{
    return (double)p/(double)q;
}
Fraction::Fraction(double f){
    double integral = floor(f);
    double frac = f - integral;
    const double precision = 1e9;
    double g = gcd(round(frac*precision), precision);
    q = precision/g;
    p = round(frac*precision)/g;

}

const Fraction operator+(const Fraction& r , const Fraction& s){
    int numerator = r.getNum()*s.getDen() + r.getDen()*s.getNum();
    int denominator = r.getDen()*s.getDen();
    Fraction f(numerator, denominator);
    f.reduce();
    return f;
}
const Fraction operator*(const Fraction& r , const Fraction& s){
    int numerator = r.getNum()*s.getNum();
    int denominator = r.getDen()*s.getDen();
    Fraction f(numerator, denominator);
    f.reduce();
    return f;
}
const Fraction operator-(const Fraction& r, const Fraction& s){
    int numerator = r.getNum()*s.getDen() - r.getDen()*s.getNum();
    int denominator = r.getDen()*s.getDen();
    Fraction f(numerator, denominator);
    f.reduce();
    return f;
}
const Fraction operator/(const Fraction& r, const Fraction& s){
    assert(s.getNum() != 0);
    int numerator = r.getNum()*s.getDen();
    int denominator = r.getDen()*s.getNum();
    Fraction f(numerator, denominator);
    f.reduce();
    return f;
}

const int compare(const Fraction& r, const Fraction& s){
    Fraction temp = r-s;
    if(temp.getNum() > 0)
        return 1;
    else if(temp.getNum() < 0)
        return -1;
    else
        return 0;
}

const bool operator==(const Fraction& r, const Fraction& s){
    return compare(r,s) == 0;
}
const bool operator!=(const Fraction& r, const Fraction& s){
    return compare(r,s) != 0;
}
const bool operator>=(const Fraction& r, const Fraction& s){
    return compare(r,s) >= 0;
}
const bool operator>(const Fraction& r, const Fraction& s){
    return compare(r,s) > 0;
}
const bool operator<(const Fraction& r, const Fraction& s){
    return compare(r,s) < 0;
}
const bool operator<=(const Fraction& r, const Fraction& s){
    return compare(r,s) <= 0;
}

const Fraction Fraction::operator-() const{
    return Fraction(-p,q);
}

std::ostream& operator<<(std::ostream& output, const Fraction& f){
    output << f.getNum() << "/" << f.getDen();

    return output;
}
