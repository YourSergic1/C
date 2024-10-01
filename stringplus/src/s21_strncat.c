#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  /*конкатенация строк*/
  char *tmp = dest;

  while (*tmp != '\0') {
    tmp++;
  }
  while (n-- && *src != '\0') {
    *tmp = *src;
    tmp++;
    src++;
  }
  *tmp = '\0';
  return dest;
}