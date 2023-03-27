#include <stdio.h>

int main(void)
{
    printf("Give me a letter: ");
    char user_letter;
    scanf("%c", &user_letter);

    if (user_letter >= 65 && user_letter <= 90)
    {
        printf("Letter %c is a Capital letter", user_letter);
    }
    else if (user_letter >= 97 && user_letter <= 122)
    {
        printf("Letter %c is a small letter", user_letter);
    }
    else if (user_letter >= '0' && user_letter <= '9')
    {
        printf("Letter %c is a number", user_letter);
    }
    else
    {
        printf("Letter %c is a special character", user_letter);
    }

    return 0;
}