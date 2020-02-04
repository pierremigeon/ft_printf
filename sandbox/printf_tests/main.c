#include <stdio.h>

int	main()
{
	int	a;

	a = -500;
	printf ("%x\n", a);
        printf ("%X\n", a);
	printf ("%#x\n", a);
	printf ("%#X\n", a);
	printf ("%o\n", a);
        printf ("%O\n", a);
	printf ("%#o\n", a);
	printf ("%#O\n", a);
	printf ("%p\n", &a);
	printf ("%+++i\n", a);
	return (0);
}
