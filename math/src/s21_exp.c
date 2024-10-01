#include "s21_math.h"

long double s21_exp(double x) {
  long double sum = 1;
  long double term = 1;
  if (x != x)
    sum = -s21_nan;
  else if (x == s21_infm)
    sum = 0;
  else if (x == s21_infp)
    sum = s21_infp;
  else {
    if (x < 0)
      sum = 1.0 / s21_exp(-x);
    else {
      for (int i = 1; i < 500; i++) {
        term *= x / i;
        sum += term;
      }
    }
  }
  return sum;
}