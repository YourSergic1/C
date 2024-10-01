#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  /*ищет первое вхождение needle в haystack*/

  char *ch = S21_NULL;
  if (needle[0] == '\0' && haystack[0] == '\0') ch = (char *)haystack;

  s21_size_t n = s21_strlen(needle);
  while (*haystack) {
    if (!s21_memcmp(haystack, needle, n)) {
      ch = (char *)haystack;
      break;
    }
    haystack++;
  }
  return ch;
}
