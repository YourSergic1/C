#include "parser.h"

// инициализация структуры для хранения данных из OBJ
DataObj *initDataOBJ(int flagParser) {
  DataObj *DataOBJ = (DataObj *)malloc(sizeof(DataObj));
  DataOBJ->dataV = NULL;
  DataOBJ->dataF = NULL;
  DataOBJ->sumV = 0;
  DataOBJ->sumF = 0;
  DataOBJ->flagParser = 0;

#ifdef OS_MAC
  flagParser = 1;
  printf("OS_MAC\n");
#endif

  if (flagParser) {
    DataOBJ->flagParser = 1;
  }
  return DataOBJ;
}

// Парсит файл OBJ
// Принимает строку с файлом OBJ
// flagParser - разделение логики на Си и С++ для тестов
// для тестов flagParser = 1
DataObj *parserObj(char *fileName, int flagParser) {
  printf("DEBUG C: parser C on\n");
  DataObj *DataOBJ = initDataOBJ(flagParser);
  strcpy(DataOBJ->filename, fileName);
  calculateDataSizeObj(DataOBJ);
  readingDataOBJ(DataOBJ);
  // printDataOBJ(DataOBJ);
  return DataOBJ;
}

// Расчёт размера данных
// и выделение памяти
int calculateDataSizeObj(DataObj *DataOBJ) {
  FILE *file = fopen(DataOBJ->filename, "r");
  if (file == NULL) {
    perror("Ошибка открытия файла");
    return 1;
  }

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    // Проверяем, начинается ли строка с 'v' или 'f'
    if (line[0] == 'v') {
      DataOBJ->sumV++;
    } else if (line[0] == 'f') {
      DataOBJ->sumF++;
    }
  }
  fclose(file);

  // Выделяем память для вершин и граней
  DataOBJ->dataV = (float *)malloc(DataOBJ->sumV * 3 * sizeof(float));
  DataOBJ->dataF = (int **)malloc(DataOBJ->sumF * sizeof(int *));
  for (int i = 0; i < DataOBJ->sumF; i++) {
    DataOBJ->dataF[i] = (int *)malloc(NUM_VERICES_FACE * sizeof(int));
  }

  return 0;
}

// Печатает данные из файла
extern int printDataOBJ(DataObj *DataOBJ) {
  printf("Вершины:\n");
  for (int i = 0; i < DataOBJ->sumV; i++) {
    float x, y, z = 0;
    x = DataOBJ->dataV[i * 3];
    y = DataOBJ->dataV[i * 3 + 1];
    z = DataOBJ->dataV[i * 3 + 2];
    printf("v %+f %+f %+f\n", x, y, z);
  }
  printf("Грани:\n");
  for (int i = 0; i < DataOBJ->sumF; i++) {
    int f1, f2, f3, f4;
    f1 = DataOBJ->dataF[i][0];
    f2 = DataOBJ->dataF[i][1];
    f3 = DataOBJ->dataF[i][2];
    f4 = DataOBJ->dataF[i][3];
    printf("f %d %d %d %d\n", f1, f2, f3, f4);
  }

  printf("ИТОГО ======================\n");
  printf("Вершин = %d\n", DataOBJ->sumV);
  printf("Поверхностей = %d\n", DataOBJ->sumF);
  return 0;
}

// читает данные из файла
int readingDataOBJ(DataObj *DataOBJ) {
  FILE *file = fopen(DataOBJ->filename, "r");
  if (file == NULL) {
    perror("Ошибка открытия файла");
    return 1;
  }

  int vertexIndex = 0;
  int faceIndex = 0;

  char line[256];
  while (fgets(line, sizeof(line), file)) {
    // Проверяем, начинается ли строка с 'v' или 'f'
    if (line[0] == 'v') {
      if (!DataOBJ->flagParser) {
        replaceDotWithComma(line);
      }

      float x = 0, y = 0, z = 0;
      // Извлекаем три числа из строки
      if (sscanf(line, "v %f %f %f", &x, &y, &z) == 3) {
        DataOBJ->dataV[vertexIndex * 3] = x;
        DataOBJ->dataV[vertexIndex * 3 + 1] = y;
        DataOBJ->dataV[vertexIndex * 3 + 2] = z;
        vertexIndex++;
      } else {
        printf("Ошибка парсинга строки v: %s", line);
      }
    } else if (line[0] == 'f') {
      int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
      // Извлекаем четыре числа из строки
      if (sscanf(line, "f %d %d %d %d", &v1, &v2, &v3, &v4) == 4) {
        DataOBJ->dataF[faceIndex][0] = v1;
        DataOBJ->dataF[faceIndex][1] = v2;
        DataOBJ->dataF[faceIndex][2] = v3;
        DataOBJ->dataF[faceIndex][3] = v4;
        faceIndex++;
      } else {
        printf("Ошибка парсинга строки f\n");
      }
    }
  }

  fclose(file);
  return 0;
}

// Замена точки на запятую в строке
// нужно для функции в парсинге sscanf()
void replaceDotWithComma(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '.') {
      str[i] = ',';
    }
  }
}

// Освобождение памяти
void freeDataOBJ(DataObj *DataOBJ) {
  if (DataOBJ->dataV != NULL) {
    free(DataOBJ->dataV);
  }
  if (DataOBJ->dataF != NULL) {
    for (int i = 0; i < DataOBJ->sumF; i++) {
      free(DataOBJ->dataF[i]);
    }
    free(DataOBJ->dataF);
  }
  free(DataOBJ);
}
