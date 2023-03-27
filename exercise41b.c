#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_RAND 10
#define MAX_RAND 30
#define ARRAY_SIZE 20

int main(void)
{
    int i, first_array[ARRAY_SIZE], second_array[ARRAY_SIZE];
    int random_number;
    srand(time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++)
    {
        random_number = rand() % (MAX_RAND + 1) + MIN_RAND;
        first_array[i] = random_number;
    }

    int j = 0;
    for (i = (ARRAY_SIZE - 1); i >= 0; i--)
    {
        second_array[j] = first_array[i];
        j++;
    }

    printf("Array of random numbers is:     ");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", first_array[i]);
    }

    printf("\nSame array in reverse order is: ");
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", second_array[i]);
    }

    return 0;
}
