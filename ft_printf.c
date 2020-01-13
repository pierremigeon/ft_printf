#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

#include <stdio.h>


/* 

Note: Any flags past some point are just treated as characters to print:
	printf ("%is", 5); prints "5s"
	-This functionality is already present in my code.
	Same goes for length modifiers:
	printf ("%ih", 5); prints "5h"
	-This functionality is also already present in my code

Errors to handle:
	-input isn't type specified (isn't this just compiler?)
	-unequal number of arguments and conversing specifiers (isn't this just compiler?)
	-nonsensical combinations of input? %hhll? (This is definitely just compiler...)
	-How do you throw compliler errors? Are these automatic or do you need to code for these?

*/

char	*hex_prefix(int ul_case, int len)
{
	if (ul_case)
		return ((len) ? "0X100" : "0X10");
	return ((len) ? "0x100" : "0x10");
}

void    putnbr_hex(int i, int depth, int ul_case)
{
	char 		out;
	static int 	d;

	d = depth;
	if (i > 16)
		putnbr_hex(i / 16, depth + 1, ul_case);
	if (d == depth)
		(depth == 5) ? write(1, hex_prefix(ul_case, 1), 5) : write(1, hex_prefix(ul_case, 0), 4);
	if (ul_case == 0)
		out = (i % 16 < 10) ? '0' + i % 16 : 'a' + i % 16 % 10;
	else
		out = (i % 16 < 10) ? '0' + i % 16 : 'A' + i % 16 % 10;
	write(1, &out, 1);
	i /= 16;
}

void	putnbr_oct(int i)
{
	char 		out;
	static int	d;

	if (i > 7)
		putnbr_oct(i / 8);
	out = '0' + i % 8;	
	write(1, &out, 1);
}




/*

Will need to consider that sometimes the octal or hex prints will be stored 
as different types (sometimes short, sometimes long, long long, unsigned long,
unsigned long long, etc. Somtimes these can just be cast up to an int, but
will probably need a new function in the case that we have a larger (long long)
or signed vs unsigned... 

void	putnbr_oct(int i, int depth, int ul_case)
{
	char	out;
	
	if (i > 8)
		putnbr_oct(i

}

*/

int	test_ls(char **fmt_substr)
{
	return ( **fmt_substr == 'l' || **fmt_substr == 'S' || \
		 **fmt_substr == 'C' || **fmt_substr == 'D' || \
		 **fmt_substr == 'O' ||	**fmt_substr == 'U' 
	       );
}


/*

just stubbing... 

int	dispatch_l(va_list ap, char **fmt_substr)
{
}

int     dispatch_ll(va_list ap, char **fmt_substr)
{
}

	Is it legal to combine the different length modifiers together? 
	Will %hlhllc throw an error, for example?
	if no error thrown, the length modifiers are unlikely to be combined in any way,
	there are just rules for precendence that you will likewise implement.
	What does %lC do?
	Answer:

	-No, you cannot combine any of the length modifiers
	-No, you cannot do %lC or %lS
	-%lD is just a long
	-%lO is unsigned long
	-%lU is unsigned long


*/


//Messy dispatcher. Need to think about how to make this one nicer.

int	dispatcher(va_list ap, char **fmt_substr)
{
	char	*s;
	char	c;
	int	i;	
	
	//if (test_ls(**fmt_substr))
	//	(*(*fmt_substr + 1) == 'l') ? dispatch_ll(va_list ap, char **fmt_substr) : dispatch_l(va_list ap, char **fmt_substr);
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
	else if (**fmt_substr == 'x' || **fmt_substr == 'X' || **fmt_substr == 'p')
	{
		i = va_arg(ap, int);
		putnbr_hex(i, 0, (**fmt_substr == 'X'));
		(*fmt_substr)++;
	}
	return (5);
}

int	write_length(char *fmt_str)
{
	int out_len;

	out_len = 0;
	if( *(fmt_str + out_len) == '%')
		out_len++;
	while (*(fmt_str + out_len) && *(fmt_str + out_len) != '%')
		out_len++;
	return (out_len);
}

int	ft_printf(char *fmt_str, ...)
{
	va_list	ap;
	char *s;
	int bytes_printed;
	int len;

	bytes_printed = 0;
	va_start(ap, fmt_str);
	while (*fmt_str)
	{
		if (*fmt_str == '%' && *(++fmt_str) != '%')
			bytes_printed += dispatcher(ap, &fmt_str);
		else 
		{
			len = write_length(fmt_str);
			bytes_printed += write(1, fmt_str, len);
			fmt_str += len;
		}
	}
	va_end(ap);
	return (bytes_printed);
}

int	main()
{
	char *string = "this is a test run to make sure that it works";
	int	i = 5;
	char	c = 'A';

	ft_printf("Printf %% %is %ih %s and this is a number %i and a number also %d and this is a character: %c and this is an address %p\n", 5, 5, string, i, i, c, string);


	printf ("This is the address with native function: %p\n", string);

	return (0);
}
