#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 5

typedef struct {
    char playerName[50];
    int score;
} Record;

// Функция сохранения записи в файл record.txt
void saveRecord(const char* playerName, int score) {
    FILE* file = fopen("record.txt", "a");  // Открываем файл для добавления данных (режим "a" - append)
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }
    
    fprintf(file, "%s %d\n", playerName, score);  // Записываем имя игрока и количество очков в файл
    fclose(file);  // Закрываем файл
}

// Функция проверки и сохранения лучшего результата в файл best.txt
int bestRecord(const char* playerName, int score) {
    FILE* file = fopen("record.txt", "r");  // Открываем файл для чтения данных (режим "r" - read)
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 0;
    }
    
    Record currentRecord;
    Record bestRecord;
    bestRecord.score = 0;

    while (fscanf(file, "%s %d", currentRecord.playerName, &currentRecord.score) == 2) {
        if (currentRecord.score > bestRecord.score) {
            bestRecord = currentRecord;  // Находим игрока с наивысшим количеством очков
        }
    }

    fclose(file);
    
    if (score > bestRecord.score) {  // Если текущий результат лучше предыдущего лучшего результата
        FILE* best_file = fopen("best.txt", "w");  // Открываем файл для записи данных (режим "w" - write)
        if (best_file == NULL) {
            printf("Ошибка при открытии файла.\n");
            return 0;
        }   
        
        fprintf(best_file, "%s %d\n", playerName, score);  // Записываем новый лучший результат в файл
        fclose(best_file);
        
        return 1;  // Возвращаем 1, чтобы указать, что рекорд побит
    } else if (score ==  bestRecord.score) {
        printf("Поздравляем, вы побили рекорд!\n");
        return 0;
    } else {
        printf("Game over\n");
        return 0;
    }
}

// Функция создания списка лучших записей в файле top5.txt
void listRecord(const char* playerName) {
    FILE* file = fopen("record.txt", "r");  // Открываем файл для чтения данных
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }
    
    Record records[100];
    int numRecords = 0;

    while (fscanf(file, "%s %d", records[numRecords].playerName, &records[numRecords].score) == 2) {
        numRecords++;
    }

    fclose(file);
    
    qsort(records, numRecords, sizeof(Record), compareRecords);  // Сортируем записи в порядке убывания количества очков
    
    FILE* top5_file = fopen("top5.txt", "w");  // Открываем файл для записи данных
    if (top5_file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }
    
    int i;
    for (i = 0; i < numRecords && i < 5; i++) {  // Записываем только 5 лучших записей или меньше, если записей меньше 5
        fprintf(top5_file, "%s %d\n", records[i].playerName, records[i].score);
    }
    
    fclose(top5_file);  // Закрываем файл
}

// Функция сравнения двух записей для сортировки
int compareRecords(const void* a, const void* b) {
    const Record* recordA = (const Record*)a;
    const Record* recordB = (const Record*)b;
    
    return recordB->score - recordA->score;  // Сравниваем записи по количеству очков в порядке убывания
}


void addRecord(const char* player_name, int score) {
    FILE* file = fopen("records.txt", "r");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    Record records[MAX_RECORDS];
    int num_records = 0;

    while (fscanf(file, "%s %d", records[num_records].playerName, &records[num_records].score) == 2) {
        num_records++;
        if (num_records >= MAX_RECORDS) {
            break;  
        }
    }

    fclose(file);  
    
    strcpy(records[num_records].playerName, player_name);
    records[num_records].score = score;
    num_records++;

   
    qsort(records, num_records, sizeof(Record), compareRecords);

    
    file = fopen("records.txt", "w");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    int i;
    for (i = 0; i < num_records && i < MAX_RECORDS; i++) {
        fprintf(file, "%s %d\n", records[i].playerName, records[i].score);
    }

    fclose(file);  
}