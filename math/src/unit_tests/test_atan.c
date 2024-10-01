#include "s21_test.h"

START_TEST(atan_1) {
  double a = 0;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

START_TEST(atan_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

START_TEST(atan_3) {
  double a = -1;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

START_TEST(atan_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_atan(a));
}
END_TEST

START_TEST(atan_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_atan(a));
}
END_TEST

START_TEST(atan_6) {
  double a = s21_infm;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

START_TEST(atan_7) {
  double a = s21_infp;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

START_TEST(atan_8) {
  double a = -33.2;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

START_TEST(atan_9) {
  double a = 31.2;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

START_TEST(atan_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

START_TEST(atan_11) {
  double a = -0.1;
  ck_assert_ldouble_eq_tol(atan(a), s21_atan(a), 1e-6);
}
END_TEST

Suite *test_atan(void) {
  Suite *s = suite_create("\033[45m-=S21_ATAN=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, atan_1);
  tcase_add_test(tc, atan_2);
  tcase_add_test(tc, atan_3);
  tcase_add_test(tc, atan_4);
  tcase_add_test(tc, atan_5);
  tcase_add_test(tc, atan_6);
  tcase_add_test(tc, atan_7);
  tcase_add_test(tc, atan_8);
  tcase_add_test(tc, atan_9);
  tcase_add_test(tc, atan_10);
  tcase_add_test(tc, atan_11);
  suite_add_tcase(s, tc);
  return s;
}