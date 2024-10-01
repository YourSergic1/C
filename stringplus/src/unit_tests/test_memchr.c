#include "s21_test.h"

START_TEST(memchr_1) {
  const char src[15] = "1234567890";
  const unsigned int ch = '\0';

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_2) {
  const char src[15] = "1234567890";
  const unsigned int ch = '0';

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_3) {
  const char src[15] = "1234567890";
  const unsigned int ch = 'h';

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_4) {
  const char src[20] = "!12!34!56!78!90!";
  const unsigned int ch = '!';

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_5) {
  const char src[15] = "123\04567890";
  const unsigned int ch = '7';

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_6) {
  const char src[15] = "123\04567890";
  const unsigned int ch = '\0';

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_7) {
  const char src[15] = "f23\0456k8r0";
  const unsigned int ch = 'f';

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_8) {
  const char src[15] = "abcd";
  const unsigned int ch = 5;

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_9) {
  const char src[15] = "abcd";
  const unsigned int ch = 445;

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

START_TEST(memchr_10) {
  const char src[15] = "ab\ncd";
  const unsigned int ch = 10;

  s21_size_t len = strlen(src);
  ck_assert_ptr_eq(memchr(src, ch, len), s21_memchr(src, ch, len));
}
END_TEST

Suite *test_memcht(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMCHR=-\033[0m");
  TCase *tc = tcase_create("memchr_tc");

  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);
  tcase_add_test(tc, memchr_7);
  tcase_add_test(tc, memchr_8);
  tcase_add_test(tc, memchr_9);
  tcase_add_test(tc, memchr_10);

  suite_add_tcase(s, tc);
  return s;
}
