#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  if (x == s21_infm || x == s21_infp || x != x)
    result = -s21_nan;
  else {
    x = s21_fmod(x, 2 * s21_pi);
    if (x < 0) x += 2 * s21_pi;
    long double taylor_row = x;
    int i = 1;
    while (s21_fabs(taylor_row) > s21_eps) {
      result = result + taylor_row;
      taylor_row = taylor_row * (-1) * (x * x) / ((2 * i + 1) * (2 * i));
      i++;
    }
  }
  return result;
}