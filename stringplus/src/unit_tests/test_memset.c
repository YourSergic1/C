#include "s21_test.h"

START_TEST(memset_1) {
  char src1[] = "1234567890";
  char src2[] = "1234567890";

  int ch = ' ';
  s21_size_t n = strlen(src1);

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

START_TEST(memset_2) {
  char src1[] = "1234567890";
  char src2[] = "1234567890";

  int ch = ' ';
  s21_size_t n = 2;

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

START_TEST(memset_3) {
  char src1[] = "1234567890";
  char src2[] = "1234567890";

  int ch = ' ';
  s21_size_t n = 0;

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

START_TEST(memset_4) {
  char src1[] = "1234567890";
  char src2[] = "1234567890";

  int ch = '\0';
  s21_size_t n = strlen(src1);

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

START_TEST(memset_5) {
  char src1[] = "1234567890";
  char src2[] = "1234567890";

  int ch = 1;
  s21_size_t n = 2;

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

START_TEST(memset_6) {
  char src1[] = "1234567890";
  char src2[] = "1234567890";

  int ch = 100;
  s21_size_t n = 2;

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

START_TEST(memset_7) {
  char src1[] = "\0\0\0\0\0";
  char src2[] = "\0\0\0\0\0";

  int ch = 10;
  s21_size_t n = 2;

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST
START_TEST(memset_8) {
  char src1[] = "\011111111\0\0\0\0";
  char src2[] = "\011111111\0\0\0\0";

  int ch = 10;
  s21_size_t n = 5;

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

START_TEST(memset_9) {
  char src1[] = "1234567890";
  char src2[] = "1234567890";

  int ch = 100;
  s21_size_t n = 2;

  memset(src1, '\0', n);
  s21_memset(src2, '\0', n);

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

START_TEST(memset_10) {
  char src1[] = "\0\01234567890";
  char src2[] = "\0\01234567890";

  int ch = 0;
  s21_size_t n = 2;

  memset(src1, '-', n);
  s21_memset(src2, '-', n);

  ck_assert_str_eq(memset(src1, ch, n), s21_memset(src2, ch, n));
}
END_TEST

Suite *test_memset(void) {
  Suite *s = suite_create("\033[45m-=S21_MEMSET=-\033[0m");
  TCase *tc = tcase_create("memset_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);
  tcase_add_test(tc, memset_7);
  tcase_add_test(tc, memset_8);
  tcase_add_test(tc, memset_9);
  tcase_add_test(tc, memset_10);

  suite_add_tcase(s, tc);
  return s;
}
