#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  /*ищет число не совпавших символов до первого освпадения одного из str2*/

  s21_size_t count = 0;
  int gg = 0;
  for (s21_size_t i = 0; str1[i] != '\0'; ++i) {
    if (gg) break;
    for (s21_size_t j = 0; str2[j] != '\0'; ++j) {
      if (str1[i] == str2[j]) {
        gg = 1;
        break;
      }
    }
    if (!gg) ++count;
  }
  return count;
}
