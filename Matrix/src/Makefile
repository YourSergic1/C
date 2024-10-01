CC = gcc -g -Wall -Werror -Wextra -std=c11
OS = $(shell uname)

ifeq ($(OS),Linux)
    Flags = -lcheck  -lm -lrt -lpthread -lsubunit
else
    Flags = -lcheck -lm -lpthread
endif

all: clean gcov_report

s21_matrix.a: clean
	$(CC) -c s21_matrix.c $(Flags)
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a
	rm *.o

test: s21_matrix.a
	$(CC) unit_test.c s21_matrix.a -o test $(Flags)
	./test

gcov_report:
	$(CC) -fprofile-arcs -ftest-coverage s21_matrix.c unit_test.c $(Flags) -o test
	./test
	lcov -t test -o test.info -c -d .
	genhtml -o report test.info
	open ./report/index.html

clean:
	rm -rf *.a *.o test *.gcno *.gcda report *.info

clang:
	clang-format -style=Google -n *.c *.h

memory_check:
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --show-reachable=yes --verbose ./test
