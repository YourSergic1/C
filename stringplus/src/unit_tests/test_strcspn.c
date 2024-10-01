#include "s21_test.h"

START_TEST(strcspn_1) {
  char str[10] = "0123456789";
  char sym[10] = "9876";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_2) {
  char str[10] = "0123456789";
  char sym[10] = "123";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_3) {
  char str[10] = "123";
  char sym[10] = "0123456789";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_4) {
  char str[10] = "";
  char sym[10] = "0123456789";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_5) {
  char str[10] = "0123456789";
  char sym[10] = "";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_6) {
  char str[20] = "\00123456789";
  char sym[10] = "34";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_7) {
  char str[20] = "0123456789";
  char sym[10] = "\034";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_8) {
  char str[20] = "\00123456789";
  char sym[10] = "\034";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_9) {
  char str[20] = "abc";
  char sym[10] = "abc";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_10) {
  char str[20] = "abc";
  char sym[10] = "abc123";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_11) {
  char str[20] = "abc123";
  char sym[10] = "abc";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_12) {
  char str[20] = "";
  char sym[10] = "";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_13) {
  char str[20] = "\0";
  char sym[10] = "";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_14) {
  char str[20] = "";
  char sym[10] = "\0";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

START_TEST(strcspn_15) {
  char str[20] = "1234567u\0";
  char sym[10] = "12345678\0";

  ck_assert_int_eq(strcspn(str, sym), s21_strcspn(str, sym));
}
END_TEST

Suite *test_strspn(void) {
  Suite *s = suite_create("\033[45m-=S21_STRSPN=-\033[0m");
  TCase *tc = tcase_create("strspn_tc");

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);
  tcase_add_test(tc, strcspn_11);
  tcase_add_test(tc, strcspn_12);
  tcase_add_test(tc, strcspn_13);
  tcase_add_test(tc, strcspn_14);
  tcase_add_test(tc, strcspn_15);

  suite_add_tcase(s, tc);
  return s;
}
