#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX_LENGTH 100

int checkOccurrence(char*, char);

int main(){

    char* s = (char*) malloc(MAX_LENGTH*sizeof(char));
    char b;
    printf("Enter a string: ");
    scanf("%s", s);

    printf("Enter the character you want to search: ");
    scanf(" %c ", &b);

    printf("It occurs %d times", checkOccurrence(s, b));
}

int checkOccurrence(char* string, char character){
    int count = 0;
    int i = 0;

    while(string[i] != '\0'){
        if(tolower(string[i])== tolower(character)){
            count++;
        }
        i++;
    }
    return count;
}
