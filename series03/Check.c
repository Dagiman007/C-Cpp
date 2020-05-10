#include <stdio.h>

int check(int[], int[]);

int main(){
    int sequence[10], y[3];

    printf("Enter the sequence: \n");
    for(int i = 0;i < 10; i++)
        scanf("%d", &sequence[i]);

    printf("Enter the sequence you want to look up (size 3): \n");
    for(int j = 0; j < 3; j++)
        scanf("%d", &y[j]);

    switch(check(sequence, y)){
        case 1:
            printf("The combination is in the list.");
            break;
        case -1:
            printf("The combination is not in the list.");
            break;
    }
}


int check(int x[10], int y[3]){
    int count = 0;
    int firstIndex = 0;
    for(int j = 0; j < 3; j++){
        for(int i = firstIndex; i < 10; i++){
            if(x[i] == y[j]){
                count += 1;
                firstIndex = i;
            }
        }
    }
    if(count == 3)
        return (1);
    else
        return -1;
}
