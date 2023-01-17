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
	{
		if (str[0] == '\0')
			write(1, "\0", 1);
		free(str);
	}	
	return ((len < n) ? len : n);
}
