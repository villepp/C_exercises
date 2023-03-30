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
 *         28.3.2023 / Ville Pitkänen
 *
 *       Version history:
 *         23.3.2023 / Ville Pitkänen
 *           C-course's final version
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
#define MAX 100

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
    /* Initialize the string with a default value */
    char string[MAX] = "Hello world !!";

    /* Initialize the command character with 1, not leaving it empty */
    char command = 1;

    print_logo();
    display_menu();

    /* If user given command is X, the program stops */
    while (command != 'X')
    {
        command = ask_command();

        switch (command)
        {
        case 'A':
            printf("String has %d vowels", count_vowels(string));
            break;
        case 'B':
            printf("String has %d consonants", count_consonants(string));
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
;   Used global variables: none
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
;   Used global variables: none
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
;	Output: char user_character[0], the new command character
;   Used global variables: none
; REMARKS when using this function:
;       Called every time inside the while loop in main
;*********************************************************************/

char ask_command(void)
{
    /* Max three characters due to newline and string ending characters */
    char user_character[3];

    printf("\nGive command: \n");
    fgets(user_character, 3, stdin);

    user_character[0] = toupper(user_character[0]);

    /* Loops until user gives one of the available command characters */
    while ((user_character[0] < 'A' || user_character[0] > 'H') && (user_character[0] != 'M' && user_character[0] != 'X'))
    {
        printf("Command invalid, try again: \n");
        fgets(user_character, 3, stdin);

        user_character[0] = toupper(user_character[0]);
    }

    return user_character[0];
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: print_string(char string[])
; DESCRIPTION: Prints the current string
;	Input: char string[], the user given string
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void print_string(char string[])
{
    printf("Current string: %s", string);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: read_string(char string[])
; DESCRIPTION: Reads a new string from the user, replacing previous
;	Input: char string[], the user given string
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void read_string(char string[])
{
    printf("Give string: ");
    fgets(string, MAX, stdin);

    /* Removes newline character from string */
    string[strcspn(string, "\n")] = 0;

    printf("New string: %s", string);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: count_vowels(char string[])
; DESCRIPTION: Counts the number of vowels in the string
;	Input: char string[], the user given string
;	Output: int vowels, number of vowels in the string
;   Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

int count_vowels(char string[])
{
    int i = 0;
    int vowels = 0;

    /* Looped until the string ending character */
    while (string[i] != '\0')
    {   /* Increase int vowels if the current character is a vowel */
        if (toupper(string[i]) == 'A' || toupper(string[i]) == 'E' || toupper(string[i]) == 'I' ||
            toupper(string[i]) == 'O' || toupper(string[i]) == 'U' || toupper(string[i]) == 'Y')
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
;	Input: char string[], the user given string
;	Output: int consonants, number of consonants in the string
;   Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

int count_consonants(char string[])
{
    int i = 0;
    int consonants = 0;

    /* Looped until the string ending character */
    while (string[i] != '\0')
    {   /* Check if current character is a letter */
        if ((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z'))
        {   /* Only increase int consonants if the current letter is NOT a vowel */
            if (toupper(string[i]) != 'A' && toupper(string[i]) != 'E' && toupper(string[i]) != 'I' &&
                toupper(string[i]) != 'O' && toupper(string[i]) != 'U' && toupper(string[i]) != 'Y')
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
;	Input: char string[], user's string to be transformed
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void to_upper(char string[])
{
    int i = 0;

    /* Looped until the string ending character */
    while (string[i] != '\0')
    {
        string[i] = toupper(string[i]);
        i++;
    }

    printf("String in uppercase: %s", string);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: to_lower(char string[])
; DESCRIPTION: Transforms the string into lowercase
;	Input: char string[], user's string to be transformed
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/

void to_lower(char string[])
{
    int i = 0;

    /* Looped until the string ending character */
    while (string[i] != '\0')
    {
        string[i] = tolower(string[i]);
        i++;
    }

    printf("String in lowercase: %s", string);
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: read_file(char string[])
; DESCRIPTION: Replaces string with the text inside of textfile.txt
;	Input: char string[], user given string
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       textfile.txt needed in order for this to work
;*********************************************************************/

void read_file(char string[])
{
    FILE *file_pointer;

    file_pointer = fopen("textfile.txt", "r");

    /* Print a message if file doesn't exist */
    if (file_pointer == NULL)
    {
        printf("textfile.txt file failed to open.");
    }
    else
    {   /* Replace string with the content of textfile.txt */
        while (fgets(string, MAX, file_pointer) != NULL)
        {
            printf("New string from file: %s", string);
        }
        fclose(file_pointer);
    }
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: write_file(char string[])
; DESCRIPTION: Replaces inside of textfile.txt with the string
;	Input: char string[], user given string
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       textfile.txt needed in order for this to work
;*********************************************************************/

void write_file(char string[])
{
    FILE *file_pointer;

    file_pointer = fopen("textfile.txt", "w");

    /* Print a message if file doesn't exist */
    if (file_pointer == NULL)
    {
        printf("textfile.txt file failed to open.");
    }
    else
    {   /* Check that the string isn't empty */
        if (strlen(string) > 0)
        {
            /* Write string to file */
            fputs(string, file_pointer);
        }
        fclose(file_pointer);

        printf("Wrote to textfile.txt: %s", string);
    }
}