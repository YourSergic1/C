#include "s21_math.h"

long double s21_log(double x) {
  int ex_pow = 0;
  long double result = 0;
  long double compare = 0;
  if (x == 0)
    result = s21_infm;
  else if (x == s21_infp)
    result = s21_infp;
  else if (x < 0)
    result = s21_nan;
  else {
    for (; x >= s21_e; x /= s21_e, ex_pow++) continue;
    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return result + ex_pow;
}