#include "../includes/ft_printf.h"

#include <assert.h>

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
	char	*s;
	int	w_remain;
	int	out_bytes;

	s = get_string(ap, fmt_substr);
	out_bytes = 0;
	(*fmt_substr)++;
	w_remain =  ft_strlen(s);
	if (flags->precision[1] == 0)
		flags->precision[0] = w_remain;
	if (flags->precision[0] < w_remain)
		flags->out_length = flags->precision[0];
	else
		flags->out_length = w_remain;
	w_remain = flags->field_width - flags->out_length;
	if (w_remain > 0 && flags->flags ^ 4)
		out_bytes += process_field_width(w_remain, 0, 0, flags);
	else if (w_remain > 0)
	{
		out_bytes += ft_putstrnl(s, flags->precision[0]);
		out_bytes += process_field_width(w_remain, 0, 0, flags);
		return (out_bytes);
	}
	return (out_bytes + ft_putstrnl(s, flags->precision[0]));
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
	if ((cs == 'i' || cs == 'd') && flags->precision[0])
		if (flags->precision[0] > int_length + neg)
			return (-1 * (flags->precision[0] - int_length + neg));
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
	larger = (flags->precision[0] + neg > int_length) ? flags->precision[0] + neg : int_length;
	if (flags->flags ^ 4 && flags->field_width > larger)
		return (flags->field_width - larger);
	return (test(flags, int_length, cs, neg));
}

int	exclusion_test(t_flags *flags, int i) 
{ 
	if (flags->precision[1] == 1 && flags->precision[0] == 0 && i == 0)
		return (0);
	return (1);
}

int	padding(t_flags *flags, int i, int base, char cs)
{
	int 	int_length;
	int	out_bytes;
	int	w;
	int	x;

	out_bytes = x = 0;
	int_length = exclusion_test(flags, i) ? numlen_base(i, base) : 0;
	int_length += print_start(flags, i, 0);
	while ((w = get_w(flags, int_length, cs, i < 0)) && ++x)
	{
		if (w < 0 && !(flags->precision[0] = 0))
			flags->precision[1] = 0;
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

void	free_t_flags(t_flags *flags)
{
	free(flags->precision);
	free(flags);
}

void	write_zeros(int i, int seen)
{
	char *start;
	char *str;
	char *fused;

	start = ft_strnew2(seen, '0');
	str = ft_strnew2(i, '0');
	fused = ft_strjoin_free(start, str, '.');

	write(1, fused, ++i + seen);
	free(str);
	free(fused);
}

int	x_to_power_of_y(int x, int y)
{
	int out;

	out = 1;
	for (int i = 0; i < y; i++)
		out *= x;
	return (out);
}

int	proc_fi(double *f, int i, char fmt_c, t_flags *flags)
{
	int temp;

	if ((flags->new == 1 || flags->new == 2) && (flags->new = 2))
		return (0);
	if (fmt_c == 'f' && *f < 1)
	{
		*f *= x_to_power_of_y(10, (long int)*flags->precision);
		temp = *f;
		if (*flags->precision == 0)
			return (!(flags->new = 2));
		(*f == 0) ? write_zeros(*flags->precision, flags->new == 0) : write(1, ".", 1);
		flags->new = 1;
		return (temp);
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

void	define_numbers(va_list ap, int *i, double *f, char fmt_c)
{
	if (fmt_c == 'i' || fmt_c == 'd' || fmt_c == 'u' || fmt_c == 'X')
		*i = (fmt_c != 'u') ? va_arg(ap, int) : va_arg(ap, unsigned int);
	else if (fmt_c == 'f')
		*f = va_arg(ap, double);
}

int	standard_dispatch(va_list ap, char **fmt_substr, t_flags *flags)
{
	int		i;
	unsigned int	u;
	double		f;
	int		base;
	int		out_b;

	if (**fmt_substr == 's' || **fmt_substr == 'c')
		return (print_string(ap, fmt_substr, flags));
	define_numbers(ap, &i, &f, **fmt_substr);
	base = get_base(**fmt_substr);
	while ((i = proc_fi(&f, i, **fmt_substr, flags)) || vzed(flags))
	{
		if ((out_b = padding(flags, i, base, **fmt_substr)) || 1)
			if (exclusion_test(flags, i))
				out_b += putnbr_base(i, base, 0, flags);
	}
	if (flags->field_width)
		out_b += padding(flags, 1, 0, **fmt_substr);
	(*fmt_substr)++;
	free_t_flags(flags);
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
	if (out->precision[1] && (out->flags & 2))
		out->flags ^= 2;
	if (out->field_width && (out->flags & 2))
	{
		out->precision[0] = 1;
		out->precision[0] = out->field_width;
		out->field_width = 0;
	}
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
	int	temp;

	temp = -1;
	out = new_uint_array(2);
	while (*str && *str != '.' && (ft_isdigit(*str) || *str == '*'))
		str++;
	if (*str == '.' && (str += 1))
	{
		temp = ft_atoi(str);
		if((out[0] = temp) || 1)
			out[1] = 1;
	}
	while (*str && ft_isdigit(*str))
		str++;
	if (*str == '*')
		if((out[0] = va_arg(ap, int)) || 1)
			out[1] = 1;
	if (check_f(str))
		if ((out[0] = (temp == -1) ? 6 : out[0]) || 1)
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
	out->field_width = get_width(ap, fmt_substr);
	out->precision = get_precision(ap, fmt_substr);
	out->new = 0;
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
