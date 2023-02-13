#include <stdio.h>
#include <string.h>

int count_char(char str[], char c);

int main(void){
    printf("Give a string: ");
    char str[50];
    fgets(str,50,stdin);
    printf("Give character to be searched: ");
    char c;
    scanf("%c",&c);

    printf("\nIn string, there is %d of selected characters",count_char(str, c));
}

int count_char(char str[], char c) {
    int counter = 0;
    int string_length = strlen(str);
    for (int i = 0; i < string_length; i++)
    {
        if (str[i] == c) {
            counter++;
        }
    }
    return counter;
}