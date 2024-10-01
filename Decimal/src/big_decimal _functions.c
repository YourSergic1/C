#include "s21_decimal.h"

void print_binary(int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
  }
  printf("\n");
}

void print_big_decimal(s21_big_decimal num) {
  for (int i = 7; i >= 0; i--) {
    print_binary(num.bits[i]);
  }
  return;
}

s21_big_decimal to_big_decimal(s21_decimal num) {
  s21_big_decimal new = {0};
  for (int i = 0; i < 3; i++) new.bits[i] = num.bits[i];
  new.bits[7] = num.bits[3];
  return new;
}

int get_bit_bd(s21_big_decimal num, int index) {
  int num_int = index / 32;
  int num_bit = index % 32;
  return (num.bits[num_int] & (1u << num_bit)) >> num_bit;
}

void set_bit_bd(s21_big_decimal *decl, int index, int bit) {
  int num_int = index / 32;
  int num_bit = index % 32;
  if (bit == 1) {
    decl->bits[num_int] |= (1u << num_bit);
  } else {
    decl->bits[num_int] &= (~((1u) << num_bit));
  }
  return;
}

int get_znak_bd(s21_big_decimal num) { return get_bit_bd(num, 255); }

void set_znak_bd(s21_big_decimal *num, int znak) {
  set_bit_bd(num, 255, znak);
  return;
}

int get_scale_bd(s21_big_decimal num) {
  s21_big_decimal scale_dec = {{0, 0, 0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < 9; ++i) {
    set_bit_bd(&scale_dec, i, get_bit_bd(num, 240 + i));
  }
  return scale_dec.bits[0];
}

void set_scale_bd(s21_big_decimal *num, int scale) {
  int znak = get_znak_bd(*num);
  num->bits[7] = scale << 16;
  set_znak_bd(num, znak);
  return;
}

void left_shift_bd(s21_big_decimal *num, int shift) {
  while (shift != 0) {
    int box1 = 0;
    int box2 = 0;
    for (int i = 0; i < 224; i++) {
      box1 = get_bit_bd(*num, i);
      set_bit_bd(num, i, box2);
      box2 = box1;
    }
    shift--;
  }
  return;
}

void right_shift_bd(s21_big_decimal *num, int shift) {
  while (shift != 0) {
    int box1 = 0;
    int box2 = 0;
    for (int i = 224; i >= 0; i--) {
      box1 = get_bit_bd(*num, i);
      set_bit_bd(num, i, box2);
      box2 = box1;
    }
    shift--;
  }
  return;
}

int max_bit_level_bd(s21_big_decimal num) {
  int max_lev = -1;
  for (int i = 0; i < 224; i++) {
    if (get_bit_bd(num, i)) max_lev = i;
  }
  return max_lev;
}

void add_for_normalize(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal *result) {
  int tmp = 0;
  int sign1 = 0;
  int sign2 = 0;
  for (int i = 0; i < 224; i++) {
    sign1 = get_bit_bd(value_1, i);
    sign2 = get_bit_bd(value_2, i);
    if (sign1 & sign2) {
      if (tmp == 1)
        set_bit_bd(result, i, 1);
      else {
        tmp = 1;
        set_bit_bd(result, i, 0);
      }
    } else if (sign1 ^ sign2) {
      if (!tmp)
        set_bit_bd(result, i, 1);
      else
        set_bit_bd(result, i, 0);
    } else if (tmp) {
      set_bit_bd(result, i, 1);
      tmp = 0;
    } else
      set_bit_bd(result, i, 0);
  }
  return;
}

int normaliz_add_sub(s21_big_decimal *value_1, s21_big_decimal *value_2) {
  int scale_1 = get_scale_bd(*value_1);
  int scale_2 = get_scale_bd(*value_2);
  int max_scale = scale_1;
  if (scale_2 > max_scale) max_scale = scale_2;
  s21_big_decimal big_decimal_ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < max_scale; ++i) {
    if (scale_1)
      --scale_1;
    else
      s21_mul_big(*value_1, big_decimal_ten, value_1);
    if (scale_2)
      --scale_2;
    else
      s21_mul_big(*value_2, big_decimal_ten, value_2);
  }
  return max_scale;
}

void normalize(s21_big_decimal *num1, s21_big_decimal *num2) {
  int scale_num1 = get_scale_bd(*num1);
  int scale_num2 = get_scale_bd(*num2);
  if (scale_num1 < scale_num2) {
    while (scale_num1 != scale_num2) {
      scale_num1++;
      s21_big_decimal box_num1 = *num1;
      s21_big_decimal box_num2 = *num1;
      left_shift_bd(&box_num1, 3);
      left_shift_bd(&box_num2, 1);
      add_for_normalize(box_num1, box_num2, num1);
      set_scale_bd(num1, scale_num1);
    }
  } else if (scale_num2 < scale_num1) {
    while (scale_num1 != scale_num2) {
      scale_num2++;
      s21_big_decimal box_num1 = *num2;
      s21_big_decimal box_num2 = *num2;
      left_shift_bd(&box_num1, 3);
      left_shift_bd(&box_num2, 1);
      add_for_normalize(box_num1, box_num2, num2);
      set_scale_bd(num2, scale_num2);
    }
  }
  return;
}

int check_for_null_bd(s21_big_decimal num) {
  int flag = 1;
  for (int i = 0; i < 224; i++) {
    if (get_bit_bd(num, i) == 0)
      continue;
    else {
      flag = 0;
      break;
    }
  }
  return flag;
}

void clear_bd(s21_big_decimal *num) {
  for (int i = 0; i < 8; i++) num->bits[i] = 0;
  return;
}

int bit_shift_right(s21_big_decimal *num, int shift) {
  int err = 0;
  for (int _shift = 0; _shift < shift && !err; _shift++) {
    for (int i = 0; i < 7 * 32 && !err; i++) {
      set_bit_bd(num, i, get_bit_bd(*num, i + 1));
    }
  }
  return err;
}

void bit_shift_left(s21_big_decimal *num, int shift) {
  int max_bit_index = 0;
  int tmp_bit = 0;

  for (int _shift = 0; _shift < shift; _shift++) {
    max_bit_index = max_bit_level_bd(*num);
    for (int i = max_bit_index; i >= 0; i--) {
      tmp_bit = get_bit_bd(*num, i);
      set_bit_bd(num, i + 1, tmp_bit);
    }
    set_bit_bd(num, 0, 0);
  }
}

int check_null_bd(s21_big_decimal vall) {
  int err = 0;

  if (!vall.bits[0] && !vall.bits[1] && !vall.bits[2] && !vall.bits[3] &&
      !vall.bits[4] && !vall.bits[5] && !vall.bits[6])
    err = 1;

  return err;
}

int s21_is_less_bd(s21_big_decimal num1, s21_big_decimal num2) {
  int flag = 0;
  s21_big_decimal num1_bd = {0};
  s21_big_decimal num2_bd = {0};
  for (int i = 0; i < 8; i++) {
    num1_bd.bits[i] = num1.bits[i];
    num2_bd.bits[i] = num2.bits[i];
  }
  normalize(&num1_bd, &num2_bd);
  if (get_znak_bd(num1_bd) == 1 && get_znak_bd(num2_bd) == 0 &&
      (!check_for_null_bd(num1_bd) || !check_for_null_bd(num2_bd)))
    flag = 1;
  else if (get_znak_bd(num1_bd) == 0 && get_znak_bd(num2_bd) == 1 &&
           (check_for_null_bd(num2_bd) == 0 || check_for_null_bd(num1_bd) == 0))
    flag = 0;
  else if (get_znak_bd(num1_bd) == 0 && get_znak_bd(num2_bd) == 0) {
    if (max_bit_level_bd(num1_bd) < max_bit_level_bd(num2_bd))
      flag = 1;
    else if (max_bit_level_bd(num2_bd) < max_bit_level_bd(num1_bd))
      flag = 0;
    else {
      for (int i = max_bit_level_bd(num1_bd) - 1; i > -1; i--) {
        if (get_bit_bd(num1_bd, i) == 0 && get_bit_bd(num2_bd, i) == 1) {
          flag = 1;
          break;
        } else if (get_bit_bd(num1_bd, i) == 1 && get_bit_bd(num2_bd, i) == 0) {
          flag = 0;
          break;
        } else
          continue;
      }
    }
  } else if (get_znak_bd(num1_bd) == 1 && get_znak_bd(num2_bd) == 1) {
    if (max_bit_level_bd(num1_bd) > max_bit_level_bd(num2_bd))
      flag = 1;
    else if (max_bit_level_bd(num2_bd) > max_bit_level_bd(num1_bd))
      flag = 0;
    else {
      for (int i = max_bit_level_bd(num1_bd) - 1; i > -1; i--) {
        if (get_bit_bd(num1_bd, i) == 1 && get_bit_bd(num2_bd, i) == 0) {
          flag = 1;
          break;
        } else if (get_bit_bd(num1_bd, i) == 0 && get_bit_bd(num2_bd, i) == 1) {
          flag = 0;
          break;
        } else
          continue;
      }
    }
  }
  return flag;
}

int s21_is_greater_bd(s21_big_decimal num1, s21_big_decimal num2) {
  int flag = 0;
  s21_big_decimal num1_bd = {0};
  s21_big_decimal num2_bd = {0};
  for (int i = 0; i < 8; i++) {
    num1_bd.bits[i] = num1.bits[i];
    num2_bd.bits[i] = num2.bits[i];
  }
  normalize(&num1_bd, &num2_bd);
  if (get_znak_bd(num1_bd) == 0 && get_znak_bd(num2_bd) == 1 &&
      (!check_for_null_bd(num1_bd) || !check_for_null_bd(num2_bd)))
    flag = 1;
  else if (get_znak_bd(num1_bd) == 1 && get_znak_bd(num2_bd) == 0 &&
           (!check_for_null_bd(num2_bd) || !check_for_null_bd(num1_bd)))
    flag = 0;
  else if (get_znak_bd(num1_bd) == 0 && get_znak_bd(num2_bd) == 0) {
    if (max_bit_level_bd(num1_bd) > max_bit_level_bd(num2_bd))
      flag = 1;
    else if (max_bit_level_bd(num1_bd) < max_bit_level_bd(num2_bd))
      flag = 0;
    else {
      for (int i = max_bit_level_bd(num1_bd) - 1; i > -1; i--) {
        if (get_bit_bd(num1_bd, i) == 1 && get_bit_bd(num2_bd, i) == 0) {
          flag = 1;
          break;
        } else if (get_bit_bd(num1_bd, i) == 0 && get_bit_bd(num2_bd, i) == 1) {
          flag = 0;
          break;
        } else
          continue;
      }
    }
  } else if (get_znak_bd(num1_bd) == 1 && get_znak_bd(num2_bd) == 1) {
    if (max_bit_level_bd(num1_bd) > max_bit_level_bd(num2_bd))
      flag = 0;
    else if (max_bit_level_bd(num1_bd) < max_bit_level_bd(num2_bd))
      flag = 1;
    else {
      for (int i = max_bit_level_bd(num1_bd) - 1; i > -1; i--) {
        if (get_bit_bd(num1_bd, i) == 1 && get_bit_bd(num2_bd, i) == 0) {
          flag = 0;
          break;
        } else if (get_bit_bd(num1_bd, i) == 0 && get_bit_bd(num2_bd, i) == 1) {
          flag = 1;
          break;
        } else
          continue;
      }
    }
  }
  return flag;
}

int s21_is_equal_bd(s21_big_decimal num1, s21_big_decimal num2) {
  int flag = 1;
  s21_big_decimal num1_bd = {0};
  s21_big_decimal num2_bd = {0};
  for (int i = 0; i < 8; i++) {
    num1_bd.bits[i] = num1.bits[i];
    num2_bd.bits[i] = num2.bits[i];
  }
  normalize(&num1_bd, &num2_bd);
  if (check_for_null_bd(num1_bd) == 1 && check_for_null_bd(num2_bd) == 1)
    flag = 1;
  else {
    for (int i = 0; i < 256; i++) {
      if (get_bit_bd(num1_bd, i) != get_bit_bd(num2_bd, i)) {
        flag = 0;
        break;
      }
    }
  }
  return flag;
}

int s21_is_greater_or_equal_bd(s21_big_decimal num1, s21_big_decimal num2) {
  int flag = 0;
  if (s21_is_equal_bd(num1, num2) == 1 || s21_is_greater_bd(num1, num2) == 1)
    flag = 1;
  return flag;
}

int mod_bd(s21_big_decimal *delimoe, s21_big_decimal delitel) {
  int flag = 0;
  if (s21_is_less_bd(*delimoe, delitel) == 1)
    flag = 1;
  else {
    while (s21_is_greater_or_equal_bd(*delimoe, delitel)) {
      s21_big_decimal box;
      for (int i = 0; i < 8; i++) {
        box.bits[i] = delitel.bits[i];
      }
      while (s21_is_greater_or_equal_bd(*delimoe, box) &&
             get_bit_bd(box, 223) != 1) {
        left_shift_bd(&box, 1);
      }
      if (get_bit_bd(box, 223) != 1) right_shift_bd(&box, 1);
      sub_big(*delimoe, box, delimoe);
    }
  }
  return flag;
}

int mod_number_bd(s21_big_decimal num) {
  s21_big_decimal zero = {{0, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal two = {{2, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal three = {{3, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal four = {{4, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal five = {
      {0b00000000000000000000000000000101, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal six = {{6, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal seven = {{7, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal eight = {{8, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal nine = {{9, 0, 0, 0, 0, 0, 0, 0}};
  int flag = -1;
  if (s21_is_equal_bd(num, zero)) flag = 0;
  if (s21_is_equal_bd(num, one)) flag = 1;
  if (s21_is_equal_bd(num, two)) flag = 2;
  if (s21_is_equal_bd(num, three)) flag = 3;
  if (s21_is_equal_bd(num, four)) flag = 4;
  if (s21_is_equal_bd(num, five)) flag = 5;
  if (s21_is_equal_bd(num, six)) flag = 6;
  if (s21_is_equal_bd(num, seven)) flag = 7;
  if (s21_is_equal_bd(num, eight)) flag = 8;
  if (s21_is_equal_bd(num, nine)) flag = 9;
  return flag;
}

void s21_bank_bd(s21_big_decimal *value, int num) {
  int scale = num;
  s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal delitel = {{1, 0, 0, 0, 0, 0, 0, 0}};
  for (int i = 0; i < num; i++) s21_mul_big(delitel, ten, &delitel);
  s21_big_decimal delimoe = {0};
  for (int i = 0; i < 8; i++) {
    delimoe.bits[i] = value->bits[i];
  }
  set_scale_bd(&delimoe, 0);
  set_znak_bd(&delimoe, 0);
  mod_bd(&delimoe, delitel);
  s21_big_decimal box = {0};
  for (int i = 0; i < 8; i++) {
    box.bits[i] = delimoe.bits[i];
  }
  set_scale_bd(&delimoe, get_scale_bd(*value));
  sub_big(*value, delimoe, value);
  int scale2 = get_scale_bd(*value) - num;
  set_scale_bd(value, 0);
  while (num > 0) {
    s21_div_bd(*value, ten, value);
    num--;
  }
  set_scale_bd(value, scale2);
  int s = 1;
  while (s21_is_greater_or_equal_bd(box, ten)) {
    s21_big_decimal box2 = {0};
    for (int i = 0; i < 8; i++) {
      box2.bits[i] = box.bits[i];
    }
    mod_bd(&box2, ten);
    sub_big(box, box2, &box);
    div_bd(box, ten, &box);
    s++;
  }
  if ((mod_number_bd(box) > 5 && get_znak_bd(*value) == 0 && s == scale) ||
      (mod_number_bd(box) == 5 && get_znak_bd(*value) == 0 &&
       get_bit_bd(*value, 0) == 1 && s == scale)) {
    s21_big_decimal one = {{1, 0, 0, 0, 0, 0, 0, 0}};
    set_scale_bd(&one, get_scale_bd(*value));
    add(*value, one, value);
  }
  if ((mod_number_bd(box) > 5 && get_znak_bd(*value) == 1 && s == scale) ||
      (mod_number_bd(box) == 5 && get_znak_bd(*value) == 1 &&
       get_bit_bd(*value, 0) == 1 && s == scale)) {
    s21_big_decimal m_one = {{1, 0, 0, 0, 0, 0, 0, 0x80000000}};
    set_scale_bd(&m_one, get_scale_bd(*value));
    add(*value, m_one, value);
  }
  return;
}