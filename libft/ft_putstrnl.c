#include "libft.h"

int	ft_putstrnl(char *str, size_t n)
{
	size_t	len;

	len = ft_strlen(str);
	if (n < len)
		write(1, str, n);
	else
		write(1, str, len);
	return ((len < n) ? len : n);
}
