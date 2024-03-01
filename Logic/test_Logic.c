#include <stdio.h>
#include "logic.h"
#include "test_logic.h"

char *ERR_PARAMS = "Ошибка в setParams: не прошла проверку на изначальные параментры игры";
char *ERR_GAME_OVER = "Ошибка в gameOver: не удалось выполнить проверку границ";
char *ERR_FINAL_RECORD = "Ошибка в finalRecord: финальная запись НЕ прошла при первоначальной проверке баллов";
char *ERR_ON_SELF_COLLUSION_CHECK = "Ошибка в gameOver: при самостоятельной проверке на столкновение";
char *ERR_CHECK_FINAL_SCORE = "Ошибка в finalRecord: не удалось проверить итоговый балл";

int test_setParams(char **message) {
    Params snake;
    setParams(&snake);
    if(snake.width != 40 ||
       snake.height != 20 ||
       snake.gameOver != 0 ||
       snake.dir != 0 ||
       snake.x != snake.width / 2 - 1 ||
       snake.y != snake.height / 2 - 1 ||
       snake.score != 0 ||
       snake.nTail != 0 ||
       snake.fruitX < 0 || snake.fruitX >= snake.width ||
       snake.fruitY < 0 || snake.fruitY >= snake.height) {
        *message = ERR_PARAMS;
        return 1;
    }
    return 0;
}

int test_gameOver(char **message) {
    Params snake;
    setParams(&snake);
    snake.x = snake.width; // за пределами границы
    gameOver(&snake);
    if(snake.gameOver != 1) {
        *message = ERR_GAME_OVER;
        return 1;
    }
   

    setParams(&snake);
    snake.y = snake.height; // за пределами границы
    gameOver(&snake);
    if(snake.gameOver != 1) {
        *message = ERR_GAME_OVER;
        return 1;
    }
    
    setParams(&snake);
    snake.nTail = 1;
    snake.tailX[0] = snake.x;
    snake.tailY[0] = snake.y;
    gameOver(&snake);
    if(snake.gameOver != 1) {
        *message = ERR_ON_SELF_COLLUSION_CHECK;
        return 1 ;
    }
    return 0;
}

int test_finalRecord(char **message) {
    Params snake;
    setParams(&snake);
    int score = finalRecord(&snake);
    if(score != 0) {
        *message = ERR_FINAL_RECORD;
        return 1;
    }

    snake.gameOver = 1;
    snake.score = 100;
    score = finalRecord(&snake);
    if(score != 100) {
        *message = ERR_CHECK_FINAL_SCORE;
        return 1;
    }
    return 0;
}

int test_Logic(char **message){
    if(test_gameOver(message) == 1) return 1;
    if(test_finalRecord(message) == 1) return 1; 
    if(test_setParams(message) == 1) return 1; 

    return 0;
 }