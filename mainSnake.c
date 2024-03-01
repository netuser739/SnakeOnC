#include "Logic\logic.h"
#include "Control\uiControl.h"
#include "record\record.h"
#include "ui\UI.h"
#include <stdio.h>
#include <stdlib.h>

void openWIndow(int curInd, int *f, int isRecordRunning, struct Params snake)
{
    int i = getch(); // getch();
    int dir;
    if (i == 'e')
    {
        switch (curInd)
        {
        case 0:
            while (gameOver)
            {
                system("clear");
                newCoordinates(&snake);
                gameScreen(snake.x, snake.y, snake.fruitX, snake.fruitY, snake.tailX, snake.tailY, snake.nTail, snake.score);
                gameInput(&snake);
                usleep(1000);
                gameOver(&snake);
            }
            break;

        case 1:
            while (isRecordRunning)
            {
                rrecordScreen(curInd);
                inputKeyboard(&curInd, &isRecordRunning, 1);
                openRecordScreen(curInd, &isRecordRunning);
            }
            break;

        case 2:
            *f = 0;
            break;

        default:
            break;
        }
    }
};

void openRecordScreen(int curInd, int *isRecordRunning)
{
    switch (curInd)
    {
    case 0:

        break;
    case 1:
        int i;
        if (i = getch() == 10)
        {
            *isRecordRunning = 0;
        }
        break;

    default:
        break;
    }
}

int main()
{
    struct Params snake;
    setParams(&snake);
    int currentIndex = 0;
    system("clear");
    int currentScreen = sstartScreen(currentIndex);

    int isGameRunning = 1;
    int isRecordRunning = 1;
    int isPlayRunning = 1;

    while (isGameRunning)
    {
        inputKeyboard(&currentIndex, &isGameRunning, 2);
        system("clear");
        currentScreen = sstartScreen(currentIndex);
        openWIndow(currentIndex, &isGameRunning, &isRecordRunning, snake);
    }
}