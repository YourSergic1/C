#include "s21_test.h"

START_TEST(strtok_1) {
  char str1[24] = " test1/test2/test3/test4";
  char str2[24] = " test1/test2/test3/test4";
  char sep[10] = "/";

  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_2) {
  char str1[24] = "";
  char str2[24] = "";
  char sep[10] = "";

  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_3) {
  char str1[24] = "123 445 ! 3";
  char str2[24] = "123 445 ! 3";
  char sep[10] = "";

  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_4) {
  char str1[24] = "123 445 ! 3";
  char str2[24] = "123 445 ! 3";
  char sep[10] = "\0";

  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_5) {
  char str1[24] = "123 445 ! 3";
  char str2[24] = "123 445 ! 3";
  char sep[20] = "123 445 ! 3";

  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_6) {
  char str1[24] = "123 445 ! 3";
  char str2[24] = "123 445 ! 3";
  char sep[24] = "123 445 ! 3567890qwert";

  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_7) {
  char str1[50] = "\001010101010101010101010101010101";
  char str2[50] = "\001010101010101010101010101010101";
  char sep[30] = "0";
  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_8) {
  char str1[50] = "01010101010101010101010101010101";
  char str2[50] = "01010101010101010101010101010101";
  char sep[5] = "1";
  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_9) {
  char str1[50] = "01010101010101010101010101010101";
  char str2[50] = "01010101010101010101010101010101";
  char sep[5] = "1";
  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_10) {
  char str1[50] = "\01010101010101010101010101010101";
  char str2[50] = "\01010101010101010101010101010101";
  char sep[5] = "\0";
  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_11) {
  char *str1 = S21_NULL;
  char *str2 = S21_NULL;
  char sep[5] = "";
  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_12) {
  char *str1 = S21_NULL;
  char *str2 = S21_NULL;
  char *sep = S21_NULL;
  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
}
END_TEST

START_TEST(strtok_13) {
  char str1[30] = "121314151617181910";
  char str2[30] = "121314151617181910";
  char sep[5] = "1";

  ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(str1, sep), s21_strtok(str2, sep));
  }
}
END_TEST

Suite *test_strtok(void) {
  Suite *s = suite_create("\033[45m-=S21_STRTOK=-\033[0m");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_10);
  tcase_add_test(tc, strtok_11);
  tcase_add_test(tc, strtok_12);
  tcase_add_test(tc, strtok_13);

  suite_add_tcase(s, tc);
  return s;
}
