#include <check.h>

#include "brick_game/tetris/backend.h"

START_TEST(TEST_create_field_and_create_figure_new) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  int result[20][10] = {0};
  int result_figure[4][4] = {0};
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      ck_assert_int_eq(game.field[i][j], result[i][j]);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(game.next[i][j], result_figure[i][j]);
    }
  }
  clear_field(&game);
}
END_TEST

START_TEST(TEST_create_figure) {
  current_figure figure;
  create_figure_current(&figure);
  int result_figure[4][4] = {0};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result_figure[i][j]);
    }
  }
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_init_one_figure) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  init_one_figure(&game, 0);
  int result_figure[4][4][4] = {
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},  //кубик
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(game.next[i][j], result_figure[0][i][j]);
    }
  }
  clear_field(&game);
}
END_TEST

START_TEST(TEST_init_figure) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  init_figure(&game);
  int number_of_figure = game.next[0][0];
  int result_figure[7][4][4] = {
      {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}},
      {{2, 0, 0, 0}, {0, 0, 1, 1}, {0, 1, 1, 0}, {0, 0, 0, 0}},
      {{3, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}},
      {{4, 0, 0, 0}, {0, 1, 1, 1}, {0, 1, 0, 0}, {0, 0, 0, 0}},
      {{5, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}},
      {{6, 0, 0, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(game.next[i][j], result_figure[number_of_figure][i][j]);
    }
  }
  clear_field(&game);
}
END_TEST

START_TEST(TEST_switch) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      game.next[i][j] = 1;
    }
  }
  switch_figure_box(&game, &figure);
  int result[4][4] = {{0, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(result[i][j], figure.type[i][j]);
    }
  }
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_move_right) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  move_right(&game, &figure);
  ck_assert_int_eq(figure.x, 5);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_move_left) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  move_left(&game, &figure);
  ck_assert_int_eq(figure.x, 3);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_move_down) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 0);
  switch_figure_box(&game, &figure);
  move_down(&game, &figure);
  ck_assert_int_eq(figure.x, 4);
  ck_assert_int_eq(figure.y, 1);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_clear_line) {
  GameInfo_t game;
  create_field(&game);
  game.score = 0;
  game.high_score = 0;
  create_figure_new(&game);
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      game.field[i][j] = 1;
    }
  }
  check_for_full(&game);
  clear_line(&game);
  ck_assert_int_eq(game.score, 1500);
  clear_field(&game);
}
END_TEST

START_TEST(TEST_rewrite) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_current(&figure);
  create_figure_new(&game);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      figure.type[i][j] = 1;
    }
  }
  figure.x = 1;
  figure.y = 1;
  rewrite_field(&game, &figure);
  int result[20][10] = {
      {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 10; j++) {
      ck_assert_int_eq(game.field[i][j], result[i][j]);
    }
  }

  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_in_game) {
  GameInfo_t game;
  create_field(&game);
  create_figure_new(&game);
  int result = 1;
  ck_assert_int_eq(result, check_in_game(&game));
  clear_field(&game);
}
END_TEST

START_TEST(TEST_rotate_O) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 0);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result[i][j]);
    }
  }
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_rotate_I) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 1);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_rotate_S) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 1}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 2);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_rotate_Z) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 3);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_rotate_L) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 4);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_rotate_J) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 5);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_rotate_T) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 0, 1, 1}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 6);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result[i][j]);
    }
  }
  rotate(&game, &figure);
  rotate(&game, &figure);
  rotate(&game, &figure);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_user_input_left) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  int input = 3;
  int flag = 0;
  int down = 0;
  int left = 0;
  int right = 0;
  int stop_down = 0;
  work_with_user_input(input, &flag, &down, &left, &right, &stop_down, &game,
                       &figure);
  ck_assert_int_eq(3, figure.x);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_user_input_right) {
  GameInfo_t game;
  current_figure figure;
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_figure(&game);
  switch_figure_box(&game, &figure);
  int input = 4;
  int flag = 0;
  int down = 0;
  int left = 0;
  int right = 0;
  int stop_down = 0;
  work_with_user_input(input, &flag, &down, &left, &right, &stop_down, &game,
                       &figure);
  ck_assert_int_eq(5, figure.x);
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

START_TEST(TEST_user_input_rotate) {
  GameInfo_t game;
  current_figure figure;
  int result[4][4] = {{0, 0, 1, 0}, {0, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  create_field(&game);
  create_figure_new(&game);
  create_figure_current(&figure);
  init_one_figure(&game, 6);
  switch_figure_box(&game, &figure);
  figure.y = 5;
  int input = 7;
  int flag = 0;
  int down = 0;
  int left = 0;
  int right = 0;
  int stop_down = 0;
  work_with_user_input(input, &flag, &down, &left, &right, &stop_down, &game,
                       &figure);
  rotate(&game, &figure);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_int_eq(figure.type[i][j], result[i][j]);
    }
  }
  clear_field(&game);
  clear_figure(&figure);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Tetris");
  TCase *tc1_1 = tcase_create("Tetris");
  SRunner *sr = srunner_create(s1);
  int nf = 0;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, TEST_create_field_and_create_figure_new);
  tcase_add_test(tc1_1, TEST_create_figure);
  tcase_add_test(tc1_1, TEST_init_one_figure);
  tcase_add_test(tc1_1, TEST_init_figure);
  tcase_add_test(tc1_1, TEST_switch);
  tcase_add_test(tc1_1, TEST_move_right);
  tcase_add_test(tc1_1, TEST_move_left);
  tcase_add_test(tc1_1, TEST_move_down);
  tcase_add_test(tc1_1, TEST_clear_line);
  tcase_add_test(tc1_1, TEST_rewrite);
  tcase_add_test(tc1_1, TEST_in_game);
  tcase_add_test(tc1_1, TEST_rotate_O);
  tcase_add_test(tc1_1, TEST_rotate_I);
  tcase_add_test(tc1_1, TEST_rotate_S);
  tcase_add_test(tc1_1, TEST_rotate_Z);
  tcase_add_test(tc1_1, TEST_rotate_L);
  tcase_add_test(tc1_1, TEST_rotate_J);
  tcase_add_test(tc1_1, TEST_rotate_T);
  tcase_add_test(tc1_1, TEST_user_input_left);
  tcase_add_test(tc1_1, TEST_user_input_right);
  tcase_add_test(tc1_1, TEST_user_input_rotate);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}