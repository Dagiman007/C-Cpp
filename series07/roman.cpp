#include <iostream>

using namespace std;

int roman2int(string);
string int2roman(int);
int value(char);

int main(){
    string s;
    int n;
    cout << "Enter a roman literal: " << endl;
    getline(cin, s);
    cout << "The number is " << roman2int(s) << endl;
    cout << "Enter a number :" << endl;
    cin >> n;
    cout << "The roman literal: " << int2roman(n) << endl;

}

string int2roman(int n){
    if (n < 1 || n > 3999)
        return "Invalid Roman Number Value";
    string s = "";
    while (n >= 1000) { s += "M"; n -= 1000; }
    while (n >= 900) { s += "CM"; n -= 900; }
    while (n >= 500) { s += "D"; n -= 500; }
    while (n >= 400) { s += "CD"; n -= 400; }
    while (n >= 100) { s += "C"; n -= 100; }
    while (n >= 90) { s += "XC"; n -= 90;}
    while (n >= 50) { s += "L"; n -= 50; }
    while (n >= 40) { s += "XL"; n -= 40;}
    while (n >= 10) {s += "X"; n -= 10;}
    while (n >= 9) {s += "IX"; n -= 9;}
    while (n >= 5) {s += "V"; n -= 5;}
    while (n >= 4) { s += "IV";n -= 4; }
    while (n >= 1) { s += "I"; n -= 1; }

    return s;
}

int roman2int(string s){
    int num = 0;

    for(int i = 0;i < s.length();i++){
        int s1 = value(s[i]);
        if(i+1 < s.length()){
            int s2 = value(s[i+1]);
            if(s1 >= s2){
                num += s1;
            }else{
                num = num + s2 - s1;
                i++;
            }
        }else{
            num += s1;
            i++;
        }
    }

    return num;
}

int value(char c)
{
    if (c == 'I')  return 1;
    if (c == 'V')  return 5;
    if (c == 'X')  return 10;
    if (c == 'L')  return 50;
    if (c == 'C')  return 100;
    if (c == 'D')  return 500;
    if (c == 'M')  return 1000;

    return -1;
}
