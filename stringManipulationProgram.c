#include <stdio.h>
#include <ctype.h>


int count_vowels(char manipulated_string[]){
    int i = 0;
    int vowels = 0;
    while(manipulated_string[i]!='\0'){
    toupper(manipulated_string[i]);
        if(manipulated_string[i] == 'A'||manipulated_string[i] == 'E'||manipulated_string[i] == 'I'||manipulated_string[i] == 'O'||manipulated_string[i] == 'U'||manipulated_string[i] == 'Y'){
            vowels++;
        }
            i++;
    }
    return vowels;
    printf("test");
}

void display_menu(void){
    printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nF) Enter another string\nG) Read string from file\nH) Write string to file\n\nM) Display this menu\nX) Exit the program");
}

char ask_command(void){
    char user_character[1];
    printf("\nGive command: \n");
    fgets(user_character,2,stdin);
    user_character[0] = toupper(user_character[0]);
    printf("%s",user_character);
            if((user_character[0] >= 'A' && user_character[0] <= 'H') || (user_character[0] == 'M'||'X')  ){
            return user_character[0];
        }
}


int main(void){
    char manipulated_string[] = "Hello world !!";
    display_menu();
    char command_char = ask_command();
    if (command_char=='A') {
        int vowels = count_vowels(manipulated_string);
        printf("\n%d",vowels);
    } else if (command_char=='B'){

    }
}