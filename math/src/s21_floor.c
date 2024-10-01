#include "s21_math.h"

long double s21_floor(double x) {  //округляем до нижнего целого
  long double result = (long double)(int)x;
  if ((long double)x == s21_infm)
    result = s21_infm;
  else if ((long double)x == s21_infp)
    result = s21_infp;
  else if (x != x)
    result = -s21_nan;
  else if (result > x) {
    result -= 1.0;
  }
  return (result);
}