
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void	test(char *tye, ...)
{
	va_list ap;
	int i;

	va_start(ap, tye);
	i = va_arg(ap, int);
	printf("%i\n", i);
	va_end(ap);
}

int	main()
{
	char *tye;

	if (!(tye = (char *)malloc(sizeof(char) * 4)))
		exit(1);
	tye[0] = 'i';
	tye[1] = 'n';
	tye[2] = 't';
	tye[3] = '\0';

	test(tye, 42);

	return (0);
}
