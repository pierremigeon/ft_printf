
MAIN = ./src/main.c
SRC = ./src/ft_printf.c
LIB = ./libft/libft.a
OUT = ft_printf

make:
	gcc $(MAIN) $(SRC) $(LIB) -o $(OUT)

runtest:
	gcc -g $(SRC) $(LIB) -o $(OUT)
	lldb ft_printf

assert_test:
	@if [ ! -e ./$(OUT) ]; then make -C .; fi
	@./$(OUT) > ./testing/assert_test_output_raw.txt
	@make run_compare -C testing

refresh:
	@./$(OUT) > ./testing/assert_test_output_raw.txt
	
clean:
	@echo "removing executable"
	@rm ft_printf
	@if [ -e $(OUT).dSYM ]; then rm -rf $(OUT).dSYM && echo "Removing debugging directory"; fi

edit:
	vi $(SRC)

edit_h:
	vi ./includes/$(OUT).h
