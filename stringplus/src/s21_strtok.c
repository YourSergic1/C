#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  /*Разбивает строку str на ряд токенов, разделенных delim.*/
  static char *input = S21_NULL;
  char *token = S21_NULL;

  if (str != S21_NULL) input = str;

  if (input == S21_NULL) return NULL;

  for (s21_size_t i = 0; delim[i]; i++) {
    if (*input == delim[i]) {
      i = -1;
      input++;
    }
  }

  token = input;
  input = s21_strpbrk(input, delim);

  if (input != S21_NULL) {
    *input = '\0';
    input++;
  }

  return token[0] ? token : S21_NULL;
}
