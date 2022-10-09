
SRC = ./tester.c
LIB = ../libft/libft.a
OUT = printf_tester

make:
	@if [ ! -e ./assert_test_output_raw.txt ]; then make refresh -C ..; fi 
	gcc $(SRC) $(LIB) -o $(OUT)

runtest:
	gcc -g $(SRC) $(LIB) -o $(OUT)
	lldb $(OUT)

assert_t: make
	@python filter.py
	@rm assert_test_output_raw.txt

run_compare: assert_t
	@./$(OUT)

clean:
	@echo "removing executable and printf output"
	@rm -f $(OUT)
	@rm -f assert_test_output_raw.txt
	@rm -f assert_test_output_filtered.txt
	@if [ -e $(OUT).dSYM ]; then rm -rf $(OUT).dSYM && echo "Removing debugging directory"; fi

fclean: clean

edit:
	vi $(SRC)
