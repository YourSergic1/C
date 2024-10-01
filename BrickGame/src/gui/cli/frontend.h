#ifndef FRONTEND_H
#define FRONTEND_H

#include "../../brick_game/tetris/backend.h"
#include "../../brick_game/tetris/defines.h"

void print_field(GameInfo_t *status);
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_figure(current_figure *figure);
void print_next_figure(GameInfo_t *new);
GameInfo_t updateCurrentState(GameInfo_t *game, current_figure *figure);
void print_info_start();
void print_info_resume();
void print_info_lost(GameInfo_t *game);

#endif