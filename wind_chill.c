#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("Give temperature in Celsius: ");
    float temperature_celsius;
    scanf("%f", &temperature_celsius);

    printf("Give Wind speed in m/s");
    float wind_speed_ms;
    scanf("%f", &wind_speed_ms);

    float temperature_fahrenheit = (temperature_celsius * 1.8) + 32;
    float wind_speed_mph = wind_speed_ms * 2.2369362920544;

    // printf("\n%.1f", temperature_fahrenheit);
    // printf("\n%.1f", wind_speed_mph);

    float wind_chill_fahrenheit = 35.74 + 0.6215 * temperature_fahrenheit - 35.75 * pow(wind_speed_mph, 0.16) + 0.4275 * temperature_fahrenheit * pow(wind_speed_mph, 0.16);
    float wind_chill_celsius = (wind_chill_fahrenheit - 32) * 5 / 9;

    printf("Feels like: %.2f C", wind_chill_celsius);

    return 0;
}