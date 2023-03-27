#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_RAND 50
#define MIN_RAND -50
#define RANDOM_AMOUNT 30

void sort_array(int array[], int size);

int main(void)
{
    int random_number = 0;
    int size = 0;
    int array[RANDOM_AMOUNT];

    srand(time(NULL));

    for (int i = 0; i < RANDOM_AMOUNT; i++)
    {
        random_number = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
        array[i] = random_number;
        size++;
    }

    printf("original array is:  ");
    for (int i = 0; i < RANDOM_AMOUNT - 1; i++)
    {
        printf("%d,", array[i]);
    }

    printf("%d", array[30]);
    printf("\n");

    sort_array(array, size);

    printf("Sorted array is:   ");
    for (int i = 0; i < RANDOM_AMOUNT; i++)
    {
        printf("%d,", array[i]);
    }

    return 0;
}

void sort_array(int array[], int size)
{
    int temp = 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}