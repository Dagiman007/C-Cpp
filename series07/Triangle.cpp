#include "Triangle.h"

#define EPSILON 1e-10

int main(){
    double x1,x2,y1,y2,z1,z2;
    cout << "Enter the first vertex: ";
    cin >> x1 >> x2;
    cout << "Enter the second vertex: ";
    cin >> y1 >> y2;
    cout << "Enter the third vertex: ";
    cin >> z1 >> z2;

    Triangle T;
    T.setX(x1, x2);
    T.setY(y1, y2);
    T.setZ(z1, z2);


    cout << "The area of the triangle: " << T.getArea() << endl;
    cout << "The perimeter of the triangle: " << T.getPerimeter() << endl;
    cout << "Is the triangle equilateral? " << endl;
    if(T.isEquilateral())
        cout << "True!!" << endl;
    else
        cout << "False" << endl;
}

void Triangle::setX(double x0, double x1){
    x[0] = x0; x[1] = x1;
}

void Triangle::setY(double y0, double y1) {
        y[0] = y0; y[1] = y1;
}
void Triangle::setZ(double z0, double z1) {
    z[0] = z0; z[1] = z1;
}
double Triangle::getArea() {
    return 0.5*fabs( (y[0]-x[0])*(z[1]-x[1])- (z[0]-x[0])*(y[1]-x[1]) );
}

double Triangle::getPerimeter(){
    double s1, s2, s3;
    s1 = sqrt((x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]));
    s2 = sqrt((y[0]-z[0])*(y[0]-z[0])+(y[1]-z[1])*(y[1]-z[1]));
    s3 = sqrt((z[0]-x[0])*(z[0]-x[0])+(z[1]-x[1])*(z[1]-x[1]));
    return s1+s2+s3;
}

bool Triangle::isEquilateral(){
    double s1, s2, s3;
    s1 = sqrt((x[0]-y[0])*(x[0]-y[0])+(x[1]-y[1])*(x[1]-y[1]));
    s2 = sqrt((y[0]-z[0])*(y[0]-z[0])+(y[1]-z[1])*(y[1]-z[1]));
    s3 = sqrt((z[0]-x[0])*(z[0]-x[0])+(z[1]-x[1])*(z[1]-x[1]));

    if(fabs(s1 - s2) < EPSILON && fabs(s1 - s3) < EPSILON && fabs(s2 - s3) < EPSILON)
        return true;
    else
        return false;
}
