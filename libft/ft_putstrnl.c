#include "libft.h"

int	ft_putstrnl(char *str, size_t n, int free_s)
{
	size_t	len;

	len = ft_strlen(str);
	if (n < len)
		write(1, str, n);
	else
		write(1, str, len);
	if (free_s)
		free(str);
	return ((len < n) ? len : n);
}
