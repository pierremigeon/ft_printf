
SRC = ./src/ft_printf.c
LIB = ./libft/libft.a
OUT = ft_printf

make:
	gcc $(SRC) $(LIB) -o $(OUT)

runtest:
	gcc -g $(SRC) $(LIB) -o $(OUT)
	lldb ft_printf

clean:
	rm ft_printf
	@if [ -e $(OUT).dSYM ]; then rm -rf $(OUT).dSYM; fi

edit:
	vi ./src/ft_printf.c

edit_h:
	vi ./includes/$(OUT).h
