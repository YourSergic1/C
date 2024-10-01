#include "s21_test.h"

START_TEST(pow_1) {
  double a = 0;
  double b = 0;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_2) {
  double a = 0;
  double b = 1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_3) {
  double a = 0;
  double b = -1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_4) {
  double a = 0;
  double b = s21_infp;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_5) {
  double a = 0;
  double b = s21_infm;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_6) {
  double a = 0;
  double b = s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_7) {
  double a = 0;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_8) {
  double a = 0;
  double b = -33.3;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_9) {
  double a = 0;
  double b = 33.3;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_10) {
  double a = 1;
  double b = 0;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_11) {
  double a = 1;
  double b = 1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_12) {
  double a = 1;
  double b = -1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_13) {
  double a = 1;
  double b = s21_infp;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_14) {
  double a = 1;
  double b = s21_infm;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_15) {
  double a = 1;
  double b = s21_nan;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_16) {
  double a = 1;
  double b = -s21_nan;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_17) {
  double a = 1;
  double b = -33.3;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_18) {
  double a = 1;
  double b = 33.3;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_19) {
  double a = -1;
  double b = 0;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_20) {
  double a = -1;
  double b = 1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_21) {
  double a = -1;
  double b = -1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_22) {
  double a = -1;
  double b = s21_infp;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_23) {
  double a = -1;
  double b = s21_infm;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_24) {
  double a = -1;
  double b = s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_25) {
  double a = -1;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_26) {
  double a = -1;
  double b = -3.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_27) {
  double a = -1;
  double b = 3.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_28) {
  double a = s21_infp;
  double b = 0;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_29) {
  double a = s21_infp;
  double b = 1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_30) {
  double a = s21_infp;
  double b = -1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_31) {
  double a = s21_infp;
  double b = s21_infp;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_32) {
  double a = s21_infp;
  double b = s21_infm;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_33) {
  double a = s21_infp;
  double b = s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_34) {
  double a = s21_infp;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_35) {
  double a = s21_infp;
  double b = -33.3;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_36) {
  double a = s21_infp;
  double b = 33.3;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_37) {
  double a = 0;
  double b = s21_infm;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_38) {
  double a = s21_infm;
  double b = 1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_39) {
  double a = s21_infm;
  double b = -1;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_40) {
  double a = s21_infm;
  double b = s21_infp;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_41) {
  double a = s21_infm;
  double b = s21_infm;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_42) {
  double a = s21_infm;
  double b = s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_43) {
  double a = s21_infm;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_44) {
  double a = s21_infm;
  double b = -33.3;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_45) {
  double a = s21_infm;
  double b = 33.3;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_46) {
  double a = -s21_nan;
  double b = 0;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_47) {
  double a = -s21_nan;
  double b = 1;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_48) {
  double a = -s21_nan;
  double b = -1;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_49) {
  double a = -s21_nan;
  double b = s21_infp;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_50) {
  double a = -s21_nan;
  double b = s21_infm;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_51) {
  double a = -s21_nan;
  double b = s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_52) {
  double a = -s21_nan;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_53) {
  double a = -s21_nan;
  double b = -33.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_54) {
  double a = -s21_nan;
  double b = 33.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_55) {
  double a = s21_nan;
  double b = 0;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_56) {
  double a = s21_nan;
  double b = 1;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_57) {
  double a = s21_nan;
  double b = -1;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_58) {
  double a = s21_nan;
  double b = s21_infp;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_59) {
  double a = s21_nan;
  double b = s21_infm;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_60) {
  double a = s21_nan;
  double b = s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_61) {
  double a = s21_nan;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_62) {
  double a = s21_nan;
  double b = -33.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_63) {
  double a = s21_nan;
  double b = 33.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_64) {
  double a = -33.3;
  double b = 0;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_65) {
  double a = -33.3;
  double b = 1;
  ck_assert_ldouble_eq_tol(pow(a, b), s21_pow(a, b), 1e-6);
}
END_TEST

START_TEST(pow_66) {
  double a = -33.3;
  double b = -1;
  ck_assert_ldouble_eq_tol(pow(a, b), s21_pow(a, b), 1e-6);
}
END_TEST

START_TEST(pow_67) {
  double a = -33.3;
  double b = s21_infp;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_68) {
  double a = -33.3;
  double b = s21_infm;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_69) {
  double a = -33.3;
  double b = s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_70) {
  double a = -33.3;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_71) {
  double a = -3.3;
  double b = 3.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_72) {
  double a = -3.3;
  double b = 3.3;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_73) {
  double a = 33.3;
  double b = 0;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_74) {
  double a = 33.3;
  double b = 1;
  ck_assert_ldouble_eq_tol(pow(a, b), s21_pow(a, b), 1e-6);
}
END_TEST

START_TEST(pow_75) {
  double a = 33.3;
  double b = -1;
  ck_assert_ldouble_eq_tol(pow(a, b), s21_pow(a, b), 1e-6);
}
END_TEST

START_TEST(pow_76) {
  double a = 33.3;
  double b = s21_infp;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_77) {
  double a = 33.3;
  double b = s21_infm;
  ck_assert_ldouble_eq(pow(a, b), s21_pow(a, b));
}
END_TEST

START_TEST(pow_78) {
  double a = 33.3;
  double b = s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_79) {
  double a = 33.3;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_pow(a, b));
}
END_TEST

START_TEST(pow_80) {
  double a = 33.3;
  double b = -33.3;
  ck_assert_ldouble_eq_tol(pow(a, b), s21_pow(a, b), 1e-6);
}
END_TEST

START_TEST(pow_81) {
  double a = 3.3;
  double b = 52.3;
  ck_assert_float_eq_tol(pow(a, b), s21_pow(a, b), 1e-6);
}
END_TEST

Suite *test_pow(void) {
  Suite *s = suite_create("\033[45m-=S21_POW=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, pow_1);
  tcase_add_test(tc, pow_2);
  tcase_add_test(tc, pow_3);
  tcase_add_test(tc, pow_4);
  tcase_add_test(tc, pow_5);
  tcase_add_test(tc, pow_6);
  tcase_add_test(tc, pow_7);
  tcase_add_test(tc, pow_8);
  tcase_add_test(tc, pow_9);
  tcase_add_test(tc, pow_10);
  tcase_add_test(tc, pow_11);
  tcase_add_test(tc, pow_12);
  tcase_add_test(tc, pow_13);
  tcase_add_test(tc, pow_14);
  tcase_add_test(tc, pow_15);
  tcase_add_test(tc, pow_16);
  tcase_add_test(tc, pow_17);
  tcase_add_test(tc, pow_18);
  tcase_add_test(tc, pow_19);
  tcase_add_test(tc, pow_20);
  tcase_add_test(tc, pow_21);
  tcase_add_test(tc, pow_22);
  tcase_add_test(tc, pow_23);
  tcase_add_test(tc, pow_24);
  tcase_add_test(tc, pow_25);
  tcase_add_test(tc, pow_26);
  tcase_add_test(tc, pow_27);
  tcase_add_test(tc, pow_28);
  tcase_add_test(tc, pow_29);
  tcase_add_test(tc, pow_30);
  tcase_add_test(tc, pow_31);
  tcase_add_test(tc, pow_32);
  tcase_add_test(tc, pow_33);
  tcase_add_test(tc, pow_34);
  tcase_add_test(tc, pow_35);
  tcase_add_test(tc, pow_36);
  tcase_add_test(tc, pow_37);
  tcase_add_test(tc, pow_38);
  tcase_add_test(tc, pow_39);
  tcase_add_test(tc, pow_40);
  tcase_add_test(tc, pow_41);
  tcase_add_test(tc, pow_42);
  tcase_add_test(tc, pow_43);
  tcase_add_test(tc, pow_44);
  tcase_add_test(tc, pow_45);
  tcase_add_test(tc, pow_46);
  tcase_add_test(tc, pow_47);
  tcase_add_test(tc, pow_48);
  tcase_add_test(tc, pow_49);
  tcase_add_test(tc, pow_50);
  tcase_add_test(tc, pow_51);
  tcase_add_test(tc, pow_52);
  tcase_add_test(tc, pow_53);
  tcase_add_test(tc, pow_54);
  tcase_add_test(tc, pow_55);
  tcase_add_test(tc, pow_56);
  tcase_add_test(tc, pow_57);
  tcase_add_test(tc, pow_58);
  tcase_add_test(tc, pow_59);
  tcase_add_test(tc, pow_60);
  tcase_add_test(tc, pow_61);
  tcase_add_test(tc, pow_62);
  tcase_add_test(tc, pow_63);
  tcase_add_test(tc, pow_64);
  tcase_add_test(tc, pow_65);
  tcase_add_test(tc, pow_66);
  tcase_add_test(tc, pow_67);
  tcase_add_test(tc, pow_68);
  tcase_add_test(tc, pow_69);
  tcase_add_test(tc, pow_70);
  tcase_add_test(tc, pow_71);
  tcase_add_test(tc, pow_72);
  tcase_add_test(tc, pow_73);
  tcase_add_test(tc, pow_74);
  tcase_add_test(tc, pow_75);
  tcase_add_test(tc, pow_76);
  tcase_add_test(tc, pow_77);
  tcase_add_test(tc, pow_78);
  tcase_add_test(tc, pow_79);
  tcase_add_test(tc, pow_80);
  tcase_add_test(tc, pow_81);
  suite_add_tcase(s, tc);
  return s;
}