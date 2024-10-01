#include "s21_test.h"

START_TEST(sprintf_1) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "a"), s21_sprintf(src2, "a"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_2) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "a a"), s21_sprintf(src2, "a a"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_3) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%d", 1), s21_sprintf(src2, "%d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_4) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "a\na"), s21_sprintf(src2, "a\na"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_5) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%d", -1), s21_sprintf(src2, "%d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_6) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%d", 0), s21_sprintf(src2, "%d", 0));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_7) {
  char src1[50] = {0};
  char src2[50] = {0};

  // printf(">>>>>>>>>>>>> %d %d\n", sprintf(src1, "%10d",1), s21_sprintf(src2,
  // "%10d",1));

  ck_assert_int_eq(sprintf(src1, "%10d", 1), s21_sprintf(src2, "%10d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_8) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% d", 1), s21_sprintf(src2, "% d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_9) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+d", 1), s21_sprintf(src2, "%+d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_10) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% 10d", 1), s21_sprintf(src2, "% 10d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_11) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+10d", 1), s21_sprintf(src2, "%+10d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_12) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-10d", 1), s21_sprintf(src2, "%+-10d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_13) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10d", 1), s21_sprintf(src2, "% -10d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_14) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.2d", 1),
                   s21_sprintf(src2, "% -10.2d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_15) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.1d", 1),
                   s21_sprintf(src2, "% -10.1d", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_16) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-10d", -1),
                   s21_sprintf(src2, "%+-10d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_17) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10d", -1), s21_sprintf(src2, "%10d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_18) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% d", -1), s21_sprintf(src2, "% d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_19) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+d", -1), s21_sprintf(src2, "%+d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_20) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% 10d", -1), s21_sprintf(src2, "% 10d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_21) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+10d", -1), s21_sprintf(src2, "%+10d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_22) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-10d", -1),
                   s21_sprintf(src2, "%+-10d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_23) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10d", -1),
                   s21_sprintf(src2, "% -10d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_24) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.2d", -1),
                   s21_sprintf(src2, "% -10.2d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_25) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.1d", -1),
                   s21_sprintf(src2, "% -10.1d", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_26) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.1d hello", -1),
                   s21_sprintf(src2, "% -10.1d hello", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_27) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.1d hello", 1),
                   s21_sprintf(src2, "% -10.1d hello", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_28) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello% -10.1d hello", -1),
                   s21_sprintf(src2, "hello% -10.1d hello", -1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_29) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello% -10.1d hello", 1),
                   s21_sprintf(src2, "hello% -10.1d hello", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_30) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello% -10.1d hello", 1),
                   s21_sprintf(src2, "hello% -10.1d hello", 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_31) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello% -*.*d hello", 10, 5, 1),
                   s21_sprintf(src2, "hello% -*.*d hello", 10, 5, 1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_32) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%hd", 32765),
                   s21_sprintf(src2, "%hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_33) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%hd", -32765),
                   s21_sprintf(src2, "%hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_34) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%hd", 0), s21_sprintf(src2, "%hd", 0));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_35) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10hd", 32765),
                   s21_sprintf(src2, "%10hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_36) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% hd", 32765),
                   s21_sprintf(src2, "% hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_37) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+hd", 32765),
                   s21_sprintf(src2, "%+hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_38) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% 10hd", 32765),
                   s21_sprintf(src2, "% 10hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_39) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% 10hd", 32765),
                   s21_sprintf(src2, "% 10hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_40) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+10hd", 32765),
                   s21_sprintf(src2, "%+10hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_41) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-10hd", 32765),
                   s21_sprintf(src2, "%+-10hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_42) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10hd", 32765),
                   s21_sprintf(src2, "% -10hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_43) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.7hd", 32765),
                   s21_sprintf(src2, "% -10.7hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_44) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.1hd", 32765),
                   s21_sprintf(src2, "% -10.1hd", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_45) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-10hd", -32765),
                   s21_sprintf(src2, "%+-10hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_46) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10hd", -32765),
                   s21_sprintf(src2, "%10hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_47) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% hd", -32765),
                   s21_sprintf(src2, "% hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_48) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+hd", -32765),
                   s21_sprintf(src2, "%+hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_49) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% 10hd", -32765),
                   s21_sprintf(src2, "% 10hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_50) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+10hd", -32765),
                   s21_sprintf(src2, "%+10hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_51) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-10hd", -32765),
                   s21_sprintf(src2, "%+-10hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_52) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10hd", -32765),
                   s21_sprintf(src2, "% -10hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_53) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.7hd", -32765),
                   s21_sprintf(src2, "% -10.7hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_54) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.1hd", -32765),
                   s21_sprintf(src2, "% -10.1hd", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_55) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.7hd hello", -32765),
                   s21_sprintf(src2, "% -10.7hd hello", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_56) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -10.7hd hello", 32765),
                   s21_sprintf(src2, "% -10.7hd hello", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_57) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello% -10.7hd hello", -32765),
                   s21_sprintf(src2, "hello% -10.7hd hello", -32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_58) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello% -10.7hd hello", 32765),
                   s21_sprintf(src2, "hello% -10.7hd hello", 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_59) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello% -*.*hd hello", 10, 7, 32765),
                   s21_sprintf(src2, "hello% -*.*hd hello", 10, 7, 32765));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_60) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%ld", 2147483611111145),
                   s21_sprintf(src2, "%ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_61) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%ld", -2147483611111145),
                   s21_sprintf(src2, "%ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_62) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%ld", (long int)0),
                   s21_sprintf(src2, "%ld", (long int)0));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_63) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10ld", 2147483611111145),
                   s21_sprintf(src2, "%10ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_64) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% ld", 2147483611111145),
                   s21_sprintf(src2, "% ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_65) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+ld", 2147483611111145),
                   s21_sprintf(src2, "%+ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_66) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% 15ld", 2147483611111145),
                   s21_sprintf(src2, "% 15ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_67) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+15ld", 2147483611111145),
                   s21_sprintf(src2, "%+15ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_68) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-15ld", 2147483611111145),
                   s21_sprintf(src2, "%+-15ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_69) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -15ld", 2147483611111145),
                   s21_sprintf(src2, "% -15ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_70) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -15.10ld", 2147483611111145),
                   s21_sprintf(src2, "% -15.10ld", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_71) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-15ld", -2147483611111145),
                   s21_sprintf(src2, "%+-15ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_72) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10ld", -2147483611111145),
                   s21_sprintf(src2, "%10ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_73) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% ld", -2147483611111145),
                   s21_sprintf(src2, "% ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_74) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+ld", -2147483611111145),
                   s21_sprintf(src2, "%+ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_75) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% 15ld", -2147483611111145),
                   s21_sprintf(src2, "% 15ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_76) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+15ld", -2147483611111145),
                   s21_sprintf(src2, "%+15ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_77) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%+-15ld", -2147483611111145),
                   s21_sprintf(src2, "%+-15ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_78) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -15ld", -2147483611111145),
                   s21_sprintf(src2, "% -15ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_79) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -15.12ld", -2147483611111145),
                   s21_sprintf(src2, "% -15.12ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_80) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -15.10ld", -2147483611111145),
                   s21_sprintf(src2, "% -15.10ld", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_81) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -15.12ld hello", -2147483611111145),
                   s21_sprintf(src2, "% -15.12ld hello", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_82) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% -15.12ld hello", 2147483611111145),
                   s21_sprintf(src2, "% -15.12ld hello", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_83) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(
      sprintf(src1, "hello% -15.12ld hello", -2147483611111145),
      s21_sprintf(src2, "hello% -15.12ld hello", -2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_84) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(
      sprintf(src1, "hello% -15.12ld hello", 2147483611111145),
      s21_sprintf(src2, "hello% -15.12ld hello", 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_85) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(
      sprintf(src1, "hello% -*.*ld hello", 15, 12, 2147483611111145),
      s21_sprintf(src2, "hello% -*.*ld hello", 15, 12, 2147483611111145));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_86) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%u", 60000), s21_sprintf(src2, "%u", 60000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_87) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10u", 60000),
                   s21_sprintf(src2, "%10u", 60000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_88) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-20.10u", 60000),
                   s21_sprintf(src2, "%-20.10u", 60000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_89) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-20.10u", 60000),
                   s21_sprintf(src2, "%-20.10u", 60000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_90) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-20.10u", 60000),
                   s21_sprintf(src2, "hello%-20.10u", 60000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_91) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-20.10u hello", 60000),
                   s21_sprintf(src2, "hello%-20.10u hello", 60000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_92) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-20.10u hello", 60000),
                   s21_sprintf(src2, "hello%-20.10u hello", 60000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_93) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-*.*u hello", 20, 10, 60000),
                   s21_sprintf(src2, "hello%-*.*u hello", 20, 10, 60000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_94) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%hu", 30000),
                   s21_sprintf(src2, "%hu", 30000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_95) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10hu", 30000),
                   s21_sprintf(src2, "%10hu", 30000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_96) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-20.10hu", 30000),
                   s21_sprintf(src2, "%-20.10hu", 30000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_97) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-20.10hu", 30000),
                   s21_sprintf(src2, "%-20.10hu", 30000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_98) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-20.10hu", 30000),
                   s21_sprintf(src2, "hello%-20.10hu", 30000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_99) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-20.10hu hello", 30000),
                   s21_sprintf(src2, "hello%-20.10hu hello", 30000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_100) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-*.*hu hello", 20, 10, 30000),
                   s21_sprintf(src2, "hello%-*.*hu hello", 20, 10, 30000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_101) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%lu", 3000111111111000),
                   s21_sprintf(src2, "%lu", 3000111111111000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_102) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10lu", 3000111111111000),
                   s21_sprintf(src2, "%10lu", 3000111111111000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_103) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-20.10lu", 3000111111111000),
                   s21_sprintf(src2, "%-20.10lu", 3000111111111000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_104) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-20.10lu", 3000111111111000),
                   s21_sprintf(src2, "%-20.10lu", 3000111111111000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_105) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-20.1lu", 3000111111111000),
                   s21_sprintf(src2, "hello%-20.1lu", 3000111111111000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_106) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-20.10lu hello", 3000111111111000),
                   s21_sprintf(src2, "hello%-20.10lu hello", 3000111111111000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_107) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello%-20.10lu hello", 3000111111111000),
                   s21_sprintf(src2, "hello%-20.10lu hello", 3000111111111000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_108) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(
      sprintf(src1, "hello%-*.*lu hello", 20, 10, 3000111111111000),
      s21_sprintf(src2, "hello%-*.*lu hello", 20, 10, 3000111111111000));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_109) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%s", "aaa"), s21_sprintf(src2, "%s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_110) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10s", "aaa"),
                   s21_sprintf(src2, "%10s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_111) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-10s", "aaa"),
                   s21_sprintf(src2, "%-10s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_112) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10.2s", "aaa"),
                   s21_sprintf(src2, "%10.2s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_113) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-10.2s", "aaa"),
                   s21_sprintf(src2, "%-10.2s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_114) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-10.4s", "aaa"),
                   s21_sprintf(src2, "%-10.4s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_115) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10.4s", "aaa"),
                   s21_sprintf(src2, "%10.4s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_116) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello %10.4s hello", "aaa"),
                   s21_sprintf(src2, "hello %10.4s hello", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_117) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%.4s", "aaa"),
                   s21_sprintf(src2, "%.4s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_118) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%.1s", "aaa"),
                   s21_sprintf(src2, "%.1s", "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_119) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "hello %*.*s hello", 10, 4, "aaa"),
                   s21_sprintf(src2, "hello %*.*s hello", 10, 4, "aaa"));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_120) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%c", 'a'), s21_sprintf(src2, "%c", 'a'));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_121) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10c", 'a'), s21_sprintf(src2, "%10c", 'a'));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_122) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-10c", 'a'),
                   s21_sprintf(src2, "%-10c", 'a'));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_123) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-*c", 10, 'a'),
                   s21_sprintf(src2, "%-*c", 10, 'a'));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_124) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%f", 2.1), s21_sprintf(src2, "%f", 2.1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_125) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%f", 2.11), s21_sprintf(src2, "%f", 2.11));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_126) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%f", 2.111), s21_sprintf(src2, "%f", 2.111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_127) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%f", 2.1111),
                   s21_sprintf(src2, "%f", 2.1111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_128) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%f", 2.11111),
                   s21_sprintf(src2, "%f", 2.11111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_129) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%f", 2.111111),
                   s21_sprintf(src2, "%f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_130) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "% f", 2.1), s21_sprintf(src2, "% f", 2.1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_131) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%10f", 2.1), s21_sprintf(src2, "%10f", 2.1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_132) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-10f", 2.1),
                   s21_sprintf(src2, "%-10f", 2.1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_133) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%- 10f", 2.1),
                   s21_sprintf(src2, "%- 10f", 2.1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_134) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10f", 2.1),
                   s21_sprintf(src2, "%-+10f", 2.1));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_135) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10.f", 2.111111),
                   s21_sprintf(src2, "%-+10.f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_136) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10.0f", 2.111111),
                   s21_sprintf(src2, "%-+10.0f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_137) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10.1f", 2.111111),
                   s21_sprintf(src2, "%-+10.1f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_138) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10.2f", 2.111111),
                   s21_sprintf(src2, "%-+10.2f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_139) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10.3f", 2.111111),
                   s21_sprintf(src2, "%-+10.3f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_140) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10.5f", 2.111111),
                   s21_sprintf(src2, "%-+10.5f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_141) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10.6f", 2.111111),
                   s21_sprintf(src2, "%-+10.6f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_142) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+10.7f", 2.111111),
                   s21_sprintf(src2, "%-+10.7f", 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

START_TEST(sprintf_143) {
  char src1[50] = {0};
  char src2[50] = {0};

  ck_assert_int_eq(sprintf(src1, "%-+*.*f", 10, 7, 2.111111),
                   s21_sprintf(src2, "%-+*.*f", 10, 7, 2.111111));
  ck_assert_pstr_eq(src1, src2);
}
END_TEST

Suite *test_sprinf(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF=-\033[0m");
  TCase *tc = tcase_create("sprinf_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, sprintf_1);
  tcase_add_test(tc, sprintf_2);
  tcase_add_test(tc, sprintf_3);
  tcase_add_test(tc, sprintf_4);
  tcase_add_test(tc, sprintf_5);
  tcase_add_test(tc, sprintf_6);
  tcase_add_test(tc, sprintf_7);
  tcase_add_test(tc, sprintf_8);
  tcase_add_test(tc, sprintf_9);
  tcase_add_test(tc, sprintf_10);
  tcase_add_test(tc, sprintf_11);
  tcase_add_test(tc, sprintf_12);
  tcase_add_test(tc, sprintf_13);
  tcase_add_test(tc, sprintf_14);
  tcase_add_test(tc, sprintf_15);
  tcase_add_test(tc, sprintf_16);
  tcase_add_test(tc, sprintf_17);
  tcase_add_test(tc, sprintf_18);
  tcase_add_test(tc, sprintf_19);
  tcase_add_test(tc, sprintf_20);
  tcase_add_test(tc, sprintf_21);
  tcase_add_test(tc, sprintf_22);
  tcase_add_test(tc, sprintf_23);
  tcase_add_test(tc, sprintf_24);
  tcase_add_test(tc, sprintf_25);
  tcase_add_test(tc, sprintf_26);
  tcase_add_test(tc, sprintf_27);
  tcase_add_test(tc, sprintf_28);
  tcase_add_test(tc, sprintf_29);
  tcase_add_test(tc, sprintf_30);
  tcase_add_test(tc, sprintf_31);
  tcase_add_test(tc, sprintf_32);
  tcase_add_test(tc, sprintf_33);
  tcase_add_test(tc, sprintf_34);
  tcase_add_test(tc, sprintf_35);
  tcase_add_test(tc, sprintf_36);
  tcase_add_test(tc, sprintf_37);
  tcase_add_test(tc, sprintf_38);
  tcase_add_test(tc, sprintf_39);
  tcase_add_test(tc, sprintf_40);
  tcase_add_test(tc, sprintf_41);
  tcase_add_test(tc, sprintf_42);
  tcase_add_test(tc, sprintf_43);
  tcase_add_test(tc, sprintf_44);
  tcase_add_test(tc, sprintf_45);
  tcase_add_test(tc, sprintf_46);
  tcase_add_test(tc, sprintf_47);
  tcase_add_test(tc, sprintf_48);
  tcase_add_test(tc, sprintf_49);
  tcase_add_test(tc, sprintf_50);
  tcase_add_test(tc, sprintf_51);
  tcase_add_test(tc, sprintf_52);
  tcase_add_test(tc, sprintf_53);
  tcase_add_test(tc, sprintf_54);
  tcase_add_test(tc, sprintf_55);
  tcase_add_test(tc, sprintf_56);
  tcase_add_test(tc, sprintf_57);
  tcase_add_test(tc, sprintf_58);
  tcase_add_test(tc, sprintf_59);
  tcase_add_test(tc, sprintf_60);
  tcase_add_test(tc, sprintf_61);
  tcase_add_test(tc, sprintf_62);
  tcase_add_test(tc, sprintf_63);
  tcase_add_test(tc, sprintf_64);
  tcase_add_test(tc, sprintf_65);
  tcase_add_test(tc, sprintf_66);
  tcase_add_test(tc, sprintf_67);
  tcase_add_test(tc, sprintf_68);
  tcase_add_test(tc, sprintf_69);
  tcase_add_test(tc, sprintf_70);
  tcase_add_test(tc, sprintf_71);
  tcase_add_test(tc, sprintf_72);
  tcase_add_test(tc, sprintf_73);
  tcase_add_test(tc, sprintf_74);
  tcase_add_test(tc, sprintf_75);
  tcase_add_test(tc, sprintf_76);
  tcase_add_test(tc, sprintf_77);
  tcase_add_test(tc, sprintf_78);
  tcase_add_test(tc, sprintf_79);
  tcase_add_test(tc, sprintf_80);
  tcase_add_test(tc, sprintf_81);
  tcase_add_test(tc, sprintf_82);
  tcase_add_test(tc, sprintf_83);
  tcase_add_test(tc, sprintf_84);
  tcase_add_test(tc, sprintf_85);
  tcase_add_test(tc, sprintf_86);
  tcase_add_test(tc, sprintf_87);
  tcase_add_test(tc, sprintf_88);
  tcase_add_test(tc, sprintf_89);
  tcase_add_test(tc, sprintf_90);
  tcase_add_test(tc, sprintf_91);
  tcase_add_test(tc, sprintf_92);
  tcase_add_test(tc, sprintf_93);
  tcase_add_test(tc, sprintf_94);
  tcase_add_test(tc, sprintf_95);
  tcase_add_test(tc, sprintf_96);
  tcase_add_test(tc, sprintf_97);
  tcase_add_test(tc, sprintf_98);
  tcase_add_test(tc, sprintf_99);
  tcase_add_test(tc, sprintf_100);
  tcase_add_test(tc, sprintf_101);
  tcase_add_test(tc, sprintf_102);
  tcase_add_test(tc, sprintf_103);
  tcase_add_test(tc, sprintf_104);
  tcase_add_test(tc, sprintf_105);
  tcase_add_test(tc, sprintf_106);
  tcase_add_test(tc, sprintf_107);
  tcase_add_test(tc, sprintf_108);
  tcase_add_test(tc, sprintf_109);
  tcase_add_test(tc, sprintf_110);
  tcase_add_test(tc, sprintf_111);
  tcase_add_test(tc, sprintf_112);
  tcase_add_test(tc, sprintf_113);
  tcase_add_test(tc, sprintf_114);
  tcase_add_test(tc, sprintf_115);
  tcase_add_test(tc, sprintf_116);
  tcase_add_test(tc, sprintf_117);
  tcase_add_test(tc, sprintf_118);
  tcase_add_test(tc, sprintf_119);
  tcase_add_test(tc, sprintf_120);
  tcase_add_test(tc, sprintf_121);
  tcase_add_test(tc, sprintf_122);
  tcase_add_test(tc, sprintf_123);
  tcase_add_test(tc, sprintf_124);
  tcase_add_test(tc, sprintf_125);
  tcase_add_test(tc, sprintf_126);
  tcase_add_test(tc, sprintf_127);
  tcase_add_test(tc, sprintf_128);
  tcase_add_test(tc, sprintf_129);
  tcase_add_test(tc, sprintf_130);
  tcase_add_test(tc, sprintf_131);
  tcase_add_test(tc, sprintf_132);
  tcase_add_test(tc, sprintf_133);
  tcase_add_test(tc, sprintf_134);
  tcase_add_test(tc, sprintf_135);
  tcase_add_test(tc, sprintf_136);
  tcase_add_test(tc, sprintf_137);
  tcase_add_test(tc, sprintf_138);
  tcase_add_test(tc, sprintf_139);
  tcase_add_test(tc, sprintf_140);
  tcase_add_test(tc, sprintf_141);
  tcase_add_test(tc, sprintf_142);
  tcase_add_test(tc, sprintf_143);

  suite_add_tcase(s, tc);
  return s;
}
