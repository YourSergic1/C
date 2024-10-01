#include "s21_test.h"

START_TEST(sin_1) {
  double a = 0;
  ck_assert_ldouble_eq_tol(sin(a), s21_sin(a), 1e-6);
}
END_TEST

START_TEST(sin_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(sin(a), s21_sin(a), 1e-6);
}
END_TEST

START_TEST(sin_3) {
  double a = -1;
  ck_assert_ldouble_eq_tol(sin(a), s21_sin(a), 1e-6);
}
END_TEST

START_TEST(sin_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_sin(a));
}
END_TEST

START_TEST(sin_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_sin(a));
}
END_TEST

START_TEST(sin_6) {
  double a = -3.2;
  ck_assert_ldouble_eq_tol(sin(a), s21_sin(a), 1e-6);
}
END_TEST

START_TEST(sin_7) {
  double a = 3.2;
  ck_assert_ldouble_eq_tol(sin(a), s21_sin(a), 1e-6);
}
END_TEST

START_TEST(sin_8) {
  double a = s21_infm;
  ck_assert_ldouble_nan(s21_sin(a));
}
END_TEST

START_TEST(sin_9) {
  double a = s21_infp;
  ck_assert_ldouble_nan(s21_sin(a));
}
END_TEST

START_TEST(sin_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(sin(a), s21_sin(a), 1e-6);
}
END_TEST

START_TEST(sin_11) {
  double a = -0.1;
  ck_assert_ldouble_eq_tol(sin(a), s21_sin(a), 1e-6);
}
END_TEST

Suite *test_sin(void) {
  Suite *s = suite_create("\033[45m-=S21_SIN=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, sin_1);
  tcase_add_test(tc, sin_2);
  tcase_add_test(tc, sin_3);
  tcase_add_test(tc, sin_4);
  tcase_add_test(tc, sin_5);
  tcase_add_test(tc, sin_6);
  tcase_add_test(tc, sin_7);
  tcase_add_test(tc, sin_8);
  tcase_add_test(tc, sin_9);
  tcase_add_test(tc, sin_10);
  tcase_add_test(tc, sin_11);
  suite_add_tcase(s, tc);
  return s;
}