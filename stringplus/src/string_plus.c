#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  s21_size_t length = s21_strlen(str);
  char *result = calloc((length + 1), sizeof(char));
  if (result == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < length; i++) {
    if (str[i] > 96 && str[i] < 123)
      result[i] = (char)((int)str[i] - 32);
    else
      result[i] = str[i];
  }
  result[length] = '\0';
  return result;
}

void *s21_to_lower(const char *str) {
  if (str == NULL) {
    return NULL;
  }

  s21_size_t length = s21_strlen(str);
  char *result = calloc((length + 1), sizeof(char));
  if (result == NULL) {
    return NULL;
  }

  for (size_t i = 0; i < length; i++) {
    if (str[i] > 64 && str[i] < 91)
      result[i] = (char)((int)str[i] + 32);
    else
      result[i] = str[i];
  }
  result[length] = '\0';

  return result;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (str == NULL || src == NULL || s21_strlen(src) <= start_index) {
    return NULL;
  }

  s21_size_t length = s21_strlen(str) + s21_strlen(src);
  char *result = calloc((length + 1), sizeof(char));
  if (result == NULL) {
    return NULL;
  }

  s21_strncpy(result, src, start_index);
  s21_strncat(result, str, s21_strlen(str));
  s21_strncat(result, start_index + src, s21_strlen(src) - start_index);
  result[length] = '\0';
  return result;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == NULL || s21_strlen(src) == 0) {
    return NULL;
  }
  if (trim_chars == NULL || s21_strlen(trim_chars) == 0) {
    return NULL;
  }

  int start_index = 0;
  int end_index = (int)s21_strlen(src);
  while (src[start_index] != '\0' &&
         s21_strchr(trim_chars, src[start_index]) != NULL) {
    start_index++;
  }
  while (end_index > start_index &&
         s21_strchr(trim_chars, src[end_index - 1]) != NULL) {
    end_index--;
  }

  if (start_index >= end_index) {
    char *result = calloc(1, sizeof(char));
    *result = '\0';
    return (void *)result;
  }

  s21_size_t result_length = end_index - start_index + 1;
  char *result = calloc(result_length, sizeof(char));
  s21_strncpy(result, src + start_index, result_length - 1);
  result[result_length - 1] = '\0';

  return (void *)result;
}
