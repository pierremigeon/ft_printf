# ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>
#include <math.h>

typedef struct 			s_flags
{
	unsigned int		flags:5;
	unsigned int		field_width;
	unsigned int		*precision;
	unsigned int		x;
	unsigned char		len_mod;
	unsigned char		new;
	unsigned char		sign;
}				t_flags;

typedef	struct			s_tuple
{
	char			c;
	t_flags			*flags;
}				t_tuple;

typedef unsigned long long	(*funky)(va_list, t_flags *flags);

int	ft_printf(char *fmt_str, ...);
char	*ft_strnew2(size_t size, int c);


#endif
