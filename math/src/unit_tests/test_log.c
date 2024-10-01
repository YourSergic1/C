#include "s21_test.h"

START_TEST(log_1) {
  double a = 0;
  ck_assert_ldouble_eq(log(a), s21_log(a));
}
END_TEST

START_TEST(log_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), 1e-6);
}
END_TEST

START_TEST(log_3) {
  double a = -1;
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(log_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(log_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(log_6) {
  double a = s21_infm;
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(log_7) {
  double a = s21_infp;
  ck_assert_ldouble_eq(log(a), s21_log(a));
}
END_TEST

START_TEST(log_8) {
  double a = -33.2;
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

START_TEST(log_9) {
  double a = 13.2;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), 1e-6);
}
END_TEST

START_TEST(log_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(log(a), s21_log(a), 1e-6);
}
END_TEST

START_TEST(log_11) {
  double a = -0.1;
  ck_assert_ldouble_nan(s21_log(a));
}
END_TEST

Suite *test_log(void) {
  Suite *s = suite_create("\033[45m-=S21_LOG=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, log_1);
  tcase_add_test(tc, log_2);
  tcase_add_test(tc, log_3);
  tcase_add_test(tc, log_4);
  tcase_add_test(tc, log_5);
  tcase_add_test(tc, log_6);
  tcase_add_test(tc, log_7);
  tcase_add_test(tc, log_8);
  tcase_add_test(tc, log_9);
  tcase_add_test(tc, log_10);
  tcase_add_test(tc, log_11);
  suite_add_tcase(s, tc);
  return s;
}