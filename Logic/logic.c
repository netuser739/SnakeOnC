#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <fcntl.h>
#include <termios.h>
#include <stdio.h>
int setParams(struct Params *snake)
{
  srand(time(NULL));
  snake->width = 20;
  snake->height = 40;
  snake->gameOver = 0;
  snake->dir;
  snake->x = snake->width / 1;
  snake->y = snake->height / 1;
  snake->fruitX = 1 + rand() % (snake->width - 1);
  snake->fruitY = 1 + rand() % (snake->height - 1);
  snake->score = 0;
  snake->nTail = 0;
  return 0;
}

int flag;
int gameInput()
{
  if (kbhit())
  {
    switch (getch())
    {
    case 'w':
      flag = 0;
      break;
    case 'd':
      flag = 1;
      break;
    case 's':
      flag = 2;
      break;
    case 'a':
      flag = 3;
      break;
    }
  }
}

void newCoordinates(struct Params *snake)
{
  srand(time(NULL));
  int prevX = snake->tailX[0];
  int prevY = snake->tailY[0];
  int prev2X;
  int prev2Y;
  snake->tailX[0] = snake->x;
  snake->tailY[0] = snake->y;
  for (int i = 1; i < 100; i++)
  {
    prev2X = snake->tailX[i];
    prev2Y = snake->tailY[i];
    snake->tailX[i] = prevX;
    snake->tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
  switch (flag)
  {
  case 0:
    snake->x--;
    break;
  case 1:
    snake->y++;
    break;
  case 2:
    snake->x++;
    break;
  case 3:
    snake->y--;
    break;
  }
  if (snake->x >= snake->width - 2)
    snake->x = 1;
  if (snake->x <= 0)
    snake->x = snake->width - 2;
  if (snake->y >= snake->height - 2)
    snake->y = 1;
  if (snake->y <= 0)
    snake->y = snake->height - 2;
  if (snake->x == snake->fruitX && snake->y == snake->fruitY)
  {
    snake->score += 10;
    snake->fruitX = 2 + rand() % (snake->width - 3);
    snake->fruitY = 2 + rand() % (snake->height - 3);
    snake->nTail++;
  }
}

void gameOver(struct Params *snake)
{
  if (snake->x < 0 || snake->x > snake->width - 2 || snake->y < 0 || snake->y > snake->height - 1)
  {
    snake->gameOver = 1;
  }
  for (int i = 0; i < snake->nTail; i++)
  {
    if (snake->tailX[i] == snake->x && snake->tailY[i] == snake->y)
    {
      snake->gameOver = 1;
    }
  }
}

int finalRecord(struct Params *snake)
{
  if (snake->gameOver == 1)
  {
    return snake->score;
  }
  return 0;
}
