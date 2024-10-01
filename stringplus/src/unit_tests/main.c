#include "../s21_string.h"
#include "s21_test.h"

int main(void) {
  int failed = 0;
  Suite *s21_string_test[] = {
      test_memcpy(),   test_memcht(),      test_memcmp(),
      test_memset(),   test_strncat(),     test_strchr(),
      test_strncmp(),  test_strncpy(),     test_strspn(),
      test_strerror(), test_strlen(),      test_strpbrk(),
      test_strrchr(),  test_strstr(),      test_strtok(),
      test_sprinf(),   test_string_plus(), NULL};

  for (int i = 0; s21_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return 0;
}
