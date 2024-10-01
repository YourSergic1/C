#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[8];
} s21_big_decimal;

//всапомогательные функции для децимал
void print_decimal(s21_decimal num);
int get_bit(s21_decimal num, int index);
void set_bit(s21_decimal *decl, int index, int bit);
int get_znak(s21_decimal num);
void set_znak(s21_decimal *num, int znak);
int get_scale(s21_decimal num);
void set_scale(s21_decimal *num, int scale);
void clear(s21_decimal *num);
int check_for_null(s21_decimal num);
void print_binary(int num);
int max_bit_level(s21_decimal num);
void right_shift(s21_decimal *num);
void left_shift(s21_decimal *num);
int mod(s21_decimal *delimoe, s21_decimal delitel);
int mod_number(s21_decimal num);

//всапомогательные функции для биг децимал
void print_big_decimal(s21_big_decimal num);
s21_big_decimal to_big_decimal(s21_decimal num);
int get_bit_bd(s21_big_decimal num, int index);
void set_bit_bd(s21_big_decimal *decl, int index, int bit);
int get_znak_bd(s21_big_decimal num);
void set_znak_bd(s21_big_decimal *num, int znak);
int get_scale_bd(s21_big_decimal num);
void set_scale_bd(s21_big_decimal *num, int scale);
void left_shift_bd(s21_big_decimal *num, int shift);
void normalize(s21_big_decimal *num1, s21_big_decimal *num2);
int max_bit_level_bd(s21_big_decimal num);
void add_for_normalize(s21_big_decimal value_1, s21_big_decimal value_2,
                       s21_big_decimal *result);
int check_for_null_bd(s21_big_decimal num);
void clear_bd(s21_big_decimal *num);
int bit_shift_right(s21_big_decimal *num, int shift);
void bit_shift_left(s21_big_decimal *num, int shift);
int normaliz_add_sub(s21_big_decimal *value_1, s21_big_decimal *value_2);
int s21_div_bd(s21_big_decimal big_num_1, s21_big_decimal big_num_2,
               s21_big_decimal *big_res);
void right_shift_bd(s21_big_decimal *num, int shift);
int s21_is_less_bd(s21_big_decimal num1, s21_big_decimal num2);
int s21_is_greater_bd(s21_big_decimal num1, s21_big_decimal num2);
int s21_is_equal_bd(s21_big_decimal num1, s21_big_decimal num2);
int s21_is_greater_or_equal_bd(s21_big_decimal num1, s21_big_decimal num2);
int mod_bd(s21_big_decimal *delimoe, s21_big_decimal delitel);
int mod_number_bd(s21_big_decimal num);
void s21_bank_bd(s21_big_decimal *value, int num);

//функции сравнения
int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_less_big(s21_big_decimal num1, s21_big_decimal num2);
int s21_is_equal_big(s21_big_decimal num1, s21_big_decimal num2);

//функции конвертации
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);

//Вспомогательные для конвертации
int check_dec_to_int_flot(s21_decimal num);
int s21_scale_checking(s21_decimal *dst, int scale);
void s21_conversion_float(float src, unsigned int *mantissa, int *scale);
int s21_checking_float(float value);

//другие функции
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);

//мат функции
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//всапомогательные функции для мат
s21_big_decimal try_div(s21_big_decimal value_1, s21_big_decimal value_2,
                        s21_big_decimal *result);
int div_bd(s21_big_decimal value_1, s21_big_decimal value_2,
           s21_big_decimal *result);
void result_to_dec_div(s21_decimal *result, s21_big_decimal big_result,
                       s21_big_decimal big_num_2, int *res);
void result_to_dec_div(s21_decimal *result, s21_big_decimal big_result,
                       s21_big_decimal big_num_2, int *res);
int s21_mul_big(s21_big_decimal value_1, s21_big_decimal value_2,
                s21_big_decimal *result);
int sub(s21_big_decimal value_1, s21_big_decimal value_2,
        s21_big_decimal *result);
int norm_and_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
int sub_big(s21_big_decimal value_1, s21_big_decimal value_2,
            s21_big_decimal *result);
int add(s21_big_decimal value_1, s21_big_decimal value_2,
        s21_big_decimal *result);
int norm_and_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
s21_decimal big_to_decimal(s21_big_decimal num);
s21_decimal try_big_to_decimal(s21_big_decimal num);

#endif