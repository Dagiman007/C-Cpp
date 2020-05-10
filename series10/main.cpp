#include "Fraction.h"
#include "FractionVector.h"

using namespace std;

int main()
{
    Fraction f1(2,3);
    Fraction f2(4,9);

    cout << f1 << endl;
    cout << f2 << endl;
    cout << "f1+f2=" << f1+f2 << endl;
    cout << "f1-f2=" << f1-f2 << endl;
    cout << "f1*f2=" << f1*f2 << endl;
    cout << "f1/f2=" << f1/f2 << endl;
    cout << "2/3 in float: " << double(f1)<< endl;
    cout << "0.67 in fraction: " << Fraction(0.67) << endl;
    cout << "Negative of 2/3: " << -f1 << endl;

    bool lt = f1<f2;
    bool eq = f1==f2;
    bool gt = f1>f2;
    bool le = f1<=f2;
    bool ge = f1>=f2;
    bool ne = f1!=f2;
    if(ge)
        cout << "f1 >= f2? True" << endl;
    if(eq)
        cout << "f1 == f2? True" << endl;
    if(gt)
        cout << "f1 > f2? True" << endl;
    if(le)
        cout << "f1 <= f2? True"  << endl;
    if(lt)
        cout << "f1 < f2? True"  << endl;
    if(ne)
        cout << "f1 != f2? True" << endl;

    cout << '\n';
    FractionVector fv(5, f1);
    Fraction f3(5,2);
    Fraction f4(2,1);
    Fraction f5(1,2);
    fv.setElement(0,f1);
    fv.setElement(1,f2);
    fv.setElement(2,f3);
    fv.setElement(3,f4);
    fv.setElement(4,f5);

    cout << "Unsorted: ";
    for(int i=0;i<5;i++)
        cout << fv.getElement(i) << "  ";

    cout << "\nSorted: ";
    fv.insertionSort();
    for(int i=0;i<5;i++)
        cout << fv.getElement(i) << "  ";


    fv.~FractionVector();
    return 0;
}
