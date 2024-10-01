#include "s21_test.h"

START_TEST(cos_1) {
  double a = 0;
  ck_assert_ldouble_eq_tol(cos(a), s21_cos(a), 1e-6);
}
END_TEST

START_TEST(cos_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(cos(a), s21_cos(a), 1e-6);
}
END_TEST

START_TEST(cos_3) {
  double a = -1;
  ck_assert_ldouble_eq_tol(cos(a), s21_cos(a), 1e-6);
}
END_TEST

START_TEST(cos_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_cos(a));
}
END_TEST

START_TEST(cos_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_cos(a));
}
END_TEST

START_TEST(cos_6) {
  double a = -3.2;
  ck_assert_ldouble_eq_tol(cos(a), s21_cos(a), 1e-6);
}
END_TEST

START_TEST(cos_7) {
  double a = 3.2;
  ck_assert_ldouble_eq_tol(cos(a), s21_cos(a), 1e-6);
}
END_TEST

START_TEST(cos_8) {
  double a = s21_infm;
  ck_assert_ldouble_nan(s21_cos(a));
}
END_TEST

START_TEST(cos_9) {
  double a = s21_infp;
  ck_assert_ldouble_nan(s21_cos(a));
}
END_TEST

START_TEST(cos_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(cos(a), s21_cos(a), 1e-6);
}
END_TEST

START_TEST(cos_11) {
  double a = -0.1;
  ck_assert_ldouble_eq_tol(cos(a), s21_cos(a), 1e-6);
}
END_TEST

Suite *test_cos(void) {
  Suite *s = suite_create("\033[45m-=S21_COS=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, cos_1);
  tcase_add_test(tc, cos_2);
  tcase_add_test(tc, cos_3);
  tcase_add_test(tc, cos_4);
  tcase_add_test(tc, cos_5);
  tcase_add_test(tc, cos_6);
  tcase_add_test(tc, cos_7);
  tcase_add_test(tc, cos_8);
  tcase_add_test(tc, cos_9);
  tcase_add_test(tc, cos_10);
  tcase_add_test(tc, cos_11);
  suite_add_tcase(s, tc);
  return s;
}