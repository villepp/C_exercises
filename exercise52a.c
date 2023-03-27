#include <stdio.h>
#define MAX 70
#define MIN 20

int ask_integer_number(int min, int max);

int main(void)
{
    printf("Give number between 20 and 70: ");
    int result = ask_integer_number(MIN, MAX);
    printf("\nUser given number was %d", result);

    return 0;
}

int ask_integer_number(int min, int max)
{
    int user_number;
    while (1) // While (1) isn't good, fix maybe
    {
        scanf("%d", &user_number);
        if (user_number >= min && user_number <= max)
        {
            return user_number;
            break;
        }
        else
        {
            printf("Number was not in range (%d-%d): ", min, max);
        }
    }
}