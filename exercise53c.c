#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_RAND 50
#define MIN_RAND -50
#define RANDOM_AMOUNT 30

void sort_array(int array[], int size);

int main(void){
    int random_number = 0;
    int size = 0;
    int array[RANDOM_AMOUNT] = {0};

    srand(time(NULL));

    for (int i = 0; i<RANDOM_AMOUNT; i++) {
    random_number=rand() %(MAX_RAND - MIN_RAND + 1) + MIN_RAND;
    array[i] = random_number;
    size++;
    }

    for (int i = 0; i < RANDOM_AMOUNT; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    sort_array(array,size);
    
    for (int i = 0; i < RANDOM_AMOUNT+1; i++)
    {
        if (array[i] >= MIN_RAND && array[i] <= MAX_RAND){
        printf("%d ", array[i]);
        } else {
            continue;
        }
    }
    
    
}

void sort_array(int array[], int size) {
    int temp = 0;
    for (int i = 0; i < size-1; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (array[i]>array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}