<<<<<<< HEAD
#include <stdio.h>

int main(void)
{
    printf("Give me a letter: ");
    char user_letter;
    scanf("%c",&user_letter);

    if (user_letter>=65 && user_letter<=90)
        printf("Letter %c is a Capital letter", user_letter);
    else
        printf("Letter %c is not a Capital letter",user_letter);

    return 0;
=======
#include <stdio.h>

int main(void)
{
    printf("Give me a letter: ");
    char user_letter;
    scanf("%c",&user_letter);

    if (user_letter>=65 && user_letter<=90)
        printf("Letter %c is a Capital letter", user_letter);
    else
        printf("Letter %c is not a Capital letter",user_letter);

    return 0;
>>>>>>> 30c1dce2d89cd49c9d6c9d8d5b29eb894d1a016a
}