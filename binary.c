#include <stdio.h>

void binary(int a)
{
    if (a > 1)
    {
        binary(a / 2);
    }
    printf("%d", a % 2);
}

int main(void)
{
    int num = 4;
    printf("The binary representation of %d is: ", num);
    binary(num);
    printf("\n");

    return 0;
}