#include "s21_test.h"

START_TEST(tan_1) {
  double a = 0;
  ck_assert_ldouble_eq_tol(tan(a), s21_tan(a), 1e-6);
}
END_TEST

START_TEST(tan_2) {
  double a = 1;
  ck_assert_ldouble_eq_tol(tan(a), s21_tan(a), 1e-6);
}
END_TEST

START_TEST(tan_3) {
  double a = -1;
  ck_assert_ldouble_eq_tol(tan(a), s21_tan(a), 1e-6);
}
END_TEST

START_TEST(tan_4) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_tan(a));
}
END_TEST

START_TEST(tan_5) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_tan(a));
}
END_TEST

START_TEST(tan_6) {
  double a = -3.2;
  ck_assert_ldouble_eq_tol(tan(a), s21_tan(a), 1e-6);
}
END_TEST

START_TEST(tan_7) {
  double a = 3.2;
  ck_assert_ldouble_eq_tol(tan(a), s21_tan(a), 1e-6);
}
END_TEST

START_TEST(tan_8) {
  double a = s21_infm;
  ck_assert_ldouble_nan(s21_tan(a));
}
END_TEST

START_TEST(tan_9) {
  double a = s21_infp;
  ck_assert_ldouble_nan(s21_tan(a));
}
END_TEST

START_TEST(tan_10) {
  double a = 0.1;
  ck_assert_ldouble_eq_tol(tan(a), s21_tan(a), 1e-6);
}
END_TEST

START_TEST(tan_11) {
  double a = -0.1;
  ck_assert_ldouble_eq_tol(tan(a), s21_tan(a), 1e-6);
}
END_TEST

Suite *test_tan(void) {
  Suite *s = suite_create("\033[45m-=S21_TAN=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, tan_1);
  tcase_add_test(tc, tan_2);
  tcase_add_test(tc, tan_3);
  tcase_add_test(tc, tan_4);
  tcase_add_test(tc, tan_5);
  tcase_add_test(tc, tan_6);
  tcase_add_test(tc, tan_7);
  tcase_add_test(tc, tan_8);
  tcase_add_test(tc, tan_9);
  tcase_add_test(tc, tan_10);
  tcase_add_test(tc, tan_11);
  suite_add_tcase(s, tc);
  return s;
}