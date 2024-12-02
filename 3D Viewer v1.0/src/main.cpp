#include <QApplication>
#include <QDebug>

#include "mainwindow.h"
#include "simple.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  int result = add_two_numbers(5, 7);
  qDebug() << "Test C:" << result;

  return a.exec();
}
