CC = gcc -g -Wall -Werror -Wextra -std=c11
INSTALL_FILES = main.c gui/cli/*.c brick_game.a
HEADERS = brick_game/tetris/*.h gui/cli/*.h
MODEL_SRC = brick_game/tetris/*.c
VIEW_SRC = gui/cli/*.c
SOURCES = $(MODEL_SRC) $(VIEW_SRC)

ifeq ($(shell uname), Linux)
  FLAGS = -lcheck -lsubunit -lm 
else
  FLAGS = -lcheck
endif

all: install gcov_report

install:  uninstall clean backend.a 
	$(CC) $(INSTALL_FILES) -lncurses -o bin/game
	rm -rf *.o *.a 

backend.a: backend.o
	ar rcs brick_game.a *.o
	ranlib brick_game.a
	rm -rf backend.o

backend.o: 
	$(CC) -c ./brick_game/tetris/backend.c 

gcov_report:
	$(CC) --coverage tests.c $(MODEL_SRC) $(VIEW_SRC) -lncurses -o tests $(FLAGS)
	valgrind --tool=memcheck --leak-check=yes ./tests
	lcov -t "tests" -o tests.info -c -d .
	genhtml -o report tests.info
	open ./report/index.html
	rm -rf *.gcno *.gcda *.info tests

clean: uninstall
	rm -rf *.o *.a *.gcda *.gcdo *.gcno tests report

dvi:
	open dvi.md

dist: install
	mkdir archiv
	cp -r $(SOURCES) $(HEADERS) archiv
	tar -cf tetris.tar archiv
	rm -rf archiv

clang:
	clang-format -style=Google -i gui/cli/*.c
	clang-format -style=Google -i gui/cli/*.h
	clang-format -style=Google -i brick_game/tetris/*.c
	clang-format -style=Google -i brick_game/tetris/*.h
	clang-format -style=Google -i *.c

uninstall:
	rm -rf bin/game