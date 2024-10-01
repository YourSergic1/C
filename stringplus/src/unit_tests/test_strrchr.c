#include "s21_test.h"

START_TEST(strrchr_1) {
  char str[11] = "0163456769";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char str[11] = "0163456769";
  int ch = '6';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char str[11] = "0163456769";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char str[11] = "01\0456769";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char str[20] = "01\04561769";
  int ch = '1';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char str[20] = "014561769";
  int ch = '!';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char str[20] = "\0014561769";
  int ch = '5';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char str[20] = "11111111";
  int ch = '1';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_9) {
  char str[20] = "\0\0\0\0\0\0\0\0\0";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr_10) {
  char str[20] = "\0\0\0\0\0\0\0\0\0";
  int ch = 'k';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

Suite *test_strrchr(void) {
  Suite *s = suite_create("\033[45m-=S21_STRRCHR=-\033[0m");
  TCase *tc = tcase_create("strrchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  tcase_add_test(tc, strrchr_10);

  suite_add_tcase(s, tc);
  return s;
}
