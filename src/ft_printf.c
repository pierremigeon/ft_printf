#include "../includes/ft_printf.h"

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


// Need to switch this to largest possible int type. 
void    putnbr_base(int i, int base, int depth, int ul_case)
{
	char 		out;
	static int 	d;

	d = depth;
	if (i >= base)
		putnbr_base(i / base, base, depth + 1, ul_case);
	if (d == depth)
		(depth == 5) ? write(1, hex_prefix(ul_case, 1), 5) : write(1, hex_prefix(ul_case, 0), 4);
	if (ul_case == 0)
		out = (i % base < 10) ? '0' + i % base : 'a' + i % base % 10;
	else
		out = (i % base < 10) ? '0' + i % base : 'A' + i % base % 10;
	write(1, &out, 1);
}

int	test_ls(char fmt_substr)
{
	if (fmt_substr == 'l')
		return (2);
	return ( fmt_substr == 'S' || fmt_substr == 'C' || \
		 fmt_substr == 'D' || fmt_substr == 'O' ||	\
		 fmt_substr == 'U'
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

int	standard_dispatch(va_list ap, char **fmt_substr, t_flags *flags)
{
	char		*s;
	int		i;
	unsigned int	u;

	if (**fmt_substr == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr(s);
	}
	else
		i = (**fmt_substr != 'u') ? va_arg(ap, int) : va_arg(ap, unsigned int);
	if (**fmt_substr == 'i' || **fmt_substr == 'd')
		ft_putnbr(i);
	else if (**fmt_substr == 'c')
		write(1, &i, 1);
	else if (**fmt_substr == 'x' || **fmt_substr == 'X' || **fmt_substr == 'p')
		putnbr_base(i, 16, 0, (**fmt_substr == 'X'));
	else if (**fmt_substr == 'o')
		putnbr_base(i, 8, 0, 0);
	else if (**fmt_substr == 'u')
		putnbr_base(i, 10, 0, 0);
	(*fmt_substr)++;
	return (5);
}

int	is_flag(char c)
{
	return (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+');
}

t_flags	*new_flags(void)
{
	t_flags	*out;

	if(!(out = (t_flags *)malloc(sizeof(t_flags))))
		exit(1);
	return (out);
}

t_flags	*get_flags(char **fmt_substr)
{
	t_flags *out;

	out = new_flags();
	out->flags = 0;
	out->field_width = ft_atoi(*fmt_substr);
	while(ft_isdigit(**fmt_substr))
		(*fmt_substr)++;
	while (is_flag(**fmt_substr))
	{
		if (**fmt_substr == '#')
			out->flags |= 1;
		if (**fmt_substr == '0')
                	out->flags |= 2;
		if (**fmt_substr == '-')
                	out->flags |= 4;
		if (**fmt_substr == ' ')
                	out->flags |= 10;
		if (**fmt_substr == '+')
			out->flags |= 20;
		(*fmt_substr)++;
	}
	if ((out->flags & 2) && (out->flags & 4))
		out->flags ^= 2;
	if ((out->flags & 20) && (out->flags & 10))
		out->flags ^= 10;
	return (out);
}

int	get_function(char **fmt_substr)
{
	int	i;

	if ((i = test_ls(**fmt_substr)))
	{
		if (*(*fmt_substr + 1) == 'l' && i == 2)
			 return (1);
		else
			return (0);
	}
	if (**fmt_substr == 'h')
	{
		if (*(*fmt_substr + 1) == 'h')
			return (3);
		else
			return (2);
	}
	if (**fmt_substr == 'j')
		return (4);
	if (**fmt_substr == 'z')
		return (5);
	else
		return (6);
}

int	dispatcher(va_list ap, char **fmt_substr)
{
	t_flags *flags;

	t_dispatcher 	functs[1] = {
		//&dispatch_l,
		//&dispatch_ll,
		//&dispatch_h,
		//&dispatch_hh,
		//&dispatch_j,
		//&dispatch_z,
		&standard_dispatch
	};
	flags = get_flags(fmt_substr);
	return (functs[get_function(fmt_substr)](ap, fmt_substr, flags));
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
	unsigned int	u = 42;

	ft_printf("Printf %% %is %ih %s and this is a number %i and a number also %d and this is a character: %c and this is an address %p\n", 5, 5, string, i, i, c, string);
	printf ("This is the address with native function: %p\n", string);
	ft_printf ("Here are all the standard conversions: %s %S %p %d %D %i %o %O %u %U %x %X %c %C\n", string, string, string, i, i, i, i, i, u, u, i, i, *string, *string);
	return (0);
}
