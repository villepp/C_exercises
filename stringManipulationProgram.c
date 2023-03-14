#include <stdio.h>
#include <ctype.h>
#include <string.h>

char string[100] = "Hello world !!";
//int menu_displayed = 0;

void print_logo(){
    printf("");
}

void display_menu(void){
    printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nF) Enter another string\nG) Read string from file\nH) Write string to file\n\nM) Display this menu\nX) Exit the program");
}

char ask_command(void){
    char user_character[3];
    printf("\nGive command: \n");
    fgets(user_character, 3, stdin);
    user_character[0] = toupper(user_character[0]);
    if((user_character[0] >= 'A' && user_character[0] <= 'H') || (user_character[0] == 'M'||'X' )){
        //printf("%c\n", user_character[0]);
        return user_character[0];
    }
}

void print_string(char string[]) {
    printf("%s\n",string);
    string[strcspn(string, "\n")] = 0;
}

void read_string(char string[]) {
    printf("Give string:");
    fgets(string, 100, stdin);
    string[strcspn(string, "\n")] = 0;
    printf("%s\n",string);
}

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

int count_consonants(char string[]){
    int i = 0;
    int consonants = 0;
    //beautiful
    while(string[i]!='\0'){
        if(string[i] == 'B'|| string[i] == 'C'|| string[i] == 'D'|| string[i] == 'F'|| string[i] == 'G'|| string[i] == 'H' || string[i] == 'J'|| string[i] == 'K'|| string[i] == 'L'|| string[i] == 'M'|| string[i] == 'N'|| string[i] == 'P' || string[i] == 'Q'|| string[i] == 'R'|| string[i] == 'S'|| string[i] == 'T'|| string[i] == 'V'|| string[i] == 'W' || string[i] == 'X'|| string[i] == 'Z'|| string[i] == 'b'|| string[i] == 'c'|| string[i] == 'd'|| string[i] == 'f'|| string[i] == 'g'|| string[i] == 'h' || string[i] == 'j'|| string[i] == 'k'|| string[i] == 'l'|| string[i] == 'm'|| string[i] == 'n'|| string[i] == 'p' || string[i] == 'q'|| string[i] == 'r'|| string[i] == 's'|| string[i] == 't'|| string[i] == 'v'|| string[i] == 'w' || string[i] == 'x'|| string[i] == 'z'){
            consonants++;
        }
            i++;
    }
    return consonants;
}

void to_upper(char string[]){
    int i = 0;
    while(string[i]!='\0'){
        string[i] = toupper(string[i]);
        i++;
    }
    printf("%s",string);
}

void to_lower(char string[]){
    int i = 0;
    while(string[i]!='\0'){
        string[i] = tolower(string[i]);
        i++;
    }
    printf("%s",string);
}


//TODO
void read_file(char string[]){
    FILE *file_pointer; 
    int variable = 4;
    
    file_pointer = fopen("textfile.txt", "r");
    fscanf(file_pointer, "%d",&variable);  /* sting may be read also with fgets(), so spaces do not give us trouble*/
    fclose(file_pointer);

}


int main(void){
    
    print_logo();

    //if(menu_displayed == 0){
        display_menu();
       // menu_displayed = 1;
    //}

    char command;
    while(command!='X'){
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
            case 'M':
                display_menu();
                break;
            default:
                break;
            }
        }
}