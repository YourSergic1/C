#include "s21_test.h"

START_TEST(fabs_1) {
  double a = 0;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_2) {
  double a = -1;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_3) {
  double a = 1;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_4) {
  double a = -0.1;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_5) {
  double a = 0.1;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_6) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_fabs(a));
}
END_TEST

START_TEST(fabs_7) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_fabs(a));
}
END_TEST

START_TEST(fabs_8) {
  double a = s21_infm;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_9) {
  double a = s21_infp;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_10) {
  double a = -32.3;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

START_TEST(fabs_11) {
  double a = 32.3;
  ck_assert_ldouble_eq(fabs(a), s21_fabs(a));
}
END_TEST

Suite *test_fabs(void) {
  Suite *s = suite_create("\033[45m-=S21_FABS=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, fabs_1);
  tcase_add_test(tc, fabs_2);
  tcase_add_test(tc, fabs_3);
  tcase_add_test(tc, fabs_4);
  tcase_add_test(tc, fabs_5);
  tcase_add_test(tc, fabs_6);
  tcase_add_test(tc, fabs_7);
  tcase_add_test(tc, fabs_8);
  tcase_add_test(tc, fabs_9);
  tcase_add_test(tc, fabs_10);
  tcase_add_test(tc, fabs_11);
  suite_add_tcase(s, tc);
  return s;
}