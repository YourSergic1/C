#include <check.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "affine_transform.h"
#include "parser.h"

#define EPSILON \
  1e-6  // Пороговое значение для сравнения чисел с плавающей точкой

START_TEST(init) {
  float result[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq(test.m[i][j], result[i][j]);
    }
  }
}
END_TEST

START_TEST(rotate_x) {
  float result[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, -1.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0) test.m[i][j] = 1.0f;
    }
  }
  matrixRotation(&test, 90, 1);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

START_TEST(rotate_y) {
  float result[4][4] = {{0.0f, 0.0f, 1.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {-1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0) test.m[i][j] = 1.0f;
    }
  }
  matrixRotation(&test, 90, 2);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

START_TEST(rotate_z) {
  float result[4][4] = {{0.0f, -1.0f, 0.0f, 0.0f},
                        {1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0) test.m[i][j] = 1.0f;
    }
  }
  matrixRotation(&test, 90, 3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

START_TEST(translation_x) {
  float result[4][4] = {{1.0f, 0.0f, 0.0f, 5},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 0.0f},
                        {
                            0.0f,
                            0.0f,
                            0.0f,
                            1.0f,
                        }};
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0) test.m[i][j] = 1.0f;
    }
  }
  matrixTranslation(&test, 5, 1);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

START_TEST(translation_y) {
  float result[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 5},
                        {0.0f, 0.0f, 1.0f, 0.0f},
                        {
                            0.0f,
                            0.0f,
                            0.0f,
                            1.0f,
                        }};
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0) test.m[i][j] = 1.0f;
    }
  }
  matrixTranslation(&test, 5, 2);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

START_TEST(translation_z) {
  float result[4][4] = {{1.0f, 0.0f, 0.0f, 0.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 5},
                        {
                            0.0f,
                            0.0f,
                            0.0f,
                            1.0f,
                        }};
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0) test.m[i][j] = 1.0f;
    }
  }
  matrixTranslation(&test, 5, 3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

START_TEST(scale) {
  float result[4][4] = {{2, 0.0f, 0.0f, 0.0f},
                        {0.0f, 2, 0.0f, 0.0f},
                        {0.0f, 0.0f, 2, 0.0f},
                        {
                            0.0f,
                            0.0f,
                            0.0f,
                            1.0f,
                        }};
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0) test.m[i][j] = 1.0f;
    }
  }
  matrixScale(&test, 2);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

START_TEST(inverse_translation) {
  float result[4][4] = {{1.0f, 0.0f, 0.0f, -2.0f},
                        {0.0f, 1.0f, 0.0f, -3.0f},
                        {0.0f, 0.0f, 1.0f, -5.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};
  Matrix4x4_Affine test;
  Point3D point = {2, 3, 5};
  matrixInverseTranslation(&test, &point, 1);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

START_TEST(point_init) {
  Point3D point;
  point3DInIt(&point, 1, 2, 3);
  ck_assert_float_eq(point.x, 1);
  ck_assert_float_eq(point.y, 2);
  ck_assert_float_eq(point.z, 3);
}
END_TEST

START_TEST(multiply_mat_vec) {
  float result[4][4] = {{1.0f, 1.0f, 1.0f, 1.0f},
                        {0.0f, 1.0f, 0.0f, 0.0f},
                        {0.0f, 0.0f, 1.0f, 0.0f},
                        {0.0f, 0.0f, 0.0f, 1.0f}};
  Point3D point;
  point3DInIt(&point, 1, 2, 3);
  ck_assert_float_eq(point.x, 1);
  ck_assert_float_eq(point.y, 2);
  ck_assert_float_eq(point.z, 3);
  Matrix4x4_Affine test;
  matrixInIt(&test);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i == 0) test.m[i][j] = 1.0f;
    }
  }
  multiplyMatrixVector(&test, &point);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_float_eq_tol(test.m[i][j], result[i][j], EPSILON);
    }
  }
}
END_TEST

Suite *test_affine(void) {
  Suite *s = suite_create("\033[45m-=S21_AFFINE_TRANSFORMS=-\033[0m");
  TCase *tc = tcase_create("affine_tc");

  tcase_add_test(tc, init);
  tcase_add_test(tc, rotate_x);
  tcase_add_test(tc, rotate_y);
  tcase_add_test(tc, rotate_z);
  tcase_add_test(tc, translation_x);
  tcase_add_test(tc, translation_y);
  tcase_add_test(tc, translation_z);
  tcase_add_test(tc, scale);
  tcase_add_test(tc, inverse_translation);
  tcase_add_test(tc, point_init);
  tcase_add_test(tc, multiply_mat_vec);

  suite_add_tcase(s, tc);
  return s;
}

START_TEST(dtaObj_init) {
  DataObj *test = initDataOBJ(1);
  ck_assert_ptr_null(test->dataF);
  ck_assert_ptr_null(test->dataV);
  ck_assert_int_eq(test->sumF, 0);
  ck_assert_int_eq(test->sumV, 0);
  freeDataOBJ(test);
}
END_TEST

START_TEST(dataSizeObj1) {
  DataObj *test = initDataOBJ(1);
  strcpy(test->filename, "cat.obj");
  int res = calculateDataSizeObj(test);
  ck_assert_int_eq(res, 1);
  freeDataOBJ(test);
}
END_TEST

START_TEST(dataSizeObj2) {
  DataObj *test = initDataOBJ(1);
  strcpy(test->filename, "obj/cat.obj");
  int res = calculateDataSizeObj(test);
  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(test->sumV, 35290);
  ck_assert_int_eq(test->sumF, 35288);
  freeDataOBJ(test);
}
END_TEST

START_TEST(readingDataSizeObj1) {
  DataObj *test = initDataOBJ(1);
  strcpy(test->filename, "cat.obj");
  int res = readingDataOBJ(test);
  ck_assert_int_eq(res, 1);
  freeDataOBJ(test);
}
END_TEST

START_TEST(readingDataSizeObj2) {
  DataObj *test = initDataOBJ(1);
  strcpy(test->filename, "obj/cat.obj");
  calculateDataSizeObj(test);
  int res = readingDataOBJ(test);
  ck_assert_int_eq(res, 0);
  ck_assert_float_eq(test->dataF[0][0], 1);
  ck_assert_float_eq(test->dataV[0], 0.031868);
  freeDataOBJ(test);
}
END_TEST

START_TEST(Dot) {
  char test[256];
  char result[256];
  strcpy(test, "1.1.1.1.1.1");
  strcpy(result, "1,1,1,1,1,1");
  replaceDotWithComma(test);
  for (int i = 0; test[i] != '\0'; i++) ck_assert_int_eq(test[i], result[i]);
}
END_TEST

START_TEST(parser) {
  DataObj *test = parserObj("obj/cat.obj", 1);
  ck_assert_int_eq(test->sumV, 35290);
  ck_assert_int_eq(test->sumF, 35288);
  ck_assert_float_eq(test->dataF[0][0], 1);
  ck_assert_float_eq(test->dataV[0], 0.031868);
  freeDataOBJ(test);
}
END_TEST

Suite *test_parser(void) {
  Suite *s = suite_create("\033[45m-=S21_PARSER=-\033[0m");
  TCase *tc = tcase_create("parser_tc");

  tcase_add_test(tc, dtaObj_init);
  tcase_add_test(tc, dataSizeObj1);
  tcase_add_test(tc, dataSizeObj2);
  tcase_add_test(tc, readingDataSizeObj1);
  tcase_add_test(tc, readingDataSizeObj2);
  tcase_add_test(tc, Dot);
  tcase_add_test(tc, parser);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  int failed = 0;
  Suite *s21_test[] = {test_affine(), test_parser(), NULL};

  for (int i = 0; s21_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return 0;
}