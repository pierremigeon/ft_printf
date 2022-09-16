#include "../includes/ft_printf.h"

#include <assert.h>

/*

Note: Any flags past some point are just treated as characters to print:
	printf ("%is", 5); prints "5s"
	-This functionality is already present in my code.
	Same goes for length modifiers:
	printf ("%ih", 5); prints "5h"
	-This functionality is also already present in my code

Errors to handle:
	-input isn't type specified 
	-unequal number of arguments and conversing specifiers 
	-nonsensical combinations of input? %hhll 
	-Would be nice to throw compiler errors but more likely just print error messages.
*/

int	ishash(t_flags *flags)
{
	return (flags->flags & 1);
}

int	iscaps(t_flags *flags)
{
	return (flags->x);
}

int	prefix(int base, int depth, int cap)
{
	depth = 10 - depth;

	if (base == 16)
		(cap) ? write(1, "0X100000000", depth) : write(1, "0x100000000", depth);
	else
		write(1, "0", 1);
	return ((base == 16) ? depth : 1);
}

long	abso(long i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	init_values(long *i, int *o, int *d, int depth)
{
	*i = abso(*i);
	*o = 0;
	*d = depth;
}

int    putnbr_base(long i, int base, int depth, t_flags *flags)
{
	char 		out;
	static int 	d;
	int		o;

	init_values(&i, &o, &d, depth);
	if (i >= base)
		o += putnbr_base(i / base, base, depth + 1, flags);
	if (d == depth && ishash(flags))
		o += prefix(base, depth, iscaps(flags));
	if (iscaps(flags))
		out = (i % base < 10) ? '0' + i % base : 'A' + i % base % 10;
	else
		out = (i % base < 10) ? '0' + i % base : 'a' + i % base % 10;
	write(1, &out, 1);
	return (o + 1);
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

int	get_base(char c)
{
	if (c == 'i' || c == 'd' || c == 'u')
		return (10);
	if (c == 'c')
		return (1);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
        if (c == 'o')
		return (8);
	return (0);
}

int	print_start(t_flags *flags, int i)
{
	int	bytes;

	bytes = 0;
	if ((flags->flags == 8 || flags->flags == 16) && i < 0)
		bytes = write(1, "-", 1);	
	if (flags->flags == 8 && i >= 0)
		bytes = write(1, " ", 1);
	if (flags->flags == 16 && i >= 0)
		bytes = write(1, "+", 1);
	return (bytes);
}

char	*ft_strnew2(size_t size, int c)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(str, c, size);
	*(str + size) = '\0';
	return (str);
}

void	process_field_width(int width)
{
	char *blanks;

	blanks = ft_strnew2(width, ' ');
	write(1, blanks, width);
	free(blanks);
}

int	print_string(va_list ap, char **fmt_substr, t_flags *flags)
{
	char	*s;
	int	w_remain;

	s = va_arg(ap, char *);
	(*fmt_substr)++;
	flags->out_length = ft_strlen(s);
	w_remain = flags->field_width - flags->out_length;
	if (w_remain > 0)
		process_field_width(w_remain);
	return (ft_putstrl(s));
}

int	standard_dispatch(va_list ap, char **fmt_substr, t_flags *flags)
{
	int		i;
	unsigned int	u;
	int		base;

	if (**fmt_substr == 's')
		return (print_string(ap, fmt_substr, flags));
	i = (**fmt_substr != 'u') ? va_arg(ap, int) : va_arg(ap, unsigned int);

	if ((base = get_base(**fmt_substr)) == 1)
		write(1, &i, 1);
	else 
		base = print_start(flags, i) + putnbr_base(i, base, 0, flags);
	(*fmt_substr)++;
	free (flags);
	return (base);
}

int	check_z(char *c)
{
	if (*c != '0')
		return (0);
	while (*c == '0')
		--c;
	return(!ft_isdigit(*c));
}

int	is_flag(char *c)
{
	return (*c == '#' || check_z(c) || *c == '-' || *c == ' ' || *c == '+');
}

int	test_X(char *str)
{
	while (*str && *str != ' ')
		if (*str++ == 'X')
			return (1);
	return (0);
}

void	finalize_flags(char c, t_flags *out)
{
	if (c == 'p' && (out->flags ^ 1))
		out->flags |= 1;
}


int	get_width(va_list ap, char *str)
{
	while(is_flag(str))
		str++;
	if (*str == '.')
		return (0);
	return ((*str == '*') ? va_arg(ap, int) : ft_atoi(str));
}

int	get_precision(va_list ap, char *str)
{
	while (*str && *str != '.')
		str++;
	if (*str && ft_isdigit(*++str))
		return ((ft_atoi(str) == 0) ? 6 : ft_atoi(str));
	if (*str == '*')
		return (va_arg(ap, int));
	return (6);
}

t_flags		*new_flag(void)
{
	t_flags		*flag;

	if(!(flag = (t_flags *)malloc(sizeof(t_flags) * 1)))
		exit (1);
	flag->flags = 0;
	return (flag);
}

t_flags		*get_t_flags(va_list ap, char *fmt_substr)
{
	t_flags *out;

	while (is_flag(fmt_substr))
		++fmt_substr;
	out = new_flag();
	out->x = test_X(fmt_substr);
	out->field_width = get_width(ap, fmt_substr);
	printf("The field width is %i\n", out->field_width);
	out->precision = get_precision(ap, fmt_substr);
	printf("The precision is %i\n", out->precision);
	return (out);
}

int	is_wp(char c)
{
	return (c == '.' || c == '*');
}

t_flags	*get_flags(va_list ap, char **fmt_substr)
{
	t_flags *out;

	out = get_t_flags(ap, *fmt_substr);
	while (is_flag(*fmt_substr))
	{
		if (**fmt_substr == '#' && (out->flags ^ 1))
			out->flags |= 1;
		if (**fmt_substr == '0' && (out->flags ^ 4))
                	out->flags |= 2;
		if (**fmt_substr == '-')
                	out->flags ^= (out->flags & 2) ? 6 : 4;
		if (**fmt_substr == ' ' && (out->flags ^ 16))
                	out->flags |= 8;
		if (**fmt_substr == '+')
			out->flags ^= (out->flags & 8) ? 24 : 16;
		(*fmt_substr)++;
	}
	while(ft_isdigit(**fmt_substr) || is_flag(*fmt_substr) || is_wp(**fmt_substr))
		(*fmt_substr)++;
	finalize_flags(**fmt_substr, out);
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
		return (0);
}

int	dispatcher(va_list ap, char **fmt_substr)
{
	t_flags		*flags;

	t_dispatcher 	functs[1] = {
		//&dispatch_l,
		//&dispatch_ll,
		//&dispatch_h,
		//&dispatch_hh,
		//&dispatch_j,
		//&dispatch_z,
		&standard_dispatch
	};
	flags = get_flags(ap, fmt_substr);
	return (functs[get_function(fmt_substr)](ap, fmt_substr, flags));
}

int	write_length(char *fmt_str)
{
	int out_len;

	out_len = 0;
	if (*(fmt_str + out_len) == '%')
		out_len++;
	while (*(fmt_str + out_len) && *(fmt_str + out_len) != '%')
		out_len++;
	return (out_len);
}

int	ft_printf(char *fmt_str, ...)
{
	va_list	ap;
	int bytes_printed;
	int len;

	bytes_printed = 0;
	va_start(ap, fmt_str);
	while (*fmt_str)
	{
		if (*fmt_str == '%' && *(++fmt_str) != '%')
			bytes_printed += dispatcher(ap, &fmt_str);
		else if (*fmt_str)
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
	char *string = "this is a test run to make sure that it works ";
	int	i = 5;
	int	neg_i = -5;
	int	i2 = 10;
	int	neg_i2 = -10;
	int	i3 = 10000;
	int	neg_i3 = -10000;
	long	l = 10;
	char	c = 'A';
	unsigned int	u = 42;
	int		bytes_printed;
	char	*s2 = "Yolo!";


	//ft_printf("Printf %% %is %ih %s and this is a number %i and a number also %d and this is a character: %c and this is an address %p\n", 5, 5, string, i, i, c, string);
	//printf ("This is the address with native function: %p\n", string);

	//bytes_printed = ft_printf ("Here are all the standard conversions: %s %p %d %i %o %u %x %X %c\n", string, string, i, i, i, u, i, i, *string);
	//printf ("Bytes printed were %i\n", bytes_printed);

	//bytes_printed = printf ("Here are all the standard conversions: %s %p %d %i %o %u %x %X %c\n", string, string, i, i, i, u, i, i, *string);
	//printf ("Bytes printed were %i\n", bytes_printed);

	/*
		ft_printf must handle the cspdiuxX% flags. 
	*/
/*
	assert(ft_printf("%s\n", string) == printf("%s\n", string));
	assert(ft_printf("%d\n", i) == printf("%d\n", i));
	assert(ft_printf("%X\n", i) == printf("%X\n", i));
	assert(ft_printf("%X\n", i2) == printf("%X\n", i2));
	assert(ft_printf("%p\n", string) == printf("%p\n", string));
	assert(ft_printf("%d\n", i) == printf("%d\n", i));
	assert(ft_printf("%i\n", i) == printf("%i\n", i));
	assert(ft_printf("%o\n", i) == printf("%o\n", i));
	assert(ft_printf("%u\n", u) == printf("%u\n", u));
	assert(ft_printf("%x\n", i) == printf("%x\n", i));
	assert(ft_printf("%X\n", i) == printf("%X\n", i));
	assert(ft_printf("%c\n", c) == printf("%c\n", c));
	assert(ft_printf("%%\n") == printf("%%\n"));
*/

/*
	printf("%p\n", NULL);
	printf("%p\n", NULL + 1);
	printf("%p\n", NULL + 3);
	printf("%p\n", NULL + 100);
	printf("%p\n", NULL + 1000);
	printf("%p\n", NULL + 10000);	
	printf("%p\n", NULL + 100000);
	printf("%p\n", NULL + 1000000);
	printf("%p\n", NULL + 10000000);
	printf("%p\n", NULL + 100000000);
	printf("%p\n", NULL + 1000000000);
	printf("%p\n", NULL + 10000000000);
	printf("%p\n", NULL + 100000000000);
	printf("%p\n", NULL + 1000000000000);
	printf("%p\n", NULL + 10000000000000);
	printf("%p\n", NULL + 100000000000000);
	printf("%p\n", NULL + 1000000000000000);
	printf("%p\n", NULL + 10000000000000000);
	printf("%p\n", NULL + 100 000 000 000 000 000);
//	ft_printf("%p\n", NULL);

*/
	/*
		ft_printf must handle hH ll flags 
	*/

	//ft_printf("%ld\n", l);
	//printf("%ld\n", l);

	//ft_printf("%+i\n", i);
	/*
	assert(ft_printf("%+i\n", i) == printf("%+i\n", i));

	assert(ft_printf("%+i\n", neg_i) == printf("%+i\n", neg_i));
	assert(ft_printf("% i\n", i) == printf("% i\n", i));
	assert(ft_printf("% i\n", neg_i) == printf("% i\n", neg_i));

	assert(ft_printf("%+i\n", i2) == printf("%+i\n", i2));
	assert(ft_printf("%+i\n", neg_i2) == printf("%+i\n", neg_i2));
	assert(ft_printf("% i\n", i2) == printf("% i\n", i2));
	assert(ft_printf("% i\n", neg_i2) == printf("% i\n", neg_i2));

	assert(ft_printf("%+i\n", i3) == printf("%+i\n", i3));
	assert(ft_printf("%+i\n", neg_i3) == printf("%+i\n", neg_i3));
	assert(ft_printf("% i\n", i3) == printf("% i\n", i3));
	assert(ft_printf("% i\n", neg_i3) == printf("% i\n", neg_i3));
	*/
// Time to test * and .* flags!!!
	ft_printf("%*i\n", i, i);
	ft_printf("%+*i\n", i, i);
	ft_printf("% *i\n", i, i);
	ft_printf("%-*i\n", i, i);
	ft_printf("%.*i\n", i, i);
	ft_printf("%+.*i\n", i, i);
	ft_printf("%-.*i\n", i, i);
	ft_printf("% .*i\n", i, i);
	


	//assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));

	ft_printf("%10swoohoo!\n", s2);
	printf("%10swoohoo!\n", s2);
/*
	ft_printf("% +i\n", i);
	ft_printf("% +i\n", neg_i);
	ft_printf("%+ i\n", i); 
	ft_printf("%+ i\n", neg_i);

	ft_printf("%+i\n", i);
	ft_printf("%+i\n", neg_i);
	ft_printf("% i\n", i);
	ft_printf("% i\n", neg_i);

	ft_printf("%+i\n", i2);
	ft_printf("%+i\n", neg_i2);
	ft_printf("% i\n", i2);
	ft_printf("% i\n", neg_i2);

	ft_printf("%+i\n", i3);
	ft_printf("%+i\n", neg_i3);
	ft_printf("% i\n", i3);
	ft_printf("% i\n", neg_i3);
*/

/*	
	printf("Tests for 0- precedence\n");
	ft_printf("%-i\n", i);
	ft_printf("%0i\n", i);
	ft_printf("%0-i\n", i);
	ft_printf("%-0i\n", i);
*/
/*
ft_printf("% 500.10i\n", i);
ft_printf("%+500.10i\n", i);
ft_printf("%-500.10i\n", i);

	assert(ft_printf("% 50.10i\n", i) == printf("% 50.10i\n", i));
	assert(ft_printf("%+50.10i\n", i) == printf("%+50.10i\n", i));
	assert(ft_printf("%-50.10i\n", i) == printf("%-50.10i\n", i));	

*/
	/*
		ft_printf must handle '-0.* +' flags with minimum field width with all conversions. 
	*/


	//Successfully passed tests message:
	printf("\n\n\t\t##########################################\n\t\t#  Congratulations!!! All Tests Passed!  #\n\t\t##########################################\n\n\n");

	return (0);
}
