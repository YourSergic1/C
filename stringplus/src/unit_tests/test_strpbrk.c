#include "s21_test.h"

START_TEST(strpbrk_1) {
  char str[11] = "0123456789";
  char sym[10] = "369";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_2) {
  char str[11] = "0123456789";
  char sym[10] = "9";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_3) {
  char str[11] = "";
  char sym[10] = "369";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_4) {
  char str[11] = "\0";
  char sym[10] = "";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_5) {
  char str[11] = "";
  char sym[10] = "";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_6) {
  char str[11] = "zxcvbnm,";
  char sym[10] = "asdfghjkl;";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_7) {
  char str[11] = "01234\056789!";
  char sym[10] = "0123456789";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_8) {
  char str[11] = "";
  char sym[10] = "\0";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

START_TEST(strpbrk_9) {
  char str[11] = "0123456789!";
  char sym[10] = "0123405\06789";
  ck_assert_pstr_eq(strpbrk(str, sym), s21_strpbrk(str, sym));
}
END_TEST

Suite *test_strpbrk(void) {
  Suite *s = suite_create("\033[45m-=S21_STRPBRK=-\033[0m");
  TCase *tc = tcase_create("strpbrk_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  tcase_add_test(tc, strpbrk_8);
  tcase_add_test(tc, strpbrk_9);

  suite_add_tcase(s, tc);
  return s;
}
