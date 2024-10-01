#include "s21_decimal.h"

int s21_is_less(s21_decimal num1, s21_decimal num2) {
  int flag = 0;
  s21_big_decimal num1_bd = to_big_decimal(num1);
  s21_big_decimal num2_bd = to_big_decimal(num2);
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

int s21_is_greater(s21_decimal num1, s21_decimal num2) {
  int flag = 0;
  s21_big_decimal num1_bd = to_big_decimal(num1);
  s21_big_decimal num2_bd = to_big_decimal(num2);
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

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int flag = 1;
  s21_big_decimal num1_bd = to_big_decimal(num1);
  s21_big_decimal num2_bd = to_big_decimal(num2);
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

int s21_is_not_equal(s21_decimal num1, s21_decimal num2) {
  int flag = 1;
  if (s21_is_equal(num1, num2) == 1) flag = 0;
  return flag;
}

int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2) {
  int flag = 0;
  if (s21_is_equal(num1, num2) == 1 || s21_is_less(num1, num2) == 1) flag = 1;
  return flag;
}

int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2) {
  int flag = 0;
  if (s21_is_equal(num1, num2) == 1 || s21_is_greater(num1, num2) == 1)
    flag = 1;
  return flag;
}

int s21_is_less_big(s21_big_decimal num1, s21_big_decimal num2) {
  int flag = 0;
  if (s21_is_equal_big(num1, num2) == 0) {
    for (int i = 96; i >= 0; i--) {
      if ((get_bit_bd(num1, i) && !(get_bit_bd(num2, i))) ||
          (!(get_bit_bd(num1, i)) && get_bit_bd(num2, i))) {
        flag = get_bit_bd(num2, i);
        break;
      }
    }
  }
  return flag;
}

int s21_is_equal_big(s21_big_decimal num1, s21_big_decimal num2) {
  int result = 1;
  for (int i = 0; i < 8; ++i) {
    if (num1.bits[i] != num2.bits[i]) {
      result = 0;
      break;
    }
  }
  return result;
}
