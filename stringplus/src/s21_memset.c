#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  /*заполняет n байтов значениями c*/
  char *p = str;
  while (n) {
    *p = (char)c;
    p++;
    n--;
  }
  return str;
}
