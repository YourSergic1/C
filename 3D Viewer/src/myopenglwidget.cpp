#include "myopenglwidget.h"

#include <QMatrix4x4>
#include <iostream>
#include <set>

MyOpenGLWidget::MyOpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), rotationAngle(0.0f) {
  lastFrameTime.start();  // Засекаем время начала первого кадра

  // Создаем таймер для обновления угла поворота
  timer = new QTimer(this);

  // создаём сигнал от таймера
  connect(timer, &QTimer::timeout, this, [this]() {
    update();  // Перерисовываем виджет
  });
  timer->start(16);  // Запускаем таймер с интервалом 16 мс (примерно 60 FPS)

  // по умолчанию перспективная проекция
  isPerspecProj = true;
}

MyOpenGLWidget::~MyOpenGLWidget() {}

// инициализация OpenGL
void MyOpenGLWidget::initializeGL() {
  initializeOpenGLFunctions();
  glClearColor(bg_red / 255, bg_green / 255, bg_blue / 255, 1);

  // render init
  glEnable(GL_LIGHTING);  // Включаем освещение
  glEnable(GL_LIGHT0);  // Включаем первый источник света
  glEnable(GL_DEPTH_TEST);  // Включаем тест глубины для корректного отображения

#ifdef OS_LINUX
  printf("OS_LINUX\n");
  openFileObj(false);  // загружаю obj по умолчанию
#endif
}

// при изменении размера OpenGL
void MyOpenGLWidget::resizeGL(int w, int h) {
  // Обновляем размеры окна
  glViewport(0, 0, w, h);

  // // Обновляем проекционную матрицу
  // QMatrix4x4 projection;
  // float aspectRatio = static_cast<float>(w) / static_cast<float>(h);
  // projection.ortho(-aspectRatio, aspectRatio, -1.0f, 1.0f, 0.1f, 100.0f);
  // glMatrixMode(GL_PROJECTION);
  // glLoadMatrixf(projection.constData());
}

// рисуем кадр
void MyOpenGLWidget::paintGL() {
  glClearColor(bg_red / 255, bg_green / 255, bg_blue / 255, 1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Установка проекционной матрицы
  QMatrix4x4 projection;
  if (isPerspecProj) {
    projection.perspective(45.0f, (float)width() / (float)height(), 0.1f,
                           100.0f);
  } else {
    projection.ortho(-2.0f, 2.0f, -2.0f, 2.0f, 0.1f, 100.0f);
  }
  glMatrixMode(GL_PROJECTION);
  glLoadMatrixf(projection.constData());

  // Установка моделирования-вида матрицы
  QMatrix4x4 modelview;
  modelview.lookAt(
      QVector3D(0.0f, 0.0f, 5.0f),  // Камера находится в (0, 0, 5)
      QVector3D(0.0f, 0.0f, 0.0f),  // Направлена в точку (0, 0, 0)
      QVector3D(0.0f, 1.0f, 0.0f));  // Верх камеры направлен вверх (0, 1, 0)
  glMatrixMode(GL_MODELVIEW);
  glLoadMatrixf(modelview.constData());

  // Вычисляем время, прошедшее между кадрами
  qint64 elapsedTime = lastFrameTime.nsecsElapsed();
  lastFrameTime.restart();

  // если включен автоповорот
  if (isAutoRotating) {
    // Обновляем угол поворота на основе прошедшего времени
    // Увеличиваем угол поворота на 0.1 градуса за миллисекунду
    rotationAngle += elapsedTime * 0.0000001f;
    if (rotationAngle > 360.0f) {
      rotationAngle -= 360.0f;  // Обнуляем угол, если он превышает 360 градусов
    }
  }
  rotationWithQt();
  lightInIt();
  drawWorldAxes();
  // localPointCalc();
  drawObjectAxes();

  // Отрисовка рёбер
  if (drawEdges > 0) {
    glDisable(GL_LIGHTING);  // Временно отключаем освещение
    glLineWidth(lineWidth);  // Устанавливаем толщину ребер
    if (drawEdges == 2) {
      glEnable(GL_LINE_STIPPLE);  // Штриховая линия
      glLineStipple(1, 0x00FF);  // Пример штрихового шаблона
    }
    glBegin(GL_LINES);
    glColor3f(edge_red / 255, edge_green / 255, edge_blue / 255);  // цвет
    for (const auto &edge : edges) {
      glVertex3fv(&vertices[edge.first * 3]);   // Индекс для OpenGL
      glVertex3fv(&vertices[edge.second * 3]);  // Индекс для OpenGL
    }
    glEnd();
    if (drawEdges == 2) {
      glDisable(GL_LINE_STIPPLE);  // Отключение штриховой линии
    }
    glEnable(GL_LIGHTING);  // Включаем освещение обратно
  }

  // Отрисовка граней
  if (drawFace) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(GLfloat) * 3, vertices);
    glDrawElements(GL_TRIANGLES, triangles.size(), GL_UNSIGNED_INT,
                   &triangles[0]);

    glDisableClientState(GL_VERTEX_ARRAY);
  }

  // Отрисовка вершин
  if (drawVertices == 1) {
    glDisable(GL_LIGHTING);  // Временно отключаем освещение
    glPointSize(radiusPoint);  // Устанавливаем размер точек
    glBegin(GL_POINTS);
    // GLfloat colorPoint[] = {1.0f, 0.0f, 0.0f};  // Красный цвет
    // glColor3f(colorPoint[0], colorPoint[1], colorPoint[2]);  // Красный цвет
    // для вершин
    glColor3f(vertex_red / 255, vertex_green / 255,
              vertex_blue / 255);  // Устанавливаем цвет круга (красный)
    for (int i = 0; i < vertexCount * 3; i += 3) {
      glVertex3f(vertices[i], vertices[i + 1], vertices[i + 2]);
    }
    glEnd();
    glEnable(GL_LIGHTING);  // Включаем освещение обратно
  }

  // Отрисовка окружностей
  if (drawVertices == 2) {
    float radius = radiusPoint / 300.0f;  // Радиус круга
    int numSegments = 10;  // Количество сегментов круга (больше = круглее)

    glDisable(GL_LIGHTING);  // Временно отключаем освещение
    glColor3f(vertex_red / 255, vertex_green / 255,
              vertex_blue / 255);  // Устанавливаем цвет круга (красный)

    for (int i = 0; i < vertexCount * 3; i += 3) {
      float cx = vertices[i];      // X координата вершины
      float cy = vertices[i + 1];  // Y координата вершины
      float cz = vertices[i + 2];  // Z координата вершины

      // Рисуем круг как полигон вокруг текущей вершины
      glBegin(GL_POLYGON);
      for (int j = 0; j < numSegments; j++) {
        float angle = 2.0f * 3.14159f * j / numSegments;
        float x = cx + cos(angle) * radius;
        float y = cy + sin(angle) * radius;
        glVertex3f(x, y, cz);  // Используем glVertex3f для 3D
      }
      glEnd();
    }
    glEnable(GL_LIGHTING);  // Включаем освещение обратно
  }
}

void MyOpenGLWidget::toggleAutoRotation() {
  isAutoRotating = !isAutoRotating;
  if (isAutoRotating) {
    qDebug() << "Starting auto-rotation.";
    timer->start(16);  // Запускаем таймер с интервалом 16 мс (примерно 60 FPS)
  } else {
    qDebug() << "Stopping auto-rotation.";
    timer->stop();  // Останавливаем таймер
  }
}

// Переключаем состояние отрисовки
void MyOpenGLWidget::toggleDrawMode() {
  drawFace = !drawFace;
  update();
}

// запускает парсер на Си из parser.h
// filePath - путь к файлу
int MyOpenGLWidget::parser(char *filePath) {
  qDebug() << "DEBUG C++: parser c++ on";
  DataObj *DataOBJ = parserObj(filePath, 0);
  prepareDataFile(DataOBJ);
  localPointObj.setX(0.0f);
  localPointObj.setY(0.0f);
  localPointObj.setZ(0.0f);
  EulerAxis.setX(0.0f);
  EulerAxis.setY(0.0f);
  EulerAxis.setZ(0.0f);
  // freeDataOBJ(DataOBJ); // очищаем данные Си
  return 0;
}

// открыть файл obj
// openFileDialog = true если нужно открыть, иначе
// читаем файл по умолчанию
void MyOpenGLWidget::openFileObj(bool openFileDialog) {
  bool flagLoad = false;
  timer->stop();
  QString filePathTMP = filePath;

  if (openFileDialog) {
    filePath = QFileDialog::getOpenFileName(
        this, "Выберите файл", QDir::currentPath(), "OBJ Files (*.obj)");

    // Проверяем, был ли выбран файл
    if (!filePath.isEmpty()) {
      qDebug() << "Выбранный файл:" << filePath;
      flagLoad = true;
    } else {
      qDebug() << "Файл не выбран";
      filePath = filePathTMP;
    }
  } else {
    filePath = DEFAULT_PATH_OBJ;
    flagLoad = true;
  }

  if (flagLoad) {
    // Преобразуем QString в char*
    QByteArray byteArray = filePath.toLocal8Bit();
    char *filePathChar = byteArray.data();
    parser(filePathChar);
  }
  showMessageStatusBar();
  timer->start(16);
}

// Установка указателя на QStatusBar
void MyOpenGLWidget::setStatusBar(QStatusBar *statusBar) {
  this->statusBar = statusBar;
}

// отображает сообщение в statusBar
void MyOpenGLWidget::showMessageStatusBar() {
  QString mess = "Файл: " + filePath;
  statusBar->showMessage(mess);
}

// Вращение средствами Qt C++
void MyOpenGLWidget::rotationWithQt() {
  QMatrix4x4 rotation;  // "пустая" матрица вращения
  // Вращение вокруг оси (1, 1, 1)
  // преобразование матрицы вращения
  rotation.rotate(rotationAngle, 1.0f, 1.0f, 1.0f);
  // Применение матрицы поворота к моим вершинам
  glMultMatrixf(rotation.constData());

  // affineRotation(false, 1);
}

// Настройки источника света
void MyOpenGLWidget::lightInIt() {
  // Позиция света (включая w=1 для точечного света)
  GLfloat lightPosition[] = {0.0f, 5.0f, 5.0f, 1.0f};
  GLfloat lightColor[] = {1.0f, 1.0f, 1.0f, 1.0f};  // Цвет света (белый)

  glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);  // Диффузный цвет
  glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);  // Спекулярный цвет

  // Настройки материала (если нужно)
  // Диффузный цвет материала
  GLfloat materialDiffuse[] = {1.0f, 0.5f, 0.5f, 1.0f};
  // Спекулярный цвет материала
  GLfloat materialSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
  GLfloat materialShininess[] = {50.0f};  // Шероховатость материала

  glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, materialDiffuse);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, materialSpecular);
  glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, materialShininess);
}

// рисовать мировые оси
void MyOpenGLWidget::drawWorldAxes() {
  glDisable(GL_LIGHTING);  // Временно отключаем освещение

  // Отрисовка линию по оси X
  glBegin(GL_LINES);
  glColor3f(1.0f, 0.0f, 0.0f);   // Красный цвет для линии
  glVertex3f(0.0f, 0.0f, 0.0f);  // Начальная точка
  glVertex3f(0.5f, 0.0f, 0.0f);  // Конечная точка
  glEnd();
  // Отрисовка линию по оси Y
  glBegin(GL_LINES);
  glColor3f(0.0f, 1.0f, 0.0f);   // Зелёный цвет для линии
  glVertex3f(0.0f, 0.0f, 0.0f);  // Начальная точка
  glVertex3f(0.0f, 0.5f, 0.0f);  // Конечная точка
  glEnd();
  // Отрисовка линию по оси Z
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f);   // Синий цвет для линии
  glVertex3f(0.0f, 0.0f, 0.0f);  // Начальная точка
  glVertex3f(0.0f, 0.0f, 0.5f);  // Конечная точка
  glEnd();

  glEnable(GL_LIGHTING);  // Включаем освещение обратно
}

// вычисления центра объекта
void MyOpenGLWidget::localPointCalc(float distance, int axis) {
  float tmp;
  if (axis == 1) {
    tmp = localPointObj.x();
    tmp += distance;
    localPointObj.setX(tmp);
  }
  if (axis == 2) {
    tmp = localPointObj.y();
    tmp += distance;
    localPointObj.setY(tmp);
  }
  if (axis == 3) {
    tmp = localPointObj.z();
    tmp += distance;
    localPointObj.setZ(tmp);
  }
}

// рисовать центр объекта
void MyOpenGLWidget::drawObjectAxes() {
  glDisable(GL_LIGHTING);  // Временно отключаем освещение

  // Отрисовка точки в центре объекта
  glPointSize(5.0f);  // Устанавливаем размер точки
  glBegin(GL_POINTS);
  glColor3f(1.0f, 1.0f, 0.0f);  // Красный цвет для точки
  glVertex3f(localPointObj.x(), localPointObj.y(), localPointObj.z());
  glEnd();

  glEnable(GL_LIGHTING);  // Включаем освещение обратно
}

void MyOpenGLWidget::setBackgroundColor(float red, float green, float blue) {
  // Обновляем значения переменных цвета фона
  bg_red = red;
  bg_green = green;
  bg_blue = blue;
  update();
}

void MyOpenGLWidget::setEdgeColor(float red, float green, float blue) {
  edge_red = red;
  edge_green = green;
  edge_blue = blue;
  update();
}

void MyOpenGLWidget::setVertexColor(float red, float green, float blue) {
  vertex_red = red;
  vertex_green = green;
  vertex_blue = blue;
  update();
}
