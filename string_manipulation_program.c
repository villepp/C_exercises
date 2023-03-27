/***************************************************************************
 *   Copyright (C) 2023 by Ville Pitkänen   *
 *   e2300558@edu.vamk.fi   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/***************************************************************************
 *
 * 1.  NAME
 *     string_manipulation_program.c
 *
 * 2.  DESCRIPTION
 *     Manipulates a string of characters, that can be asked from the user.
 *     Program will display a menu of different actions, and the user may
 *     select what action the program will perform to this string.
 *
 * 3.  VERSIONS
 *       Original:
 *         23.3.2023 / Ville Pitkänen
 *
 *       Version history:
 *
 *
 ***************************************************************************/

/*-------------------------------------------------------------------*
 *    HEADER FILES                                                    *
 *--------------------------------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*-------------------------------------------------------------------*
 *    GLOBAL VARIABLES AND CONSTANTS                                  *
 *--------------------------------------------------------------------*/
/* Control flags */

/* Global constants */

/* Global variables */

/* Global structures */

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
void print_logo();
void display_menu(void);
char ask_command(void);
void print_string(char string[]);
void read_string(char string[]);
int count_vowels(char string[]);
int count_consonants(char string[]);
void to_upper(char string[]);
void to_lower(char string[]);
void read_file(char string[]);
void write_file(char string[]);

/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/

int main(void)
{
    char string[100] = "Hello world !!"; /* Initialize the string with a default value */

    print_logo();
    display_menu();

    char command;
    while (command != 'X')
    { /* If user given command is X, the program stops */
        command = ask_command();
        switch (command)
        {
        case 'A':
            printf("%d", count_vowels(string));
            break;
        case 'B':
            printf("%d", count_consonants(string));
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
} /* End of main */

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: void print_logo()
; DESCRIPTION: Prints a cool logo at the start of the program
;	Input: none
;	Output: none
;  Used global variables: none
; REMARKS when using this function:
;       Should only be used once (see description)
;*********************************************************************/

void print_logo()
{
    printf("\n      ::::::::                ::::::::  :::    ::: ::::::::::: :::::::::: :::          :::   :::    :::::::: ::::::::::: ::::    ::: ::::::::::: :::::::::::\n");
    printf("    :+:    :+:              :+:    :+: :+:    :+:     :+:     :+:        :+:         :+:+: :+:+:  :+:    :+:    :+:     :+:+:   :+:     :+:         :+:      \n");
    printf("   +:+                     +:+    +:+ +:+    +:+     +:+     +:+        +:+        +:+ +:+:+ +:+ +:+    +:+    +:+     :+:+:+  +:+     +:+         +:+       \n");
    printf("  +#+       +#++:++#++:++ +#+    +:+ +#++:++#++     +#+     +#++:++#   +#+        +#+  +:+  +#+ +#+    +:+    +#+     +#+ +:+ +#+     +#+         +#+        \n");
    printf(" +#+                     +#+    +#+ +#+    +#+     +#+     +#+        +#+        +#+       +#+ +#+    +#+    +#+     +#+  +#+#+#     +#+         +#+         \n");
    printf("#+#    #+#              #+#    #+# #+#    #+# #+# #+#     #+#        #+#        #+#       #+# #+#    #+#    #+#     #+#   #+#+#     #+#         #+#          \n");
    printf("########                ########  ###    ###  #####      ########## ########## ###       ###  ######## ########### ###    ####     ###     ###########       \n\n");
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: display_menu(void)
; DESCRIPTION: Displays menu of commands and their descriptions
;	Input: none
;	Output: none
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void display_menu(void)
{
    printf("A) Count the number of vowels in the string\n");
    printf("B) Count the number of consonants in the string\n");
    printf("C) Convert the string to uppercase\n");
    printf("D) Convert the string to lowercase\n");
    printf("E) Display the current string\n");
    printf("F) Enter another string\n");
    printf("G) Read string from file\n");
    printf("H) Write string to file\n\n");
    printf("M) Display this menu\n");
    printf("X) Exit the program");
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: ask_command(void)
; DESCRIPTION: Asks for a character from the user
;	Input: none
;	Output: char user_character[0]
;  Used global variables: none
; REMARKS when using this function:
;       Called every time inside the while loop in main
;*********************************************************************/

char ask_command(void)
{
    printf("\nGive command: \n");

    char user_character[3]; /* Max three characters due to newline and string ending characters */
    fgets(user_character, 3, stdin);

    user_character[0] = toupper(user_character[0]);
    if ((user_character[0] >= 'A' && user_character[0] <= 'H') || (user_character[0] == 'M' || 'X'))
    {
        return user_character[0];
    }
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: print_string(char string[])
; DESCRIPTION: Prints the current string
;	Input: char string[]
;	Output: none
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void print_string(char string[])
{
    printf("%s", string);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: read_string(char string[])
; DESCRIPTION: Reads a new string from the user, replacing previous
;	Input: char string[]
;	Output: none
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void read_string(char string[])
{
    printf("Give string:");
    fgets(string, 100, stdin);
    string[strcspn(string, "\n")] = 0; /* Removes newline character from string*/
    printf("%s", string);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: count_vowels(char string[])
; DESCRIPTION: Counts the number of consonants in the string
;	Input: char string[]
;	Output: int vowels
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

int count_vowels(char string[])
{
    int i = 0;
    int vowels = 0;

    while (string[i] != '\0')
    {
        if (toupper(string[i]) == 'A' || toupper(string[i]) == 'E' || toupper(string[i]) == 'I' || toupper(string[i]) == 'O' || toupper(string[i]) == 'U' || toupper(string[i]) == 'Y')
        {
            vowels++;
        }
        i++;
    }

    return vowels;
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: count_consonants(char string[])
; DESCRIPTION: Counts the number of consonants in the string
;	Input: char string[]
;	Output: int consonants
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

int count_consonants(char string[])
{
    int i = 0;
    int consonants = 0;

    while (string[i] != '\0')
    {
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {
            if (toupper(string[i]) != 'A' && toupper(string[i]) != 'E' && toupper(string[i]) != 'I' && toupper(string[i]) != 'O' && toupper(string[i]) != 'U' && toupper(string[i]) != 'Y')
            {
                consonants++;
            }
        }
        i++;
    }

    return consonants;
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: to_upper(char string[])
; DESCRIPTION: Transforms the string into uppercase
;	Input: char string[]
;	Output: none
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void to_upper(char string[])
{
    int i = 0;

    while (string[i] != '\0')
    {
        string[i] = toupper(string[i]);
        i++;
    }

    printf("%s", string);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: to_lower(char string[])
; DESCRIPTION: Transforms the string into lowercase
;	Input: char string[]
;	Output: none
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void to_lower(char string[])
{
    int i = 0;

    while (string[i] != '\0')
    {
        string[i] = tolower(string[i]);
        i++;
    }

    printf("%s", string);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: read_file(char string[])
; DESCRIPTION: Replaces string with the text inside of textfile.txt
;	Input: char string[]
;	Output: none
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void read_file(char string[])
{
    FILE *file_pointer;

    file_pointer = fopen("textfile.txt", "r");

    if (file_pointer == NULL)
    {
        printf("textfile.txt file failed to open.");
    }
    else
    {
        while (fgets(string, 100, file_pointer) != NULL)
        {
            printf("%s", string);
        }
        fclose(file_pointer);
    }
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: write_file(char string[])
; DESCRIPTION: Replaces inside of textfile.txt with the string
;	Input: char string[]
;	Output: none
;  Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void write_file(char string[])
{
    FILE *file_pointer;

    file_pointer = fopen("textfile.txt", "w");

    if (file_pointer == NULL)
    {
        printf("textfile.txt file failed to open.");
    }
    else
    {
        if (strlen(string) > 0)
        {
            fputs(string, file_pointer);
            fputs("\n", file_pointer);
        }
        fclose(file_pointer);
    }
}