#include "s21_test.h"

START_TEST(floor_1) {
  double a = 0;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_2) {
  double a = -0.1;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_3) {
  double a = 0.1;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_4) {
  double a = 1;
  ck_assert_ldouble_eq(ceil(a), s21_ceil(a));
}
END_TEST

START_TEST(floor_5) {
  double a = -1;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_6) {
  double a = s21_infp;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_7) {
  double a = s21_infm;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_8) {
  double a = -s21_nan;
  ck_assert_ldouble_nan(s21_floor(a));
}
END_TEST

START_TEST(floor_9) {
  double a = s21_nan;
  ck_assert_ldouble_nan(s21_floor(a));
}
END_TEST

START_TEST(floor_10) {
  double a = -378.2;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

START_TEST(floor_11) {
  double a = 378.2;
  ck_assert_ldouble_eq(floor(a), s21_floor(a));
}
END_TEST

Suite *test_floor(void) {
  Suite *s = suite_create("\033[45m-=S21_FLOOR=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_4);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);
  tcase_add_test(tc, floor_7);
  tcase_add_test(tc, floor_8);
  tcase_add_test(tc, floor_9);
  tcase_add_test(tc, floor_10);
  tcase_add_test(tc, floor_11);
  suite_add_tcase(s, tc);
  return s;
}
