#include <stdio.h>

int main(void)
{
    char grade;
    printf("Give grade ");
    scanf("%c", &grade);

    switch (grade)
    {
    case 'E':
        printf("Excellent");
        break;
    case 'V':
        printf("Very Good");
        break;
    case 'G':
        printf("Good");
        break;
    case 'A':
        printf("Average");
        break;
    case 'F':
        printf("Fail");
        break;
    default:
        printf("Character is not a grade mark");
        break;
    }

    return 0;
}