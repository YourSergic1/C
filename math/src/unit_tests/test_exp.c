#include "s21_test.h"

START_TEST(exp_1) {
  double a = 0;
  ck_assert_ldouble_eq(exp(a), s21_exp(a));
}
END_TEST

START_TEST(exp_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), 1e-6);
}
END_TEST

START_TEST(exp_3) {
  double a = -1;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), 1e-6);
}
END_TEST

START_TEST(exp_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_exp(a));
}
END_TEST

START_TEST(exp_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_exp(a));
}
END_TEST

START_TEST(exp_6) {
  double a = s21_infm;
  ck_assert_ldouble_eq(exp(a), s21_exp(a));
}
END_TEST

START_TEST(exp_7) {
  double a = s21_infp;
  ck_assert_ldouble_eq(exp(a), s21_exp(a));
}
END_TEST

START_TEST(exp_8) {
  double a = -33.2;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), 1e-6);
}
END_TEST

START_TEST(exp_9) {
  double a = 13.2;
  ck_assert_float_eq_tol(exp(a), s21_exp(a), 1e-6);
}
END_TEST

START_TEST(exp_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), 1e-6);
}
END_TEST

START_TEST(exp_11) {
  double a = -0.1;
  ck_assert_ldouble_eq_tol(exp(a), s21_exp(a), 1e-6);
}
END_TEST

Suite *test_exp(void) {
  Suite *s = suite_create("\033[45m-=S21_EXP=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, exp_1);
  tcase_add_test(tc, exp_2);
  tcase_add_test(tc, exp_3);
  tcase_add_test(tc, exp_4);
  tcase_add_test(tc, exp_5);
  tcase_add_test(tc, exp_6);
  tcase_add_test(tc, exp_7);
  tcase_add_test(tc, exp_8);
  tcase_add_test(tc, exp_9);
  tcase_add_test(tc, exp_10);
  tcase_add_test(tc, exp_11);
  suite_add_tcase(s, tc);
  return s;
}