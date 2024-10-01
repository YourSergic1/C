#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  /*поиск последнего вхождения символа в строку.*/
  char *ch = S21_NULL;

  if (c == '\0')
    ch = (char *)(str + s21_strlen(str));
  else {
    for (int i = 0; str[i] != '\0'; ++i) {
      if (str[i] == c) ch = (char *)(str + i);
    }
  }
  return ch;
}
