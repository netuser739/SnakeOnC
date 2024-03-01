#include "test_error.h"
#include "error.h"
#include <stdio.h>

int main(void){
    char *message;

    int err_code = _testErrors(&message);
    if(err_code == 1){
       printf(message);
        return 1;
    }

   printf("Ошибка в saveRecord : невозможно прочитать файл");
    return 0;
}
