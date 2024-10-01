#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  if (!result)
    flag = 1;
  else {
    clear(result);
    for (int i = 0; i < 4; i++) {
      result->bits[i] = value.bits[i];
    }
    if (get_znak(*result) == 1)
      set_znak(result, 0);
    else
      set_znak(result, 1);
  }
  return flag;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  int scale = get_scale(value);
  if (!result || scale > 28)
    flag = 1;
  else if (scale == 0) {
    for (int i = 3; i >= 0; i--) {
      result->bits[i] = value.bits[i];
    }
  } else {
    s21_decimal ten = {{0b00000000000000000000000000001010, 0, 0, 0}};
    s21_decimal delitel = {{1, 0, 0, 0}};
    for (int i = 0; i < scale; i++) s21_mul(delitel, ten, &delitel);
    s21_decimal delimoe = {0};
    for (int i = 0; i < 4; i++) {
      delimoe.bits[i] = value.bits[i];
    }
    set_scale(&delimoe, 0);
    int znak = 0;
    if (get_znak(delimoe) == 1) {
      znak = 1;
      set_znak(&delimoe, 0);
    }
    mod(&delimoe, delitel);
    set_scale(&delimoe, scale);
    if (znak == 1)
      s21_add(value, delimoe, result);
    else
      s21_sub(value, delimoe, result);
    set_scale(result, 0);
    while (scale > 0) {
      s21_div(*result, ten, result);
      scale--;
    }
  }
  return flag;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  int scale = get_scale(value);
  if (!result || scale > 28)
    flag = 1;
  else if (scale == 0) {
    for (int i = 3; i >= 0; i--) {
      result->bits[i] = value.bits[i];
    }
  } else {
    s21_decimal box;
    s21_truncate(value, &box);
    for (int i = 3; i >= 0; i--) {
      result->bits[i] = box.bits[i];
    }
    if (get_znak(value) == 1) {
      s21_decimal one = {{1, 0, 0, 0x80000000}};
      s21_add(*result, one, result);
    }
  }
  return flag;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int flag = 0;
  int scale = get_scale(value);
  if (!result || scale > 28)
    flag = 1;
  else if (scale == 0) {
    for (int i = 3; i >= 0; i--) {
      result->bits[i] = value.bits[i];
    }
  } else {
    s21_decimal box;
    s21_truncate(value, &box);
    s21_decimal one = {{1, 0, 0, 0}};
    s21_decimal m_one = {{1, 0, 0, 0x80000000}};
    s21_decimal ten = {{0b00000000000000000000000000001010, 0, 0, 0}};
    s21_decimal delitel = {{1, 0, 0, 0}};
    for (int i = 0; i < scale; i++) s21_mul(delitel, ten, &delitel);
    s21_decimal delimoe = {0};
    for (int i = 0; i < 4; i++) {
      delimoe.bits[i] = value.bits[i];
    }
    set_scale(&delimoe, 0);
    set_znak(&delimoe, 0);
    mod(&delimoe, delitel);
    int s = 1;
    while (s21_is_greater_or_equal(delimoe, ten)) {
      s21_decimal box2 = {0};
      for (int i = 0; i < 4; i++) {
        box2.bits[i] = delimoe.bits[i];
      }
      mod(&box2, ten);
      s21_sub(delimoe, box2, &delimoe);
      s21_div(delimoe, ten, &delimoe);
      s++;
    }
    if (mod_number(delimoe) >= 5 && get_znak(value) == 0 && (s == scale))
      s21_add(box, one, &box);
    else if (mod_number(delimoe) >= 5 && get_znak(value) == 1 && (s == scale))
      s21_add(box, m_one, &box);
    for (int i = 0; i < 4; i++) {
      result->bits[i] = box.bits[i];
    }
  }
  return flag;
}