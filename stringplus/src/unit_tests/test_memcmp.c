#include "s21_test.h"

START_TEST(memcmp_1) {
  unsigned char str1[15] = "AB4567890";
  unsigned char str2[15] = "AB4567890";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  unsigned char str1[15] = "21234567890";
  unsigned char str2[15] = "1234567890";
  s21_size_t n = 0;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str1, n));
}
END_TEST

START_TEST(memcmp_3) {
  unsigned char str1[15] = "1234567890-1";
  unsigned char str2[15] = "1234567890";
  s21_size_t n = 15;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  unsigned char str1[15] = "\01234567890-1";
  unsigned char str2[15] = "1234567890";
  s21_size_t n = 15;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_5) {
  unsigned char str1[15] = "1234567890-1";
  unsigned char str2[15] = "1234567890";
  s21_size_t n = 12;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  unsigned char str1[15] = "AAABBB";
  unsigned char str2[15] = "aaabbb";
  s21_size_t n = 12;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  unsigned char str1[15] = "1234567890";
  unsigned char str2[15] = "";
  s21_size_t n = 12;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  unsigned char str1[15] = "1234567890";
  unsigned char str2[15] = "\0\0\0\0\0";
  s21_size_t n = 12;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_9) {
  unsigned char str1[15] = "12345\0";
  unsigned char str2[15] = "\012345";
  s21_size_t n = 12;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_10) {
  unsigned char str1[15] = "12345\0";
  unsigned char str2[15] = "\012345";
  s21_size_t n = 0;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_11) {
  unsigned char str1[15] = "\0123";
  unsigned char str2[15] = "\0123";
  s21_size_t n = 15;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_12) {
  unsigned char str1[15] = "\0124";
  unsigned char str2[15] = "\0123";
  s21_size_t n = 15;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_13) {
  char str1[16] = "aabbaa";
  char str2[16] = "\0aabbaa";
  s21_size_t n = 5;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14) {
  char str1[16] = "aabbbb";
  char str2[16] = "\0aabbaa";
  s21_size_t n = 5;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14_1) {
  char str1[16] = "\0aabbbb";
  char str2[16] = "\0aabbaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14_2) {
  char str1[16] = "\0babbbb";
  char str2[16] = "\0aabbaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14_3) {
  char str1[16] = "\0Aabbbb";
  char str2[16] = "\0aabbaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14_4) {
  char str1[16] = "\0Aabbbb";
  char str2[16] = "A\0abbbb";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14_5) {
  char str1[16] = "aaa\0aaa";
  char str2[16] = "aaa\0aaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14_6) {
  char str1[16] = "aaa\0Aaa";
  char str2[16] = "aaa\0aaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14_7) {
  char str1[16] = "aaa\0bbb";
  char str2[16] = "aaa\0aaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_14_8) {
  char str1[16] = "\0aabbaa";
  char str2[16] = "\0aabbaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_15) {
  char str1[16] = "\0aabbaa";
  char str2[16] = "\0aabbaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_16) {
  char str1[16] = "\0aabbbb";
  char str2[16] = "\0aabbaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_17) {
  char str1[16] = "AABBAA";
  char str2[16] = "aabbaa";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_18) {
  char str1[16] = "AaBbCc";
  char str2[16] = "aAbBcC";
  s21_size_t n = 7;

  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

Suite *test_memcmp(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCMY=-\033[0m");
  TCase *tc = tcase_create("memcmy_tc");

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  tcase_add_test(tc, memcmp_11);
  tcase_add_test(tc, memcmp_12);
  tcase_add_test(tc, memcmp_13);
  tcase_add_test(tc, memcmp_14);
  tcase_add_test(tc, memcmp_14_1);
  tcase_add_test(tc, memcmp_14_2);
  tcase_add_test(tc, memcmp_14_3);
  tcase_add_test(tc, memcmp_14_4);
  tcase_add_test(tc, memcmp_14_5);
  tcase_add_test(tc, memcmp_14_6);
  tcase_add_test(tc, memcmp_14_7);
  tcase_add_test(tc, memcmp_14_8);
  tcase_add_test(tc, memcmp_15);
  tcase_add_test(tc, memcmp_16);
  tcase_add_test(tc, memcmp_17);
  tcase_add_test(tc, memcmp_18);

  suite_add_tcase(s, tc);
  return s;
}
