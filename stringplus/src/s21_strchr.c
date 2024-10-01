#include "s21_string.h"

char *s21_strchr(const char *str, int m) {
  /*возвращает ссылку на первое вхождение m в строке str (ищет в строке)*/
  char *answ = S21_NULL;

  int i = 0;
  while (str[i]) {
    if (str[i] == m) answ = (char *)str + i;
    i++;
  }
  if (!answ && m == '\0') answ = (char *)str + i;
  return answ;
}
