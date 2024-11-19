////////////////////////////////////////////////
// Тут вычисляются данные для 3D объектов     //
// Рёбра, треугольники, вызываются методы Си, //
// связанные с трансформациями                //
////////////////////////////////////////////////

#include <QMatrix4x4>
#include <iostream>
#include <set>

#include "myopenglwidget.h"

// очистка данных obj
void MyOpenGLWidget::clearData() {
  vertices = nullptr;
  faces.clear();
  triangles.clear();
  edges.clear();
  // timer->stop();
}

// подготовка данных obj из файла
void MyOpenGLWidget::prepareDataFile(DataObj *DataOBJ) {
  clearData();
  vertices = DataOBJ->dataV;
  for (int i = 0; i < DataOBJ->sumF; ++i) {
    faces.push_back(std::vector<int>(DataOBJ->dataF[i], DataOBJ->dataF[i] + 4));
  }
  convertFacesToTriangles();
  extractEdgesFromFaces();
  vertexCount = DataOBJ->sumV;
}

// Вычисляет треугольники из поверхностей
void MyOpenGLWidget::convertFacesToTriangles() {
  for (const auto &face : faces) {
    if (face.size() == 4) {
      // Разбиваем грань на два треугольника
      triangles.push_back(face[0] - 1);  // Вершина 1 (индекс для OpenGL)
      triangles.push_back(face[1] - 1);  // Вершина 2
      triangles.push_back(face[2] - 1);  // Вершина 3

      triangles.push_back(face[0] - 1);  // Вершина 1
      triangles.push_back(face[2] - 1);  // Вершина 3
      triangles.push_back(face[3] - 1);  // Вершина 4
    }
  }
}

// Вычисляет рёбра из поверхностей, для каркасного режима
void MyOpenGLWidget::extractEdgesFromFaces() {
  std::set<std::pair<int, int>> edgeSet;

  for (const auto &face : faces) {
    for (size_t i = 0; i < face.size(); ++i) {
      int v1 = face[i] - 1;  // Корректируем индекс для OpenGL
      int v2 = face[(i + 1) % face.size()] - 1;  // Следующая вершина

      if (v1 > v2) {
        std::swap(v1, v2);
      }
      edgeSet.insert({v1, v2});  // Добавляем ребро в множество
    }
  }
  // Переносим уникальные рёбра в вектор
  edges.assign(edgeSet.begin(), edgeSet.end());
}

// Аффиново вращение
// direction - направление поворота
void MyOpenGLWidget::affineRotation(bool direction, int axis) {
  float Rot = 5.0f;
  if (!direction) {
    Rot *= -1.0f;
  }
  Matrix4x4_Affine matrix;
  Point3D localPoint;
  point3DInIt(&localPoint, localPointObj.x(), localPointObj.y(),
              localPointObj.z());

  matrixInverseTranslation(&matrix, &localPoint, 1);
  calcDataFromMatrix(&matrix, false);

  matrixRotation(&matrix, Rot, axis);
  calcDataFromMatrix(&matrix, false);

  matrixInverseTranslation(&matrix, &localPoint, 0);
  calcDataFromMatrix(&matrix, false);

  update();
}

// Аффиново масштабирование
void MyOpenGLWidget::affineScale(bool direction) {
  float scale = 1.1f;
  if (!direction) {
    scale = 0.9f;
  }
  Matrix4x4_Affine matrix;
  Point3D localPoint;
  point3DInIt(&localPoint, localPointObj.x(), localPointObj.y(),
              localPointObj.z());

  matrixInverseTranslation(&matrix, &localPoint, 1);
  calcDataFromMatrix(&matrix, false);

  matrixScale(&matrix, scale);
  calcDataFromMatrix(&matrix, false);

  matrixInverseTranslation(&matrix, &localPoint, 0);
  calcDataFromMatrix(&matrix, false);

  update();
}

// Аффиново перемещение
void MyOpenGLWidget::affineTranslation(bool direction, int axis) {
  float distance = 0.1f;
  if (!direction) {
    distance *= -1.0f;
  }
  Matrix4x4_Affine matrix;
  matrixTranslation(&matrix, distance, axis);
  calcDataFromMatrix(&matrix, false);
  localPointCalc(distance, axis);
  update();
}

// Вычисление данных по матрице
// Объект point хранит 3 координаты для одной точки
// Беру оп три числа из массива точек 3D объекта и формирую point
// Потом умножаю point на матрицу преобразования
// Потом извлекаю данные из point и возвращаю их в массив вершин
void MyOpenGLWidget::calcDataFromMatrix(Matrix4x4_Affine *matrix, bool Debug) {
  float x = 0;
  float y = 0;
  float z = 0;

  if (Debug) {
    qDebug() << "vertexCount" << vertexCount;
    matrixPrint(matrix);
  }

  Point3D point;
  for (int i = 0; i < vertexCount; i++) {
    int iv = i * 3;  // по 3 числа на вершину
    x = vertices[iv];
    y = vertices[iv + 1];
    z = vertices[iv + 2];
    point3DInIt(&point, x, y, z);
    if (Debug) point3DPrint(&point);
    multiplyMatrixVector(matrix, &point);
    if (Debug) point3DPrint(&point);
    vertices[iv] = point.x;
    vertices[iv + 1] = point.y;
    vertices[iv + 2] = point.z;
  }
}