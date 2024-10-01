#include "s21_test.h"

START_TEST(strncpy_1) {
  char dst2[10] = "111111111";
  char dst1[10] = "111111111";

  char src[10] = "123";
  s21_size_t n = 3;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_2) {
  char dst2[10] = "111111111";
  char dst1[10] = "111111111";

  char src[10] = "123";
  s21_size_t n = 4;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_3) {
  char dst2[10] = "111111111";
  char dst1[10] = "111111111";

  char src[10] = "\0";
  s21_size_t n = 4;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_4) {
  char dst2[10] = "\0111111111";
  char dst1[10] = "\0111111111";

  char src[10] = "-a-b-c-d";
  s21_size_t n = 3;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_5) {
  char dst2[10] = "";
  char dst1[10] = "";

  char src[10] = "";
  s21_size_t n = 3;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_6) {
  char dst2[10] = "";
  char dst1[10] = "";

  char src[10] = "";
  s21_size_t n = 0;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_7) {
  char dst2[10] = "123";
  char dst1[10] = "123";

  char src[10] = "";
  s21_size_t n = 0;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_8) {
  char dst2[70] = {'\0'};
  char dst1[70] = {'\0'};

  char src[50] = "asdfghjhgfdfgherrwr3245t4y65juy432r4\0wrge6554w3";
  s21_size_t n = 50;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_9) {
  char dst2[10] = "";
  char dst1[10] = "";

  char src[50] = "\0";
  s21_size_t n = 1;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

START_TEST(strncpy_10) {
  char dst2[10] = "";
  char dst1[10] = "";

  char src[50] = "\0";
  s21_size_t n = 2;

  ck_assert_pstr_eq(strncpy(dst1, src, n), s21_strncpy(dst2, src, n));
}
END_TEST

Suite *test_strncpy(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCPY=-\033[0m");
  TCase *tc = tcase_create("strncpy_tc");

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);
  tcase_add_test(tc, strncpy_7);
  tcase_add_test(tc, strncpy_8);
  tcase_add_test(tc, strncpy_9);
  tcase_add_test(tc, strncpy_10);

  suite_add_tcase(s, tc);
  return s;
}
