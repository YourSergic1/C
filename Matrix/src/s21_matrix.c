#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;
  if (rows < 1 || columns < 1)
    flag = INCORRECT_MATRIX;
  else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double));
    if (result->matrix == NULL)
      flag = INCORRECT_MATRIX;
    else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          for (int j = 0; j < i; j++) free(result->matrix[j]);
          free(result->matrix);
          flag = INCORRECT_MATRIX;
        }
      }
    }
  }
  return flag;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}

int s21_check_matrix(matrix_t *A) {
  int flag = OK;
  if (NULL == A || NULL == A->matrix || 0 >= A->rows || 0 >= A->columns)
    flag = INCORRECT_MATRIX;
  return flag;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (s21_check_matrix(A) == 0 && s21_check_matrix(B) == 0 &&
      A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows && flag; i++) {
      for (int j = 0; j < A->columns && flag; j++) {
        if (fabsl(truncl(A->matrix[i][j] * 10000000) -
                  truncl(B->matrix[i][j] * 10000000)) >= 1)
          flag = FAILURE;
      }
    }
  } else
    flag = FAILURE;
  return flag;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && s21_check_matrix(B) == 0 && result != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      int create_flag = 0;
      create_flag = s21_create_matrix(A->rows, A->columns, result);
      if (create_flag == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      } else
        flag = create_flag;
    } else
      flag = CALCULATION_ERROR;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && s21_check_matrix(B) == 0 && result != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      int create_flag = 0;
      create_flag = s21_create_matrix(A->rows, A->columns, result);
      if (create_flag == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      } else
        flag = create_flag;
    } else
      flag = CALCULATION_ERROR;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && result != NULL) {
    int create_flag = 0;
    create_flag = s21_create_matrix(A->rows, A->columns, result);
    if (create_flag == 0) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else
      flag = create_flag;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && s21_check_matrix(B) == 0 && result != NULL) {
    if (A->columns == B->rows) {
      int create_flag = 0;
      create_flag = s21_create_matrix(A->rows, B->columns, result);
      if (create_flag == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < B->rows; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      } else
        flag = create_flag;
    } else
      flag = CALCULATION_ERROR;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && result != NULL) {
    int create_flag = 0;
    create_flag = s21_create_matrix(A->columns, A->rows, result);
    if (create_flag == 0) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    } else
      flag = create_flag;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

int s21_minor(int row, int column, matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && result != NULL) {
    int create_flag = 0;
    create_flag = s21_create_matrix(A->columns - 1, A->rows - 1, result);
    if (create_flag == 0) {
      int minor_row = 0;
      int minor_column = 0;
      for (int i = 0; i < A->rows; i++) {
        if (row == i) continue;
        minor_column = 0;
        for (int j = 0; j < A->columns; j++) {
          if (column == j) continue;
          result->matrix[minor_row][minor_column] = A->matrix[i][j];
          minor_column++;
        }
        minor_row++;
      }
    } else
      flag = create_flag;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

void s21_determinant_exception(matrix_t *A, double *result) {
  if (A->columns == 1) *result = A->matrix[0][0];
  if (A->columns == 2)
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  if (A->columns == 3)
    *result = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
              A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
              A->matrix[0][2] * A->matrix[1][0] * A->matrix[2][1] -
              A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0] -
              A->matrix[0][0] * A->matrix[1][2] * A->matrix[2][1] -
              A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2];
  return;
}

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && result != NULL) {
    if (A->rows == A->columns) {
      if (A->rows == 1 || A->rows == 2 || A->rows == 3) {
        s21_determinant_exception(A, result);
      } else {
        int sign = 1;
        *result = 0;
        for (int i = 0; i < A->columns && flag == OK; i++) {
          matrix_t minor = {0};
          int create_flag = s21_minor(0, i, A, &minor);
          if (create_flag == 1) {
            flag = INCORRECT_MATRIX;
          } else {
            double det_part = 0;
            flag = s21_determinant(&minor, &det_part);
            if (!flag) {
              *result += sign * A->matrix[0][i] * det_part;
              sign = -sign;
            }
          }
          s21_remove_matrix(&minor);
        }
      }
    } else
      flag = CALCULATION_ERROR;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && result != NULL) {
    if (A->rows == A->columns) {
      int create_flag = 0;
      create_flag = s21_create_matrix(A->rows, A->columns, result);
      if (create_flag == OK) {
        if (A->rows == 1) {
          result->matrix[0][0] = 1;
        } else {
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              matrix_t minor = {0};
              double det = 0;
              s21_minor(i, j, A, &minor);
              s21_determinant(&minor, &det);
              result->matrix[i][j] = det;
              if ((i + j) % 2 != 0) result->matrix[i][j] *= -1;
              s21_remove_matrix(&minor);
            }
          }
        }
      } else
        flag = create_flag;
    } else
      flag = CALCULATION_ERROR;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (s21_check_matrix(A) == 0 && result != NULL) {
    if (A->rows == A->columns) {
      double determinant = 0;
      s21_determinant(A, &determinant);
      if (determinant != 0) {
        if (A->columns == 1) {
          int create_flag = 0;
          create_flag = s21_create_matrix(A->columns, A->rows, result);
          if (create_flag == OK)
            result->matrix[0][0] = 1 / determinant;
          else
            flag = create_flag;
        } else {
          determinant = 1 / determinant;
          matrix_t complements = {0};
          s21_calc_complements(A, &complements);
          matrix_t complements_transpose = {0};
          s21_transpose(&complements, &complements_transpose);
          s21_mult_number(&complements_transpose, determinant, result);
          s21_remove_matrix(&complements);
          s21_remove_matrix(&complements_transpose);
        }

      } else
        flag = CALCULATION_ERROR;
    } else
      flag = CALCULATION_ERROR;
  } else
    flag = INCORRECT_MATRIX;
  return flag;
}