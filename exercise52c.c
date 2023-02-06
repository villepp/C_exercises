#include <stdio.h>

int leap_year(void);

int main(void){
    printf("Give year: ");
    leap_year();
}

int leap_year(void) {
    int year;
    scanf("%d",&year);
    if(year%4 == 0 && (year%100 != 0 || year%400 == 0)) {
            printf("Year is a leap year");
        } else {
            printf("Year is NOT a leap year");
            }
}



/*
original

    if(year%4 == 0) {
        if(year%100!=0 || year%400==0) {
            printf("Year is a leap year");
        } else {
            printf("Year is NOT a leap year");
        }
    } else {
            printf("Year is NOT a leap year");
        }
*/