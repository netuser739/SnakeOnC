#include "test_uiControl.h"
#include "uiControl.h"
#include <stdio.h>

int main(){
    char *message;

    int err_code = test_UiControl(&message);

    if(err_code == 1){
        printf(message);
        return 1;
    }

    printf("ALL TEST CORRECT");
    return 0;
}