#include "s21_test.h"

START_TEST(abs_1) {
  int a = 0;
  ck_assert_int_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_2) {
  int a = -1;
  ck_assert_int_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_3) {
  int a = 1;
  ck_assert_int_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_4) {
  int a = -199;
  ck_assert_int_eq(abs(a), s21_abs(a));
}
END_TEST

START_TEST(abs_5) {
  int a = 199;
  ck_assert_int_eq(abs(a), s21_abs(a));
}
END_TEST

Suite *test_abs(void) {
  Suite *s = suite_create("\033[45m-=S21_ABS=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, abs_1);
  tcase_add_test(tc, abs_2);
  tcase_add_test(tc, abs_3);
  tcase_add_test(tc, abs_4);
  tcase_add_test(tc, abs_5);
  tcase_add_test(tc, abs_4);
  suite_add_tcase(s, tc);
  return s;
}
