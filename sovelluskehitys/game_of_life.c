#include "headers.h"

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
    struct cell board[COLUMNS][ROWS] = {0, 0};

    setlocale(LC_ALL, "");

    /* Ncurses initialization */
    initscr();
    start_color();
    use_default_colors();
    cbreak();
    noecho();

    init_pair(1, COLOR_BLACK, COLOR_CYAN); /* Wall */
    init_pair(2, COLOR_BLUE, COLOR_GREEN); /* Dead cell */
    init_pair(3, COLOR_RED, COLOR_RED);    /* Alive cell */

    choose_board(board, board_choice);

    continue_board(board, continue_choice);

    printw("\nProgram stopped\n");

    endwin();

    return 0;
} /* end of main */
