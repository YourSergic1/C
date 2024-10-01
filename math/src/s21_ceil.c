#include "s21_math.h"

long double s21_ceil(double x) {  //округляем до верхнего целого
  long double result;
  if ((long double)x == s21_infm)
    result = s21_infm;
  else if ((long double)x == s21_infp)
    result = s21_infp;
  else if (x != x)
    result = -s21_nan;
  else {
    result = (long double)(long long int)x;
    if (result < x) result += 1.0;
  }

  return result;
}