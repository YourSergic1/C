#ifndef AFFINE_TRANSFORM_H
#define AFFINE_TRANSFORM_H

#include <math.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

// матрица для аффиновых преобразований
typedef struct {
  float m[4][4];
} Matrix4x4_Affine;

// вершина
typedef struct {
  float x, y, z;
} Point3D;

extern void matrixInIt(Matrix4x4_Affine *matrix);
extern void matrixPrint(Matrix4x4_Affine *matrix);
extern void matrixRotation(Matrix4x4_Affine *matrix, float angle, int axis);
extern void matrixTranslation(Matrix4x4_Affine *matrix, float distance,
                              int axis);
extern void matrixScale(Matrix4x4_Affine *matrix, float scale);
extern void matrixInverseTranslation(Matrix4x4_Affine *matrix,
                                     Point3D *localPoint, int inverse);
extern void point3DInIt(Point3D *point, float x, float y, float z);
extern void point3DPrint(Point3D *point);
extern void multiplyMatrixVector(Matrix4x4_Affine *matrix, Point3D *point);

#ifdef __cplusplus
}
#endif

#endif  // AFFINE_TRANSFORM_H