#include <stdio.h>

int days_in_month(int month);

int main(void)
{
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("Give month: ");
    int month;
    scanf("%d", &month);

    int days = days_in_month(month);

    printf("There are %d days in %s", days, months[month - 1]);
}

int days_in_month(int month)
{
    int days_array[] = {28, 29, 30, 31};
    
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return days_array[3];
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return days_array[2];
        break;
    case 2:
        return days_array[0];
        break;
    default:
        break;
    }
}