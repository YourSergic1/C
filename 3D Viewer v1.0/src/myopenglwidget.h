#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QByteArray>
#include <QElapsedTimer>
#include <QFileDialog>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QStatusBar>
#include <QTimer>
#include <QVector3D>
#include <utility>  // Для std::pair
#include <vector>

#include "affine_transform.h"
#include "parser.h"  // парсер на Си

#define DEFAULT_PATH_OBJ "obj/Cube.obj"

class MyOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
 public:
  explicit MyOpenGLWidget(QWidget *parent = nullptr);
  ~MyOpenGLWidget() override;
  void setStatusBar(QStatusBar *statusBar);
  void setBackgroundColor(float red, float green, float blue);
  void setEdgeColor(float red, float green, float blue);
  void setVertexColor(float red, float green, float blue);
  double bg_red = 51, bg_green = 51, bg_blue = 51;
  double edge_red = 255, edge_green = 255, edge_blue = 0;
  double vertex_red = 255, vertex_green = 0, vertex_blue = 0;

  // Режимы отрисовки
  int drawEdges = 1;  // выбора отрисовки рёбра/грани
  int drawVertices = 0;   // отрисовка вершин
  bool drawFace = false;  // отрисовка граней
  bool isPerspecProj = true;  // перспективная/ортогональная проекция
  bool isAutoRotating = false;

  float radiusPoint = 8.0f;  // радиус вспомогательных точек
  float lineWidth = 1.0f;  // толщина линий

 protected:
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;

 private:
  QElapsedTimer lastFrameTime;
  float rotationAngle;
  QString filePath;  // путь к файлу
  QTimer *timer;
  QStatusBar *statusBar;  // для передачи сообщений на statusBar
  QVector3D localPointObj;  // для обратного переноса
  QVector3D EulerAxis;      // повороты Эйлера

  // данные объектов openGL
  GLfloat *vertices = nullptr;             // вершины
  std::vector<std::vector<int>> faces;     // грани
  std::vector<int> triangles;              // треугольники
  std::vector<std::pair<int, int>> edges;  // рёбра
  int vertexCount;  // кол-во данных о вершинах

  void convertFacesToTriangles();
  void extractEdgesFromFaces();
  void clearData();
  int parser(char *filePath);
  void showMessageStatusBar();
  // void generatePoint3D();
  void calcDataFromMatrix(Matrix4x4_Affine *matrix, bool Debug);
  void drawWorldAxes();
  void rotationWithQt();
  void lightInIt();
  void localPointCalc(float distance, int axis);
  void drawObjectAxes();  // тестовый

 public slots:
  void toggleAutoRotation();
  void toggleDrawMode();
  void prepareDataFile(DataObj *DataOBJ);
  void openFileObj(bool openFileDialog);
  // void rot();
  void affineRotation(bool direction, int axis);
  void affineTranslation(bool direction, int axis);
  void affineScale(bool direction);
  void switchisPerspecProj();
  void switchDashedLine();
  void switchDrawVerices();
  void switchRadiusPoint(bool dir);
  void switchSizeLine(bool dir);
};

#endif  // MYOPENGLWIDGET_H
