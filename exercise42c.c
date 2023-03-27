#include <stdio.h>
#include <string.h>

int main(void)
{
    char user_string[100];
    printf("Give string: ");
    fgets(user_string, 100, stdin);

    // printf("%s", user_string);
    int string_length = strlen(user_string);

    printf("The length of the string is: %d\n", string_length - 1); // minus 1 because of string ending character

    char copied_string[50];

    /*
        for (int i = 0; i < string_length; i++)
        {
            copied_string[i] = user_string[i];
        }
    */

    strcpy(copied_string, user_string);

    printf("The copied string is: %s", copied_string);
}