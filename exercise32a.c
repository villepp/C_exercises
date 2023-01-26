<<<<<<< HEAD
#include <stdio.h>

int main(void)
{
    printf("Give me number: ");
    int given_number;
    scanf("%d", &given_number);

    printf("\nThe multiplication table for %d is: \n", given_number);

    for(int i=0 ; i<=10 ; i++)
    {
        int result = i*given_number;
        printf("%d * %d = %d\n",i, given_number, result);
    }
    return 0;
=======
#include <stdio.h>

int main(void)
{
    printf("Give me number: ");
    int given_number;
    scanf("%d", &given_number);

    printf("\nThe multiplication table for %d is: \n", given_number);

    for(int i=0 ; i<=10 ; i++)
    {
        int result = i*given_number;
        printf("%d * %d = %d\n",i, given_number, result);
    }
    return 0;
>>>>>>> 30c1dce2d89cd49c9d6c9d8d5b29eb894d1a016a
}