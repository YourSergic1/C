#include "s21_test.h"

START_TEST(strchr_1) {
  char str[11] = "0123456789";
  int ch = '6';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_2) {
  char str[11] = "0123456789";
  int ch = '\0';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_3) {
  char str[11] = "0123456789";
  int ch = '0';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_4) {
  char str[11] = "0123456789";
  int ch = 1;
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_5) {
  char str[11] = "0123456789";
  int ch = 'D';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_6) {
  char str[11] = "0123456789";
  int ch = ' ';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_7) {
  char str[11] = "0123 456789";
  int ch = ' ';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_8) {
  char str[20] = "0123 456\0\0789";
  int ch = ' ';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_9) {
  char str[13] = {'0', '1', '2', 3, '4', 5, 6, '\0', 0, '\0', 7, '8', '9'};
  int ch = ' ';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_10) {
  char str[13] = {'0', '1', '2', 3, '4', 5, 6, '\0', 0, '\0', 7, '8', '9'};
  int ch = '\0';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

Suite *test_strchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRCHR=-\033[0m");
  TCase *tc = tcase_create("strchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);
  tcase_add_test(tc, strchr_8);
  tcase_add_test(tc, strchr_9);
  tcase_add_test(tc, strchr_10);

  suite_add_tcase(s, tc);
  return s;
}
