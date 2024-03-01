#include "test_uiControl.h"
#include "uiControl.h"
//#include "uiControl.c"

char *ERR_OPEN_WINDOW = "Ошибка в openWindow: не удалось выйти из программы";
char *ERR_INPUT_KEYBOARD = "Ошибка в inputKeybord: не изменяестся значение выбранного окна";
char *ERR_GAME_INPUT = "Ошибка в gameInput: не определяется направление змейки";

int _testOpenWindow(char **message){
    int n = 4;
    int i = 1;
    int curInd = 0;
    int f = 1;
    while(i < n){
        openWIndow(curInd, &f, i);
        if(curInd == 2 && f != 0){
            *message = ERR_OPEN_WINDOW;
            return 1;
        }
        curInd++;
        i++;
    }
   
    return 0;
};

int _testInputKeyboard(char **message){
    int curInd = 0;
    int buf = 0;
    int f = 1;
    int i = 1;
    int n = 4;
    while(i < n){
        inputKeyboard(&curInd, &f, i);
        if(curInd == buf){
            *message = ERR_INPUT_KEYBOARD;
            return 1;
        }
        buf = curInd;
        i++;

    }

    return 0;
};

int _testGameInput(char **message){
    int curDir = 0;
    int buf = 1;
    int i = 1;
    int n = 5;
    while(i < n){
        curDir = gameInput(i);
        if(curDir == buf){
            *message = ERR_GAME_INPUT;
            return 1;
        }
        buf = curDir;
        i++;

    }

    return 0;
}

int _testRecordScreen(char **message){
    int n = 2;
    int i = 0;
    while(i < n){
        recordScreen(i);
        i++;
    }
    
    return 0;
};

int _testStartScreen(char **message){
    int n = 3;
    int i = 0;
    while(i < n){
        startScreen(i);
        i++;
    }

    return 0;
};

int test_UiControl(char **message){
    if(_testOpenWindow(&*message) == 1) return 1;
    if(_testInputKeyboard(&*message) == 1) return 1; 
    if(_testGameInput(&*message) == 1) return 1;
    //if(_testRecordScreen(&*message) == 1) return 1; 
    //if(_testStartScreen(&*message) == 1) return 1; 

    return 0;
};