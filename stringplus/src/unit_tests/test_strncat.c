#include "s21_test.h"

START_TEST(strncat_1) {
  char src1[10] = "000";
  char src2[10] = "000";
  const char app[] = " 123";

  s21_size_t n = 1;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_2) {
  char src1[10] = "000";
  char src2[10] = "000";
  const char app[] = "\0\0\0";

  s21_size_t n = 1;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_3) {
  char src1[10] = "000";
  char src2[10] = "000";
  const char app[] = "\ta\nd\fd\0";

  s21_size_t n = 5;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_4) {
  char src1[10] = "000";
  char src2[10] = "000";
  const char app[] = "";

  s21_size_t n = 5;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_5) {
  char src1[10] = "";
  char src2[10] = "";
  const char app[] = "";

  s21_size_t n = 5;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_6) {
  char src1[10] = "";
  char src2[10] = "";
  const char app[] = "\0";

  s21_size_t n = 5;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_7) {
  char src1[10] = "\0";
  char src2[10] = "\0";
  const char app[] = "\0";

  s21_size_t n = 5;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_8) {
  char src1[20] = "\0";
  char src2[20] = "\0";
  const char app[] = "123\n123\0123\n";

  s21_size_t n = 15;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_9) {
  char src1[30] = "\0123\n321";
  char src2[30] = "\0123\n321";
  const char app[] = "123\n123\0123\n";

  s21_size_t n = 15;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

START_TEST(strncat_10) {
  char src1[30] = "\0123\n321";
  char src2[30] = "\0123\n321";
  const char app[] = "123\n123\0123\n";

  s21_size_t n = 0;

  ck_assert_pstr_eq(strncat(src1, app, n), s21_strncat(src2, app, n));
}
END_TEST

Suite *test_strncat(void) {
  Suite *s = suite_create("\033[45m-=S21_STRNCAT=-\033[0m");
  TCase *tc = tcase_create("strncat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);

  suite_add_tcase(s, tc);
  return s;
}
