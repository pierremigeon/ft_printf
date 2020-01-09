#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

#include <stdio.h>

void    putnbr_hex(int i, int depth, int ul_case)
{
	char 		out;
	static int 	d;

	d = depth;
	if (i > 16)
		putnbr_hex(i / 16, depth + 1, 1);
	if (d == depth)
		write(1, "10", 2);
	out = (i % 16 < 10) ? '0' + i % 16 : 'a' + i % 16 % 10;
	write(1, &out, 1);
	i /= 16;
}

int	dispatcher(va_list ap, char **fmt_substr)
{
	char	*s;
	char	c;
	int	i;	

	if (**fmt_substr == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr(s);
		(*fmt_substr)++;
	}
	else if (**fmt_substr == 'i' || **fmt_substr == 'd')
	{
		i = va_arg(ap, int);
		ft_putnbr(i);
		(*fmt_substr)++;
	}
	else if (**fmt_substr == 'c')
	{
		c = va_arg(ap, int);
		write(1, &c, 1);
		(*fmt_substr)++;
	}
	else if (**fmt_substr == 'p')
	{
		i = va_arg(ap, int);
		putnbr_hex(i, 0, 1);
		(*fmt_substr)++;
	}
	return (5);
}

// Calls to write are sort of expensive, better to calculate the total space 
// until the next % and then do one call to write (in the else while loop)
int	ft_printf(char *fmt_str, ...)
{
	va_list	ap;
	char *s;
	int bytes_printed;

	bytes_printed = 0;
	va_start(ap, fmt_str);
	while (*fmt_str)
	{
		if (*fmt_str == '%' && *(++fmt_str) != '%')
			bytes_printed += dispatcher(ap, &fmt_str);
		else while (*fmt_str && *fmt_str != '%')
			bytes_printed += write(1, fmt_str++, 1);
	}
	va_end(ap);
	return (bytes_printed);
}

int	main()
{
	char *string = "this is a test run to make sure that it works";
	int	i = 5;
	char	c = 'A';

	ft_printf("Printf %s and this is a number %i and a number also %d and this is a character: %c and this is an address %p\n", string, i, i, c, string);


	printf ("This is the addres with native function: %p\n", string);






	return (0);
}
