#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

struct cell
{
    int current; /* current situation, which is visible on screen */
    int future;  /* temporary calculation area for next round calculation */
};

void generate_first_board(struct cell board[MAX][MAX]);
void create_next_day(struct cell board[MAX][MAX]);
int count_neighbours(struct cell board[MAX][MAX], int i, int j);
void show_next_day(struct cell board[MAX][MAX]);

int main(void)
{
    /* Initialize character used by user to choose whether to continue or not */
    char continue_choise = 'f';

    /* Initialize board used for the game */
    struct cell board[MAX][MAX] = {0, 0};

    /* Generates first board and shows it to the user */
    generate_first_board(board);

    /* Continue showing the next day until user inputs n*/
    while (continue_choise != 'n')
    {
        printf("Show the next  day?: y/n ");
        scanf(" %c", &continue_choise);

        /* Create the next day, count_neighbours function is also called inside this function */
        create_next_day(board);

        /* Show the next day while also updating cells from future position to current */
        show_next_day(board);
    }

    printf("\nProgram stopped\n");

    return 0;
}

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
                    board[i][j].current = 1;
                }

                printf("%d", board[i][j].current);
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

void create_next_day(struct cell board[MAX][MAX])
{
    int i, j = 0;

    for (i = 1; i < MAX; i++)
    {
        for (j = 1; j < MAX; j++)
        {
            /* Alive cell */
            if (board[i][j].current == 1)
            {
                int sum_alive = count_neighbours(board, i, j);

                if (sum_alive == 2 || sum_alive == 3)
                {
                    board[i][j].future = 1;
                }
                else
                {
                    board[i][j].future = 0;
                }
            }
            /* Dead cell */
            else if (board[i][j].current == 0)
            {
                int sum_dead = count_neighbours(board, i, j);

                if (sum_dead == 3)
                {
                    board[i][j].future = 1;
                }
                else
                {
                    board[i][j].future = 0;
                }
            }
            else
            {
                printf("\n!!!error!!!\n");
            }
        }
    }
}

int count_neighbours(struct cell board[MAX][MAX], int i, int j)
{
    int sum =
        board[i - 1][j - 1].current + /* Cell top left of cell examined */
        board[i][j - 1].current + /* Cell on top of cell examined */
        board[i + 1][j - 1].current + /* Cell top right of cell examined */
        board[i - 1][j].current + /* Cell left of cell examined */
        board[i + 1][j].current + /* Cell right of cell examined */
        board[i - 1][j + 1].current + /* Cell bottom left of cell examined */
        board[i][j + 1].current + /* Cell bottom of cell examined */
        board[i + 1][j + 1].current; /* Cell bottom right of cell examined */

    return sum;
}

void show_next_day(struct cell board[MAX][MAX])
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
                printf("%d", board[i][j].current);
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