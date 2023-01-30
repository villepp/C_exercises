#include <stdio.h>

int main(void)
{
    printf("Give number (bigger that 8 ):");
    int user_number, result;
    scanf("%d", &user_number);

        for (int i = 0; i <= user_number; i++)
        {
            if (i%2==0 && i>6) {
            result += i;
            }
        }
        printf("sum=%d", result);
    }