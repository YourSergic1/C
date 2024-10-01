#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double itog = 0;
  long double copy_base = base;
  long double copy_exp = exp;
  if ((copy_exp == 1 || copy_exp == -1) && copy_base != copy_base)
    itog = s21_nan;
  else if (copy_base != copy_base &&
           (copy_exp == s21_infm || copy_exp == s21_infp))
    itog = s21_nan;
  else if (copy_base == 1)
    itog = 1;
  else if (copy_exp != copy_exp)
    itog = -s21_nan;
  else if (copy_base == 0 && (copy_exp == 0))
    itog = 1;
  else if (copy_base == 0 && (copy_exp == s21_infm))
    itog = s21_infp;
  else if (copy_base == 0 && (copy_exp == s21_infp))
    itog = 0;
  else if (copy_base == 0 && (copy_exp > 0))
    itog = 0;
  else if (copy_base == 0 && (copy_exp < 0))
    itog = s21_infp;
  else if (copy_base == -1 && (copy_exp == s21_infm || copy_exp == s21_infp))
    itog = 1;
  else if (copy_base == -1 && (copy_exp - (int)copy_exp != 0))
    itog = s21_nan;
  else if (copy_base < 0 && copy_base != s21_infm &&
           (copy_exp - (int)copy_exp != 0) && copy_exp != s21_infm &&
           copy_exp != s21_infp)
    itog = s21_nan;
  else if (copy_exp == 0 && (copy_base != copy_base || copy_base == s21_infm ||
                             copy_base == s21_infp))
    itog = 1;
  else if (copy_exp == s21_infm) {
    if (copy_base < -1 || copy_base > 1)
      itog = 0;
    else
      itog = s21_infp;
  } else if (copy_exp == s21_infp) {
    if (copy_base < -1 || copy_base > 1)
      itog = s21_infp;
    else
      itog = 0;
  } else if (copy_base == s21_infp && (copy_exp == s21_infp || copy_exp > 0))
    itog = s21_infp;
  else if (copy_base == s21_infp && (copy_exp == s21_infm || copy_exp < 0))
    itog = 0;
  else if (copy_base == s21_infm && (copy_exp == s21_infp))
    itog = s21_infp;
  else if (copy_base == s21_infm && (copy_exp == s21_infm))
    itog = 0;
  else if (copy_base == s21_infm && (copy_exp > 0) && (copy_exp != 1))
    itog = s21_infp;
  else if (copy_base == s21_infm && (copy_exp == 1))
    itog = s21_infm;
  else if (copy_base == s21_infm && (copy_exp < 0))
    itog = 0;
  else {
    itog = s21_pow_main(copy_base, copy_exp);
  }
  return itog;
}

long double s21_pow_main(long double copy_base, long double copy_exp) {
  long double itog = 0;
  if (copy_base < 0) {
    copy_base = -copy_base;
    itog = s21_exp(copy_exp * s21_log(copy_base));
    if (s21_fmod(copy_exp, 2) != 0) {
      itog = -itog;
    }
  } else {
    itog = s21_exp(copy_exp * s21_log(copy_base));
  }
  return itog;
}