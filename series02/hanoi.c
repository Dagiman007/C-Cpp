#include <stdio.h>

void hanoi(int, char, char, char);

int main(){
    int numberOfDisks;

    printf("Please enter the number of disks: ");
    scanf("%d", &numberOfDisks);
    printf("Follow these moves: ");
    printf("\n");
    hanoi(numberOfDisks, 'A', 'B', 'C');
}

void hanoi(int numberOfDisks, char fromTower, char toTower, char auxTower){
    if(numberOfDisks == 1){
        printf("Move disk %d", numberOfDisks);
        printf(" from %c", fromTower);
        printf(" to %c", toTower);
        printf("\n");
    }else{
        hanoi(numberOfDisks - 1, fromTower, auxTower, toTower);
        printf("Move disk %d", numberOfDisks);
        printf(" from %c", fromTower);
        printf(" to %c", toTower);
        printf("\n");
        hanoi(numberOfDisks - 1, auxTower, toTower, fromTower);
    }
}
