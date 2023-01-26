#include <stdio.h>

int main(void) {
    char user_string[50];
    printf("Give string: ");
    fgets(user_string,30,stdin);

    printf("%s", user_string);
}