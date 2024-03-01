#include "test.h"
#include "record.h"
#include <stdio.h>

int main(void){
    char *message;

    int err_code = _testRecord(&message);
    if(err_code != 1){
       printf(message);
        return 1;
    }

   printf("Ошибка в listRecord: некорректный список лидеров");
    return 0;
}
