#include <stdio.h>
// #include <string.h>

int main(void)
{
    char user_string[50];
    printf("Give string: ");
    fgets(user_string, 30, stdin);

    /*
    printf("%s", user_string);
    int string_length = strlen(user_string);

    printf("The length of the string is: %d\n", string_length-1); //minus 1 because of new line character
    */

    char copied_string[50];
    int i = 0;
    while (user_string[i] != '\0')
    {
        copied_string[i] = ("%c", user_string[i]);
        i++;
    }

    /*
        int length;
        for (int i = 0; i < string_length; i++)
        {
            copied_string[i] = user_string[i];
            length++;
        }
        */
    printf("The length of the string is: %d\n", i - 1); // minus 1 because of new line character

    // strcpy(copied_string,user_string);

    printf("The copied string is: %s", copied_string);
}