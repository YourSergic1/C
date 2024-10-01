#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  /*копирует b в a до n байт*/

  s21_size_t i = 0;
  while (i < n) {
    dest[i] = src[i];
    ++i;
  }
  return dest;
}
