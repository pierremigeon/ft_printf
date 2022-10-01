#include "../includes/ft_printf.h"

#include <assert.h>

/*

Any flags past the type converion are just treated as characters to print:
	printf ("%is", 5); prints "5s"
	printf ("%ih", 5); prints "5h"

Errors to handle:
	-input isn't type specified 
	-unequal number of arguments and conversing specifiers 
	-nonsensical combinations of input? %hhll 
	-Would be nice to throw compiler errors but more likely just print error messages.
*/

int	isConversion(char c)
{
	return (c == 'c' || c == 's' || \
		c == 'p' || c == 'd' || \
		c == 'i' || c == 'u' || \
		c == 'x' || c == 'X' || \
		c == 'f' );
}

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

	%hlhllc throw an error
	What does %lC do?
	-cannot combine any of the length modifiers
	-cannot do %lC or %lS
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

int	print_start(t_flags *flags, int i, int x)
{
	if (i < 0)
		return ((x) ? write(1, "-", 1) : 1);
	if (flags->flags == 8 && i >= 0)
		return ((x) ? write(1, " ", 1) : 1);
	if (flags->flags == 16 && i >= 0)
		return ((x) ? write(1, "+", 1) : 1);
	return (0);
}

void	reduce_field_width(t_flags *flags, int w)
{
	if(flags->flags ^ 4)
		return ;
	if (flags->field_width > w)
		flags->field_width -= w;
	else if (flags->field_width <= w)
		flags->field_width = 0;
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

int	process_field_width(int width, int x, int i, t_flags *flags)
{
	char *blanks;
	int	save;

	if (width > 0)
	{
		blanks = ft_strnew2(width, ' ');
		write(1, blanks, width);
		if (x == 1)
			width += print_start(flags, i, 1);
	}
	else
	{
		width = abso(width);
		save = width;
		if (x == 1)
			width += print_start(flags, i, 1);
		blanks = ft_strnew2(save, '0');
		write(1, blanks, save);
	}
	free(blanks);
	return (width);
}

int	print_string(va_list ap, char **fmt_substr, t_flags *flags)
{
	char	*s;
	int	w_remain;
	int	out_bytes;

	s = va_arg(ap, char *);
	out_bytes = 0;
	(*fmt_substr)++;
	flags->out_length = ft_strlen(s);
	w_remain = flags->field_width - flags->out_length;
	if (w_remain > 0)
		out_bytes += process_field_width(w_remain, 0, 0, flags);
	return (out_bytes + ft_putstrl(s));
}

int	numlen_base(int i, int base)
{
	int	len;
	
	if (i == 0)
		return (1);
	if (base == 0)
		return (0);
	len = 0;
	i = abso(i);
	while (i > 0)
	{
		++len;
		i /=base;
	}
	return (len);
}

int	test(t_flags *flags, int int_length, char cs, int neg)
{
	if ((cs == 'i' || cs == 'd') && flags->precision)
		if (flags->precision > int_length + neg)
			return (-1 * (flags->precision - int_length + neg));
	return (0);
}

int	test_flag(int value)
{
	return (value == 8 || value == 16);
}

int	get_w(t_flags *flags, int int_length, char cs, int neg)
{
	int larger;

	if (!neg && test_flag(flags->flags))
		neg = 1;
	larger = (flags->precision + neg > int_length) ? flags->precision + neg : int_length;
	if (flags->flags ^ 4 && flags->field_width > larger)
		return (flags->field_width - larger);
	return (test(flags, int_length, cs, neg));
}

int	padding(t_flags *flags, int i, int base, char cs)
{
	int 	int_length;
	int	out_bytes;
	int	w;
	int	x;

	out_bytes = x = 0;
	int_length = numlen_base(i, base);
	int_length += print_start(flags, i, 0);
	while ((w = get_w(flags, int_length, cs, i < 0)) && ++x)
	{
		if (w < 0)
			flags->precision = 0;
		out_bytes += process_field_width(w, x, i, flags);
		if (flags->flags ^ 4)
			flags->field_width = 0;
		else
			reduce_field_width(flags, abso(w) + int_length);
	}
	if (!x && ((out_bytes += print_start(flags, i, 1)) || 1))
		reduce_field_width(flags, int_length);
	if (flags->flags & 4)
		flags->flags = 0;
	return (out_bytes);
}

int	standard_dispatch(va_list ap, char **fmt_substr, t_flags *flags)
{
	int		i;
	unsigned int	u;
	int		base;
	int		out_b;

	if (**fmt_substr == 's')
		return (print_string(ap, fmt_substr, flags));
	i = (**fmt_substr != 'u') ? va_arg(ap, int) : va_arg(ap, unsigned int);
	if ((base = get_base(**fmt_substr)) == 1)
		out_b = write(1, &i, 1);
	else if ((out_b = padding(flags, i, base, **fmt_substr)) || 1)
		out_b += /* print_start(flags, i, 1) + */ putnbr_base(i, base, 0, flags);
	if (flags->field_width)
		out_b += padding(flags, 1, 0, **fmt_substr);
	(*fmt_substr)++;
	free (flags);
	return (out_b);
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

int	check_f(char *str)
{
	while (*str && *(str++) != 'f')
		if (isConversion(*str))
			break;
	return (*str == 'f');
}

int	get_precision(va_list ap, char *str)
{
	while (*str && *str != '.')
		str++;
	if (*str && ft_isdigit(*++str))
		if(!(check_f(str)))
			return (ft_atoi(str));
	if (*str == '*')
		return (va_arg(ap, int));
	if (check_f(str) && ft_isdigit(*str))
		return ((ft_atoi(str) == 0) ? 6 : ft_atoi(str));
	return (0);
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
	out->precision = get_precision(ap, fmt_substr);
	if (out->precision > out->field_width && !(check_f(fmt_substr)))
		out->field_width = 0;
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

	ft_printf("%+.*i\n", i, i);

	printf("%+50.10i\n", i);
	printf("%i\n", printf("%+50.10i\n", i));	
	ft_printf("%+50.10i\n", i);
	printf("%i\n", ft_printf("%+50.10i\n", i));

	printf("%-i\n", neg_i);
	printf("%i\n",printf("%-i\n", neg_i));
	ft_printf("%-i\n", neg_i);
	printf("%i\n", ft_printf("%-i\n", neg_i));

/*
	ft_printf must handle the cspdiuxX% flags.
	Basic cspdiuxX% tests here.
*/

	assert(ft_printf("%s\n", string) == printf("%s\n", string));
	assert(ft_printf("%d\n", i) == printf("%d\n", i));
	assert(ft_printf("%X\n", i) == printf("%X\n", i));
	assert(ft_printf("%X\n", i2) == printf("%X\n", i2));
	assert(ft_printf("%p\n", string) == printf("%p\n", string));
	assert(ft_printf("%d\n", i) == printf("%d\n", i));
	assert(ft_printf("%i\n", i) == printf("%i\n", i));
	assert(ft_printf("%o\n", i) == printf("%o\n", i));
	assert(ft_printf("%u\n", u) == printf("%u\n", u));
	//assert(ft_printf("%U\n", u) == printf("%U\n", u));
	assert(ft_printf("%x\n", i) == printf("%x\n", i));
	assert(ft_printf("%X\n", i) == printf("%X\n", i));
	assert(ft_printf("%c\n", c) == printf("%c\n", c));
	assert(ft_printf("%%\n") == printf("%%\n"));

/*
	Tests for char %c here
	develop the %lc tests also, which is the same thing as %C
*/

for (int x = 0; x < 256; x++) {
	assert(ft_printf("%c\n", x) == printf("%c\n", x));
}



/*
	ft_printf must handle '-0.* +' flags with minimum field width with all conversions.
*/


	// A couple random width and precision specifier tests
	assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));
	assert(ft_printf("% 50.10i\n", i) == printf("% 50.10i\n", i));
	assert(ft_printf("%+50.10i\n", i) == printf("%+50.10i\n", i));
	assert(ft_printf("%-50.10i\n", i) == printf("%-50.10i\n", i));

	// Plus (+), Minus(-) and Space( ) tests with pos/neg ints of varying sizes
	assert(ft_printf("%+i\n", i) == printf("%+i\n", i));
	assert(ft_printf("%+i\n", neg_i) == printf("%+i\n", neg_i));
	assert(ft_printf("%-i\n", i) == printf("%-i\n", i));
	assert(ft_printf("%-i\n", neg_i) == printf("%-i\n", neg_i));
	assert(ft_printf("% i\n", i) == printf("% i\n", i));
	assert(ft_printf("% i\n", neg_i) == printf("% i\n", neg_i));

	assert(ft_printf("%+i\n", i2) == printf("%+i\n", i2));
	assert(ft_printf("%+i\n", neg_i2) == printf("%+i\n", neg_i2));
	assert(ft_printf("%-i\n", i2) == printf("%-i\n", i2));
	assert(ft_printf("%-i\n", neg_i2) == printf("%-i\n", neg_i2));
	assert(ft_printf("% i\n", i2) == printf("% i\n", i2));
	assert(ft_printf("% i\n", neg_i2) == printf("% i\n", neg_i2));

	assert(ft_printf("%+i\n", i3) == printf("%+i\n", i3));
	assert(ft_printf("%+i\n", neg_i3) == printf("%+i\n", neg_i3));
	assert(ft_printf("%-i\n", i3) == printf("%-i\n", i3));
	assert(ft_printf("%-i\n", neg_i3) == printf("%-i\n", neg_i3));
	assert(ft_printf("% i\n", i3) == printf("% i\n", i3));
	assert(ft_printf("% i\n", neg_i3) == printf("% i\n", neg_i3));

// Plus (+), Minus(-) and Space( ) tests with pos/neg longs of varying sizes

	// Test (-) flag with varying field widths
	printf("*~~~*\n");
	printf("%-5i%s\n", i, "words");	
	ft_printf("%-5i%s\n", i, "words");
	printf("%-5.5i%s\n", i, "words");
	ft_printf("%-5.5i%s\n", i, "words");
	printf("%-8.5i%s\n", i, "words");
	ft_printf("%-8.5i%s\n", i, "words");
	printf("%8.5i%s\n", i, "words");
	ft_printf("%8.5i%s\n", i, "words");
	printf("*~~~*\n");

//Test Plus (+), Minus(-) and Space( ) flags with strings

// Time to test * and .* flags!!!
// * and .* with +/-/ / flags
	assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));
	assert(ft_printf("%+*i\n", i, i) == printf("%+*i\n", i, i));
	assert(ft_printf("% *i\n", i, i) == printf("% *i\n", i, i));
	assert(ft_printf("%-*i\n", i, i) == printf("%-*i\n", i, i));
	assert(ft_printf("%.*i\n", i, i) == printf("%.*i\n", i, i));
	assert(ft_printf("%+.*i\n", i, i) == printf("%+.*i\n", i, i));
	assert(ft_printf("%-.*i\n", i, i) == printf("%-.*i\n", i, i));
	assert(ft_printf("% .*i\n", i, i) == printf("% .*i\n", i, i));
	assert(ft_printf("%.*i\n", i, i) == printf("%.*i\n", i, i));

//// * and .* with +/-/ / flags using a long
	//assert(ft_printf("%*li\n", i, l) == printf("%*li\n", i, l));
	//assert(ft_printf("%+*i\n", i, l) == printf("%+*i\n", i, l));
	//assert(ft_printf("% *i\n", i, l) == printf("% *i\n", i, l));
	//assert(ft_printf("%-*i\n", i, l) == printf("%-*i\n", i, l));
	//assert(ft_printf("%.*i\n", i, l) == printf("%.*i\n", i, l));
	//assert(ft_printf("%+.*i\n", i, l) == printf("%+.*i\n", i, l));
	//assert(ft_printf("%-.*i\n", i, l) == printf("%-.*i\n", i, l));
	//assert(ft_printf("% .*i\n", i, l) == printf("% .*i\n", i, l));
	//assert(ft_printf("%.*i\n", i, l) == printf("%.*i\n", i, l));



// Tests of * and .* with 0 flags
	assert(ft_printf("%0*i\n", i, i) == printf("%0*i\n", i, i));


/* All the %i tests with %d */



	// A couple random width and precision specifier tests
	assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));
	assert(ft_printf("% 50.10i\n", i) == printf("% 50.10i\n", i));
	assert(ft_printf("%+50.10i\n", i) == printf("%+50.10i\n", i));
	assert(ft_printf("%-50.10i\n", i) == printf("%-50.10i\n", i));

	// Plus (+), Minus(-) and Space( ) tests with pos/neg ints of varying sizes
	assert(ft_printf("%+d\n", i) == printf("%+d\n", i));
	assert(ft_printf("%+d\n", neg_i) == printf("%+d\n", neg_i));
	assert(ft_printf("%-d\n", i) == printf("%-d\n", i));
	assert(ft_printf("%-d\n", neg_i) == printf("%-d\n", neg_i));
	assert(ft_printf("% i\n", i) == printf("% d\n", i));
	assert(ft_printf("% d\n", neg_i) == printf("% d\n", neg_i));

	assert(ft_printf("%+d\n", i2) == printf("%+d\n", i2));
	assert(ft_printf("%+d\n", neg_i2) == printf("%+d\n", neg_i2));
	assert(ft_printf("%-d\n", i2) == printf("%-d\n", i2));
	assert(ft_printf("%-d\n", neg_i2) == printf("%-d\n", neg_i2));
	assert(ft_printf("% i\n", i2) == printf("% d\n", i2));
	assert(ft_printf("% d\n", neg_i2) == printf("% d\n", neg_i2));

	assert(ft_printf("%+d\n", i3) == printf("%+d\n", i3));
	assert(ft_printf("%+d\n", neg_i3) == printf("%+d\n", neg_i3));
	assert(ft_printf("%-d\n", i3) == printf("%-d\n", i3));
	assert(ft_printf("%-d\n", neg_i3) == printf("%-d\n", neg_i3));
	assert(ft_printf("% d\n", i3) == printf("% d\n", i3));
	assert(ft_printf("% d\n", neg_i3) == printf("% d\n", neg_i3));

// Plus (+), Minus(-) and Space( ) tests with pos/neg longs of varying sizes



	// Test (-) flag with varying field widths
	printf("*~~~*\n");
	printf("%-5i%s\n", i, "words");	
	ft_printf("%-5i%s\n", i, "words");
	printf("%-5.5i%s\n", i, "words");
	ft_printf("%-5.5i%s\n", i, "words");
	printf("%-8.5i%s\n", i, "words");
	ft_printf("%-8.5i%s\n", i, "words");
	printf("%8.5i%s\n", i, "words");
	ft_printf("%8.5i%s\n", i, "words");
	printf("*~~~*\n");

//Test Plus (+), Minus(-) and Space( ) flags with strings

// Time to test * and .* flags!!!
// * and .* with +/-/ / flags
	assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));
	assert(ft_printf("%+*i\n", i, i) == printf("%+*i\n", i, i));
	assert(ft_printf("% *i\n", i, i) == printf("% *i\n", i, i));
	assert(ft_printf("%-*i\n", i, i) == printf("%-*i\n", i, i));
	assert(ft_printf("%.*i\n", i, i) == printf("%.*i\n", i, i));
	assert(ft_printf("%+.*i\n", i, i) == printf("%+.*i\n", i, i));
	assert(ft_printf("%-.*i\n", i, i) == printf("%-.*i\n", i, i));
	assert(ft_printf("% .*i\n", i, i) == printf("% .*i\n", i, i));
	assert(ft_printf("%.*i\n", i, i) == printf("%.*i\n", i, i));

//// * and .* with +/-/ / flags using a long
	//assert(ft_printf("%*li\n", i, l) == printf("%*li\n", i, l));
	//assert(ft_printf("%+*i\n", i, l) == printf("%+*i\n", i, l));
	//assert(ft_printf("% *i\n", i, l) == printf("% *i\n", i, l));
	//assert(ft_printf("%-*i\n", i, l) == printf("%-*i\n", i, l));
	//assert(ft_printf("%.*i\n", i, l) == printf("%.*i\n", i, l));
	//assert(ft_printf("%+.*i\n", i, l) == printf("%+.*i\n", i, l));
	//assert(ft_printf("%-.*i\n", i, l) == printf("%-.*i\n", i, l));
	//assert(ft_printf("% .*i\n", i, l) == printf("% .*i\n", i, l));
	//assert(ft_printf("%.*i\n", i, l) == printf("%.*i\n", i, l));



// Tests of * and .* with 0 flags
	assert(ft_printf("%0*i\n", i, i) == printf("%0*i\n", i, i));











/*
	printf("Tests for 0- precedence\n");
	assert(ft_printf("%-i\n", i) == printf("%-i\n", i));
	assert(ft_printf("%0i\n", i) == printf("%0i\n", i));
	ft_printf("%0-i\n", i) == printf("%0-i\n", i));
	ft_printf("%-0i\n", i);
*/

	//Successfully passed tests message:
	printf("\n\n\t\t##########################################\n\t\t#  Congratulations!!! All Tests Passed!  #\n\t\t##########################################\n\n\n");

	return (0);
}
