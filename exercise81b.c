#include <stdio.h>

int main(void){
    int x, y, sum, difference, product, quotient;
    int *ptr1, *ptr2, *ptr3, *ptr4;

    printf("Give first value : ");
    scanf("%d",&x);
    printf("Give second value : ");
    scanf("%d",&y);

    ptr1 = &x;
    ptr2 = &y;

    sum = *ptr1 + *ptr2;
    difference = *ptr1 - *ptr2;
    product = *ptr1 * *ptr2;
    quotient = *ptr1 / *ptr2;

    ptr3 = &sum;
    ptr4 = &difference;

    printf("Sum of values using pointers : %d\n",*ptr3);
    printf("Difference of values using pointers : %d\n",*ptr4);

    ptr3 = &product;
    ptr4 = &quotient;

    printf("Product of values using pointers : %d\n",*ptr3);
    printf("Quotient of values using pointers : %d",*ptr4);
    
    return 0;
}