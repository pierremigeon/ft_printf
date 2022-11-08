
MAIN = ./src/main.c
SRC = ./src/ft_printf.c
LIB = ./libft/libft.a
OUT = ft_printf

make:
	gcc $(MAIN) $(SRC) $(LIB) -o $(OUT)

runtest:
	gcc -g $(MAIN) $(SRC) $(LIB) -o $(OUT)
	lldb ft_printf

assert_test: refresh
	@make run_compare -C test_suite

refresh:
	@if [ ! -e ./$(OUT) ]; then make -C .; fi
	@./$(OUT) > ./test_suite/assert_test_output_raw.txt
	
clean:
	@echo "removing executable"
	@rm ft_printf
	@if [ -e $(OUT).dSYM ]; then rm -rf $(OUT).dSYM && echo "Removing debugging directory"; fi

edit:
	vi $(SRC)
edit_m:
	vi $(MAIN)

edit_h:
	vi ./includes/$(OUT).h
