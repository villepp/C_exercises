#include <stdio.h>

int main(void)
{
    int array[10]={15, 73, 43, -28, 65, 186, -37, 28, 13, 88};
    printf("Content of array is: \n");

    for(int i=0 ; i<10; i++)
    {
        printf("%d   %3d\n",i, array[i]);
    }
    return 0;
}