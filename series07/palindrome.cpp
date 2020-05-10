#include <iostream>
#include <string.h>

using namespace std;

bool isPalindrome(string);

int main(){
    string word;
    cout << "Enter a string to check: " << endl;
    getline(cin, word);

    if(isPalindrome(word))
        cout << "The string is palindrome." << endl;
    else
        cout << "The string is NOT a palindrome." << endl;
}

bool isPalindrome(string word){
    bool status = true;
    int start = 0;
    int len = word.length() - 1;
    while(len >= 1){
        if(word[start] != word[len])
            status = false;
        start++;
        len--;
    }

    return status;
}
