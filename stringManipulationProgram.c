#include <stdio.h>
#include <ctype.h>




int count_vowels(char manipulated_string[]){
    int i = 0;
    int vowels = 0;
    while(manipulated_string[i]!='\0'){
        if(manipulated_string[i] == 'A'||'E'||'I'||'O'||'U'||'Y'){
            vowels++;
        }
    }
    return vowels;
}

void display_menu(void){
    printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nF) Enter another string\nG) Read string from file\nH) Write string to file\n\nM) Display this menu\nX) Exit the program");
    char ask_command();
}

char ask_command(void){
    char manipulated_string[] = "Hello world !!";
    char user_character[] = "";
    printf("Give command: ");
    fgets(user_character,1,stdin);
    user_character = toupper(user_character);

    if (user_character=="A") {
        int vowels = count_vowels(manipulated_string);
        printf("%d",vowels);
    } else if (user_character=="B"){

    }
}


int main(void){
    display_menu();
}