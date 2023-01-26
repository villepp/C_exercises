#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int array[39]={0};
    int random_number;
    srand(time(NULL));


   for (int i = 0; i<7; i++) {
        random_number = rand() % 39;
        while(1)
            {
                if (array[random_number] == 1) {
                    random_number = rand() % 39;
            } else break;
            }
        array[random_number]++;
    }

//TODO: laita vielä printit oikein

for (int i = 0; i<39; i++) {
    printf("%d ", array[i]);
}


int num = 0;
    printf("\nUser played numbers: ");
    for (int i = 0; i<=39; i++) {
        if (array[i]==1) {
            printf("%d: %d \n",num, i);
            num++;
        }
    }
}