#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RAND 109
#define MIN_RAND 0

int main(void)
{
    int drawn_numbers[110] = {0};
    int random_number;
    srand(time(NULL));

    for (int i = 0; i < 30; i++)
    {
        random_number = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
        while (1)
        {
            if (drawn_numbers[random_number] == 0)
            {
                drawn_numbers[random_number]++;
                break;
            }
            else
                random_number = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
        }
    }

    printf("\nContent of array is [ ");
    for (int i = 0; i < 110; i++)
    {
        if (drawn_numbers[i] == 1)
        {
            printf("%.1f, ", (float)i / 10 - 1);
        }
    }
    printf("\b\b ]");
}