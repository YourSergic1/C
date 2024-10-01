#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  /*Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
   * байтах строки, на которую указывает аргумент str.*/
  const char *s = str;

  void *num = S21_NULL;

  for (s21_size_t i = 0; i < n; ++i) {
    if (s[i] == c) {
      num = (void *)(&(s[i]));
      break;
    }
  }
  return num;
}
