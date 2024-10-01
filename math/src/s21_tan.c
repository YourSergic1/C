#include "s21_math.h"

long double s21_tan(double x) {
  long double result = 0;
  if (x == s21_infm || x == s21_infp)
    result = -s21_nan;
  else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}