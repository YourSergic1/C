#include "s21_decimal.h"

void print_decimal(s21_decimal num) {
  for (int i = 3; i >= 0; i--) {
    print_binary(num.bits[i]);
  }
  return;
}

int get_bit(s21_decimal num, int index) {
  int num_int = index / 32;
  int num_bit = index % 32;
  return (num.bits[num_int] & (1u << num_bit)) >> num_bit;
}

void set_bit(s21_decimal *decl, int index, int bit) {
  int num_int = index / 32;
  int num_bit = index % 32;
  if (bit == 1) {
    decl->bits[num_int] |= (1u << num_bit);
  } else {
    decl->bits[num_int] &= (~((1u) << num_bit));
  }
  return;
}

int get_znak(s21_decimal num) { return get_bit(num, 127); }

void set_znak(s21_decimal *num, int znak) {
  set_bit(num, 127, znak);
  return;
}

int get_scale(s21_decimal num) {
  s21_decimal scale_dec = {{0, 0, 0, 0}};
  for (int i = 0; i < 9; ++i) {
    set_bit(&scale_dec, i, get_bit(num, 112 + i));
  }
  return scale_dec.bits[0];
}

void set_scale(s21_decimal *num, int scale) {
  int znak = get_znak(*num);
  num->bits[3] = scale << 16;
  set_znak(num, znak);
  return;
}

void clear(s21_decimal *num) {
  for (int i = 0; i < 4; i++) num->bits[i] = 0;
  return;
}

int check_for_null(s21_decimal num) {
  int flag = 1;
  for (int i = 0; i < 96; i++) {
    if (get_bit(num, i) == 0)
      continue;
    else {
      flag = 0;
      break;
    }
  }
  return flag;
}

int max_bit_level(s21_decimal num) {
  int max_lev = -1;
  for (int i = 0; i < 96; i++) {
    if (get_bit(num, i)) max_lev = i;
  }
  return max_lev;
}

void left_shift(s21_decimal *num) {
  int box1 = 0;
  int box2 = 0;
  for (int i = 0; i < 96; i++) {
    box1 = get_bit(*num, i);
    set_bit(num, i, box2);
    box2 = box1;
  }
  return;
}

void right_shift(s21_decimal *num) {
  int box1 = 0;
  int box2 = 0;
  for (int i = 96; i >= 0; i--) {
    box1 = get_bit(*num, i);
    set_bit(num, i, box2);
    box2 = box1;
  }
  return;
}

int mod(s21_decimal *delimoe, s21_decimal delitel) {
  int flag = 0;
  if (s21_is_less(*delimoe, delitel) == 1)
    flag = 1;
  else {
    while (s21_is_greater_or_equal(*delimoe, delitel)) {
      s21_decimal box;
      for (int i = 0; i < 4; i++) {
        box.bits[i] = delitel.bits[i];
      }
      int flag = 0;
      while (s21_is_greater_or_equal(*delimoe, box)) {
        if (get_bit(box, 95) == 1) {
          flag = 1;
          break;
        }
        left_shift(&box);
      }
      if (flag == 0) right_shift(&box);
      s21_sub(*delimoe, box, delimoe);
    }
  }
  return flag;
}

int mod_number(s21_decimal num) {
  s21_decimal zero = {{0, 0, 0, 0}};
  s21_decimal one = {{1, 0, 0, 0}};
  s21_decimal two = {{2, 0, 0, 0}};
  s21_decimal three = {{3, 0, 0, 0}};
  s21_decimal four = {{4, 0, 0, 0}};
  s21_decimal five = {{5, 0, 0, 0}};
  s21_decimal six = {{6, 0, 0, 0}};
  s21_decimal seven = {{7, 0, 0, 0}};
  s21_decimal eight = {{8, 0, 0, 0}};
  s21_decimal nine = {{9, 0, 0, 0}};
  int flag = -1;
  if (s21_is_equal(num, zero)) flag = 0;
  if (s21_is_equal(num, one)) flag = 1;
  if (s21_is_equal(num, two)) flag = 2;
  if (s21_is_equal(num, three)) flag = 3;
  if (s21_is_equal(num, four)) flag = 4;
  if (s21_is_equal(num, five)) flag = 5;
  if (s21_is_equal(num, six)) flag = 6;
  if (s21_is_equal(num, seven)) flag = 7;
  if (s21_is_equal(num, eight)) flag = 8;
  if (s21_is_equal(num, nine)) flag = 9;
  return flag;
}