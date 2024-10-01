#include "s21_test.h"

START_TEST(ceil_1) {
  double a = 0;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_2) {
  double a = -0.1;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_3) {
  double a = 0.1;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_4) {
  double a = 1;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_5) {
  double a = -1;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_6) {
  double a = s21_infp;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_7) {
  double a = s21_infm;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_8) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_ceil(a));
}
END_TEST

START_TEST(ceil_9) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_ceil(a));
}
END_TEST

START_TEST(ceil_10) {
  double a = -378.2;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(ceil_11) {
  double a = 378.2;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

Suite *test_ceil(void) {
  Suite *s = suite_create("\033[45m-=S21_CEIL=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, ceil_1);
  tcase_add_test(tc, ceil_2);
  tcase_add_test(tc, ceil_3);
  tcase_add_test(tc, ceil_4);
  tcase_add_test(tc, ceil_5);
  tcase_add_test(tc, ceil_6);
  tcase_add_test(tc, ceil_7);
  tcase_add_test(tc, ceil_8);
  tcase_add_test(tc, ceil_9);
  tcase_add_test(tc, ceil_10);
  tcase_add_test(tc, ceil_11);
  suite_add_tcase(s, tc);
  return s;
}
