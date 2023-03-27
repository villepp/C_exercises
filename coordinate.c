#include <stdio.h>

int get_coordinates(int a, int b)
{
    if (a < 0 && b > 0)
    {
        printf("The coordinate point (%d,%d) lies in the first quadrant.", a, b);
    }
    else if (a > 0 && b > 0)
    {
        printf("The coordinate point (%d,%d) lies in the second quadrant.", a, b);
    }
    else if (a < 0 && b < 0)
    {
        printf("The coordinate point (%d,%d) lies in the third quadrant.", a, b);
    }
    else if (a > 0 && b < 0)
    {
        printf("The coordinate point (%d,%d) lies in the fourth quadrant.", a, b);
    }
    else
        printf("Incorrect input");
        
    return 0;
}

int main(void)
{
    int a;
    int b;

    printf("Give coordinate point in format (x,y): ");
    scanf("(%d,%d)", &a, &b);

    get_coordinates(a, b);
}