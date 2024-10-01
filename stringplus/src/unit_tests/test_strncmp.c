#include "s21_test.h"

START_TEST(strncmp_1) {
  char str1[16] = "1234567890\0";
  char str2[16] = "1234507890\0";
  s21_size_t n = 14;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_2) {
  char str1[16] = "1234567890\0";
  char str2[16] = "1234507891\0";
  s21_size_t n = 14;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_3) {
  char str1[16] = "\0";
  char str2[16] = "\0";
  s21_size_t n = 14;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4) {
  char str1[16] = "1234567890\0";
  char str2[16] = "\0";
  s21_size_t n = 14;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  char str1[16] = "\0";
  char str2[16] = "1234567890\0";
  s21_size_t n = 14;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_6) {
  char str1[16] = "aabb\0";
  char str2[16] = "aabb\0";
  s21_size_t n = 14;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7) {
  char str1[16] = "aabbaa\0";
  char str2[16] = "aabbbb\0";
  s21_size_t n = 2;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_8) {
  char str1[16] = "aabbaa\0";
  char str2[16] = "aabbaa\0";
  s21_size_t n = 0;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_9) {
  char str1[16] = "\0aabbaa\0";
  char str2[16] = "aabbaa\0";
  s21_size_t n = 5;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_10) {
  char str1[16] = "\0aabbbb\0";
  char str2[16] = "aabbaa\0";
  s21_size_t n = 5;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_11) {
  char str1[16] = "aabbaa\0";
  char str2[16] = "\0aabbaa\0";
  s21_size_t n = 5;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_12) {
  char str1[16] = "aabbbb\0";
  char str2[16] = "\0aabbaa\0";
  s21_size_t n = 5;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_13) {
  char str1[16] = "\0aabbaa\0";
  char str2[16] = "\0aabbaa\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14_1) {
  char str1[16] = "\0aabbbb\0";
  char str2[16] = "\0aabbaa\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14_2) {
  char str1[16] = "\0babbbb\0";
  char str2[16] = "\0aabbaa\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14_3) {
  char str1[16] = "\0Aabbbb\0";
  char str2[16] = "\0aabbaa\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14_4) {
  char str1[16] = "\0Aabbbb\0";
  char str2[16] = "A\0abbbb\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14_5) {
  char str1[16] = "aaa\0aaa\0";
  char str2[16] = "aaa\0aaa\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14_6) {
  char str1[16] = "aaa\0Aaa\0";
  char str2[16] = "aaa\0aaa\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_14_7) {
  char str1[16] = "aaa\0bbb\0";
  char str2[16] = "aaa\0aaa\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_15) {
  char str1[16] = "AABBAA\0";
  char str2[16] = "aabbaa\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_16) {
  char str1[16] = "AaBbCc\0";
  char str2[16] = "aAbBcC\0";
  s21_size_t n = 7;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST
// ========
START_TEST(strncmp_17) {
  char str1[15] = "12345\0";
  char str2[15] = "\012345\0";
  s21_size_t n = 12;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_18) {
  char str1[15] = "12345\0";
  char str2[15] = "\012345\0";
  s21_size_t n = 0;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_19) {
  char str1[15] = "\0123\0";
  char str2[15] = "\0123\0";
  s21_size_t n = 15;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_20) {
  char str1[15] = "\0124\0";
  char str2[15] = "\0123\0";
  s21_size_t n = 15;

  ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *test_strncmp(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCMP=-\033[0m");
  TCase *tc = tcase_create("strncmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);
  tcase_add_test(tc, strncmp_11);
  tcase_add_test(tc, strncmp_12);
  tcase_add_test(tc, strncmp_13);
  tcase_add_test(tc, strncmp_14_1);
  tcase_add_test(tc, strncmp_14_2);
  tcase_add_test(tc, strncmp_14_3);
  tcase_add_test(tc, strncmp_14_4);
  tcase_add_test(tc, strncmp_14_5);
  tcase_add_test(tc, strncmp_14_6);
  tcase_add_test(tc, strncmp_14_7);
  tcase_add_test(tc, strncmp_15);
  tcase_add_test(tc, strncmp_16);
  tcase_add_test(tc, strncmp_17);
  tcase_add_test(tc, strncmp_18);
  tcase_add_test(tc, strncmp_19);
  tcase_add_test(tc, strncmp_20);

  suite_add_tcase(s, tc);
  return s;
}
