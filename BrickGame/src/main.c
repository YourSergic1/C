#include "gui/cli/frontend.h"

int main() {
  current_figure figure;
  GameInfo_t game;
  init_game(&game, &figure);  //подготовка к анчалу игры
  wait_for_start(&game, &figure);  //ожидание начала
  mane_game(&game, &figure);       // Основной цикл игры
  endwin();
  clear_field(&game);
  clear_figure(&figure);  // Очистка и завершение ncurses
  return 0;
}