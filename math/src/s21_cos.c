#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 0;
  if (x == s21_infm || x == s21_infp || x != x)
    result = -s21_nan;
  else {
    result = s21_sin(s21_pi / 2 - x);
  }
  return result;
}