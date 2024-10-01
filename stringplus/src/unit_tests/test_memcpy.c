#include "s21_test.h"

START_TEST(memcpy_1) {
  unsigned char src[15] = "1234567890";
  unsigned char dst1[10] = "";
  unsigned char dst2[10] = "";

  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_2) {
  unsigned char src[15] = "\0";
  unsigned char dst1[10] = "123";
  unsigned char dst2[10] = "123";

  s21_size_t n = 1;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_3) {
  unsigned char src[15] = "\0";
  unsigned char dst1[10] = "123";
  unsigned char dst2[10] = "123";

  s21_size_t n = 0;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_4) {
  unsigned char src[15] = "789";
  unsigned char dst1[10] = "123456789";
  unsigned char dst2[10] = "123456789";

  s21_size_t n = 4;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_5) {
  unsigned char src[15] = "7\t89";
  unsigned char dst1[10] = "123456789";
  unsigned char dst2[10] = "123456789";

  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_6) {
  unsigned char src[15] = "7t89K";
  unsigned char dst1[10] = "";
  unsigned char dst2[10] = "";

  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_7) {
  char src[15] = "7\089123";
  unsigned char dst1[10] = "123456789";
  unsigned char dst2[10] = "123456789";

  s21_size_t n = strlen(src);
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_8) {
  unsigned char src[15] = "ffff";
  unsigned char dst1[10] = "\0123";
  unsigned char dst2[10] = "\0123";

  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_9) {
  unsigned char src[15] = "\0ffff";
  unsigned char dst1[10] = "\0123";
  unsigned char dst2[10] = "\0123";

  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

START_TEST(memcpy_10) {
  unsigned char src[15] = "kk1\0ffff";
  unsigned char dst1[10] = "110123";
  unsigned char dst2[10] = "110123";

  s21_size_t n = 2;
  ck_assert_str_eq(memcpy(dst1, src, n), s21_memcpy(dst2, src, n));
}
END_TEST

Suite *test_memcpy(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCPY=-\033[0m");
  TCase *tc = tcase_create("memcpy_tc");

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);
  tcase_add_test(tc, memcpy_6);
  tcase_add_test(tc, memcpy_7);
  tcase_add_test(tc, memcpy_8);
  tcase_add_test(tc, memcpy_9);
  tcase_add_test(tc, memcpy_10);

  suite_add_tcase(s, tc);
  return s;
}
