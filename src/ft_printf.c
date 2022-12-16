#include "../includes/ft_printf.h"

#include <assert.h>

int	isConversion(char c)
{
	return (c == 'c' || c == 's' || \
		c == 'p' || c == 'd' || \
		c == 'i' || c == 'u' || \
		c == 'x' || c == 'X' || \
		c == 'f' || c == 'o');
}

int	ishash(t_flags *flags)
{
	return (!(flags->flags ^ 1));
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

long	abso_int(long i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

double	abso_double(double i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	init_values(long *i, int *o, int *d, int depth)
{
	*i = abso_int(*i);
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

int	get_base(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'f')
		return (10);
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
        if (c == 'o')
		return (8);
	return (0);
}

int	print_start(t_flags *flags, long i, int x)
{
	if (i < 0)
		return ((x) ? write(1, "-", 1) : 1);
	if (flags->flags & 8 && i >= 0)
		return ((x) ? write(1, " ", 1) : 1);
	if (flags->flags & 16 && flags->flags != 17 && i >= 0)
		return ((x) ? write(1, "+", 1) : 1);
	return (0);
}

void	reduce_field_width(t_flags *flags, int w, char fmt_c)
{
	if(flags->flags ^ 4 && flags->flags ^ 6 || fmt_c == 'f' && flags->new == 1)
		return ;
	if (fmt_c == 'f' && (flags->new == 3 || flags->new == 4))
		flags->field_width = 0;
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

int	process_field_width(int width, int x, long i, t_flags *flags)
{
	char 	*blanks;
	int	out;
	int 	neg;
	int	save;

	out = 0;
	neg = (width > 0) ? 0 : 1;
	save = width = abso_int(width);
	blanks = !(neg) ? ft_strnew2(width, ' ') : NULL;
	if (!(flags->flags & 4) && blanks)
		out += write(1, blanks, width);
	(blanks) ? free(blanks) : 1;
	if (x == 1)
		out += print_start(flags, i, 1);
	blanks = (neg) ? ft_strnew2(save, '0') : NULL;
	(blanks) ? out += write(1, blanks, save) : 1;
	if (flags->flags & 4 && flags->flags ^ 4)
		flags->flags = 4;
	free(blanks);
	return (out);
}

char	*get_string(va_list ap, char **fmt_substr)
{
	char	*s;
	char	c;

	if (**fmt_substr == 's')
		return (va_arg(ap, char *));
	c = va_arg(ap, int);
	if (!(s = (char *)malloc(sizeof(char) * 2)))
		exit(1);
	ft_bzero(s, 2);
	s[0] = c;
	return (s);
}

int	print_string(va_list ap, char **fmt_substr, t_flags *flags)
{
	char		*s;
	int		w_remain[2] = { 0, 0 };
	int		out_bytes;
	unsigned int	out_length;

	s = get_string(ap, fmt_substr);
	w_remain[1] = (**fmt_substr == 'c') ? 1 : 0; 
	out_bytes = (s[0] == '\0' && w_remain[1]) ? 1 : 0;
	(*fmt_substr)++;
	w_remain[0] = ft_strlen(s);
	if (flags->precision[1] == 0)
		flags->precision[0] = w_remain[0];
	if (flags->precision[0] < w_remain[0])
		out_length = flags->precision[0];
	else
		out_length = w_remain[0];
	w_remain[0] = flags->field_width - out_length;
	if (w_remain[0] > 0 && flags->flags ^ 4)
		out_bytes += process_field_width(w_remain[0], 0, 0, flags);
	else if (w_remain[0] > 0 && (flags->flags = 17))
	{
		out_bytes += ft_putstrnl(s, flags->precision[0], w_remain[1]);
		out_bytes += process_field_width(w_remain[0], 0, 0, flags);
		return (out_bytes);
	}
	return (out_bytes + ft_putstrnl(s, flags->precision[0], w_remain[1]));
}

int	numlen_base(long i, int base)
{
	int	len;
	
	if (i == 0)
		return (1);
	if (base == 0)
		return (0);
	len = 0;
	i = abso_int(i);
	while (i > 0)
	{
		++len;
		i /=base;
	}
	return (len);
}

int	test(t_flags *flags, int int_length, char cs, int neg)
{
	int bin;

	bin = (flags->precision[1] != 1);
	if (cs != 's' && cs != 'f')
		if (flags->precision[0] > int_length + neg * bin)
			return (-1 * (flags->precision[0] - int_length - neg*bin));
	bin = (flags->flags ^ 4) ? 1 : 0;
	if (cs == 'f')
		if (flags->field_width > int_length)
			 return (-1 * (flags->field_width - int_length - neg) * bin);
	return (0);
}

int	get_w(t_flags *flags, int int_length, char cs, int neg)
{
	int larger;

	if (cs == 'f' && flags->new == 1)
		return (0);
	if ((flags->new == 3) || (flags->new == 4))
		if (flags->flags == 17 || flags->flags == 4)
			return (flags->field_width);
	larger = (flags->precision[0] > int_length) ? flags->precision[0] : int_length;
	if (flags->flags ^ 4 && flags->flags ^ 6 && flags->flags ^ 2 && flags->field_width > larger)
		return (flags->field_width - larger - neg);
	return (test(flags, int_length, cs, neg));
}

int	exclusion_test(t_flags *flags, long i) 
{ 
	if (flags->precision[1] == 1 && flags->precision[0] == 0 && i == 0)
		return (0);
	return (1);
}

int	has_pad(t_flags *flags, long i)
{
	return ((flags->flags == 8 || flags->flags == 16) || i < 0);
}

int	padding(t_flags *flags, long i, int base, char cs)
{
	int 	int_length;
	int	out_bytes;
	int	w;
	int	x;

	out_bytes = x = 0;
	int_length = exclusion_test(flags, i) ? 
		numlen_base(i, base) + (cs == 'f') * (flags->precision[0] > 0) * (flags->precision[0] + 1) : 0;
	while ((w = get_w(flags, int_length, cs, has_pad(flags, i))) && ++x)
	{
		if (w < 0 && cs != 'f' && !(flags->precision[0] = 0))
			flags->precision[1] = 0;
		out_bytes += process_field_width(w, x, i, flags);
		if (flags->flags ^ 4)
			flags->field_width = flags->flags = 0;
		else
			reduce_field_width(flags, out_bytes + int_length, cs);
	}
	if (!x && ((out_bytes += print_start(flags, i, 1)) || 1))
		reduce_field_width(flags, int_length + out_bytes, cs);
	if (flags->flags & 4 && (cs != 'f' || flags->new > 0))
		flags->flags = 17;
	return (out_bytes);
}

void	free_t_flags(t_flags *flags)
{
	free(flags->precision);
	free(flags);
}

int sign_bit(double x)
{
	return (1.0/x != 1.0/fabs(x));
}

int	write_zeros(t_flags *flags, double f)
{

	char 	*start;
	char 	*str;
	char	*fused;
	int	i = flags->precision[0];

	if (!flags->new && f != 0)
		(f < 0) ? write(1, "-0", 2) : write(1, "0", 1);
	if (f != 0)
		return ((flags->new == 0) ? (f < 0) + (flags->new == 0) : 0);
	if (!!(2 & flags->flags))
		start = ft_strnew2(flags->field_width - i - 1, '0');
	else
		start = ft_strnew2(!flags->new + sign_bit(f), '0');
	if (sign_bit(f))
		start[0] = '-';
	str = ft_strnew2(i, '0');
	fused = ft_strjoin_free(start, str, '.');
	i = ft_strlen(fused);
	write(1, fused, i);
	free(str);
	free(fused);
	return (i);
}

char	*ft_itoa_double(double num, int length)
{
	int		i;
	int		temp;
	char		*out;

	i = 0;
	if (!(out = (char *)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	out[length] = '\0';
	if (num == 0 && length > 0)
		out[--length] = '0';
	while (i < length)
	{
		num *= 10;
		temp = num;
		out[i++] = (char)(temp + '0');
		num -= temp;
	}
	num *= 10;
	temp = num;
	while (out[--i] == '9' && temp >= 5)
		out[i] = '0';
	if (temp >= 5)
		out[i] += 1;
	return (out);
}

int	print_fraction(double f, t_flags *flags)
{
	char *fraction;

	fraction = ft_itoa_double(f, flags->precision[0]);
	write(1, fraction, flags->precision[0]);
	free(fraction);
	return (0);
}

long	proc_fi(double *f, int i, char fmt_c, t_flags *flags)
{
	long long	temp;

	if ((flags->new == 1 || flags->new == 2) && (flags->new = 2))
		return (0);
	if (fmt_c == 'f' && abso_double(*f) < 1)
	{
		flags->precision[1] += write_zeros(flags, *f);
		*f = abso_double(*f);
		if (*flags->precision == 0)
			return (!(flags->new = 2));
		if (*f != 0 && (flags->new = 2) && write(1, ".", 1))
			return(print_fraction(*f, flags));
		return (!(flags->new = 2));
	} else if (fmt_c == 'f') {
		temp = *f;
		*f -= temp;
		return (temp);
	}
	if (fmt_c != 'f')
		flags->new = 1;
	return (i);
}

int	vzed(t_flags *flags)
{
	if (flags->new == 2)
		return (0);
	if (flags->new == 1)
		flags->new = 2; 
	return(1);
}

int	define_numbers(va_list ap, long	int *i, double *f, char fmt_c)
{
	if (fmt_c != 'f')
		*i = (fmt_c != 'u') ? (long int)va_arg(ap, int) : va_arg(ap, unsigned int);
	else 
		*f = va_arg(ap, double);
	return (0);
}

int	clean_slate(t_flags *flags, double f)
{
	int out;

	if (flags->precision[1] > 1 && f == 0)
		out = flags->precision[1] - 1;
	else if (flags->precision[1] > 1)
		out = flags->precision[0] + flags->precision[1];
	else
		out = flags->precision[0] + 1;
	if (flags->flags ^ 4)
		flags->field_width = flags->flags = 0;
	else if (flags->precision[1] > 1)
		flags->field_width -= out;
	return (out);
}

int	standard_dispatch(va_list ap, char **fmt_substr, t_flags *flags)
{
	long		i;
	double		f;
	int		base;
	int		out_b;

	if (**fmt_substr == 's' || **fmt_substr == 'c')
		return (print_string(ap, fmt_substr, flags));
	out_b = define_numbers(ap, &i, &f, **fmt_substr);
	base = get_base(**fmt_substr);
	while ((i = proc_fi(&f, i, **fmt_substr, flags)) || vzed(flags))
	{
		if ((out_b += padding(flags, i, base, **fmt_substr)) || 1)
			if (exclusion_test(flags, i))
				out_b += putnbr_base(i, base, 0, flags);
		(flags->new == 0) ? (flags->new = 4) : 0;
	}
	if (**fmt_substr == 'f' && flags->precision[0] != 0)
		out_b += clean_slate(flags, f);
	if (flags->field_width && (flags->new = (3 + sign_bit(f))))
		if (!(flags->flags == 4) || (flags->flags = 17))
			if (!(*flags->precision = 0))
				out_b += padding(flags, 1, 0, **fmt_substr);
	(*fmt_substr)++;
	free_t_flags(flags);
	return (out_b);
}

int	get_bin(char *fmt_substr)
{
	while (!isConversion(*fmt_substr))
		fmt_substr++;
	return ((*fmt_substr == 'd' || *fmt_substr == 'i') ? 1 : 0 || (*fmt_substr == 'o' || 
		*fmt_substr == 'u' || *fmt_substr == 'x' || *fmt_substr == 'X') ? 5 : 0);
}

void	get_length_modifier(char **fmt_substr, t_flags *flags, va_list ap)
{
	int	bin;

	if (!(bin = get_bin(*fmt_substr)))
		return;
	--bin;
	while (!isConversion(**fmt_substr) && bin < 9)
		if ((**fmt_substr == 'h' || **fmt_substr == 'l') && (*fmt_substr)++)
			++bin;
	flags->len_mod = bin;
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
	if (out->field_width && (out->flags & 2) && (out->flags ^ 6) && !out->precision[1])
	{
		out->precision[1] = 2;
		out->precision[0] = out->field_width;
		out->field_width = 0;
	} 
}

unsigned int	get_width(va_list ap, char *str, t_flags *out)
{
	int out_w;

	out_w = 0;	
	while(is_flag(str))
		str++;
	if (*str == '.')
		return (0);
	out_w = (*str == '*') ? va_arg(ap, int) : ft_atoi(str);
	if (out_w < 0)
		return (!(out->flags |= 4) + (unsigned int)abso_int(out_w));
	return ((unsigned int)out_w);
}

int	check_f(char *str)
{
	if (*str == 'f')
		return (1);
	while (*str && *(str++) != 'f')
		if (isConversion(*str))
			break;
	return (*str == 'f');
}

unsigned int *new_uint_array(int i)
{
	unsigned int *new;

	if(!(new = (unsigned int *)malloc(sizeof(unsigned int) * i)))
		exit(1);
	while (i > 0)
		new[--i] = 0;
	return (new);
}

unsigned int	*get_precision(va_list ap, char *str)
{
	unsigned int *out;
	int	t1;
	int	t2;

	out = new_uint_array(2);
	while (*str && *str != '.' && (ft_isdigit(*str) || *str == '*'))
		str++;
	if (*str == '.' && (str += 1))
	{
		while (!ft_isdigit(*str) && *str != '*')
			str++;
		if (ft_isdigit(*str) && ((t1 = ft_atoi(str)) || 1))
			if (t1 >= 0)
				if((out[0] = (unsigned int)t1) || 1)
					out[1] = 1;
		if ((t2 = -1) && *str == '*')
			t2 = va_arg(ap, int);
		if (t2 >= 0)
			if((out[0] = (unsigned int)t2) || 1)
				out[1] = 1;
	}
	if (check_f(str))
		if ((out[0] = (!out[1]) ? 6 : out[0]) || 1)
			out[1] = 1;
	return (out);
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
	out->field_width = get_width(ap, fmt_substr, out);
	out->precision = get_precision(ap, fmt_substr);
	out->new = 0;
	out->sign = 0;
	if (out->precision[0] > out->field_width && !(check_f(fmt_substr)))
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
		if (**fmt_substr == '0' && out->flags ^ 4)
                	out->flags |= 2;
		if (**fmt_substr == '-' && out->flags ^ 4)
                	out->flags ^= 4;
		if (**fmt_substr == ' ' && (out->flags ^ 16))
                	out->flags |= 8;
		if (**fmt_substr == '+')
			out->flags ^= (out->flags & 8) ? 24 : 16;
		(*fmt_substr)++;
	}
	finalize_flags(**fmt_substr, out);
	while(ft_isdigit(**fmt_substr) || is_flag(*fmt_substr) || is_wp(**fmt_substr))
		(*fmt_substr)++;
	return (out);
}

int	dispatcher(va_list ap, char **fmt_substr)
{
	t_flags		*flags;

	flags = get_flags(ap, fmt_substr);
	get_length_modifier(fmt_substr, flags, ap);
	return (standard_dispatch(ap, fmt_substr, flags));
}

int	write_length(char *fmt_str, int x)
{
	int out_len;

	out_len = 0;
	if (*(fmt_str + out_len) == '%')
		++out_len;
	while (x && *(fmt_str + out_len) && *(fmt_str + out_len) != '%')
		++out_len;
	while (!x && *(fmt_str + out_len) && (*(fmt_str + out_len) != ' ' && 
		!isConversion(*(fmt_str + out_len))))
			++out_len;
	if (isConversion(*(fmt_str + out_len)))
		++out_len;
	return (out_len);
}

void	check_format_correct(char **fmt_substr)
{
	int h;
	int l;
	char *start;

	h = l = 0;
	start = *fmt_substr;
	++*fmt_substr;
	while (is_flag(*fmt_substr))
		++*fmt_substr;
	while (ft_isdigit(**fmt_substr) || is_wp(**fmt_substr))
		++*fmt_substr;
	while (**fmt_substr == 'h' && (h += 1) || **fmt_substr == 'l' && (l += 1))
		++*fmt_substr;
	if (isConversion(**fmt_substr) && !(h && l) && h < 3 && l < 3)
		return;
	write(1, "format string: \"", 16);
	h = write_length(start, 0);
	write(1, start, h);
	write(1, "\" erroneous format string-- length modifier incorrect. Exiting.\n", 64);
	exit(1);
}

void	error_check(char *fmt_str)
{
	while (*fmt_str)
	{
		if (*fmt_str == '%' && *(fmt_str + 1) != '%')
			check_format_correct(&fmt_str);
		else if (*fmt_str == '%')
			fmt_str += 2;
		else
			fmt_str++;
	}
}

int	ft_printf(char *fmt_str, ...)
{
	va_list	ap;
	int bytes_printed;
	int len;

	error_check(fmt_str);
	bytes_printed = 0;
	va_start(ap, fmt_str);
	while (*fmt_str)
	{
		if (*fmt_str == '%' && *(++fmt_str) != '%')
			bytes_printed += dispatcher(ap, &fmt_str);
		else if (*fmt_str)
		{
			len = write_length(fmt_str, 1);
			bytes_printed += write(1, fmt_str, len);
			fmt_str += len;
		}
	}
	va_end(ap);
	return (bytes_printed);
}
