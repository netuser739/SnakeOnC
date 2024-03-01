#include <stdio.h>
#include <stdlib.h>
#include "test_error.h"
#include "error.h"

char *ERR_OPEN_SAVE_FILE = "Ошибка в saveRecord: файл не открыт или отсутствует";

char *ERR_CANNOT_READ = "Ошибка в saveRecord : невозможно прочитать файл";


int _testErrorIndex(char** message){
    int testCases[] = {0, 1, 2, 3, 4, 5};
    int numCases = sizeof(testCases) / sizeof(int);

    for(int i=0; i < numCases; i++){
        int res = errorIndex(testCases[i]);
        switch(res){
            case 0x1:
                *message =  ERR_OPEN_SAVE_FILE;
                break;
            case 0x2:
                *message = ERR_CANNOT_READ;
                break;
        }
    }
}
int _testErrors(char **message){
    if(_testErrorIndex(message) == 1) return 1;
    return 0;
 }