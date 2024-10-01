#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  /*побайтовое сравнение первых n байтов str2 в str1*/
  const char *p1 = str1;
  const char *p2 = str2;

  int flag = 0;
  for (s21_size_t i = 0; i < n; i++) {
    if (*p1 != *p2) {
      flag = (*p1 - *p2);
      break;
    }
    p1++;
    p2++;
  }
  return flag;
}
