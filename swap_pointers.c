#include <stdio.h>

int main(void)
{
    int a, b;
    printf("Give number 1: ");
    scanf("%d", &a);
    
    printf("Give number 2: ");
    scanf("%d", &b);

    printf("Before swap: a = %d, b = %d", a, b);

    int *ptr1, *ptr2;

    ptr1 = &a;
    ptr2 = &b;

    int temp;

    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;

    printf("\nAfter swap: a = %d, b = %d", a, b);

    return 0;
}