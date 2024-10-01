#include "s21_math.h"

long double s21_acos(double x) {
  long double res = 0;
  if (s21_fabs(x) < s21_eps)
    res = s21_pi / 2;
  else if (x == 1.0)
    res = 0;
  else if (x == -1.0)
    res = s21_pi;
  else if (x != x)
    res = -s21_nan;
  else if (x == s21_infp || x == s21_infm)
    res = -s21_nan;
  else if (x > 0 && x < 1)
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  else if (x > -1 && x < 0)
    res = s21_pi + s21_atan(s21_sqrt(1 - x * x) / x);
  else
    res = s21_nan;

  return res;
}