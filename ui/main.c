#include <stdio.h>
#include "test_UI.h"
#include "UI.h"

int main(void)
{

    char *message;
    int err_code = test_UI(&message);


    if (err_code != 0){
        printf(message);
        return 1;
    }

    printf("ALL test correct!");
    return 0;
}