#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_RAND 20
#define MIN_RAND -20

int suffle_number()
{
    int random_number = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
    return random_number;
}

int main(void)
{
    int random_value;
    srand(time(NULL));
    random_value = suffle_number();
    printf("The returned random value is %d", random_value);

    return 0;
}