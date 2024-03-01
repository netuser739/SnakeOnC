#include <stdio.h>
#include "logic.h"
#include "test_Logic.h"

int main(void){
    char *message;

    int err_code = test_Logic(&message);
    if(err_code == 1){
       printf(message);
        return 1;
    }
    printf("Ошибка в finalRecord: финальная запись НЕ прошла при первоначальной проверке баллов");
    return 0;
}
