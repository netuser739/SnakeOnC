#ifndef GAME_RECORDS_H
#define GAME_RECORDS_H
// Структура для хранения рекорда
typedef struct {
    char playerName[15];
    int score;
}Record;

/*
 * saveRecord - функция для сохранения нового рекорда в файл
 * @newRecord: рекорд для сохранения (имя пользователя и счет)
 *
 * Функция сохраняет новый рекорд в файл records.txt. Каждый новый рекорд добавляется в конец файла.
 */
void saveRecord(Record newRecord);

/*
 * bestRecord - функция для сохранения наилучшего рекорда в файл
 *
 * Функция считывает все рекорды из файла records.txt, находит рекорд с наибольшим счетом и
 * сохраняет его в файл best_record.txt. Если файл best_record.txt уже существует, его содержимое заменяется.
 */
void bestRecord();

/*
 * listRecord - функция для сохранения 5 лучших рекордов в файл
 *
 * Функция считывает все рекорды из файла records.txt, сортирует их по убыванию счета и
 * сохраняет 5 лучших рекордов в файл top5_records.txt. Если файл top5_records.txt уже существует,
 * его содержимое заменяется.
 */
void listRecord();

#endif //GAME_RECORDS_H