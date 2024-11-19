#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NUM_VERICES_FACE 4  // каждая грань состоит из 4 вершин

// структура данных obj-файла
typedef struct {
  float *dataV;  // Массив вершин)
  int **dataF;   // Массив граней
  int sumV;      // Кол-во вершин
  int sumF;      // Кол-во граней
  char filename[256];
  int flagParser;  // управление тестами
} DataObj;

extern DataObj *parserObj(char *fileName, int flagParser);
extern DataObj *initDataOBJ(int flagParser);
extern int calculateDataSizeObj(DataObj *DataOBJ);
extern int printDataOBJ(DataObj *DataOBJ);
extern int readingDataOBJ(DataObj *DataOBJ);
extern void replaceDotWithComma(char *str);
extern void freeDataOBJ(DataObj *DataOBJ);

#ifdef __cplusplus
}
#endif

#endif  // PARSER_H