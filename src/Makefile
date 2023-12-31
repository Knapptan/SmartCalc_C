.PHONY: all clean build format test gcov_report

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11
TEST_FLAGS = `pkg-config --cflags --libs check` -lm -lcheck
MODEL_FILES = back/smart.c back/deposit.c back/cred.c
TEST_FILES = tests/run_tests.c

all:
	$(MAKE) clean
	$(MAKE) uninstall
	$(MAKE) install

install:
	@$(MAKE) uninstall
	@mkdir SmartCalc
	@cd SmartCalc && cmake -B build "../front/" && make -C build SmartCalc
	@cp -R SmartCalc/build/SmartCalc.app ~/Desktop/SmartCalc.app
	@echo " SmartCalc V1.0 by Knapptan was installed successfully! "
	@make dvi


uninstall:
	@rm -rf SmartCalc
	@rm -rf ~/Desktop/SmartCalc.app
	@echo " SmartCalc V1.0 was uninstalled successfully! "

dvi:
	@open documentation.md

dist:
	 tar -cf SmartCalc.tar SmartCalc

test:
	$(MAKE) clean
	 $(CC) $(CFLAGS) $(TEST_FILES) $(MODEL_FILES) $(TEST_FLAGS) -o test
	 ./test

gcov_report:
	 $(MAKE) clean
	 $(CC) $(CFLAGS) $(TEST_FILES) $(MODEL_FILES) -coverage $(TEST_FLAGS) -o gcovreport
	 ./gcovreport
	 lcov -t "gcovreport" -o gcovreport.info -c -d .
	 genhtml -o report gcovreport.info
	 @open report/index.html
	 @rm -rf *.a *.info *.gcda *.gcno gcovreport

format:
	clang-format -style=Google -i back/*.c back/*.h front/*.cpp front/*.h tests/*.c

format_check:
	clang-format -style=Google -n back/*.c back/*.h front/*.cpp front/*.h tests/*.c

clean:
	@rm -rf *.o *.a report *.gcno *.gcda  *.tar SmartCalc test gcovreport