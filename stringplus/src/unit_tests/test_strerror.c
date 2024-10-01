#include "s21_test.h"

START_TEST(strerror_1) { ck_assert_str_eq("Success", s21_strerror(0)); }
END_TEST

START_TEST(strerror_2) {
  ck_assert_str_eq("Operation not permitted", s21_strerror(1));
}
END_TEST

START_TEST(strerror_3) {
  ck_assert_str_eq("No such file or directory", s21_strerror(2));
}
END_TEST

START_TEST(strerror_4) { ck_assert_str_eq("No such process", s21_strerror(3)); }
END_TEST

START_TEST(strerror_5) {
  ck_assert_str_eq("Interrupted system call", s21_strerror(4));
}
END_TEST

START_TEST(strerror_6) {
  ck_assert_str_eq("Input/output error", s21_strerror(5));
}
END_TEST

START_TEST(strerror_7) {
  ck_assert_str_eq("No such device or address", s21_strerror(6));
}
END_TEST

START_TEST(strerror_8) {
  ck_assert_str_eq("Argument list too long", s21_strerror(7));
}
END_TEST

START_TEST(strerror_9) {
  ck_assert_str_eq("Exec format error", s21_strerror(8));
}
END_TEST

START_TEST(strerror_10) {
  ck_assert_str_eq("Bad file descriptor", s21_strerror(9));
}
END_TEST

START_TEST(strerror_11) {
  int n = -1;
  ck_assert_str_eq("Unknown error -1", s21_strerror(n));
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("\033[45m-=S21_STRERROR=-\033[0m");
  TCase *tc = tcase_create("strerror_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strerror_5);
  tcase_add_test(tc, strerror_6);
  tcase_add_test(tc, strerror_7);
  tcase_add_test(tc, strerror_8);
  tcase_add_test(tc, strerror_9);
  tcase_add_test(tc, strerror_10);
  tcase_add_test(tc, strerror_11);

  suite_add_tcase(s, tc);
  return s;
}
