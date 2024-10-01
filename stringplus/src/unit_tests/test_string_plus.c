#include "s21_test.h"

START_TEST(string_plus_1) {
  char *a = s21_to_upper("a");

  ck_assert_pstr_eq(a, "A");
  free(a);
}
END_TEST

START_TEST(string_plus_2) {
  char *a = s21_to_upper("A");

  ck_assert_pstr_eq(a, "A");
  free(a);
}
END_TEST

START_TEST(string_plus_3) {
  char *a = s21_to_upper("123");

  ck_assert_pstr_eq(a, "123");
  free(a);
}
END_TEST

START_TEST(string_plus_4) {
  char *a = s21_to_upper("a123a");

  ck_assert_pstr_eq(a, "A123A");
  free(a);
}
END_TEST

START_TEST(string_plus_5) {
  char *a = s21_to_upper("aBaBaBa");

  ck_assert_pstr_eq(a, "ABABABA");
  free(a);
}
END_TEST

START_TEST(string_plus_6) {
  char *a = s21_to_upper(".! ");

  ck_assert_pstr_eq(a, ".! ");
  free(a);
}
END_TEST

START_TEST(string_plus_7) {
  char *a = s21_to_upper("Hello world!");

  ck_assert_pstr_eq(a, "HELLO WORLD!");
  free(a);
}
END_TEST

START_TEST(string_plus_8) {
  char *a = s21_to_upper("abc\nabc");

  ck_assert_pstr_eq(a, "ABC\nABC");
  free(a);
}
END_TEST

START_TEST(string_plus_9) {
  char *a = s21_to_upper("Hello world!\nHello world!");

  ck_assert_pstr_eq(a, "HELLO WORLD!\nHELLO WORLD!");
  free(a);
}
END_TEST

START_TEST(string_plus_10) {
  char *a = s21_to_lower("A");

  ck_assert_pstr_eq(a, "a");
  free(a);
}
END_TEST

START_TEST(string_plus_11) {
  char *a = s21_to_lower("a");

  ck_assert_pstr_eq(a, "a");
  free(a);
}
END_TEST

START_TEST(string_plus_12) {
  char *a = s21_to_lower("123");

  ck_assert_pstr_eq(a, "123");
  free(a);
}
END_TEST

START_TEST(string_plus_13) {
  char *a = s21_to_lower("A123A");

  ck_assert_pstr_eq(a, "a123a");
  free(a);
}
END_TEST

START_TEST(string_plus_14) {
  char *a = s21_to_lower("aBaBaBa");

  ck_assert_pstr_eq(a, "abababa");
  free(a);
}
END_TEST

START_TEST(string_plus_15) {
  char *a = s21_to_lower(".! ");

  ck_assert_pstr_eq(a, ".! ");
  free(a);
}
END_TEST

START_TEST(string_plus_16) {
  char *a = s21_to_lower("Hello world!");

  ck_assert_pstr_eq(a, "hello world!");
  free(a);
}
END_TEST

START_TEST(string_plus_17) {
  char *a = s21_to_lower("ABC\nABC");

  ck_assert_pstr_eq(a, "abc\nabc");
  free(a);
}
END_TEST

START_TEST(string_plus_18) {
  char *a = s21_to_lower("hELLO WORLD!\nhELLO WORLD!");

  ck_assert_pstr_eq(a, "hello world!\nhello world!");
  free(a);
}
END_TEST

START_TEST(string_plus_19) {
  char *a = s21_insert("AAA", "BBB", 0);

  ck_assert_pstr_eq(a, "BBBAAA");
  free(a);
}
END_TEST

START_TEST(string_plus_20) {
  char *a = s21_insert("AAA", "BBB", 1);

  ck_assert_pstr_eq(a, "ABBBAA");
  free(a);
}
END_TEST

START_TEST(string_plus_21) {
  char *a = s21_insert("AAA", "BBB", 2);

  ck_assert_pstr_eq(a, "AABBBA");
  free(a);
}
END_TEST

// START_TEST(string_plus_22) {
//     char *a=s21_insert("AAA","BBB",2);

//   ck_assert_pstr_eq(a, S21_NULL);
//   free(a);
// }
// END_TEST

START_TEST(string_plus_23) {
  char *a = s21_insert("AAA", "", 2);

  ck_assert_pstr_eq(a, "AAA");
  free(a);
}
END_TEST

START_TEST(string_plus_24) {
  char *a = s21_insert("", "BBB", 2);

  ck_assert_pstr_eq(a, S21_NULL);
  free(a);
}
END_TEST

START_TEST(string_plus_25) {
  char *a = s21_insert("AAA", "123", 1);

  ck_assert_pstr_eq(a, "A123AA");
  free(a);
}
END_TEST

START_TEST(string_plus_26) {
  char *a = s21_insert("A\nA", "111", 1);

  ck_assert_pstr_eq(a, "A111\nA");
  free(a);
}
END_TEST

START_TEST(string_plus_27) {
  char *a = s21_insert("A\nA", "111", 2);

  ck_assert_pstr_eq(a, "A\n111A");
  free(a);
}
END_TEST

START_TEST(string_plus_28) {
  char *a = s21_trim("AAA", "A");

  ck_assert_pstr_eq(a, "");
  free(a);
}
END_TEST

START_TEST(string_plus_29) {
  char *a = s21_trim("ABA", "A");

  ck_assert_pstr_eq(a, "B");
  free(a);
}
END_TEST

START_TEST(string_plus_30) {
  char *a = s21_trim("BAB", "A");

  ck_assert_pstr_eq(a, "BAB");
  free(a);
}
END_TEST

START_TEST(string_plus_31) {
  char *a = s21_trim("BAB", "");

  ck_assert_pstr_eq(a, S21_NULL);
  free(a);
}
END_TEST

START_TEST(string_plus_32) {
  char *a = s21_trim("", "A");

  ck_assert_pstr_eq(a, S21_NULL);
  free(a);
}
END_TEST

START_TEST(string_plus_33) {
  char *a = s21_trim("ASDzSAD", "DSA");

  ck_assert_pstr_eq(a, "z");
  free(a);
}
END_TEST

START_TEST(string_plus_34) {
  char *a = s21_trim("ASD1SAD", "1");

  ck_assert_pstr_eq(a, "ASD1SAD");
  free(a);
}
END_TEST

START_TEST(string_plus_35) {
  char *a = s21_trim("11ASD1SAD111", "1");

  ck_assert_pstr_eq(a, "ASD1SAD");
  free(a);
}
END_TEST

START_TEST(string_plus_36) {
  char *a = s21_trim("11\n11", "\n");

  ck_assert_pstr_eq(a, "11\n11");
  free(a);
}
END_TEST

START_TEST(string_plus_37) {
  char *a = s21_trim("\n11\n11\n", "\n");

  ck_assert_pstr_eq(a, "11\n11");
  free(a);
}
END_TEST

Suite *test_string_plus(void) {
  Suite *s = suite_create("\033[45m-=S21_STRING_PLUS=-\033[0m");
  TCase *tc = tcase_create("string_plus_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, string_plus_1);
  tcase_add_test(tc, string_plus_2);
  tcase_add_test(tc, string_plus_3);
  tcase_add_test(tc, string_plus_4);
  tcase_add_test(tc, string_plus_5);
  tcase_add_test(tc, string_plus_6);
  tcase_add_test(tc, string_plus_7);
  tcase_add_test(tc, string_plus_8);
  tcase_add_test(tc, string_plus_9);
  tcase_add_test(tc, string_plus_10);
  tcase_add_test(tc, string_plus_11);
  tcase_add_test(tc, string_plus_12);
  tcase_add_test(tc, string_plus_13);
  tcase_add_test(tc, string_plus_14);
  tcase_add_test(tc, string_plus_15);
  tcase_add_test(tc, string_plus_16);
  tcase_add_test(tc, string_plus_17);
  tcase_add_test(tc, string_plus_18);
  tcase_add_test(tc, string_plus_19);
  tcase_add_test(tc, string_plus_20);
  tcase_add_test(tc, string_plus_21);
  // tcase_add_test(tc, string_plus_22);
  tcase_add_test(tc, string_plus_23);
  tcase_add_test(tc, string_plus_24);
  tcase_add_test(tc, string_plus_25);
  tcase_add_test(tc, string_plus_26);
  tcase_add_test(tc, string_plus_27);
  tcase_add_test(tc, string_plus_28);
  tcase_add_test(tc, string_plus_29);
  tcase_add_test(tc, string_plus_30);
  tcase_add_test(tc, string_plus_31);
  tcase_add_test(tc, string_plus_32);
  tcase_add_test(tc, string_plus_33);
  tcase_add_test(tc, string_plus_34);
  tcase_add_test(tc, string_plus_35);
  tcase_add_test(tc, string_plus_36);
  tcase_add_test(tc, string_plus_37);

  suite_add_tcase(s, tc);
  return s;
}
