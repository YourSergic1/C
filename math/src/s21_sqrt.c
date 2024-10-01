#include "s21_math.h"

long double s21_sqrt(double x) {
  long double sqrt_x = x;
  long double left = 0;
  long double right = x;
  long double result = 0;
  if (sqrt_x < 0) {
    result = s21_nan;
  } else if (sqrt_x == 0) {
    result = 0;
  } else if (sqrt_x == 1) {
    result = 1;
  } else if (sqrt_x == s21_infm) {
    result = s21_infm;
  } else if (sqrt_x == s21_infp) {
    result = s21_infp;
  } else {
    if (sqrt_x < 1) right = 1;
    result = (left + right) / 2;
    while (result - left > s21_eps) {
      if (result * result > sqrt_x)
        right = result;
      else
        left = result;
      result = (left + right) / 2;
    }
  }
  return result;
}