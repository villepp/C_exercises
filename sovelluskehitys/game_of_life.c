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
 *     game_of_life.c
 *
 * 2.  DESCRIPTION
 *     the game of life game :)
 *
 *
 * 3.  VERSIONS
 *       Original:
 *         5.4.2023 / ville
 *
 *       Version history:
 *
 *
 ***************************************************************************/

/*--------------------------------------------------------------------------*
 *    HEADER FILES                                                          *
 *--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/*--------------------------------------------------------------------------*
 *    GLOBAL VARIABLES                                                      *
 *--------------------------------------------------------------------------*/
/* Control flags */

/* Global constants */
#define MAX 10

/* Global variables */

/* Global structures */
struct cell
{
    int current; /* current situation, which is visible on screen */
    int future;  /* temporary calculation area for next round calculation */
};

enum
{
    DEAD,
    ALIVE
}; /* add creature status --?*/

/*-------------------------------------------------------------------*
 *    FUNCTION PROTOTYPES                                             *
 *--------------------------------------------------------------------*/
void choose_board(struct cell board[MAX][MAX], char board_choice);
void generate_first_board(struct cell board[MAX][MAX]);
void board_from_file(struct cell board[MAX][MAX]);
void create_next_board(struct cell board[MAX][MAX]);
int count_neighbours(struct cell board[MAX][MAX], int i, int j);
void show_next_board(struct cell board[MAX][MAX]);

/*********************************************************************
 *    MAIN PROGRAM                                                      *
 **********************************************************************/

int main(void)
{
    /* Initialize character used by user to choose whether to read board from file or not */
    char board_choice = 'a';
    /* Initialize character used by user to choose whether to continue or not */
    char continue_choice = 'f';

    /* Initialize board used for the game */
    struct cell board[MAX][MAX] = {0, 0};

    choose_board(board, board_choice);

    printf("Show the next  board?: y/n ");
    scanf(" %c", &continue_choice);
    continue_choice = tolower(continue_choice);

    /* Continue showing the next board until user inputs n*/
    while (continue_choice != 'n')
    {
        /* Create the next board, count_neighbours function is also called inside this function */
        create_next_board(board);

        /* Show the next board while also updating cells from future position to current */
        show_next_board(board);

        printf("Show the next  board?: y/n ");
        scanf(" %c", &continue_choice);
        continue_choice = tolower(continue_choice);
    }

    printf("\nProgram stopped\n");

    return 0;
} /* end of main */

/*********************************************************************
 *    FUNCTIONS                                                       *
 **********************************************************************/

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: choose_board(struct cell board[MAX][MAX], char board_choice)
; DESCRIPTION:  prompts user whether to read gameboard from file or
;               generate the board randomly
;	Input: struct cell board[MAX][MAX], char board_choice
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       calls itself recursively if given an invalid input
;*********************************************************************/
void choose_board(struct cell board[MAX][MAX], char board_choice)
{
    printf("Read board from file?: y/n ");
    scanf(" %c", &board_choice);
    board_choice = tolower(board_choice);

    if (board_choice == 'n')
    {
        /* Generate first board and shows it to the user */
        generate_first_board(board);
    }
    else if (board_choice == 'y')
    {
        /* Generate first board from file and shows it to the user */
        board_from_file(board);
        //TODO lisää vaihtoehto, että käyttäjä voi lisätä elossa olevia cellejä haluamiinsa koordinaatteihin
    }
    else
    {
        printf("\nInvalid input... \n");
        choose_board(board, board_choice);
    }
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: generate_first_board(struct cell board[MAX][MAX])
; DESCRIPTION:  generates the first board randomly or calls function
;               to generate it from file
;	Input: struct cell board[MAX][MAX], an empty board
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/
void generate_first_board(struct cell board[MAX][MAX])
{
    int i, j = 0;
    int random_number = 0;

    srand(time(NULL));

    printf("Current board: \n\n");

    for (i = 0; i <= MAX; i++)
    {
        for (j = 0; j <= MAX; j++)
        {
            if (i >= 1 && i < MAX && j >= 1 && j < MAX)
            {
                random_number = rand() % 4;

                if (random_number == 1)
                {
                    board[i][j].current = ALIVE;
                    printf("o");
                }
                else
                {
                    printf(" ");
                }
            }
            /* Print edges of the board */
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: board_from_file(struct cell board[MAX][MAX])
; DESCRIPTION:  generates board from text file
;	Input: struct cell board[MAX][MAX], an empty board
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       none
;*********************************************************************/
void board_from_file(struct cell board[MAX][MAX])
{
    FILE *fp;
    char state_c;
    int state, c, r;

    c = 0;
    r = 0;
    fp = fopen("gameboard.txt", "r");

    while (!feof(fp))
    {

        fscanf(fp, "%c", &state_c);

        state = state_c - '0';

        board[r][c].current = state;

        c++;

        if (c > MAX - 1)

        {

            r++;

            c = 0;

            /* reads the newline characters away */

            fscanf(fp, "%c", &state_c); /* reads newline from file */

#if defined(_WIN32) && (!defined(__unix__) || !defined(__unix) || (!defined(__APPLE__) && !defined(__MACH__)))

            fscanf(fp, "%c", &state_c); /* reads carriage return from file in case of Windows */
#endif
        }
    }

    int i, j;
    for (i = 0; i <= MAX; i++)
    {
        for (j = 0; j <= MAX; j++)
        {
            if (i >= 1 && i < MAX && j >= 1 && j < MAX)
            {
                if (board[i][j].current == ALIVE)
                {
                    printf("o");
                }
                else
                {
                    printf(" ");
                }
            }
            /* Print edges of the board */
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: create_next_board(struct cell board[MAX][MAX])
; DESCRIPTION:  generates the next board
;	Input: struct cell board[MAX][MAX]
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       Called inside while loop in main
;*********************************************************************/
void create_next_board(struct cell board[MAX][MAX])
{
    int i, j = 0;

    for (i = 1; i < MAX; i++)
    {
        for (j = 1; j < MAX; j++)
        {
            /* Alive cell */
            if (board[i][j].current == ALIVE)
            {
                int sum_alive = count_neighbours(board, i, j);

                if (sum_alive == 2 || sum_alive == 3)
                {
                    board[i][j].future = ALIVE;
                }
                else
                {
                    board[i][j].future = DEAD;
                }
            }
            /* Dead cell */
            else if (board[i][j].current == DEAD)
            {
                int sum_dead = count_neighbours(board, i, j);

                if (sum_dead == 3)
                {
                    board[i][j].future = ALIVE;
                }
                else
                {
                    board[i][j].future = DEAD;
                }
            }
            else
            {
                printf("\n!!!error!!!\n");
            }
        }
    }
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: count_neighbours(struct cell board[MAX][MAX], int i, int j)
; DESCRIPTION:  Counts the neighbours of the current cell examined
;	Input: struct cell board[MAX][MAX], int i, int j
;          int i and int j being the current cell position
;	Output: int sum, the sum of the current neighbours
;   Used global variables: none
; REMARKS when using this function:
;       Called inside the create_next_board function
;*********************************************************************/
int count_neighbours(struct cell board[MAX][MAX], int i, int j)
{
    int sum =
        board[i - 1][j - 1].current + /* Cell top left of cell examined */
        board[i][j - 1].current +     /* Cell on top of cell examined */
        board[i + 1][j - 1].current + /* Cell top right of cell examined */
        board[i - 1][j].current +     /* Cell left of cell examined */
        board[i + 1][j].current +     /* Cell right of cell examined */
        board[i - 1][j + 1].current + /* Cell bottom left of cell examined */
        board[i][j + 1].current +     /* Cell bottom of cell examined */
        board[i + 1][j + 1].current;  /* Cell bottom right of cell examined */

    return sum;
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: show_next_board(struct cell board[MAX][MAX])
; DESCRIPTION:  prints the board for the next day
;               also changes the state of future cells to current
;	Input: struct cell board[MAX][MAX]
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       Called inside the while loop in main
;*********************************************************************/
void show_next_board(struct cell board[MAX][MAX])
{
    int i, j = 0;

    printf("\n\nNew board : \n\n");

    for (i = 0; i <= MAX; i++)
    {
        for (j = 0; j <= MAX; j++)
        {
            if (i >= 1 && i < MAX && j >= 1 && j < MAX)
            {
                board[i][j].current = board[i][j].future;

                if (board[i][j].current == ALIVE)
                {
                    printf("o");
                }
                else
                {
                    printf(" ");
                }
            }
            /* Print edges of the board */
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}