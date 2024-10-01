#include "s21_math.h"

long double s21_fmod(double x, double y) {  //остаток от деления х на у
  long double result = 0;
  long double fmod_x = x;
  long double fmod_y = y;
  long long int div = 0;
  if (fmod_y == 0 || fmod_x == s21_infm || fmod_x == s21_infp)
    result = -s21_nan;
  else if (fmod_y == s21_infm || fmod_y == s21_infp)
    result = fmod_x;
  else {
    div = fmod_x / fmod_y;
    result = fmod_x - div * fmod_y;
  }
  return result;
}