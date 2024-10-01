#include "s21_math.h"

int s21_abs(int x) {  //модуль числа
  if (x < 0) {
    x = x * (-1);
  }
  return x;
}