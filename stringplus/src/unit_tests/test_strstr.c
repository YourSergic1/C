#include "s21_test.h"

START_TEST(strstr_1) {
  char str1[11] = "0123456789";
  char str2[10] = "345";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_2) {
  char str1[11] = "0123456789";
  char str2[10] = "0123456789";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_3) {
  char str1[11] = "0123456789";
  char str2[10] = "0123!";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_4) {
  char str1[11] = "0123456789";
  char str2[10] = "9";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_5) {
  char str1[30] = "123 12 123 12 123 12";
  char str2[10] = "123";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_6) {
  char str1[30] = "";
  char str2[10] = "";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_7) {
  char str1[30] = "1";
  char str2[10] = "";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_8) {
  char str1[30] = "";
  char str2[10] = "1";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_9) {
  char str1[30] = "\0123";
  char str2[10] = "";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_10) {
  char str1[30] = "";
  char str2[10] = "\0123";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_11) {
  char str1[30] = "\0123";
  char str2[10] = "\0123";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_12) {
  char str1[30] = "123\0123";
  char str2[10] = "\0123";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_13) {
  char str1[30] = "\0123";
  char str2[10] = "123\0123";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_14) {
  char str1[30] = "123\0123";
  char str2[10] = "123\0123";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

START_TEST(strstr_15) {
  char str1[30] = "123\0123";
  char str2[10] = "\0123";

  ck_assert_pstr_eq(strstr(str1, str2), s21_strstr(str1, str2));
}
END_TEST

Suite *test_strstr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRSTR=-\033[0m");
  TCase *tc = tcase_create("strstr_tc");

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  tcase_add_test(tc, strstr_11);
  tcase_add_test(tc, strstr_12);
  tcase_add_test(tc, strstr_13);
  tcase_add_test(tc, strstr_14);
  tcase_add_test(tc, strstr_15);

  suite_add_tcase(s, tc);
  return s;
}
