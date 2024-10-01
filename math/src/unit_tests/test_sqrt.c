#include "s21_test.h"

START_TEST(sqrt_1) {
  double a = 0;
  ck_assert_ldouble_eq_tol(sqrt(a), s21_sqrt(a), 1e-6);
}
END_TEST

START_TEST(sqrt_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(sqrt(a), s21_sqrt(a), 1e-6);
}
END_TEST

START_TEST(sqrt_3) {
  double a = -1;
  ck_assert_ldouble_nan(s21_sqrt(a));
}
END_TEST

START_TEST(sqrt_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_sqrt(a));
}
END_TEST

START_TEST(sqrt_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_sqrt(a));
}
END_TEST

START_TEST(sqrt_6) {
  double a = -3.2;
  ck_assert_ldouble_nan(s21_sqrt(a));
}
END_TEST

START_TEST(sqrt_7) {
  double a = 3.2;
  ck_assert_ldouble_eq_tol(sqrt(a), s21_sqrt(a), 1e-6);
}
END_TEST

START_TEST(sqrt_8) {
  double a = s21_infm;
  ck_assert_ldouble_nan(s21_sqrt(a));
}
END_TEST

START_TEST(sqrt_9) {
  double a = s21_infp;
  ck_assert_ldouble_eq(sqrt(a), s21_sqrt(a));
}
END_TEST

START_TEST(sqrt_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(sqrt(a), s21_sqrt(a), 1e-6);
}
END_TEST

START_TEST(sqrt_11) {
  double a = -0.1;
  ck_assert_ldouble_nan(s21_sqrt(a));
}
END_TEST

Suite *test_sqrt(void) {
  Suite *s = suite_create("\033[45m-=S21_SQRT=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, sqrt_1);
  tcase_add_test(tc, sqrt_2);
  tcase_add_test(tc, sqrt_3);
  tcase_add_test(tc, sqrt_4);
  tcase_add_test(tc, sqrt_5);
  tcase_add_test(tc, sqrt_6);
  tcase_add_test(tc, sqrt_7);
  tcase_add_test(tc, sqrt_8);
  tcase_add_test(tc, sqrt_9);
  tcase_add_test(tc, sqrt_10);
  tcase_add_test(tc, sqrt_11);
  suite_add_tcase(s, tc);
  return s;
}