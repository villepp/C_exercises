#include <stdio.h>

int main(void){
    int first_value, second_value, sum = 0;

    printf("Give first value : ");
    scanf("%d",&first_value);
    printf("Give second value : ");
    scanf("%d",&second_value);

    int *pointer_first = &first_value;
    int *pointer_second = &second_value;

    sum = *pointer_first + *pointer_second;

    printf("Sum of values using pointers : %d",sum);
    return 0;
}