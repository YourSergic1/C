#include "s21_test.h"

START_TEST(asin_1) {
  double a = 0;
  ck_assert_ldouble_eq_tol(asin(a), s21_asin(a), 1e-6);
}
END_TEST

START_TEST(asin_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(asin(a), s21_asin(a), 1e-6);
}
END_TEST

START_TEST(asin_3) {
  double a = -1;
  ck_assert_ldouble_eq_tol(asin(a), s21_asin(a), 1e-6);
}
END_TEST

START_TEST(asin_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_asin(a));
}
END_TEST

START_TEST(asin_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_asin(a));
}
END_TEST

START_TEST(asin_6) {
  double a = s21_infm;
  ck_assert_ldouble_nan(s21_asin(a));
}
END_TEST

START_TEST(asin_7) {
  double a = s21_infp;
  ck_assert_ldouble_nan(s21_asin(a));
}
END_TEST

START_TEST(asin_8) {
  double a = -33.2;
  ck_assert_ldouble_nan(s21_asin(a));
}
END_TEST

START_TEST(asin_9) {
  double a = 31.2;
  ck_assert_ldouble_nan(s21_asin(a));
}
END_TEST

START_TEST(asin_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(asin(a), s21_asin(a), 1e-6);
}
END_TEST

START_TEST(asin_11) {
  double a = -0.1;
  ck_assert_ldouble_eq_tol(asin(a), s21_asin(a), 1e-6);
}
END_TEST

Suite *test_asin(void) {
  Suite *s = suite_create("\033[45m-=S21_ASIN=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, asin_1);
  tcase_add_test(tc, asin_2);
  tcase_add_test(tc, asin_3);
  tcase_add_test(tc, asin_4);
  tcase_add_test(tc, asin_5);
  tcase_add_test(tc, asin_6);
  tcase_add_test(tc, asin_7);
  tcase_add_test(tc, asin_8);
  tcase_add_test(tc, asin_9);
  tcase_add_test(tc, asin_10);
  tcase_add_test(tc, asin_11);
  suite_add_tcase(s, tc);
  return s;
}