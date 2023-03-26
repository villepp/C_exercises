#include <stdio.h>

int main(void)
{
    int temperature = 0;

    printf("Give temperature");
    scanf("%d", &temperature);

    if (temperature < 0)
    {
        printf("Freezing weather");
    }
    else if (temperature <= 10)
    {
        printf("Very Cold Weather");
    }
    else if (temperature <= 20)
    {
        printf("Cold weather");
    }
    else if (temperature <= 30)
    {
        printf("Normal in Temp");
    }
    else if (temperature <= 40)
    {
        printf("Its Hot");
    }
    else if (temperature > 40)
    {
        printf("Its Very Hot");
    }
    else
    {
        return 0;
    }

    return 0;
}