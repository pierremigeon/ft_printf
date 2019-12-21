#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

/*
void	dispatcher()
{
}
*/

int	ft_printf(char *fmt_str, ...)
{
	va_list	ap;
	char *s;
	int bytes_printed;

	bytes_printed = 0;
	va_start(ap, fmt_str);
	while (*fmt_str)
	{
		if (*fmt_str == '%')
		{
			if (*(++fmt_str) == 's')
			{
				s = va_arg(ap, char *);
				ft_putstr(s);
				fmt_str++;
			}
		}
		else
			bytes_printed += write(1, fmt_str++, 1);
	}
	va_end(ap);

	return (bytes_printed);
}

int	main()
{
	char *string = "this is a test run to make sure that it works";
	ft_printf("Printf %s\n", string);
	return (0);
}
