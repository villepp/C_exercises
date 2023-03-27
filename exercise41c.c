#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RAND 10
#define MIN_RAND 0
#define RANDOM_AMOUNT 1000

int main(void)
{
    int random_number;
    int array[MAX_RAND + 1] = {0};
    srand(time(NULL));

    for (int i = 1; i <= RANDOM_AMOUNT; ++i)
    {
        random_number = rand() % (MAX_RAND + 1) - MIN_RAND;
        array[random_number]++;
        // printf("%d\n",random_number);
    }
    for (int i = 0; i <= MAX_RAND; ++i)
    {
        printf(" number %2d occurred %3d times\n", i, array[i]);
    }
    
    return 0;
}