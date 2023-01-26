#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RAND 120
#define MIN_RAND -50

int main(void)
{
    int random_number;
    int even_temp, odd_temp = 0;
    int original_array[15]={0};
    int even_array[15]={0};
    int odd_array[15]={0};
    srand(time(NULL));

    for (int i = 0; i<15; i++) {
        random_number=rand() %(MAX_RAND - MIN_RAND + 1) + MIN_RAND; //Better solution for random num... 
        original_array[i] = random_number;
    }

    for (int i = 0; i<15; i++) {
        if (original_array[i]%2==0) {
            even_array[even_temp] = original_array[i];
            even_temp++;
        } else {
            odd_array[odd_temp] = original_array[i];
            odd_temp++;
        }
    }

    printf("All numbers are:\n");
    for (int i = 0; i < 15; i++) {
        printf("%d ", original_array[i]);
    }

    //int odd_size = sizeof(odd_array) / sizeof(odd_array[0]);
    printf("\nOdd numbers are:\n");
    for (int i = 0; i < odd_temp; i++) {
            printf("%d ", odd_array[i]);
    }

    //int even_size = sizeof(even_array) / sizeof(even_array[0]);
    printf("\nEven numbers are:\n");
    for (int i = 0; i < even_temp; i++) {
            printf("%d ", even_array[i]);
    }

/*
Don't need this previous solution anymore =D
    for (int i = 0; i < 15; i++) {
        if (original_array[i] == 0) {
            printf("%d ", original_array[i]);
        }
    }
*/
    return 0;
}