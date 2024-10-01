#include "s21_decimal.h"

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  clear(result);
  s21_big_decimal big_num_1 = to_big_decimal(value_1);
  s21_big_decimal big_num_2 = to_big_decimal(value_2);
  s21_big_decimal big_result = to_big_decimal(*result);
  int res = 0;
  if (max_bit_level_bd(big_num_1) == -1 && max_bit_level_bd(big_num_2) == -1)
    res = 0;

  else if (get_znak_bd(big_num_1) && get_znak_bd(big_num_2)) {
    res = norm_and_add(big_num_1, big_num_2, &big_result);
    set_znak_bd(&big_result, 1);
  } else if (!(get_znak_bd(big_num_1)) && !(get_znak_bd(big_num_2)))
    res = norm_and_add(big_num_1, big_num_2, &big_result);

  else if (!(get_znak_bd(big_num_1)) && get_znak_bd(big_num_2)) {
    set_znak_bd(&big_num_2, 0);
    res = sub_big(big_num_1, big_num_2, &big_result);
  } else if (get_znak_bd(big_num_1) && !(get_znak_bd(big_num_2))) {
    set_znak_bd(&big_num_1, 0);
    res = sub_big(big_num_2, big_num_1, &big_result);
  }
  *result = big_to_decimal(big_result);
  if (result->bits[3] == 1) {
    result->bits[3] = 0;
    res = 1;
  } else if (result->bits[3] == 2) {
    result->bits[3] = 0;
    res = 2;
  }
  return res;
}

int norm_and_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int scale = normaliz_add_sub(&value_1, &value_2);
  set_scale_bd(result, scale);
  int res = add(value_1, value_2, result);
  return res;
}

int add(s21_big_decimal value_1, s21_big_decimal value_2,
        s21_big_decimal *result) {
  int res = 0;
  int tmp = 0;
  int sign1 = 0;
  int sign2 = 0;
  for (int i = 0; i < 7 * 32; i++) {
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
  if (tmp) res = 1;
  return res;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int err = 0;
  clear(result);
  s21_big_decimal big_num_1 = to_big_decimal(value_1);
  s21_big_decimal big_num_2 = to_big_decimal(value_2);
  s21_big_decimal big_result = to_big_decimal(*result);

  if (!get_znak_bd(big_num_1) && get_znak_bd(big_num_2)) {
    set_znak_bd(&big_num_2, 0);
    err = norm_and_add(big_num_1, big_num_2, &big_result);
  } else if (get_znak_bd(big_num_1) && !get_znak_bd(big_num_2)) {
    err = norm_and_add(big_num_1, big_num_2, &big_result);
    set_znak_bd(&big_result, 1);
  } else if (get_znak_bd(big_num_1) && get_znak_bd(big_num_2)) {
    set_znak_bd(&big_num_2, 0);
    set_znak_bd(&big_num_1, 0);
    err = sub_big(big_num_2, big_num_1, &big_result);
  } else
    err = sub_big(big_num_1, big_num_2, &big_result);
  *result = big_to_decimal(big_result);
  if (result->bits[3] == 1) {
    result->bits[3] = 0;
    err = 1;
  } else if (result->bits[3] == 2) {
    result->bits[3] = 0;
    err = 2;
  }
  return err;
}

int sub_big(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result) {
  int err = 0;
  s21_big_decimal big_dec_null = {0};
  if (max_bit_level_bd(value_1) == -1 && max_bit_level_bd(value_2) == -1) {
    err = 0;
    *result = big_dec_null;
  } else if (s21_is_equal_big(value_1, value_2)) {
    err = 0;
    *result = big_dec_null;
  } else if (s21_is_less_bd(value_1, value_2)) {
    set_znak_bd(result, 1);
    norm_and_sub(value_2, value_1, result);
  } else {
    err = norm_and_sub(value_1, value_2, result);
  }
  return err;
}

int norm_and_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  int err = 0;
  int scale = normaliz_add_sub(&value_1, &value_2);
  set_scale_bd(result, scale);
  err = sub(value_1, value_2, result);
  return err;
}

int sub(s21_big_decimal value_1, s21_big_decimal value_2,
        s21_big_decimal *result) {
  for (int i = 0; i < 7 * 32; i++) {
    if (get_bit_bd(value_2, i))
      set_bit_bd(&value_2, i, 0);
    else
      set_bit_bd(&value_2, i, 1);
  }
  if (add(value_1, value_2, result)) {
    s21_big_decimal num_once = {{1, 0, 0, 0, 0, 0, 0, 0}};
    add(*result, num_once, result);
  }
  return 0;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal big_num_1 = to_big_decimal(value_1);
  s21_big_decimal big_num_2 = to_big_decimal(value_2);
  s21_big_decimal big_result = to_big_decimal(*result);
  int err = s21_mul_big(big_num_1, big_num_2, &big_result);
  set_scale_bd(&big_result, get_scale_bd(big_num_1) + get_scale_bd(big_num_2));
  if (get_znak(value_1) != get_znak(value_2)) set_znak_bd(&big_result, 1);
  *result = big_to_decimal(big_result);
  if (result->bits[3] == 1) {
    result->bits[3] = 0;
    err = 1;
  } else if (result->bits[3] == 2) {
    result->bits[3] = 0;
    err = 2;
  }
  return err;
}

int s21_mul_big(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result) {
  clear_bd(result);
  int tmp_shift = 0;
  int count_shift = max_bit_level_bd(value_2) + 1;
  s21_big_decimal tmp_res = {0};
  for (int i = 0; i < count_shift; i++) {
    if (get_bit_bd(value_2, i)) {
      bit_shift_left(&value_1, i - tmp_shift);
      tmp_shift = i;
      tmp_res = *result;
      add(tmp_res, value_1, result);
    }
  }
  return 0;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  clear(result);
  if (!value_2.bits[0] && !value_2.bits[1] && !value_2.bits[2] &&
      (value_1.bits[0] || value_1.bits[1] || value_1.bits[2])) {
    res = 3;
  }
  int sign_res = 0;
  s21_big_decimal big_num_1 = to_big_decimal(value_1);
  s21_big_decimal big_num_2 = to_big_decimal(value_2);
  if (get_znak_bd(big_num_1) != get_znak_bd(big_num_2)) sign_res = 1;
  s21_big_decimal big_result = to_big_decimal(*result);
  int scale = 0;
  s21_big_decimal ten_dec = {{10, 0, 0, 0, 0, 0, 0, 0}};
  scale = get_scale_bd(big_num_1) - get_scale_bd(big_num_2);
  while (scale < 0) {
    s21_mul_big(big_num_1, ten_dec, &big_num_1);
    ++scale;
  }
  if (!res) res = div_bd(big_num_1, big_num_2, &big_result);
  set_scale_bd(&big_result, scale + get_scale_bd(big_result));
  if (sign_res) set_znak_bd(&big_result, 1);
  s21_big_decimal tmp_res = {0};
  s21_big_decimal remains_dec = {0};
  s21_big_decimal null_dec = {0};
  scale = 0;
  int sign = 0;
  while (get_scale_bd(big_result)) {
    remains_dec = try_div(big_result, ten_dec, &tmp_res);
    if (s21_is_less_big(null_dec, remains_dec)) {
      break;
    } else {
      scale = get_scale_bd(big_result) - 1;
      sign = get_znak_bd(big_result);
      big_result = tmp_res;
      set_scale_bd(&big_result, scale);
      set_znak_bd(&big_result, sign);
    }
  }
  result_to_dec_div(result, big_result, big_num_2, &res);
  return res;
}

int s21_div_bd(s21_big_decimal big_num_1, s21_big_decimal big_num_2,
               s21_big_decimal *big_res) {
  if (check_for_null_bd(big_num_2)) return 3;

  int res = 0;
  clear_bd(big_res);
  int sign_res = 0;

  if (get_znak_bd(big_num_1) != get_znak_bd(big_num_2)) sign_res = 1;
  int scale = 0;
  s21_big_decimal ten_dec = {{10, 0, 0, 0, 0, 0, 0, 0}};
  scale = get_scale_bd(big_num_1) - get_scale_bd(big_num_2);
  while (scale < 0) {
    s21_mul_big(big_num_1, ten_dec, &big_num_1);
    ++scale;
  }
  if (!res) res = div_bd(big_num_1, big_num_2, big_res);
  set_scale_bd(big_res, scale + get_scale_bd(*big_res));
  if (sign_res) set_znak_bd(big_res, 1);
  s21_big_decimal tmp_res = {0};
  s21_big_decimal remains_dec = {0};
  s21_big_decimal null_dec = {0};
  scale = 0;
  int sign = 0;
  while (get_scale_bd(*big_res)) {
    remains_dec = try_div(*big_res, ten_dec, &tmp_res);
    if (s21_is_less_big(null_dec, remains_dec)) {
      break;
    } else {
      scale = get_scale_bd(*big_res) - 1;
      sign = get_znak_bd(*big_res);
      *big_res = tmp_res;
      set_scale_bd(big_res, scale);
      set_znak_bd(big_res, sign);
    }
  }

  return res;
}

void result_to_dec_div(s21_decimal *result, s21_big_decimal big_result,
                       s21_big_decimal big_num_2, int *res) {
  s21_big_decimal minull_null_dec = {
      {0x00000000, 0x00000000, 0x00000000, 0x80000000}};
  s21_big_decimal null_dec = {0};
  *result = big_to_decimal(big_result);
  if (result->bits[3] == 1) {
    result->bits[3] = 0;
    *res = 1;
  } else if (result->bits[3] == 2) {
    result->bits[3] = 0;
    *res = 2;
  } else if (s21_is_equal_big(big_num_2, null_dec) ||
             s21_is_equal_big(big_num_2, minull_null_dec)) {
    result->bits[3] = result->bits[2] = result->bits[1] = result->bits[0] = 0;
    *res = 3;
  }
}

int div_bd(s21_big_decimal value_1, s21_big_decimal value_2,
           s21_big_decimal *result) {
  int res = 0;
  s21_big_decimal null_dec = {0};
  s21_big_decimal ten_dec = {{10, 0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal tmp_res = {0};
  int scale = 0;
  while (1) {
    try_div(value_1, value_2, result);
    set_scale_bd(result, scale);
    if (get_znak_bd(value_1) != get_znak_bd(value_2)) set_znak_bd(result, 1);
    s21_mul_big(*result, value_2, &tmp_res);
    if (get_znak_bd(*result) != get_znak_bd(value_2)) set_znak_bd(&tmp_res, 1);
    if (s21_is_equal_big(tmp_res, value_1)) break;
    *result = null_dec;
    ++scale;
    s21_mul_big(value_1, ten_dec, &value_1);
    if (s21_is_equal_big(value_1, null_dec))
      break;
    else if (scale >= 28) {
      res = 2;
      break;
    }
  }
  return res;
}

s21_big_decimal try_div(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result) {
  s21_big_decimal tmp_num = {0};
  int flag = 1;
  set_scale_bd(&value_1, 0);
  set_scale_bd(&value_2, 0);
  int max_bit_value_1 = max_bit_level_bd(value_1);
  int max_bit_value_2 = max_bit_level_bd(value_2);
  int count_bit = 0;
  for (int i = 0; i <= max_bit_value_2; ++i) {
    bit_shift_left(&tmp_num, 1);
    set_bit_bd(&tmp_num, 0, get_bit_bd(value_1, max_bit_value_1 - i));
    ++count_bit;
  }
  if (s21_is_less_big(tmp_num, value_2)) {
    bit_shift_right(&tmp_num, 1);
    --count_bit;
  }
  while (count_bit <= max_bit_value_1 + 1 || flag) {
    if (!s21_is_less_big(tmp_num, value_2)) {
      sub_big(tmp_num, value_2, &tmp_num);
      bit_shift_left(result, 1);
      set_bit_bd(result, 0, 1);
      flag = 0;
    } else {
      bit_shift_left(result, 1);
      set_bit_bd(result, 0, 0);
    }
    bit_shift_left(&tmp_num, 1);
    set_bit_bd(&tmp_num, 0, get_bit_bd(value_1, max_bit_value_1 - count_bit));
    ++count_bit;
  }
  return tmp_num;
}

s21_decimal big_to_decimal(s21_big_decimal num) {
  s21_decimal new = try_big_to_decimal(num);

  s21_decimal tmp = new;

  if ((new.bits[3] == 1 || new.bits[3] == 2) && get_scale_bd(num)) {
    while ((new.bits[3] == 1 || new.bits[3] == 2) && get_scale_bd(num) &&
           get_scale_bd(num) <= 28) {
      s21_bank_bd(&num, 1);
      new = try_big_to_decimal(num);
    }

    s21_decimal minus_null = {{0, 0, 0, 0b10000000000000000000000000000000}};
    if (s21_is_equal(new, minus_null)) {
      new = tmp;
    }
  }

  if (check_for_null(new) & get_znak(new)) new.bits[3] = 0;
  return new;
}

s21_decimal try_big_to_decimal(s21_big_decimal num) {
  s21_decimal new = {0};
  int err = 0;
  for (int i = 0; i < 7; ++i) {
    if (i < 3)
      new.bits[i] = num.bits[i];
    else if (num.bits[i]) {
      err = 1;
      break;
    }
  }
  new.bits[3] = num.bits[7];
  if (err) {
    s21_decimal dec_null = {0};
    new = dec_null;
    if (!get_znak_bd(num)) {
      new.bits[3] = 1;
    } else
      new.bits[3] = 2;
  }
  s21_decimal null_dec = {{0, 0, 0, 0}};
  if (get_scale_bd(num) > 28) {
    new = null_dec;
    if (get_znak_bd(num)) {
      set_znak(&new, 1);
    }
  }
  return new;
}
