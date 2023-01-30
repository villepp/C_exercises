#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Input rows: ");
    int rows;
    int spaces_reduction = 2;
    scanf("%d", &rows);
    printf("\n");
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("%d", i);
        }
        for (int k = 0; k < (rows*2)-spaces_reduction; k++)
        {
            printf(" ");
        }
        for (int l = 0; l < i; l++)
        {
            printf("%d", i);
        }
        printf("\n");
        spaces_reduction = spaces_reduction + 2;
    }
}