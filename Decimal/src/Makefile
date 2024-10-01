C = gcc -Wall -Werror -Wextra -std=c11
OS = $(shell uname)

ifeq ($(OS),Linux)
    Flags = -lcheck  -lm -lrt -lpthread -lsubunit
else
    Flags = -lcheck -lm -lpthread
endif

all: gcov_report

s21_decimal.a: clean
	$(CC) -c *.c $(Flags)
	ar rcs s21_decimal.a *.o
	ranlib s21_decimal.a
	rm *.o

test: s21_decimal.a
	$(CC) --coverage *.c tests/*.c -o test $(Flags)
	./test

gcov_report: test
	lcov -t "result" -o res.info -c -d .
	genhtml -o report res.info
	open report/index.html

clean:
	rm -rf *.a *.o test *.gcno *.gcda report *.info

clang:
	clang-format -style=Google -n *.c *.h tests/*.c tests/*.h