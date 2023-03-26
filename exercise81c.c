#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int guess_the_number(int number_to_be_guessed, int* tries_used);
int main()
{
    srand(time(NULL));
    int guessed_num = rand() % 100 + 1;
    int tries_used;
    int result = guess_the_number(guessed_num, &tries_used);
    if (result == 1)
    {
        printf("You won! It took you %d tries.", tries_used);
    }
    else
    {
        printf("You lost! The number was %d.", guessed_num);
    }
    return 0;
}

int guess_the_number(int guessed_num, int *tries_used) {
    int user_num;
    for(int i = 1; i<=5; i++) {
        printf("Guess the number between 1 - 100 : ");
        scanf("%d",&user_num);
        if(user_num==guessed_num){
            *tries_used = i;    //fix?
            return 1;
        } else if (i==5) {
            //*tries_used = i;    //fix?
            return 0;
        } else if (user_num<guessed_num) {
            printf("The number is bigger than you guessed\n");
        } else {
            printf("The number is lower than you guessed\n");
        }
    }
    return 0;
}