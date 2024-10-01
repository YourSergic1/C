CC=gcc
CFLAG=-g -Wall -Werror -Wextra -std=c11

TEST_EXE = test
LIB = s21_math

PREF_TEST = unit_tests/

SRC_STRING_FILE = $(wildcard *.c)
OBJ_STRING_FILE = $(patsubst %.c, %.o, $(SRC_STRING_FILE))


SRC_STRING_FILE_TEST = $(wildcard *.c)
OBJ_STRING_FILE_TEST = $(patsubst %.c, %.oo, $(SRC_STRING_FILE_TEST))


SRC_TEST_FILE = $(wildcard $(PREF_TEST)*.c)
OBJ_TEST_FILE= $(patsubst  $(PREF_TEST)%.c,  $(PREF_TEST)%.o, $(SRC_TEST_FILE))


all: $(TEST_EXE) $(LIB).a gcov_report


gcov_report: $(TEST_EXE)
	lcov -t "s21_math_test" -o fizzbuzz.info -c -d .
	genhtml -o report fizzbuzz.info



$(LIB).a: $(OBJ_STRING_FILE)
	ar r $(LIB).a *.o


$(TEST_EXE) : rebuild $(OBJ_STRING_FILE_TEST)  $(OBJ_TEST_FILE)
	$(CC) $(CFLAG) -lcheck --coverage $(OBJ_TEST_FILE) $(OBJ_STRING_FILE_TEST) -o $(TEST_EXE) -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	./test



%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@ 


%.oo : %.c
	$(CC) $(CFLAG) -c --coverage $< -o $@ -pthread -lcheck_pic -pthread -lrt -lm -lsubunit


# test


$(PREF_TEST)%.o : $(PREF_TEST)%.c
	$(CC) $(CFLAG) -c --coverage $< -o $@ -pthread -lcheck_pic -pthread -lrt -lm -lsubunit


rebuild:
	@rm -rf test
	@rm -rf $(LIB).a	

clean : rebuild
	@rm -rf *.o
	@rm -rf *.oo
	@rm -rf $(PREF_TEST)*.o
	@rm -rf *.info
	@rm -rf *.gcno
	@rm -rf $(PREF_TEST)*.gcno
	@rm -rf *.gcda
	@rm -rf $(PREF_TEST)*.gcda
	@rm -rf report

clang_n:
	clang-format -style=Google -n *.c *.h unit_tests/*.c unit_tests/*.h

clang_i:
	clang-format -style=Google -i *.c *.h unit_tests/*.c unit_tests/*.h
