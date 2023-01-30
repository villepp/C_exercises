#include <stdio.h>

int main(void)
{
    printf("Give grade ");
    char grade;
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
}