#include <stdio.h>
#define MAX_V 100
#define MIN_V 0
#define MAX_R 65
#define MIN_R 1

int ask_integer_number(int min, int max);

int main(void)
{
    printf("Give Voltage between 0 and 100: ");
    int voltage = ask_integer_number(MIN_V,MAX_V);
    printf("Give Resistance between 1 and 65: ");
    int resistance = ask_integer_number(MIN_R,MAX_R);
    float current = (float)voltage/resistance;
    int power_consumption = voltage*current;
    printf("\nPower consumption in %d ohm resistance with %d V voltage is %d W and current is %.1f A",resistance,voltage,power_consumption,current);
}

int ask_integer_number(int min, int max) {
    int user_number;
    while (1)
    {
        scanf("%d", &user_number);
        if(user_number>=min && user_number<=max) {
            return user_number;
            break;
        } else {
            printf("Number was not in range (%d-%d): ",min,max);
        }
    }
}