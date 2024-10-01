#ifndef S21_MATH
#define S21_MATH

#include <stdio.h>
#include <stdlib.h>

#define s21_pi 3.14159265358979323846L
#define s21_e 2.71828182845904523536L
#define s21_infp (1.0) / (+0.0)
#define s21_infm (1.0) / (-0.0)
#define s21_nan (0.0) / (0.0)
#define s21_eps 0.00000000000001L

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_pow_main(long double copy_base, long double copy_exp);

#endif