#include <check.h>

#include "s21_matrix.h"

void gen_matrix(double number, matrix_t* A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}

START_TEST(test_create_matrix_ok_1) {
  matrix_t matrix = {0};
  int rows = 1, columns = 1;

  int s21_result = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);
  ck_assert_int_eq(matrix.matrix[0][0], 0);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_ok_2) {
  matrix_t matrix = {0};
  int rows = 100, columns = 55;

  int s21_result = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_int_eq(matrix.rows, rows);
  ck_assert_int_eq(matrix.columns, columns);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_int_eq(matrix.matrix[i][j], 0);
    }
  }

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_create_matrix_error_1) {
  matrix_t matrix = {0};
  int rows = 0, columns = 1000;

  int s21_result = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_create_matrix_error_2) {
  matrix_t matrix = {0};
  int rows = 1000, columns = 0;

  int s21_result = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_create_matrix_error_3) {
  matrix_t matrix = {0};
  int rows = 1000, columns = -1;

  int s21_result = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_create_matrix_error_4) {
  matrix_t matrix = {0};
  int rows = 0, columns = 0;
  int s21_result = s21_create_matrix(rows, columns, &matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
}
END_TEST

START_TEST(test_remove_matrix) {
  matrix_t matrix = {0};
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &matrix);

  s21_remove_matrix(&matrix);

  ck_assert_ptr_eq(matrix.matrix, NULL);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

START_TEST(test_eq_matrix_success_1) {
  matrix_t A = {0}, B = {0};
  int rows = 100, columns = 99;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);

  int s21_result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(s21_result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_success_2) {
  matrix_t A = {0}, B = {0};
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  gen_matrix(1.0, &A);
  gen_matrix(1.0, &B);

  int s21_result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(s21_result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_success_3) {
  matrix_t A = {0}, B = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  gen_matrix(1.2345678, &A);
  gen_matrix(1.2345678, &B);

  int s21_result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(s21_result, SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_failure_1) {
  matrix_t A = {0}, B = {0};
  int rows1 = 100;
  int rows2 = 99, columns = 99;
  s21_create_matrix(rows1, columns, &A);
  s21_create_matrix(rows2, columns, &B);

  int s21_result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(s21_result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_failure_2) {
  matrix_t A = {0}, B = {0};
  int rows = 100;
  int columns1 = 99;
  int columns2 = 1;
  s21_create_matrix(rows, columns1, &A);
  s21_create_matrix(rows, columns2, &B);

  int s21_result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(s21_result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_failure_3) {
  matrix_t A = {0}, B = {0};
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  gen_matrix(1.0, &A);
  gen_matrix(2.0, &B);

  int s21_result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(s21_result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_failure_4) {
  matrix_t A = {0}, B = {0};
  int rows = -10, columns = 2;
  s21_create_matrix(10, columns, &A);
  s21_create_matrix(10, columns, &B);
  A.rows = rows;
  B.rows = rows;

  int s21_result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(s21_result, FAILURE);
  A.rows = 10;
  B.rows = 10;

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_matrix_failure_5) {
  matrix_t A = {0}, B = {0};
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  gen_matrix(1.0000001, &A);
  gen_matrix(1.0000000, &B);

  int s21_result = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(s21_result, FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_ok_1) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0}, sum_result = {0};
  int rows = 2, columns = 2;

  s21_create_matrix(rows, columns, &A);
  gen_matrix(5.0, &A);

  s21_create_matrix(rows, columns, &B);
  gen_matrix(-2.0, &B);

  s21_create_matrix(rows, columns, &sum_result);

  sum_result.matrix[0][0] = 3.0;
  sum_result.matrix[0][1] = 5.0;
  sum_result.matrix[1][0] = 7.0;
  sum_result.matrix[1][1] = 9.0;

  int s21_result = s21_sum_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              sum_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sum_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_sum_matrix_ok_2) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0}, sum_result = {0};
  int rows = 2, columns = 3;

  s21_create_matrix(rows, columns, &A);
  gen_matrix(1.0000001, &A);

  s21_create_matrix(rows, columns, &B);
  gen_matrix(1.0000002, &B);

  s21_create_matrix(rows, columns, &sum_result);

  sum_result.matrix[0][0] = 2.0000003;
  sum_result.matrix[0][1] = 4.0000003;
  sum_result.matrix[0][2] = 6.0000003;
  sum_result.matrix[1][0] = 8.0000003;
  sum_result.matrix[1][1] = 10.0000003;
  sum_result.matrix[1][2] = 12.0000003;

  int s21_result = s21_sum_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              sum_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sum_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_sum_matrix_error_1) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0};
  int rows1 = 2;
  int rows2 = 1, columns = 2;
  s21_create_matrix(rows1, columns, &A);
  s21_create_matrix(rows2, columns, &B);

  int s21_result = s21_sum_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_error_2) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0};
  int rows = 2, columns = -2;
  s21_create_matrix(rows, 2, &A);
  s21_create_matrix(rows, 2, &B);
  B.columns = columns;
  A.columns = columns;

  int s21_result = s21_sum_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_matrix_error_3) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0};
  int rows = -5, columns = -2;
  s21_create_matrix(rows, 2, &A);
  s21_create_matrix(rows, 2, &B);
  B.columns = columns;
  A.columns = columns;

  int s21_result = s21_sum_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_ok_1) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0}, sub_result = {0};
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(1.0000001, &A);

  s21_create_matrix(rows, columns, &B);
  gen_matrix(1.0000001, &B);
  s21_create_matrix(rows, columns, &sub_result);

  sub_result.matrix[0][0] = 0.0;
  sub_result.matrix[0][1] = 0.0;
  sub_result.matrix[1][0] = 0.0;
  sub_result.matrix[1][1] = 0.0;

  int s21_result = s21_sub_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              sub_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sub_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_sub_matrix_ok_2) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0}, sub_result = {0};
  int rows = 2, columns = 3;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(11.0000003, &A);

  s21_create_matrix(rows, columns, &B);
  gen_matrix(1.0000001, &B);

  s21_create_matrix(rows, columns, &sub_result);

  sub_result.matrix[0][0] = 10.0000002;
  sub_result.matrix[0][1] = 10.0000002;
  sub_result.matrix[0][2] = 10.0000002;
  sub_result.matrix[1][0] = 10.0000002;
  sub_result.matrix[1][1] = 10.0000002;
  sub_result.matrix[1][2] = 10.0000002;

  int s21_result = s21_sub_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              sub_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sub_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_sub_matrix_error_1) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0};
  int rows1 = 2;
  int rows2 = 1, columns = 2;
  s21_create_matrix(rows1, columns, &A);
  s21_create_matrix(rows2, columns, &B);

  int s21_result = s21_sub_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sub_matrix_error_2) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0};
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  B.rows = -1;

  int s21_result = s21_sub_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
  B.rows = rows;

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_mult_number_ok_1) {
  matrix_t A = {0}, s21_result_matrix = {0}, mult_num_result = {0};
  double number = 2.5f;
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(1.0, &A);
  s21_create_matrix(rows, columns, &mult_num_result);

  mult_num_result.matrix[0][0] = 2.5;
  mult_num_result.matrix[0][1] = 5.0;
  mult_num_result.matrix[1][0] = 7.5;
  mult_num_result.matrix[1][1] = 10.0;

  int s21_result = s21_mult_number(&A, number, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              mult_num_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&mult_num_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_mult_number_ok_2) {
  matrix_t A = {0}, s21_result_matrix = {0}, mult_num_result = {0};
  double number = 2.0;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(1.025, &A);

  s21_create_matrix(rows, columns, &mult_num_result);

  mult_num_result.matrix[0][0] = 2.05;
  mult_num_result.matrix[0][1] = 4.05;
  mult_num_result.matrix[0][2] = 6.05;
  mult_num_result.matrix[1][0] = 8.05;
  mult_num_result.matrix[1][1] = 10.05;
  mult_num_result.matrix[1][2] = 12.05;
  mult_num_result.matrix[2][0] = 14.05;
  mult_num_result.matrix[2][1] = 16.05;
  mult_num_result.matrix[2][2] = 18.05;

  int s21_result = s21_mult_number(&A, number, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              mult_num_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&mult_num_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_mult_number_error_1) {
  matrix_t A = {0}, s21_result_matrix = {0};
  double number = 2.5;
  int rows = 0, columns = 2;
  s21_create_matrix(2, columns, &A);
  A.rows = rows;

  int s21_result = s21_mult_number(&A, number, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
  A.rows = 2;

  s21_remove_matrix(&A);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_mult_number_error_2) {
  matrix_t A = {0}, s21_result_matrix = {0};
  double number = 2.5;
  int rows = -5, columns = 2;
  s21_create_matrix(2, columns, &A);
  A.rows = rows;

  int s21_result = s21_mult_number(&A, number, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
  A.rows = 2;

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_mult_matrix_ok_1) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0}, mult_result = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &mult_result);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 5.0;
  A.matrix[2][0] = 3.0;
  A.matrix[2][1] = 6.0;
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = -1.0;
  B.matrix[0][2] = 1.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 3.0;
  B.matrix[1][2] = 4.0;
  mult_result.matrix[0][0] = 9.0;
  mult_result.matrix[0][1] = 11.0;
  mult_result.matrix[0][2] = 17.0;
  mult_result.matrix[1][0] = 12.0;
  mult_result.matrix[1][1] = 13.0;
  mult_result.matrix[1][2] = 22.0;
  mult_result.matrix[2][0] = 15.0;
  mult_result.matrix[2][1] = 15.0;
  mult_result.matrix[2][2] = 27.0;

  int s21_result = s21_mult_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              mult_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mult_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_mult_matrix_ok_2) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0}, mult_result = {0};
  int rowsA = 3, columns = 2;
  int columnsB = 3;
  s21_create_matrix(rowsA, columns, &A);
  s21_create_matrix(columns, columnsB, &B);
  s21_create_matrix(rowsA, columnsB, &mult_result);

  A.matrix[0][0] = -3;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 2;
  A.matrix[2][0] = 0.5;
  A.matrix[2][1] = -1;

  B.matrix[0][0] = -3;
  B.matrix[0][1] = 1;
  B.matrix[0][2] = 0;
  B.matrix[1][0] = 2;
  B.matrix[1][1] = 0.5;
  B.matrix[1][2] = -1;
  mult_result.matrix[0][0] = 11;
  mult_result.matrix[0][1] = -2.5;
  mult_result.matrix[0][2] = -1;
  mult_result.matrix[1][0] = 4;
  mult_result.matrix[1][1] = 1;
  mult_result.matrix[1][2] = -2;
  mult_result.matrix[2][0] = -3.5;
  mult_result.matrix[2][1] = 0;
  mult_result.matrix[2][2] = 1;

  int s21_result = s21_mult_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rowsA; i++) {
    for (int j = 0; j < columnsB; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              mult_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&mult_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_mult_matrix_error_1) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0};

  s21_create_matrix(3, 2, &A);
  s21_create_matrix(3, 2, &B);

  int s21_result = s21_mult_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_mult_matrix_error_2) {
  matrix_t A = {0}, B = {0}, s21_result_matrix = {0};
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  A.rows = 0;

  int s21_result = s21_mult_matrix(&A, &B, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
  A.rows = 3;

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_transpose_ok_1) {
  matrix_t A = {0}, s21_result_matrix = {0}, transpose_result = {0};
  int rows = 3, columns = 2;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(1.0, &A);
  s21_create_matrix(columns, rows, &transpose_result);
  transpose_result.matrix[0][0] = 1.0;
  transpose_result.matrix[0][1] = 3.0;
  transpose_result.matrix[0][2] = 5.0;
  transpose_result.matrix[1][0] = 2.0;
  transpose_result.matrix[1][1] = 4.0;
  transpose_result.matrix[1][2] = 6.0;

  int s21_result = s21_transpose(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              transpose_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&transpose_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_transpose_ok_2) {
  matrix_t A = {0}, s21_result_matrix = {0}, transpose_result = {0};
  int rows = 3, columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(columns, rows, &transpose_result);
  A.matrix[0][0] = 1.2345678;
  A.matrix[0][1] = 2.3456789;
  A.matrix[1][0] = 3.4567890;
  A.matrix[1][1] = 4.5678901;
  A.matrix[2][0] = 5.6789012;
  A.matrix[2][1] = 6.7890123;
  transpose_result.matrix[0][0] = 1.2345678;
  transpose_result.matrix[0][1] = 3.4567890;
  transpose_result.matrix[0][2] = 5.6789012;
  transpose_result.matrix[1][0] = 2.3456789;
  transpose_result.matrix[1][1] = 4.5678901;
  transpose_result.matrix[1][2] = 6.7890123;

  int s21_result = s21_transpose(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              transpose_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&transpose_result);
  s21_remove_matrix(&s21_result_matrix);
}
END_TEST

START_TEST(test_transpose_error_1) {
  matrix_t A = {0}, s21_result_matrix = {0};
  int rows = 3;
  s21_create_matrix(rows, 2, &A);
  A.columns = -2;

  int s21_result = s21_transpose(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_transpose_error_2) {
  int res = 0;
  matrix_t A = {0};

  res = s21_transpose(&A, &A);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_ok_1) {
  matrix_t A = {0};
  double s21_result_determinant = 0.0;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(1.0, &A);
  double det_result = 0.0;

  int s21_result = s21_determinant(&A, &s21_result_determinant);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_double_eq_tol(s21_result_determinant, det_result, CMP_EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_ok_2) {
  matrix_t A = {0};
  double s21_result_determinant = 0.0;
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(-5.12345, &A);
  double det_result = -2;

  int s21_result = s21_determinant(&A, &s21_result_determinant);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_double_eq_tol(s21_result_determinant, det_result, CMP_EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_ok_3) {
  matrix_t A = {0};
  double s21_result_determinant = 0.0;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 7.0;
  double det_result = 7.0;

  int s21_result = s21_determinant(&A, &s21_result_determinant);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_double_eq_tol(s21_result_determinant, det_result, CMP_EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_ok_4) {
  matrix_t A = {0};
  double s21_result_determinant = 0.0;
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.234;
  A.matrix[0][1] = 1.234;
  A.matrix[0][2] = 1.234;
  A.matrix[0][3] = 1.234;
  A.matrix[0][4] = 1.234;
  A.matrix[1][0] = -1.234;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = -1.234;
  A.matrix[1][3] = 0;
  A.matrix[1][4] = -1.234;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -1.234;
  A.matrix[2][2] = 0;
  A.matrix[2][3] = -1.234;
  A.matrix[2][4] = 0;
  A.matrix[3][0] = -1.234;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = -1.234;
  A.matrix[3][3] = 0;
  A.matrix[3][4] = -1.234;
  A.matrix[4][0] = 0;
  A.matrix[4][1] = -1.234;
  A.matrix[4][2] = 0;
  A.matrix[4][3] = -1.234;
  A.matrix[4][4] = 0;
  double system_result = 0.0;

  int s21_result = s21_determinant(&A, &s21_result_determinant);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_double_eq_tol(s21_result_determinant, system_result, CMP_EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_ok_5) {
  matrix_t A;
  double s21_result_determinant = 0.0;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 10.0;
  double system_result = -3.0;

  int s21_result = s21_determinant(&A, &s21_result_determinant);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_double_eq_tol(s21_result_determinant, system_result, CMP_EPSILON);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_error_1) {
  matrix_t A = {0};
  double s21_result_determinant = 0.0;
  int rows = 2, columns = 3;
  s21_create_matrix(rows, columns, &A);

  int s21_result = s21_determinant(&A, &s21_result_determinant);

  ck_assert_int_eq(s21_result, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_determinant_error_2) {
  matrix_t A = {0};
  double s21_result_determinant = 0.0;
  int rows = 0, columns = 3;
  s21_create_matrix(rows, columns, &A);

  int s21_result = s21_determinant(&A, &s21_result_determinant);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_ok_1) {
  matrix_t A = {0}, s21_result_matrix = {0}, calc_compl_result = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &calc_compl_result);
  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 0.0;
  A.matrix[1][1] = 4.0;
  A.matrix[1][2] = 2.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = 2.0;
  A.matrix[2][2] = 1.0;
  calc_compl_result.matrix[0][0] = 0.0;
  calc_compl_result.matrix[0][1] = 10.0;
  calc_compl_result.matrix[0][2] = -20.0;
  calc_compl_result.matrix[1][0] = 4.0;
  calc_compl_result.matrix[1][1] = -14.0;
  calc_compl_result.matrix[1][2] = 8.0;
  calc_compl_result.matrix[2][0] = -8.0;
  calc_compl_result.matrix[2][1] = -2.0;
  calc_compl_result.matrix[2][2] = 4.0;

  int s21_result = s21_calc_complements(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              calc_compl_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&s21_result_matrix);
  s21_remove_matrix(&calc_compl_result);
}
END_TEST

START_TEST(test_calc_complements_ok_2) {
  matrix_t A = {0}, s21_result_matrix = {0}, calc_compl_result = {0};
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &calc_compl_result);
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = 3.0;
  calc_compl_result.matrix[0][0] = 1.0;

  int s21_result = s21_calc_complements(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_double_eq_tol(s21_result_matrix.matrix[0][0],
                          calc_compl_result.matrix[0][0], CMP_EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&s21_result_matrix);
  s21_remove_matrix(&calc_compl_result);
}
END_TEST

START_TEST(test_calc_complements_error_1) {
  matrix_t A = {0}, s21_result_matrix = {0};
  int rows = 3, columns = 2;
  s21_create_matrix(rows, columns, &A);

  int s21_result = s21_calc_complements(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_calc_complements_error_2) {
  matrix_t A = {0}, s21_result_matrix = {0};
  int rows = 3, columns = 0;
  s21_create_matrix(rows, 2, &A);
  A.columns = columns;

  int s21_result = s21_calc_complements(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_ok_1) {
  matrix_t A = {0}, s21_result_matrix = {0}, inverse_result = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &inverse_result);
  A.matrix[0][0] = -5.0;
  A.matrix[0][1] = -3.0;
  A.matrix[0][2] = -1.0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 9.0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 25.0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1.0;
  inverse_result.matrix[0][0] = 0.05;
  inverse_result.matrix[0][1] = 0.0166667;
  inverse_result.matrix[0][2] = 0.05;
  inverse_result.matrix[1][0] = 0;
  inverse_result.matrix[1][1] = 0.1111111;
  inverse_result.matrix[1][2] = 0;
  inverse_result.matrix[2][0] = -1.25;
  inverse_result.matrix[2][1] = -0.4166667;
  inverse_result.matrix[2][2] = -0.25;

  int s21_result = s21_inverse_matrix(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              inverse_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&s21_result_matrix);
  s21_remove_matrix(&inverse_result);
}
END_TEST

START_TEST(test_inverse_matrix_ok_2) {
  matrix_t A = {0}, s21_result_matrix = {0}, inverse_result = {0};
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &inverse_result);
  A.matrix[0][0] = 5;
  A.matrix[0][1] = -25;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 0;
  inverse_result.matrix[0][0] = 0;
  inverse_result.matrix[0][1] = 0.25;
  inverse_result.matrix[1][0] = -0.04;
  inverse_result.matrix[1][1] = 0.05;

  int s21_result = s21_inverse_matrix(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(s21_result_matrix.matrix[i][j],
                              inverse_result.matrix[i][j], CMP_EPSILON);
    }
  }

  s21_remove_matrix(&A);
  s21_remove_matrix(&s21_result_matrix);
  s21_remove_matrix(&inverse_result);
}
END_TEST

START_TEST(test_inverse_matrix_ok_3) {
  matrix_t A = {0}, s21_result_matrix = {0}, inverse_result = {0};
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &inverse_result);
  A.matrix[0][0] = 3.0;
  inverse_result.matrix[0][0] = 1.0 / A.matrix[0][0];

  int s21_result = s21_inverse_matrix(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, OK);
  ck_assert_double_eq_tol(s21_result_matrix.matrix[0][0],
                          inverse_result.matrix[0][0], CMP_EPSILON);

  s21_remove_matrix(&A);
  s21_remove_matrix(&s21_result_matrix);
  s21_remove_matrix(&inverse_result);
}
END_TEST

START_TEST(test_inverse_matrix_error_1) {
  matrix_t A = {0}, s21_result_matrix = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(1.0, &A);

  int s21_result = s21_inverse_matrix(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_inverse_matrix_error_2) {
  matrix_t A = {0}, s21_result_matrix = {0};
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  gen_matrix(2.0, &A);
  s21_remove_matrix(&A);

  int s21_result = s21_inverse_matrix(&A, &s21_result_matrix);

  ck_assert_int_eq(s21_result, INCORRECT_MATRIX);
}
END_TEST

Suite* suite_remove_matrix(void) {
  Suite* suite = suite_create("s21_remove_matrix");
  TCase* tc_s21_remove_matrix;

  tc_s21_remove_matrix = tcase_create("tc_s21_remove_matrix");
  tcase_add_test(tc_s21_remove_matrix, test_remove_matrix);

  suite_add_tcase(suite, tc_s21_remove_matrix);

  return suite;
}

Suite* suite_create_matrix(void) {
  Suite* suite = suite_create("s21_create_matrix");
  TCase* tc_s21_create_matrix;

  tc_s21_create_matrix = tcase_create("tc_s21_create_matrix");
  tcase_add_test(tc_s21_create_matrix, test_create_matrix_ok_1);
  tcase_add_test(tc_s21_create_matrix, test_create_matrix_ok_2);
  tcase_add_test(tc_s21_create_matrix, test_create_matrix_error_1);
  tcase_add_test(tc_s21_create_matrix, test_create_matrix_error_2);
  tcase_add_test(tc_s21_create_matrix, test_create_matrix_error_3);
  tcase_add_test(tc_s21_create_matrix, test_create_matrix_error_4);

  suite_add_tcase(suite, tc_s21_create_matrix);

  return suite;
}

Suite* suite_eq_matrix(void) {
  Suite* suite = suite_create("s21_eq_matrix");
  TCase* tc_s21_eq_matrix;

  tc_s21_eq_matrix = tcase_create("tc_s21_eq_matrix");
  tcase_add_test(tc_s21_eq_matrix, test_eq_matrix_success_1);
  tcase_add_test(tc_s21_eq_matrix, test_eq_matrix_success_2);
  tcase_add_test(tc_s21_eq_matrix, test_eq_matrix_success_3);
  tcase_add_test(tc_s21_eq_matrix, test_eq_matrix_failure_1);
  tcase_add_test(tc_s21_eq_matrix, test_eq_matrix_failure_2);
  tcase_add_test(tc_s21_eq_matrix, test_eq_matrix_failure_3);
  tcase_add_test(tc_s21_eq_matrix, test_eq_matrix_failure_4);
  tcase_add_test(tc_s21_eq_matrix, test_eq_matrix_failure_5);

  suite_add_tcase(suite, tc_s21_eq_matrix);

  return suite;
}

Suite* suite_sum_matrix(void) {
  Suite* suite = suite_create("s21_sum_matrix");
  TCase* tc_s21_sum_matrix;

  tc_s21_sum_matrix = tcase_create("tc_s21_sum_matrix");
  tcase_add_test(tc_s21_sum_matrix, test_sum_matrix_ok_1);
  tcase_add_test(tc_s21_sum_matrix, test_sum_matrix_ok_2);
  tcase_add_test(tc_s21_sum_matrix, test_sum_matrix_error_1);
  tcase_add_test(tc_s21_sum_matrix, test_sum_matrix_error_2);
  tcase_add_test(tc_s21_sum_matrix, test_sum_matrix_error_3);

  suite_add_tcase(suite, tc_s21_sum_matrix);

  return suite;
}

Suite* suite_sub_matrix(void) {
  Suite* suite = suite_create("s21_sub_matrix");
  TCase* tc_s21_sub_matrix;

  tc_s21_sub_matrix = tcase_create("tc_s21_sub_matrix");
  tcase_add_test(tc_s21_sub_matrix, test_sub_matrix_ok_1);
  tcase_add_test(tc_s21_sub_matrix, test_sub_matrix_ok_2);
  tcase_add_test(tc_s21_sub_matrix, test_sub_matrix_error_1);
  tcase_add_test(tc_s21_sub_matrix, test_sub_matrix_error_2);

  suite_add_tcase(suite, tc_s21_sub_matrix);

  return suite;
}

Suite* suite_mult_number(void) {
  Suite* suite = suite_create("s21_mult_number");
  TCase* tc_s21_mult_number;

  tc_s21_mult_number = tcase_create("tc_s21_mult_number");
  tcase_add_test(tc_s21_mult_number, test_mult_number_ok_1);
  tcase_add_test(tc_s21_mult_number, test_mult_number_ok_2);
  tcase_add_test(tc_s21_mult_number, test_mult_number_error_1);
  tcase_add_test(tc_s21_mult_number, test_mult_number_error_2);

  suite_add_tcase(suite, tc_s21_mult_number);

  return suite;
}

Suite* suite_mult_matrix(void) {
  Suite* suite = suite_create("s21_mult_matrix");
  TCase* tc_s21_mult_matrix;

  tc_s21_mult_matrix = tcase_create("tc_s21_mult_matrix");
  tcase_add_test(tc_s21_mult_matrix, test_mult_matrix_ok_1);
  tcase_add_test(tc_s21_mult_matrix, test_mult_matrix_ok_2);
  tcase_add_test(tc_s21_mult_matrix, test_mult_matrix_error_1);
  tcase_add_test(tc_s21_mult_matrix, test_mult_matrix_error_2);

  suite_add_tcase(suite, tc_s21_mult_matrix);

  return suite;
}

Suite* suite_transpose(void) {
  Suite* suite = suite_create("s21_transpose");
  TCase* tc_s21_transpose;

  tc_s21_transpose = tcase_create("tc_s21_transpose");
  tcase_add_test(tc_s21_transpose, test_transpose_ok_1);
  tcase_add_test(tc_s21_transpose, test_transpose_ok_2);
  tcase_add_test(tc_s21_transpose, test_transpose_error_1);
  tcase_add_test(tc_s21_transpose, test_transpose_error_2);

  suite_add_tcase(suite, tc_s21_transpose);

  return suite;
}

Suite* suite_determinant(void) {
  Suite* suite = suite_create("s21_determinant");
  TCase* tc_s21_determinant;

  tc_s21_determinant = tcase_create("tc_s21_determinant");
  tcase_add_test(tc_s21_determinant, test_determinant_ok_1);
  tcase_add_test(tc_s21_determinant, test_determinant_ok_2);
  tcase_add_test(tc_s21_determinant, test_determinant_ok_3);
  tcase_add_test(tc_s21_determinant, test_determinant_ok_4);
  tcase_add_test(tc_s21_determinant, test_determinant_ok_5);
  tcase_add_test(tc_s21_determinant, test_determinant_error_1);
  tcase_add_test(tc_s21_determinant, test_determinant_error_2);

  suite_add_tcase(suite, tc_s21_determinant);

  return suite;
}

Suite* suite_calc_complements(void) {
  Suite* suite = suite_create("s21_calc_complements");
  TCase* tc_s21_calc_complements;

  tc_s21_calc_complements = tcase_create("tc_s21_calc_complements");
  tcase_add_test(tc_s21_calc_complements, test_calc_complements_ok_1);
  tcase_add_test(tc_s21_calc_complements, test_calc_complements_ok_2);
  tcase_add_test(tc_s21_calc_complements, test_calc_complements_error_1);
  tcase_add_test(tc_s21_calc_complements, test_calc_complements_error_2);

  suite_add_tcase(suite, tc_s21_calc_complements);

  return suite;
}

Suite* suite_inverse_matrix(void) {
  Suite* suite = suite_create("s21_inverse_matrix");
  TCase* tc_s21_inverse_matrix;

  tc_s21_inverse_matrix = tcase_create("tc_s21_inverse_matrix");
  tcase_add_test(tc_s21_inverse_matrix, test_inverse_matrix_ok_1);
  tcase_add_test(tc_s21_inverse_matrix, test_inverse_matrix_ok_2);
  tcase_add_test(tc_s21_inverse_matrix, test_inverse_matrix_ok_3);
  tcase_add_test(tc_s21_inverse_matrix, test_inverse_matrix_error_1);
  tcase_add_test(tc_s21_inverse_matrix, test_inverse_matrix_error_2);

  suite_add_tcase(suite, tc_s21_inverse_matrix);

  return suite;
}

int main(void) {
  int failed = 0;
  Suite* suite[11];
  SRunner* runner;

  suite[0] = suite_create_matrix();
  suite[1] = suite_remove_matrix();
  suite[2] = suite_eq_matrix();
  suite[3] = suite_sum_matrix();
  suite[4] = suite_sub_matrix();
  suite[5] = suite_mult_number();
  suite[6] = suite_mult_matrix();
  suite[7] = suite_transpose();
  suite[8] = suite_determinant();
  suite[9] = suite_calc_complements();
  suite[10] = suite_inverse_matrix();

  runner = srunner_create(suite[0]);

  srunner_add_suite(runner, suite[1]);
  srunner_add_suite(runner, suite[2]);
  srunner_add_suite(runner, suite[3]);
  srunner_add_suite(runner, suite[4]);
  srunner_add_suite(runner, suite[5]);
  srunner_add_suite(runner, suite[6]);
  srunner_add_suite(runner, suite[7]);
  srunner_add_suite(runner, suite[8]);
  srunner_add_suite(runner, suite[9]);
  srunner_add_suite(runner, suite[10]);

  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
