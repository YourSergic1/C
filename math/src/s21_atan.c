#include "s21_math.h"

long double s21_atan(double x) {
  long double itog = 0.0;
  if (x == 1.0)
    itog = s21_pi / 4;
  else if (x == -1.0)
    itog = -s21_pi / 4;
  else if (x == 0.0)
    itog = 0.0;
  else if (x == s21_infp)
    itog = s21_pi / 2;
  else if (x == s21_infm)
    itog = -s21_pi / 2;
  else if (x != x)
    itog = s21_nan;
  else if (x > -1 && x < 1) {
    for (int i = 0; i < 500; i++) {
      itog += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i);
    }
  } else {
    for (int i = 0; i < 500; i++) {
      itog += (s21_pow(-1, i) * s21_pow(x, -(1 + 2 * i))) / (1 + 2 * i);
    }
    itog = ((s21_pi * s21_sqrt(s21_pow(x, 2))) / (2 * x)) - itog;
  }
  return itog;
}