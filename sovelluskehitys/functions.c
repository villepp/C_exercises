#include "headers.h"
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
void choose_board(struct cell board[COLUMNS][ROWS], char board_choice)
{
    printw("Read board from file?: y/n ");
    echo();
    board_choice = getch();
    noecho();
    board_choice = tolower(board_choice);

    if (board_choice == 'n')
    {
        refresh();
        /* Generate first board and shows it to the user */
        generate_first_board(board);
    }
    else if (board_choice == 'y')
    {
        refresh();
        /* Generate first board from file and shows it to the user */
        board_from_file(board);
    }
    else
    {
        printw("\nInvalid input... \n");
        choose_board(board, board_choice);
    }
    refresh();
}

/*********************************************************************
;	F U N C T I O N    D E S C R I P T I O N
;---------------------------------------------------------------------
; NAME: continue_board(struct cell board[COLUMNS][ROWS], char continue_choice)
; DESCRIPTION:  prompts user whether to show the next board
;	Input: struct cell board[MAX][MAX], char continue_choice
;	Output: none
;   Used global variables: none
; REMARKS when using this function:
;       calls itself recursively
;*********************************************************************/
void continue_board(struct cell board[COLUMNS][ROWS], char continue_choice)
{
    printw("\n\nShow the next  board?: y/n \n\n");
    echo();
    continue_choice = getch();
    noecho();
    continue_choice = tolower(continue_choice);

    /* Continue showing the next board until user inputs n*/
    if (continue_choice == 'n')
    {
        endwin();
        exit(0);
    }
    else if (continue_choice == 'y')
    {

        /* Create the next board, count_neighbours function is also called inside this function */
        create_next_board(board);

        /* Show the next board while also updating cells from future position to current */
        show_next_board(board);

        continue_board(board, continue_choice);

        refresh();
    }
    else
    {
        printw("\nInvalid input... \n");
        continue_board(board, continue_choice);
    }
    refresh();
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
void generate_first_board(struct cell board[COLUMNS][ROWS])
{
    int i, j = 0;
    int random_number = 0;

    srand(time(NULL));

    clear();
    move(0, 0);

    printw("\n\nCurrent board: \n\n");

    for (i = 0; i <= COLUMNS; i++)
    {
        for (j = 0; j <= ROWS; j++)
        {
            move(i, j);
            if (i >= 1 && i < COLUMNS && j >= 1 && j < ROWS)
            {
                random_number = rand() % 5;

                if (random_number == 1)
                {
                    board[i][j].current = ALIVE;
                    attron(COLOR_PAIR(3));
                    printw(ALIVE_CELL);
                    attroff(COLOR_PAIR(3));
                }
                else
                {
                    attron(COLOR_PAIR(2));
                    printw(DEAD_CELL);
                    attroff(COLOR_PAIR(2));
                }
            }
            /* Print edges of the board */
            else
            {
                attron(COLOR_PAIR(1));
                printw(WALL);
                attroff(COLOR_PAIR(1));
            }
        }
    }
    refresh();
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
void board_from_file(struct cell board[COLUMNS][ROWS])
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

        if (c >= COLUMNS)

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

    clear();
    move(0, 0);

    int i, j;
    for (i = 0; i <= COLUMNS; i++)
    {
        for (j = 0; j <= ROWS; j++)
        {
            move(i, j);
            if (i >= 1 && i < COLUMNS && j >= 1 && j < ROWS)
            {
                if (board[i][j].current == ALIVE)
                {
                    attron(COLOR_PAIR(3));
                    printw(ALIVE_CELL);
                    attroff(COLOR_PAIR(3));
                }
                else
                {
                    attron(COLOR_PAIR(2));
                    printw(DEAD_CELL);
                    attroff(COLOR_PAIR(2));
                }
            }
            /* Print edges of the board */
            else
            {
                attron(COLOR_PAIR(1));
                printw(WALL);
                attroff(COLOR_PAIR(1));
            }
        }
    }
    refresh();
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
void create_next_board(struct cell board[COLUMNS][ROWS])
{
    int i, j = 0;

    for (i = 1; i < COLUMNS; i++)
    {
        for (j = 1; j < ROWS; j++)
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
                printw("\n!!!error!!!\n"); /* This is mainly for testing to see if any errors occur */
            }
        }
    }
    refresh();
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
int count_neighbours(struct cell board[COLUMNS][ROWS], int i, int j)
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
void show_next_board(struct cell board[COLUMNS][ROWS])
{
    int i, j = 0;

    clear();
    move(0, 0);

    printw("\n\nNew board : \n\n");

    for (i = 0; i <= COLUMNS; i++)
    {
        for (j = 0; j <= ROWS; j++)
        {
            if (i >= 1 && i < COLUMNS && j >= 1 && j < ROWS)
            {
                board[i][j].current = board[i][j].future;

                if (board[i][j].current == ALIVE)
                {
                    attron(COLOR_PAIR(3));
                    printw(ALIVE_CELL);
                    attroff(COLOR_PAIR(3));
                }
                else
                {
                    attron(COLOR_PAIR(2));
                    printw(DEAD_CELL);
                    attroff(COLOR_PAIR(2));
                }
            }
            /* Print edges of the board */
            else
            {
                attron(COLOR_PAIR(1));
                printw(WALL);
                attroff(COLOR_PAIR(1));
            }
        }
        printw("\n");
    }
    refresh();
}