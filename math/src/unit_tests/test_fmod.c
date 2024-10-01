#include "s21_test.h"

START_TEST(fmod_1) {
  double a = 0;
  double b = 0;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_2) {
  double a = 0;
  double b = 1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_3) {
  double a = 0;
  double b = -1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_4) {
  double a = 0;
  double b = -s21_infp;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_5) {
  double a = 0;
  double b = -s21_infm;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_6) {
  double a = 0;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_7) {
  double a = 0;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_8) {
  double a = 0;
  double b = -33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_9) {
  double a = 0;
  double b = 33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_10) {
  double a = 1;
  double b = 0;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_11) {
  double a = 1;
  double b = 1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_12) {
  double a = 1;
  double b = -1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_13) {
  double a = 1;
  double b = -s21_infp;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_14) {
  double a = 1;
  double b = -s21_infm;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_15) {
  double a = 1;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_16) {
  double a = 1;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_17) {
  double a = 1;
  double b = -33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_18) {
  double a = 1;
  double b = 33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_19) {
  double a = -1;
  double b = 0;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_20) {
  double a = -1;
  double b = 1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_21) {
  double a = -1;
  double b = -1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_22) {
  double a = -1;
  double b = -s21_infp;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_23) {
  double a = -1;
  double b = -s21_infm;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_24) {
  double a = -1;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_25) {
  double a = -1;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_26) {
  double a = -1;
  double b = -33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_27) {
  double a = -1;
  double b = 33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_28) {
  double a = s21_infp;
  double b = 0;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_29) {
  double a = s21_infp;
  double b = 1;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_30) {
  double a = s21_infp;
  double b = -1;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_31) {
  double a = s21_infp;
  double b = -s21_infp;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_32) {
  double a = s21_infp;
  double b = -s21_infm;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_33) {
  double a = s21_infp;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_34) {
  double a = s21_infp;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_35) {
  double a = s21_infp;
  double b = -33.3;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_36) {
  double a = s21_infp;
  double b = 33.3;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_37) {
  double a = 0;
  double b = s21_infm;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_38) {
  double a = s21_infm;
  double b = 1;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_39) {
  double a = s21_infm;
  double b = -1;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_40) {
  double a = s21_infm;
  double b = s21_infp;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_41) {
  double a = s21_infm;
  double b = s21_infm;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_42) {
  double a = s21_infm;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_43) {
  double a = s21_infm;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_44) {
  double a = s21_infm;
  double b = -33.3;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_45) {
  double a = s21_infm;
  double b = 33.3;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_46) {
  double a = -s21_nan;
  double b = 0;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_47) {
  double a = -s21_nan;
  double b = 1;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_48) {
  double a = -s21_nan;
  double b = -1;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_49) {
  double a = -s21_nan;
  double b = -s21_infp;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_50) {
  double a = -s21_nan;
  double b = -s21_infm;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_51) {
  double a = -s21_nan;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_52) {
  double a = -s21_nan;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_53) {
  double a = -s21_nan;
  double b = -33.3;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_54) {
  double a = -s21_nan;
  double b = 33.3;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_55) {
  double a = s21_nan;
  double b = 0;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_56) {
  double a = s21_nan;
  double b = 1;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_57) {
  double a = s21_nan;
  double b = -1;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_58) {
  double a = s21_nan;
  double b = -s21_infp;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_59) {
  double a = s21_nan;
  double b = -s21_infm;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_60) {
  double a = s21_nan;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_61) {
  double a = s21_nan;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_62) {
  double a = s21_nan;
  double b = -33.3;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_63) {
  double a = s21_nan;
  double b = 33.3;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_64) {
  double a = -33.3;
  double b = 0;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_65) {
  double a = -33.3;
  double b = 1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_66) {
  double a = -33.3;
  double b = -1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_67) {
  double a = -33.3;
  double b = -s21_infp;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_68) {
  double a = -33.3;
  double b = -s21_infm;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_69) {
  double a = -33.3;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_70) {
  double a = -33.3;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_71) {
  double a = -33.3;
  double b = -33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_72) {
  double a = -33.3;
  double b = 33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_73) {
  double a = 33.3;
  double b = 0;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_74) {
  double a = 33.3;
  double b = 1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_75) {
  double a = 33.3;
  double b = -1;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_76) {
  double a = 33.3;
  double b = -s21_infp;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_77) {
  double a = 33.3;
  double b = -s21_infm;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_78) {
  double a = 33.3;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_79) {
  double a = 33.3;
  double b = -s21_nan;
  ck_assert_ldouble_nan(s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_80) {
  double a = 33.3;
  double b = -33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

START_TEST(fmod_81) {
  double a = 33.3;
  double b = 33.3;
  ck_assert_ldouble_eq(fmod(a, b), s21_fmod(a, b));
}
END_TEST

Suite *test_fmod(void) {
  Suite *s = suite_create("\033[45m-=S21_FMOD=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, fmod_1);
  tcase_add_test(tc, fmod_2);
  tcase_add_test(tc, fmod_3);
  tcase_add_test(tc, fmod_4);
  tcase_add_test(tc, fmod_5);
  tcase_add_test(tc, fmod_6);
  tcase_add_test(tc, fmod_7);
  tcase_add_test(tc, fmod_8);
  tcase_add_test(tc, fmod_9);
  tcase_add_test(tc, fmod_10);
  tcase_add_test(tc, fmod_11);
  tcase_add_test(tc, fmod_12);
  tcase_add_test(tc, fmod_13);
  tcase_add_test(tc, fmod_14);
  tcase_add_test(tc, fmod_15);
  tcase_add_test(tc, fmod_16);
  tcase_add_test(tc, fmod_17);
  tcase_add_test(tc, fmod_18);
  tcase_add_test(tc, fmod_19);
  tcase_add_test(tc, fmod_20);
  tcase_add_test(tc, fmod_21);
  tcase_add_test(tc, fmod_22);
  tcase_add_test(tc, fmod_23);
  tcase_add_test(tc, fmod_24);
  tcase_add_test(tc, fmod_25);
  tcase_add_test(tc, fmod_26);
  tcase_add_test(tc, fmod_27);
  tcase_add_test(tc, fmod_28);
  tcase_add_test(tc, fmod_29);
  tcase_add_test(tc, fmod_30);
  tcase_add_test(tc, fmod_31);
  tcase_add_test(tc, fmod_32);
  tcase_add_test(tc, fmod_33);
  tcase_add_test(tc, fmod_34);
  tcase_add_test(tc, fmod_35);
  tcase_add_test(tc, fmod_36);
  tcase_add_test(tc, fmod_37);
  tcase_add_test(tc, fmod_38);
  tcase_add_test(tc, fmod_39);
  tcase_add_test(tc, fmod_40);
  tcase_add_test(tc, fmod_41);
  tcase_add_test(tc, fmod_42);
  tcase_add_test(tc, fmod_43);
  tcase_add_test(tc, fmod_44);
  tcase_add_test(tc, fmod_45);
  tcase_add_test(tc, fmod_46);
  tcase_add_test(tc, fmod_47);
  tcase_add_test(tc, fmod_48);
  tcase_add_test(tc, fmod_49);
  tcase_add_test(tc, fmod_50);
  tcase_add_test(tc, fmod_51);
  tcase_add_test(tc, fmod_52);
  tcase_add_test(tc, fmod_53);
  tcase_add_test(tc, fmod_54);
  tcase_add_test(tc, fmod_55);
  tcase_add_test(tc, fmod_56);
  tcase_add_test(tc, fmod_57);
  tcase_add_test(tc, fmod_58);
  tcase_add_test(tc, fmod_59);
  tcase_add_test(tc, fmod_60);
  tcase_add_test(tc, fmod_61);
  tcase_add_test(tc, fmod_62);
  tcase_add_test(tc, fmod_63);
  tcase_add_test(tc, fmod_64);
  tcase_add_test(tc, fmod_65);
  tcase_add_test(tc, fmod_66);
  tcase_add_test(tc, fmod_67);
  tcase_add_test(tc, fmod_68);
  tcase_add_test(tc, fmod_69);
  tcase_add_test(tc, fmod_70);
  tcase_add_test(tc, fmod_71);
  tcase_add_test(tc, fmod_72);
  tcase_add_test(tc, fmod_73);
  tcase_add_test(tc, fmod_74);
  tcase_add_test(tc, fmod_75);
  tcase_add_test(tc, fmod_76);
  tcase_add_test(tc, fmod_77);
  tcase_add_test(tc, fmod_78);
  tcase_add_test(tc, fmod_79);
  tcase_add_test(tc, fmod_80);
  tcase_add_test(tc, fmod_81);
  suite_add_tcase(s, tc);
  return s;
}