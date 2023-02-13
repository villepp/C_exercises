#include <stdio.h>

int main(void) {
    printf("Enter 10 numbers\n");

    int given_number;
    int array[10];
    int i;
    int sum = 0;

    for (i = 0; i < 10; i++) {
        printf("%d.\t", i+1);
        scanf("%d", &given_number);
        array[i] = given_number;
        sum += given_number;
    }
	
    printf("\nThe mean value of numbers [ ");
	
    for (i = 0; i < 9; i++) {
        printf("%d,", array[i]);
    }
	
    float mean = (float)sum/10;
    int last_int = array[10 -1]; //we know that we are asking for 10 numbers, 10 represents size of array.
    printf("%d ] is %.1f", last_int, mean);
	
    return 0;
}