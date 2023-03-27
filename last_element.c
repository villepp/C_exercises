#include <stdio.h>

int main(void)
{
    int array[] = {4, 5, 6, 7, 8};

    int size = sizeof(array) / sizeof(array[0]);

    if (size > 0)
    {
        int lastElement = array[size - 1];
        printf("Last element of array : %d \n", lastElement);
    }
    else
    {
        printf("Array is empty \n");
    }

    return 0;
}