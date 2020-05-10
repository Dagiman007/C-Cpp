#include "ellipse.h"

int main(){
    double x0, y0, a, b, x, y;
    cout << "Enter the center: " << endl;
    cin >> x0 >> y0;
    cout << "Enter a and b : ";
    cin >> a >> b;
    cout << "Enter coordinates you want to check" <<endl;
    cin >> x >> y;

    ellipse e;
    e.setCenter(x0, y0);
    e.setA(a); e.setB(b);

    if(e.isCircle()){
        cout << "The shape is circle " << endl;
    }
    if(e.isInside(x, y)){
        cout << "The point is inside the ellipse " << endl;
    }else{
        cout << "The point is outside the ellipse" << endl;
    }
    e.printFocalPoints();
    cout << "The eccentricity : " << e.getEccentricity();
    return 0;
}

double ellipse::getA(){
    return a;
}
double ellipse::getB(){
    return b;
}
void ellipse::setCenter(double x0, double x1){
    center[0] = x0; center[1] = x1;
}
void ellipse::setA(double a){
    this->a = a;
}
void ellipse::setB(double b){
    this->b = b;
}
bool ellipse::isInside(double x, double y){
    double pos = (x-center[0])*(x-center[0])/a + (y-center[1])*(y-center[1])/b;
    if (pos<1)
        return true;
    else if (pos == 1){
        cout<<"The point is on the ellipse"<<endl;
        return true;
    }
    else
        return false;
}
bool ellipse::isCircle(){
    bool temp;
    getA() == getB() ? temp = true : temp = false;
    return temp;
}
void ellipse::printFocalPoints(){
    double c;
    double focus1[2];
    double focus2[2];
    if(a>b){
        c = sqrt(a*a-b*b);
        focus1[0] = center[0]+c;
        focus1[1] = center[1];
        focus2[0] = center[0]-c;
        focus2[1] = center[1];}

    else if(b >= a){
        c = sqrt(b*b-a*a);
        focus1[0] = center[0];
        focus1[1] = center[1]+c;
        focus2[0] = center[0];
        focus2[1] = center[1]-c;}

        cout<<" Focal points (" << focus1[0]<<","<<focus1[1]<<")"<<" and ("<<focus2[0]<<","<<focus2[1]<<")"<<endl;

}
double ellipse::getEccentricity(){
    double e;
    if (a>=b) e = sqrt(1 - (b*b)/(a*a));
    else     e = sqrt(1 - (a*a)/(b*b));
    return e;
}
