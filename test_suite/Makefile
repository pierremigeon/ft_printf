
SRC = ./src/tester.c
LIB = ../libft/libft.a
OUT = printf_tester
FILTER = ./src/filter.py

make: clean
	@echo "\n# -> Gathering input data"
	@make refresh -C .. 
	@echo "# -> Compiling error detection program"
	@gcc $(SRC) $(LIB) -o $(OUT)

filter: make
	@echo "# -> Filtering printf output to remove annotations..."
	@python $(FILTER)
	@rm assert_test_output_raw.txt

run_compare: filter
	@echo "# -> Detecting Failed Tests..."
	@./$(OUT) > failed_tests.txt
	@tail -n 1 failed_tests.txt > summary.txt
	@make c_lite
	@echo "# -> Done...Summary and failed tests in directory\n"
see:
	less ./Makefile

c_lite:
	@rm -f assert_test_output_raw.txt
	@rm -f assert_test_output_filtered.txt
	@rm -f $(OUT)

clean: c_lite
	@rm -f summary.txt	
	@rm -f failed_tests.txt

fclean: clean

edit:
	vi $(SRC)
