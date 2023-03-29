#include <stdio.h>
void insert_element(int *array, int size, int number_to_be_inserted, int position);

int main(void)
{
    int a[11] = {4, 6, 2, 8, 5, 9, 4, 0, 3};
    insert_element(a, 9, 1, 9);
    for (int i = 0; i < 10; i++)
        printf("%d ", a[i]);

    return 0;
}

void insert_element(int *array, int size, int number_to_be_inserted, int position)
{
    for (int i = size; i > position; i--)
    {
        array[i] = array[i - 1];
    }
    array[position] = number_to_be_inserted;
}