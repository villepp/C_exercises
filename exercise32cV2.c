#include <stdio.h>

int main(void)
{
    int given_number;
    int array[10];
    int i;
    int sum = 0;

    printf("Enter 10 numbers\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d.\t", i + 1);
        scanf("%d", &given_number);
        array[i] = given_number;
        sum += given_number;
    }

    printf("\nThe mean value of numbers [ ");

    for (i = 0; i < 9; i++)
    {
        printf("%d,", array[i]);
    }

    float mean = (float)sum / 10;
    int last_int = array[10 - 1]; // we are asking for 10 numbers, 10 represents size of array, index of last is 9.
    printf("%d ] is %.1f", last_int, mean);

    return 0;
}