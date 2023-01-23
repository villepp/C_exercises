#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RAND 170
#define MIN_RAND -50

int main(void)
{
    int random_number;
    int original_array[15]={0};
    int even_array[15]={0};
    int odd_array[15]={0};
    srand(time(NULL));

    for (int i = 0; i<1000; i++) {
        random_number=rand() %(MAX_RAND+1) MIN_RAND;
        printf("%d\n",random_number);
    }
    return 0;
}