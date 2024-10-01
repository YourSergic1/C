#ifndef BACKEND_H
#define BACKEND_H

#include "../../gui/cli/frontend.h"
#include "defines.h"

void create_field(GameInfo_t *new);
void create_figure_new(GameInfo_t *new);
void create_figure_current(current_figure *figure);

void init_figure(GameInfo_t *new);
void init_one_figure(GameInfo_t *new, int number);
void init_game(GameInfo_t *game, current_figure *figure);

int wait_for_start(GameInfo_t *game, current_figure *figure);
int wait_for_resume(GameInfo_t *game);

int userInput(int input);

void switch_figure_box(GameInfo_t *new, current_figure *figure);
int move_right(GameInfo_t *game, current_figure *figure);
int move_left(GameInfo_t *game, current_figure *figure);
int move_down(GameInfo_t *game, current_figure *figure);
void check_for_full(GameInfo_t *game);
void clear_line(GameInfo_t *game);
void rewrite_field(GameInfo_t *game, current_figure *figure);

void clear_field(GameInfo_t *old);
void clear_figure(current_figure *figure);

int check_in_game(GameInfo_t *game);
void wait_to_esc(GameInfo_t *game);

void rotate(GameInfo_t *game, current_figure *figure);
void rewrite_figure(current_figure *figure);
void rotate_I(GameInfo_t *game, current_figure *figure);
void rotate_S(GameInfo_t *game, current_figure *figure);
void rotate_Z(GameInfo_t *game, current_figure *figure);
void rotate_L(GameInfo_t *game, current_figure *figure);
void rotate_J(GameInfo_t *game, current_figure *figure);
void rotate_T(GameInfo_t *game, current_figure *figure);

void work_with_user_input(int input, int *flag, int *down, int *left,
                          int *right, int *stop_down, GameInfo_t *game,
                          current_figure *figure);
void check_for_moving(int *down, int *left, int *right, GameInfo_t *game,
                      current_figure *figure, int *flag);
void mane_game(GameInfo_t *game, current_figure *figure);

#endif