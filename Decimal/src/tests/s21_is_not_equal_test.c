#include "s21_test.h"

// TRUE TESTS
START_TEST(is_not_equal_test_1) {
  s21_decimal values_1[] = {
      {{0x0000000C, 0x00000000, 0x00000000, 0x80010000}},  //              -1.2
      {{0x000000F3, 0x00000000, 0x00000000, 0x00020000}},  //              2.43
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}},
      //                                          79228162514264337593543950335
      {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}},
      //                                          79228162514264337593543950334
      {{0x000007CF, 0x00000000, 0x00000000, 0x00000000}},  //              1999
      {{0x0000000F, 0x00000014, 0x00000000, 0x800A0000}},  //     -8.5899345935
      {{0x0000000F, 0x00000014, 0x0000072E, 0x800A0000}},
      //                                              -3390511560756.4055216143
      {{0x0000000F, 0x00000014, 0x0000072E, 0x00020000}},
      //                                               339051156075640552161.43
      {{0x99362457, 0x0007AE79, 0x00000000, 0x00080000}},  // 21621621.21712727
      {{0x99362457, 0x0007AE79, 0x00000000, 0x00080000}},  // 21621621.21712727
      {{0x2113B8B0, 0x00000917, 0x00000000, 0x80070000}},  //   -999494.3838384
      {{0x2113B8B0, 0x00000917, 0x00000000, 0x80070000}},  //   -999494.3838384
      {{0x00000086, 0x00000054, 0x00000013, 0x00010000}},
      //                                                 35048813776125873370.2
      {{0x00000085, 0x00000054, 0x00000013, 0x00010000}},
      //                                                 35048813776125873370.1
      {{0x000011EB, 0x00000000, 0x00000000, 0x80010000}},  //            -458.7
      {{0x00000000, 0x00000000, 0x00000000, 0x00020000}},  //              0.00
      {{0x0000007B, 0x00000000, 0x00000000, 0x00070000}}   //         0.0000123
  };

  s21_decimal values_2[] = {
      {{0x00000070, 0x00000000, 0x00000000, 0x80020000}},  //             -1.12
      {{0x000000F4, 0x00000000, 0x00000000, 0x00030000}},  //             0.244
      {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}},
      //                                          79228162514264337593543950334
      {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000}},
      //                                          79228162514264337593543950335
      {{0x00004E20, 0x00000000, 0x00000000, 0x00000000}},  //             20000
      {{0x0000000D, 0x00000014, 0x00000000, 0x800A0000}},  //     -8.5899345933
      {{0x0000000F, 0x00000013, 0x0000072E, 0x800A0000}},
      //                                              -3390511560755.9760248847
      {{0x0000000F, 0x00000014, 0x0000072F, 0x00020000}},
      //                                               339235623516377647677.59
      {{0x99362458, 0x0007AE79, 0x00000000, 0x00080000}},  // 21621621.21712728
      {{0x99362456, 0x0007AE79, 0x00000000, 0x00080000}},  // 21621621.21712726
      {{0x2113B8AF, 0x00000917, 0x00000000, 0x80070000}},  //   -999494.3838383
      {{0x2113B8B1, 0x00000917, 0x00000000, 0x80070000}},  //   -999494.3838385
      {{0x00003458, 0x00000054, 0x00000013, 0x00030000}},
      //                                                 350488137761258746.968
      {{0x00003458, 0x00000054, 0x00000013, 0x00030000}},
      //                                                 350488137761258746.968
      {{0x000011EB, 0x00000000, 0x00000000, 0x80020000}},  //            -45.87
      {{0x00000086, 0x00000000, 0x00000000, 0x00010000}},  //              13.4
      {{0x00000000, 0x00000000, 0x00000000, 0x00010000}}   //               0.0
  };

  for (size_t i = 0; i < sizeof(values_1) / sizeof(s21_decimal); i++) {
    ck_assert_int_eq(TRUE, s21_is_not_equal(values_1[i], values_2[i]));
  }
}
END_TEST

// FALSE TESTS
START_TEST(is_not_equal_test_2) {
  s21_decimal values_1[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  //                 0
      {{0x00000000, 0x00000000, 0x00000000, 0x00030000}},  //             0.000
      {{0x00000000, 0x00000000, 0x00000000, 0x800A0000}},  //      0.0000000000
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  //                 1
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //                -1
      {{0x99362457, 0x0007AE79, 0x00000000, 0x00080000}},  // 21621621.21712727
      {{0x2113B8B0, 0x00000917, 0x00000000, 0x80070000}}   //   -999494.3838384
  };

  s21_decimal values_2[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  //                 0
      {{0x00000000, 0x00000000, 0x00000000, 0x00010000}},  //               0.0
      {{0x00000000, 0x00000000, 0x00000000, 0x00030000}},  //             0.000
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  //                 1
      {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},  //                -1
      {{0x99362457, 0x0007AE79, 0x00000000, 0x00080000}},  // 21621621.21712727
      {{0x2113B8B0, 0x00000917, 0x00000000, 0x80070000}}   //   -999494.3838384
  };

  for (size_t i = 0; i < sizeof(values_1) / sizeof(s21_decimal); i++) {
    ck_assert_int_eq(FALSE, s21_is_not_equal(values_1[i], values_2[i]));
  }
}
END_TEST

Suite* s21_is_not_equal_suite(void) {
  Suite* s;
  s = suite_create("\033[33ms21_is_not_equal\033[0m");

  TCase* tc_core;
  tc_core = tcase_create("s21_is_not_equal_core");
  tcase_add_test(tc_core, is_not_equal_test_1);
  tcase_add_test(tc_core, is_not_equal_test_2);
  suite_add_tcase(s, tc_core);

  return s;
}
