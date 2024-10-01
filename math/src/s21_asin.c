#include "s21_math.h"

long double s21_asin(double x) {
  long double res = 0;
  if (s21_fabs(x) < s21_eps) res = 0;
  if (x == 1.0) res = s21_pi / 2;
  if (x == -1.0) res = -s21_pi / 2;
  if (x == s21_infp) res = s21_pi / 2;
  if (x == s21_infm) res = -s21_pi / 2;
  if (x < -1.0 || x > 1.0)
    res = s21_nan;
  else {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  }
  return res;
}