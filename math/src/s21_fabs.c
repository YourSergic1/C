#include "s21_math.h"

long double s21_fabs(double x) {  //тоже что и абс
  long double x_lf = x;
  if (x_lf != x_lf)
    x_lf *= -1;
  else if (x_lf < 0) {
    x_lf = -x_lf;
  }
  return x_lf;
}