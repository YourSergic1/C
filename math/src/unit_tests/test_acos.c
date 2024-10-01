#include "s21_test.h"

START_TEST(acos_1) {
  double a = 0;
  ck_assert_ldouble_eq_tol(acos(a), s21_acos(a), 1e-6);
}
END_TEST

START_TEST(acos_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(acos(a), s21_acos(a), 1e-6);
}
END_TEST

START_TEST(acos_3) {
  double a = -1;
  ck_assert_ldouble_eq_tol(acos(a), s21_acos(a), 1e-6);
}
END_TEST

START_TEST(acos_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_acos(a));
}
END_TEST

START_TEST(acos_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_acos(a));
}
END_TEST

START_TEST(acos_6) {
  double a = s21_infm;
  ck_assert_ldouble_nan(s21_acos(a));
}
END_TEST

START_TEST(acos_7) {
  double a = s21_infp;
  ck_assert_ldouble_nan(s21_acos(a));
}
END_TEST

START_TEST(acos_8) {
  double a = -33.2;
  ck_assert_ldouble_nan(s21_acos(a));
}
END_TEST

START_TEST(acos_9) {
  double a = 31.2;
  ck_assert_ldouble_nan(s21_acos(a));
}
END_TEST

START_TEST(acos_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(acos(a), s21_acos(a), 1e-6);
}
END_TEST

START_TEST(acos_11) {
  double a = -0.1;
  ck_assert_ldouble_eq_tol(acos(a), s21_acos(a), 1e-6);
}
END_TEST

Suite *test_acos(void) {
  Suite *s = suite_create("\033[45m-=S21_ACOS=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, acos_1);
  tcase_add_test(tc, acos_2);
  tcase_add_test(tc, acos_3);
  tcase_add_test(tc, acos_4);
  tcase_add_test(tc, acos_5);
  tcase_add_test(tc, acos_6);
  tcase_add_test(tc, acos_7);
  tcase_add_test(tc, acos_8);
  tcase_add_test(tc, acos_9);
  tcase_add_test(tc, acos_10);
  tcase_add_test(tc, acos_11);
  suite_add_tcase(s, tc);
  return s;
}