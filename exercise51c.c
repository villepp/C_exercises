#include <stdio.h>

void print_average(int a, int b);

int main(void)
{
    printf("Give number 1: ");
    int a;
    scanf("%d", &a);

    printf("Give number 2: ");
    int b;
    scanf("%d", &b);

    printf("\n");
    print_average(a, b);
    
    return 0;
}

void print_average(int a, int b)
{
    printf("User entered numbers %d and %d.\n", a, b);
    float average = (float)(a + b) / 2;
    if (a > b)
    {
        printf("Bigger number is %d average is %.1f", a, average);
    }
    else
    {
        printf("Bigger number is %d average is %.1f", b, average);
    }
}