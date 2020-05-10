#include <stdio.h>

int main(){

    unsigned int numberOfFriends;
    float prizeMoney;
    float fairShare;

    /* get the prize money and validate if it's positive */
    do{
        printf("Enter the money you won (has to be positive): ");
        scanf("%f", &prizeMoney);
    }while(prizeMoney < 0);

    /* prompt the user to enter the number of friends he has */
    printf("Enter your number of friends: ");
    scanf("%d", &numberOfFriends);

    /* compute the fair amount each will get including the user */
    fairShare = prizeMoney / ((float)(numberOfFriends + 1));

    /* display result */
    printf("Each of you will get %f", fairShare);

    return 0;
}
