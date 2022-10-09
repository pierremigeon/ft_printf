#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <stdio.h>

typedef struct 	s_flags
{
	unsigned int	flags:5;
	unsigned int	field_width;
	unsigned int	*precision;
	unsigned int	out_length;
	unsigned int	x;
}		t_flags;

typedef int     (*t_dispatcher)(va_list ap, char **fmt_substr, t_flags *flags);

int	ft_printf(char *fmt_str, ...);
char	*ft_strnew2(size_t size, int c);


#endif
