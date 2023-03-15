#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Initialize the string
char string[100] = "Hello world !!";

//Prints a cool logo at the start of the program.
void print_logo(){
    printf("\n      ::::::::                ::::::::  :::    ::: ::::::::::: :::::::::: :::          :::   :::    :::::::: ::::::::::: ::::    ::: ::::::::::: ::::::::::: \n    :+:    :+:              :+:    :+: :+:    :+:     :+:     :+:        :+:         :+:+: :+:+:  :+:    :+:    :+:     :+:+:   :+:     :+:         :+:      \n   +:+                     +:+    +:+ +:+    +:+     +:+     +:+        +:+        +:+ +:+:+ +:+ +:+    +:+    +:+     :+:+:+  +:+     +:+         +:+       \n  +#+       +#++:++#++:++ +#+    +:+ +#++:++#++     +#+     +#++:++#   +#+        +#+  +:+  +#+ +#+    +:+    +#+     +#+ +:+ +#+     +#+         +#+        \n +#+                     +#+    +#+ +#+    +#+     +#+     +#+        +#+        +#+       +#+ +#+    +#+    +#+     +#+  +#+#+#     +#+         +#+         \n#+#    #+#              #+#    #+# #+#    #+# #+# #+#     #+#        #+#        #+#       #+# #+#    #+#    #+#     #+#   #+#+#     #+#         #+#          \n########                ########  ###    ###  #####      ########## ########## ###       ###  ######## ########### ###    ####     ###     ###########       \n\n");
}

//Displays a menu of commands for the user. The commands are used in main() and ask_command().
void display_menu(void){
    printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nF) Enter another string\nG) Read string from file\nH) Write string to file\n\nM) Display this menu\nX) Exit the program");
}


//Prompts for a command character (characters mentioned in display_menu()). Returns the character to main, then character is used in switch statement. If character isn't a command, the function simply runs again.
char ask_command(void){
    char user_character[3]; //Three character due to newline and string ending characters.
    printf("\nGive command: \n");
    fgets(user_character, 3, stdin);
    user_character[0] = toupper(user_character[0]);
    if((user_character[0] >= 'A' && user_character[0] <= 'H') || (user_character[0] == 'M'||'X' )){
        return user_character[0];
    }
}

//Prints the current string.
void print_string(char string[]) {
    printf("%s",string);
}

//Prompts for a new string from the user. Then finds the trailing newline character and sets its value to 0, removing it. Finally prints the new string.
void read_string(char string[]) {
    printf("Give string:");
    fgets(string, 100, stdin);
    string[strcspn(string, "\n")] = 0;
    printf("%s",string);
}


//Counts the vowels in the string using a while-loop.
int count_vowels(char string[]){
    int i = 0;
    int vowels = 0;
    while(string[i]!='\0'){
        if(string[i] == 'A'|| string[i] == 'E'|| string[i] == 'I'|| string[i] == 'O'|| string[i] == 'U'|| string[i] == 'Y' || string[i] == 'a'|| string[i] == 'e'|| string[i] == 'i'|| string[i] == 'o'|| string[i] == 'u'|| string[i] == 'y'){
            vowels++;
        }
            i++;
    }
    return vowels;
}

//Counts the consonants in the string using a while-loop.
int count_consonants(char string[]){
    int i = 0;
    int consonants = 0;
    while(string[i]!='\0'){
        if(string[i] == 'B'|| string[i] == 'C'|| string[i] == 'D'|| string[i] == 'F'|| string[i] == 'G'|| string[i] == 'H' || string[i] == 'J'|| string[i] == 'K'|| string[i] == 'L'|| string[i] == 'M'|| string[i] == 'N'|| string[i] == 'P' || string[i] == 'Q'|| string[i] == 'R'|| string[i] == 'S'|| string[i] == 'T'|| string[i] == 'V'|| string[i] == 'W' || string[i] == 'X'|| string[i] == 'Z'|| string[i] == 'b'|| string[i] == 'c'|| string[i] == 'd'|| string[i] == 'f'|| string[i] == 'g'|| string[i] == 'h' || string[i] == 'j'|| string[i] == 'k'|| string[i] == 'l'|| string[i] == 'm'|| string[i] == 'n'|| string[i] == 'p' || string[i] == 'q'|| string[i] == 'r'|| string[i] == 's'|| string[i] == 't'|| string[i] == 'v'|| string[i] == 'w' || string[i] == 'x'|| string[i] == 'z'){
            consonants++;
        }
            i++;
    }
    return consonants;
}

//Changes every character in the string to uppercase using a while-loop and toupper() C library function.
void to_upper(char string[]){
    int i = 0;
    while(string[i]!='\0'){
        string[i] = toupper(string[i]);
        i++;
    }
    printf("%s",string);
}

//Changes every character in the string to lowercase using a while-loop and tolower() C library function.
void to_lower(char string[]){
    int i = 0;
    while(string[i]!='\0'){
        string[i] = tolower(string[i]);
        i++;
    }
    printf("%s",string);
}

//Reads text from textfile.txt. The string is changed to whatever text the file contains.
void read_file(char string[]){
    FILE *file_pointer; 
    
    file_pointer = fopen("textfile.txt", "r");

    if (file_pointer == NULL){
        printf("textfile.txt file failed to open.");
    }
    else {
       while(fgets (string, 100, file_pointer) != NULL)
        {
            printf("%s",string);
        }
         fclose(file_pointer);
    }

}

//Writes the current string to textfile.txt, replacing whatever is inside it.
void write_file(char string[]) {
    FILE *file_pointer;

    file_pointer = fopen("textfile.txt", "w");

    if (file_pointer == NULL)
    {
        printf("textfile.txt file failed to open.");
    }
    else{
        if (strlen(string) > 0)
        {
            fputs(string, file_pointer);
            fputs("\n", file_pointer);
        }
        fclose(file_pointer);
    }
}

//First displays the logo and menu using their functions. Then initializes a command character, its value is set through ask_command() by the user. Switch - case check what the character is and go to the appropriate function.
int main(void){
    
    print_logo();
    display_menu();

    char command;
    while(command!='X'){ //if command is X, the program stops.
        command = ask_command();
        switch (command)
            {
            case 'A':
                printf("%d",count_vowels(string));
                break;
            case 'B':
                printf("%d",count_consonants(string));
                break;
            case 'C':
                to_upper(string);
                break;
            case 'D':
                to_lower(string);
                break;
            case 'E':
                print_string(string);
                break;
            case 'F':
                read_string(string);
                break;
            case 'G':
                read_file(string);
                break;
            case 'H':
                write_file(string);
                break;
            case 'M':
                display_menu();
                break;
            default:
                break;
            }
        }
    return 0;
}