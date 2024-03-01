#include <stdio.h>
#include "UI.h"
#include "test_UI.h"
char *ERR_STRELKA_POS = "strelka pos";
char *ERR_DISPLAY_DRAW = "error display draw";
char *ERR_STRELKA_NUMBER = "error strelka number";
char *ERR_FILE_NOT_FOUND = "error file not found";

int _testStartScreen(int strelka,  char **message){
    const char *file = "test.txt";
    freopen(file, "w", stdout);
    startScreen(strelka);
    fclose(stdout);
    freopen("/dev/tty", "w", stdout);

    FILE *fp;
    fp = fopen(file, "r");
    char *buf[1600];

    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }
    else{
        *message = ERR_FILE_NOT_FOUND;
        return 1;
    }
    

    if(buf[0] != '_'){
        *message = ERR_DISPLAY_DRAW;
        return 1;
    }
    
    if(buf[455] != 'P'){
        *message = ERR_DISPLAY_DRAW;
        return 1;
    }

    if(strelka == 0 && buf[449] != '>'){
        *message = ERR_STRELKA_POS;
        return 1;
    }
    
    if(strelka == 1 && buf[754] != '>'){
        *message = ERR_STRELKA_POS;
        return 1;
    }

    if(strelka == 2 && buf[1059] != '>'){
        *message = ERR_STRELKA_POS;
        return 1;
    }

    if(strelka > 2 || strelka < 0){
            *message = ERR_STRELKA_NUMBER;
            return 1;
    }

    fopen(file, "w");
    return 0;
}


//////////////////////////////////////////////////////////////////////////////
int _testRecordScreen(int strelka, char **message){
    const char *file = "test.txt";
    freopen(file, "w", stdout);
    recordScreen(strelka);
    fclose(stdout);
    freopen("/dev/tty", "w", stdout);

    FILE *fp;
    fp = fopen(file, "r+");
    char *buf[1600];

    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }else{
        
        *message = ERR_FILE_NOT_FOUND;
        return 1;
    }

    if(buf[0] != '_'){
        *message = ERR_DISPLAY_DRAW;
        return 1;
    }
    if(buf[1065] != 'A'){
        *message = ERR_DISPLAY_DRAW;
        return 1;
    }
    

    if(strelka == 0 && buf[1059] != '>'){
        *message = ERR_STRELKA_POS;
        return 1;
    }
    if(strelka == 1 && buf[1303] != '>'){
        *message = ERR_STRELKA_POS;
        return 1;
    }
    if(strelka > 1 || strelka < 0){
        *message = ERR_STRELKA_NUMBER;
        return 1;
    }
    fopen(file, "w");
    return 0;
}
int _testgameScreen(int snakeHeadX, int snakeHeadY, int furuitX, int fruitY, int arrayTailSnakeX[], int arrayTailSnakeY[], int snakeLength, char **message){

    const char *file = "test.txt";
    freopen(file, "w", stdout);
    gameScreen(snakeHeadX, snakeHeadY, furuitX, fruitY, arrayTailSnakeX, arrayTailSnakeY, snakeLength);
    fclose(stdout);
    freopen("/dev/tty", "w", stdout);  

    FILE *fp;
    fp = fopen(file, "r+");
    char *buf[1600];

    if (fp){
        for(int i=0;i<1600;i++){
            buf[i] = fgetc(fp);
        }
    }else{
        *message = ERR_FILE_NOT_FOUND;
        return 1;
    }
    
    if(buf[80] != '|'){
        *message = ERR_DISPLAY_DRAW;
        return 1;
    }

    if(buf[0] != '_'){
        *message = ERR_DISPLAY_DRAW;
        return 1;
    }

    if(buf[80] != '|'){
        *message = ERR_DISPLAY_DRAW;
        return 1;
    }

    fopen(file, "w");
    return 0;
}



int test_UI(char **message){
    int arrayTailSnakeX[] = {5,5,5};
    int arrayTailSnakeY[] = {6,7,8};
    if(_testgameScreen(5, 5, 10, 10, arrayTailSnakeX, arrayTailSnakeY, 3, message) == 1) return 1;
    if(_testRecordScreen(0,message) == 1) return 1;
    if(_testStartScreen(0,message) == 1) return 1;
    return 0;
}

