#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "uiControl.h"
#include <fcntl.h>
#include <termios.h>
#include <stdio.h>

static struct termios old, current;
/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  current = old; /* make new settings same as old settings */
  current.c_lflag &= ~ICANON; /* disable buffered i/o */
  if (echo) {
      current.c_lflag |= ECHO; /* set echo mode */
  } else {
      current.c_lflag &= ~ECHO; /* set no echo mode */
  }
  tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
}

int kbhit(){
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &old);
    current = old;
    current.c_iflag &= ~ ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &current);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch!= EOF){
        ungetc(ch, stdin);
        return 1;
    }
    return 0;
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  if (kbhit()){
    ch = getchar();

  }
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}

// int gameInput(){
//     int i = 0;

//         // i = getch();    //getch();
//         // int goodInput = i == 119 || i == 115 || i == 97 || i == 100;
//         // if(!goodInput) return 4;
//         if(kbhit()){
//             switch (i)
//         {
//             case 119:
//                 return 0;
//                 break;
//             case 100:
//                 return 1;
//                 break;
//             case 115:
//                 return 2;
//                 break;
//             case 97:
//                 return 3;
//                 break;        
//             default:
//                 break;
//             }
//         }

//     return 1;
// }

void inputKeyboard(int *curInd, int *f, int n){
    int i;
    while(1){
        i = getch();  //getch();
        if(i == 119 || i == 115){ // 80 || 72
            break;
        }
    }
    switch(i){
        case 115:    //80
            if(*curInd == n){
                *curInd = 0;
            } else *curInd = *curInd + 1;
            break;
        case 119:    //72
            if(*curInd == 0){
                *curInd = n;
            } else *curInd = *curInd - 1;
                break;
        case 27:    //27
            *f = 0;
            break;
    }
}

// void openWIndow(int curInd, int *f, struct Params *snake){
//     int i = getch();    //getch();
//     if(i == 10){
//         switch(curInd){
//         case 0:
//             gameScreen(&snake);
//             break;
//         case 1:
//             rrecordScreen(0);
//             break;
//         case 2:
//             *f = 0;
//             //open exit
//             break;
//         default:
//             break;
//         }
//     }
// };
