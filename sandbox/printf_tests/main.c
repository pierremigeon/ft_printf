#include <stdio.h>

int	main()
{
	int	a;

	a = -500;

	int	i = 55;
	char	c = 'a';
	char	*s = "yolo";

	/*
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
	*/

	// with a non-float, if a precision is given, then the zero is ignored. 

	printf("%015.10i%c\n", i/6, c);
	printf("%015i\n", i/6);
	printf("%015.10f\n", (float)i/6);
	printf("%01.1i\n", i);	
	printf("%10.5spoo\n", s);

	return (0);
}
