#include <string.h>

#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int flag = 0;
  if (!dst)
    flag = 1;
  else {
    clear(dst);
    if (src < 0) {
      set_znak(dst, 1);
      src *= -1;
    }
    dst->bits[0] = src;
  }
  return flag;
}

int s21_checking_float(float value) {
  int result = 0;
  if (isinf(value) || isnan(value)) {
    result = 1;
  }
  if (fabs(value) > 79228162514264337593543950335.0F) {
    result = 1;
  }
  if (fabs(value) < 1E-28 && value != 0) {
    result = 1;
  }
  return result;
}

void s21_conversion_float(float src, unsigned int *mantissa, int *scale) {
  char array[64] = {0}, temp[64] = {0};
  sprintf(array, "%.6E", src);
  // printf("array = %s\n", array);
  temp[0] = array[0];
  for (int i = 2; i <= 7; i++) {
    temp[i - 1] = array[i];
  }
  // printf("temp = %s\n", temp);
  *mantissa = atoi(temp);
  memset(temp, 0, 64);
  // printf("temp = %s\n", temp);
  for (int i = 9; i <= 11; i++) {
    temp[i - 9] = array[i];
  }
  // printf("temp = %s\n", temp);
  temp[3] = '\0';
  *scale = atoi(temp) - 6;
}

int s21_scale_checking(s21_decimal *dst, int scale) {
  int value = 0;
  if (scale < 0) {
    int ost = 0;
    scale *= -1;
    while ((dst->bits[0] % 10 == 0 && scale) || scale > 28) {
      ost = dst->bits[0] % 10;
      dst->bits[0] /= 10;
      scale--;
    }
    if (ost >= 5) {
      dst->bits[0] += 1;
    }
    set_scale(dst, scale);
  } else {
    while (scale > 0) {
      s21_decimal temp = {{0, 0, 0, 0}};
      value = s21_mul(*dst, (s21_decimal){{10, 0, 0, 0}}, &temp);
      *dst = temp;
      scale--;
    }
  }
  return value;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (!dst) {
    return 1;
  }
  int value = s21_checking_float(src);
  clear(dst);
  if (value == 0) {
    if (src < 0.0f) {
      set_bit(dst, 127, 1);
      src = -src;
    }
    unsigned int mantissa = 0;
    int scale = 0;
    s21_conversion_float(src, &mantissa, &scale);
    dst->bits[0] = mantissa;
    s21_scale_checking(dst, scale);
  }
  return value == 0 ? 0 : 1;
}

int check_dec_to_int_flot(s21_decimal num) {
  int err = 1;
  // проверка nan
  for (int i = 111; i <= 118; i++) {
    if (get_bit(num, i) == 0) err = 0;
  }
  // проверка степени
  if (get_scale(num) < 0 || get_scale(num) > 28) err = 1;
  // проверка бесконечности
  err = 1;
  for (int i = 111; i <= 118; i++) {
    if (get_bit(num, i) == 0) err = 0;
  }
  for (int i = 95; i >= 0; i--) {
    if (get_bit(num, i) == 1) err = 0;
  }
  // проверка последнего бита
  for (int i = 127; i >= 96; i--) {
    if (get_bit(num, i)) {
      if (i != 127 && (i < 112 || i > 119)) {
        err = 1;
      }
    }
  }
  return err;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  if (check_dec_to_int_flot(src) != 0 || !dst) {
    return 1;
  } else {
    int value = 0;
    double temp = 0.0;
    for (int i = 0; i <= 95; i++) {
      if (get_bit(src, i)) {
        temp += pow(2.0, i);
      }
    }
    double power = pow(10.0, get_scale(src));
    temp /= power;
    if (get_znak(src)) {
      temp = -temp;
    }
    *dst = temp;
    return value;
  }
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int err = 0;
  if (check_dec_to_int_flot(src) != 0) {
    err = 1;
  } else {
    int sign = 0;
    if (get_znak(src)) sign = 1;
    s21_decimal max_int = {{0b01111111111111111111111111111111, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_truncate(src, &result);
    set_znak(&result, 0);
    if (s21_is_less_or_equal(result, max_int)) {
      *dst = result.bits[0];
      if (sign) *dst *= -1;
    } else
      err = 1;
  }
  return err;
}