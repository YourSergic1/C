#include "affine_transform.h"

// инициирует единичную матрицу 4х4
void matrixInIt(Matrix4x4_Affine *matrix) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix->m[i][j] = (i == j) ? 1.0f : 0.0f;
    }
  }
}

// печатает матрицу
void matrixPrint(Matrix4x4_Affine *matrix) {
  printf("Matrix:\n");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%+.6f ", matrix->m[i][j]);
    }
    printf("\n");
  }
}

// Преобразует матрицу в матрицу поворота
// *matrix - указатель на матрицу болванку
// axis - ось вращения, x y z
// angle - угол поворота в градусах
// Подставляет в нужные места матрицы нужные значения cos и sin
void matrixRotation(Matrix4x4_Affine *matrix, float angle, int axis) {
  angle = angle * (3.14159265358979323846 / 180.f);  // в радианы

  float c = cosf(angle);
  float s = sinf(angle);

  matrixInIt(matrix);

  // Аффиново преобразование
  switch (axis) {
    case 1:
      // поворот по X
      matrix->m[1][1] = c;
      matrix->m[1][2] = -s;
      matrix->m[2][1] = s;
      matrix->m[2][2] = c;
      break;
    case 2:
      // поворот по Y
      matrix->m[0][0] = c;
      matrix->m[0][2] = s;
      matrix->m[2][0] = -s;
      matrix->m[2][2] = c;
      break;
    case 3:
      // поворот по Z
      matrix->m[0][0] = c;
      matrix->m[0][1] = -s;
      matrix->m[1][0] = s;
      matrix->m[1][1] = c;
      break;
  }
}

// Преобразует матрицу в матрицу перемещения
// Подставляет смещение в последнюю колонку матрицы
void matrixTranslation(Matrix4x4_Affine *matrix, float distance, int axis) {
  matrixInIt(matrix);

  // Аффиново преобразование
  switch (axis) {
    case 1:
      // перемещенеи по X
      matrix->m[0][3] = distance;
      break;
    case 2:
      // перемещенеи по Y
      matrix->m[1][3] = distance;
      break;
    case 3:
      // перемещенеи по Z
      matrix->m[2][3] = distance;
      break;
  }
}

// // Преобразует матрицу в матрицу масштаба
// void matrixScale(Matrix4x4_Affine *matrix, float distance, int axis) {
//   matrixInIt(matrix);

//   // Аффиново преобразование
//   switch (axis) {
//     case 1:
//       // масштаб по X
//       matrix->m[0][0] = distance;
//       break;
//     case 2:
//       // масштаб по Y
//       matrix->m[1][1] = distance;
//       break;
//     case 3:
//       // масштаб по Z
//       matrix->m[2][2] = distance;
//       break;
//   }
// }

// Преобразует матрицу в матрицу масштаба
// Аффиново масштабирование
void matrixScale(Matrix4x4_Affine *matrix, float scale) {
  matrixInIt(matrix);
  matrix->m[0][0] = scale;
  matrix->m[1][1] = scale;
  matrix->m[2][2] = scale;
}

// Матрица обратного переноса
// Перед и после вращения, смещает опорную точку объекта в центр мира.
// localPoint - опорная точка
// inverse - направление обратного перехода
void matrixInverseTranslation(Matrix4x4_Affine *matrix, Point3D *localPoint,
                              int inverse) {
  matrixInIt(matrix);

  float xTmp = localPoint->x;
  float yTmp = localPoint->y;
  float zTmp = localPoint->z;

  if (inverse) {
    xTmp *= -1;
    yTmp *= -1;
    zTmp *= -1;
  }

  matrix->m[0][3] = xTmp;
  matrix->m[1][3] = yTmp;
  matrix->m[2][3] = zTmp;
}

// Инициирует вершину
void point3DInIt(Point3D *point, float x, float y, float z) {
  point->x = x;
  point->y = y;
  point->z = z;
}

// Печатает вершину
void point3DPrint(Point3D *point) {
  printf("point3D %+.6f %+.6f %+.6f\n", point->x, point->y, point->z);
}

// умножает матрицу на вектор (вершину)
void multiplyMatrixVector(Matrix4x4_Affine *matrix, Point3D *point) {
  float x_po = point->x;
  float y_po = point->y;
  float z_po = point->z;
  float x_tmp;
  float y_tmp;
  float z_tmp;

  x_tmp = matrix->m[0][0] * x_po + matrix->m[0][1] * y_po +
          matrix->m[0][2] * z_po + matrix->m[0][3];
  y_tmp = matrix->m[1][0] * x_po + matrix->m[1][1] * y_po +
          matrix->m[1][2] * z_po + matrix->m[1][3];
  z_tmp = matrix->m[2][0] * x_po + matrix->m[2][1] * y_po +
          matrix->m[2][2] * z_po + matrix->m[2][3];

  point->x = x_tmp;
  point->y = y_tmp;
  point->z = z_tmp;
}