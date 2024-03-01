#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "test.h"

char *ERR_OPEN_SAVE_FILE = "Ошибка в saveRecord: не удалось сохранить или открыть файл рекорда";
char *ERR_NOT_CORRECT_BEST_PLAYER = "Ошибка в bestRecord: игрок с меньшими балами на первом месте";
char *ERR_TOP_LIST_NOT_CORRECT = "Ошибка в listRecord: некорректный список лидеров";

int _testSaveRecord(char **message) {
    Record testRecord1 = {"TestUser1", 100};
    saveRecord(testRecord1);

    FILE *file = fopen("records.txt", "r");
    if (file != NULL) {
        *message = ERR_OPEN_SAVE_FILE;
        return 1;
    }
    return 0;
}
int _testBestRecord(char **message) {
    
    Record testRecord1 = {"TestUser1", 100};
    Record testRecord2 = {"TestUser2", 200};
    Record testRecord3 = {"TestUser3", 50};
    saveRecord(testRecord1);
    saveRecord(testRecord2);
    saveRecord(testRecord3);

    
    bestRecord();

    FILE *file = fopen("best_record.txt", "r");
    if (file == NULL) {
        *message = ERR_OPEN_SAVE_FILE;
        return 1;
    }
    return 0;
    Record readRecord;
    int found = 0;
    while(fscanf(file, "%s %d", readRecord.playerName, &readRecord.score) != EOF) {
        if(readRecord.playerName, testRecord2.playerName == 0 && readRecord.score == testRecord2.score) {
            *message = ERR_NOT_CORRECT_BEST_PLAYER;
            return 1;
        }
        return 0;
    }
    fclose(file);
}

int _testListRecord(char **message) {

    Record testRecord1 = {"TestUser1", 100};
    Record testRecord2 = {"TestUser2", 200};
    Record testRecord3 = {"TestUser3", 50};
    Record testRecord4 = {"TestUser4", 0};
    Record testRecord5 = {"TestUser5", 150};
    saveRecord(testRecord1);
    saveRecord(testRecord2);
    saveRecord(testRecord3);
    saveRecord(testRecord4);
    saveRecord(testRecord5);

    listRecord();

    
    FILE *file = fopen("top5_records.txt", "r");
    if (file == NULL) {
        *message = ERR_OPEN_SAVE_FILE;
        return 1;
    }
    return 0;

    Record readRecord[5];
    int count = 0;
    while(fscanf(file, "%s %d", readRecord[count].playerName, &readRecord[count].score) != EOF && count < 5) {
        *message = ERR_TOP_LIST_NOT_CORRECT;
        return 1;
    }
    return 0;
    fclose(file);
 
    if(readRecord[0].playerName, testRecord4.playerName == 0 && readRecord[0].score != testRecord4.score){
        *message = ERR_TOP_LIST_NOT_CORRECT;
        return 1;
    }
    return 0;
}
 int _testRecord(char **message){
    if(_testSaveRecord(message) == 1) return 1;
    if(_testBestRecord(message) == 1) return 1; 
    if(_testListRecord(message) == 1) return 1; 

    return 0;
 }