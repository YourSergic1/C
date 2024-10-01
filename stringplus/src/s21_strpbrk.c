#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  /*Находит первый символ в строке str1, который соответствует любому символу,
   * указанному в str2.*/
  int num = -1;
  int gg = 0;

  for (int i = 0; str1[i] != '\0'; ++i) {
    for (int j = 0; str2[j] != '\0'; ++j) {
      if (str1[i] == str2[j]) {
        num = i;
        gg = 1;
        break;
      }
    }
    if (gg) break;
  }

  return (num != -1) ? (char *)str1 + num : S21_NULL;
}
