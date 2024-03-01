#include <stdio.h>
#include "UI.h"
int x = 25;
int y = 60;

int sstartScreen(int strelka)
{
    int screenBaseArray[25][60];
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (i == 0 || i == 24)
            {
                screenBaseArray[i][j] = '_';
            }
            else if (j == 0 || j == 59)
            {
                screenBaseArray[i][j] = '|';
            }
            else
            {
                screenBaseArray[i][j] = ' ';
            }
        }
    }

    int kordinatyStrok[] = {6, 8, 11, 13, 16, 18};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 23; j < 37; j++)
        {
            screenBaseArray[kordinatyStrok[i]][j] = '_';
        }
    }

    int kordinatyCentraStrok[] = {7, 12, 17};
    for (int i = 0; i < 3; i++)
    {
        screenBaseArray[kordinatyCentraStrok[i]][23] = '|';
        screenBaseArray[kordinatyCentraStrok[i]][36] = '|';
    }

    int play[] = {'P', 'L', 'A', 'Y'};
    int record[] = {'R', 'E', 'C', 'O', 'R', 'D'};
    int exit[] = {'E', 'X', 'I', 'T'};
    int count = 0;

    count = 4;
    for (int i = 0; i < count; i++)
    {
        screenBaseArray[7][28 + i] = play[i];
    }

    count = 6;
    for (int i = 0; i < count; i++)
    {
        screenBaseArray[12][27 + i] = record[i];
    }

    count = 4;
    for (int i = 0; i < count; i++)
    {
        screenBaseArray[17][28 + i] = exit[i];
    }

    if (strelka == 0)
    {
        screenBaseArray[7][22] = '>';
    }
    else if (strelka == 1)
    {
        screenBaseArray[12][22] = '>';
    }
    else if (strelka == 2)
    {
        screenBaseArray[17][22] = '>';
    }

    // SHOW
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%c", screenBaseArray[i][j]);
        }
        printf("\n");
    }
    return 1;
}

int rrecordScreen(int strelka)
{
    int screenBaseArray[25][60];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (i == 0 || i == 24)
            {
                screenBaseArray[i][j] = '_';
            }
            else if (j == 0 || j == 59)
            {
                screenBaseArray[i][j] = '|';
            }
            else
            {
                screenBaseArray[i][j] = ' ';
            }
        }
    }

    int congratulations[] = {'C', 'O', 'N', 'G', 'R', 'A', 'T', 'U', 'L', 'A', 'T', 'I', 'O', 'N', 'S', '!'};
    int congratulations2[] = {'Y', 'O', 'U', ' ', 'H', 'A', 'V', 'E', ' ', 'B', 'R', 'O', 'K', 'E', 'N', ' ', 'T', 'H', 'E', ' ', 'R', 'E', 'C', 'O', 'R', 'D', '!'};
    for (int j = 0; j < 16; j++)
    {
        screenBaseArray[5][22 + j] = congratulations[j];
    }
    for (int j = 0; j < 27; j++)
    {
        screenBaseArray[6][17 + j] = congratulations2[j];
    }

    for (int i = 9; i < 14; i++)
    {
        screenBaseArray[i][19] = '.';
    }

    int kordinatyStrok[] = {16, 18, 20, 22};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 23; j < 37; j++)
        {
            screenBaseArray[kordinatyStrok[i]][j] = '_';
        }
    }

    int kordinatyCentraStrok[] = {17, 21};
    for (int i = 0; i < 2; i++)
    {
        screenBaseArray[kordinatyCentraStrok[i]][23] = '|';
        screenBaseArray[kordinatyCentraStrok[i]][36] = '|';
    }

    int addName[] = {'A', 'D', 'D'};
    int exit[] = {'E', 'X', 'I', 'T'};
    int count = 0;

    count = 3;
    for (int i = 0; i < count; i++)
    {
        screenBaseArray[17][28 + i] = addName[i];
    }

    count = 4;
    for (int i = 0; i < count; i++)
    {
        screenBaseArray[21][28 + i] = exit[i];
    }

    if (strelka == 0)
    {
        screenBaseArray[17][22] = '>';
    }
    else if (strelka == 1)
    {
        screenBaseArray[21][22] = '>';
    }

    // SHOW
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%c", screenBaseArray[i][j]);
        }
        printf("\n");
    }
    return 2;
}

int gameScreen(int snakeHeadX, int snakeHeadY, int furuitX, int fruitY, int arrayTailSnakeX[], int arrayTailSnakeY[], int snakeLength, int score)
{
    int screenBaseArray[25][60];
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            if (i == 0 || i == 19)
            {
                screenBaseArray[i][j] = '_';
            }
            else if (j == 0 || j == 39)
            {
                screenBaseArray[i][j] = '|';
            }
            else
            {
                screenBaseArray[i][j] = ' ';
            }
        }
    }

    screenBaseArray[snakeHeadX][snakeHeadY] = '@';
    screenBaseArray[furuitX][fruitY] = '0';

    for (int i = 0; i < snakeLength; i++)
    {
        screenBaseArray[arrayTailSnakeX[i]][arrayTailSnakeY[i]] = '#';
    }

    // SHOW
    printf("%d", score);
    printf("\n");
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            printf("%c", screenBaseArray[i][j]);
        }
        printf("\n");
    }
    return 3;
}

int printScreen(currentScreen){

}
