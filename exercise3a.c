#include <stdio.h>

int main(void)
{
    printf("Give number 1: ");
    int first_number;
    scanf("%d", &first_number);

    printf("Give number 2: ");
    int second_number;
    scanf("%d", &second_number);

    if (first_number > second_number)
        printf("User did input numbers %d and %d and the bigger one is %d", first_number, second_number, first_number);
    else
        printf("User did input numbers %d and %d and the bigger one is %d", first_number, second_number, second_number);

    return 0;
}
