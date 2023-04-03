#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cell
{
    int current;  /* current situation, which is visible on screen */
    int future;   /* temporary calculation area for next round calculation */
};

void create_next_day(struct cell board[10][10]);

int main(void)
{
    int i, j = 0;

    struct cell board [10] [10] = {0, 0};

    int random_number = 0;

    srand(time(NULL));

    //board[4][4].current = 1;
    //board[4][5].current = 1;
    //board[4][6].current = 1;
    //board[5][6].current = 1;

    printf("Current board: \n\n");

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            random_number = rand() % 5;
            if (random_number == 0) 
            {
                board[i][j].current = 1;
            } 
            printf("%d",board[i][j]);
        }
        printf("\n");
    }

    //TODO while loop, jatka kunnes boardit samat
    create_next_day(board);

    return 0;
}

void create_next_day(struct cell board[10][10])
{
    int i, j = 0;


    /*alive cell*/
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {

                if(board[i][j].current==1)
                {
                int sum = 
                board[i-1][j-1].current + 
                board[i][j-1].current + 
                board[i+1][j-1].current + 
                board[i-1][j].current + 
                board[i+1][j].current + 
                board[i-1][j+1].current + 
                board[i][j+1].current + 
                board[i+1][j+1].current;

                if(sum == 2 || sum == 3)
                {
                    board[i][j].future = 1;
                }
                else
                {
                    board[i][j].future = 0;
                }
            }
        }
    }

    /*empty cell*/
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {

              if(board[i][j].current==0)
              {   
                int sum = 
                board[i-1][j-1].current + 
                board[i][j-1].current + 
                board[i+1][j-1].current + 
                board[i-1][j].current + 
                board[i+1][j].current + 
                board[i-1][j+1].current + 
                board[i][j+1].current + 
                board[i+1][j+1].current;

                if(sum==3)
                {
                    board[i][j].future = 1;
                }
                else
                {
                    board[i][j].future = 0;
                }
              }
            }
        }

        printf("\n\nNew board : \n\n");

    

    for(i=1;i<=9;i++)
    {
        for(j=1;j<=9;j++)
        {
            printf("%d",board[i][j].future);
        }
        printf("\n");
    }

}


//tee tänne ehkä erillinen funktio count_neighbours 
