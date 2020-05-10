#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

string dec2bin(int);
int bin2dec(string);

int main(){
    string bin;
    int n;
    cout << "Enter a binary representation: " << endl;
    getline(cin, bin);
    cout << "The decimal representation is : " << bin2dec(bin) << endl;
    cout << "Enter a decimal number: " << endl;
    cin >> n;
    cout << "The binary representation is : " << dec2bin(n) << endl;
}

string dec2bin(int n){
    string binary = "";
    int remainder;

    while(n != 0){
        remainder = n%2;
        binary = std::to_string(remainder) + binary;
        n = n / 2;
    }

    return binary;
}

int bin2dec(string s){
    int decimal = 0;
    int len = s.length();

    for(int i = 0;i < s.length(); i++){
        if(s[i] == '1')
            decimal += pow(2.0, (len-1));
        len -= 1;
    }

    return decimal;
}
