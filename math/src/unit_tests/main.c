#include "../s21_math.h"
#include "s21_test.h"

int main(void) {
  int failed = 0;
  Suite *s21_math_test[] = {test_abs(),   test_asin(), test_acos(), test_atan(),
                            test_ceil(),  test_cos(),  test_exp(),  test_fabs(),
                            test_floor(), test_fmod(), test_sin(),  test_tan(),
                            test_sqrt(),  test_pow(),  test_log(),  NULL};

  for (int i = 0; s21_math_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner *sr = srunner_create(s21_math_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return 0;
}