#include "s21_string.h"

s21_size_t s21_strlen(const char *str) {
  /*находит длину*/
  s21_size_t a = 0;
  while (str[a] != '\0') {
    a++;
  }
  return (a);
}
