#include <stdio.h>

int errorIndex(int errCode){
    switch (errCode)
    {
    case 0:
        return NULL;
        break;
    case 1:
        return 0x1;     //ошибка: файл не открыт или отсутствует
        break;
    case 2:
        return 0x2;     //ошибка: невозможно прочитать файл
        break;
    
    default:
    return NULL;
        break;
    }
}

int SaveRecord(int i){
    return i;
}
