#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RAND 100
#define MIN_RAND 1
#define RANDOM_AMOUNT 20

int main(void)
{
    int random_number, temp_random;
    int smallest_number = MAX_RAND; //at first the minimum number is set to max, so afterwards it is sure to lower down to a smaller number... and vice versa
    int biggest_number = MIN_RAND;
    int array[RANDOM_AMOUNT]={0};
    srand(time(NULL));

    for (int i = 0; i<RANDOM_AMOUNT; i++) {
    random_number=rand() %(MAX_RAND - MIN_RAND + 1) + MIN_RAND;
    array[i] = random_number;

    if(random_number<smallest_number) {
        smallest_number=random_number;
    }
    else if(random_number>biggest_number){
        biggest_number=random_number;
    }
}

    printf("Content of array is [ ");
    for (int i = 0; i<RANDOM_AMOUNT; i++) {
        printf("%d ", array[i]);
    }
    printf("]\n and the biggest number was %d and smallest was %d\n\n   ", biggest_number, smallest_number);

    for (int i = 0; i<=biggest_number; i++) { //should this print the last number, 10, or not?
        if(i%10 == 0) {
                printf("%d", i/10);
            }
        else{
            (printf(" "));
            }
    }

    printf("\n   ");
    for (int i = 0; i<=biggest_number; i++) {
        printf("%d",i%10);
    }

    printf("\n   ");
    for (int i = 0; i<=biggest_number; i++) {
        printf("-");
    }

    printf(">\n");
    for (int i = 0; i<RANDOM_AMOUNT; i++) {
        printf("%2d: ",i);
        for (int j = 0; j<array[i]; j++) {
            printf("*");
        }
        for (int k = array[i]; k<=biggest_number; k++) {
            if(k<biggest_number){
                printf(" ");
            }
        }
        printf(" ( %2d)\n",array[i]);
    }
    return 0;
}