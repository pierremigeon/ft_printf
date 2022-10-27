

#include <stdio.h>

typedef		struct		p
{
	unsigned int	a;
}	lol;



int	main()
{
	lol	*test;
	unsigned int	b;
	unsigned int	c;

	b = c;
	c = 1;
	test->a = b;
	//printf("%i\n", test->++a);

	printf("%-15.10iP\n", 5);	
	printf("%15.0fP\n", 0.5);	
	printf("%.0f\n", 0.0);	

	//printf("%0*d\n", -100, -100);
	printf("%0*.6d\n", -10, -100);
//-> ignored	printf("%-0100d\n", 100);
	//printf("%0-100d\n", -100);
	printf("%0*.5d\n", -10, -100);
	printf("%.5d\n", -100);


	int	tess = 6;

	if (tess ^ 4)
		printf("tess ^ 4 printed for %i\n", tess);
	if (tess ^ 2)
		printf("tess ^ 2 printed for %i\n", tess);
	if (tess ^ 6)
		printf("tess ^ 6 printed for %i\n", tess);
	if (tess ^ 2 && tess ^ 4)
		printf("tess ^ 2 && tess ^ 4 printed for %i\n", tess);
	if (tess ^ 4 && tess ^ 6)
		printf("tess ^ 4 && tess ^ 6 printed for %i\n", tess);
	tess =  4;
	if (tess ^ 4 && tess ^ 6)
		printf("tess ^ 4 && tess ^ 6 printed for %i\n", tess);

	int a = -100;
	printf("%0.*d\n", a, a);
	printf("%010.*d\n", a, a);
	printf("%5.*d\n", -6, 5);
	a = 10;
	printf("%0.*d\n", a, a);
	float g = 3.14;
	//printf("%.-5f\n", g);
	printf("%.*f\n", -20, g);

	printf("%.*i\n", 2, -5);
	printf("%0*i\n", 2, -5);
	printf("%0*i\n", -2, -5);

	printf("%0*i\n", 5, -5);
	printf("%.*i\n", 5, -5);
	printf("%0*.*i\n", 5, 5, -5);
	printf("%05.7i\n", -5);
	printf("%07.5i\n", -5);
	printf("%07i\n", -5);
	printf("%.2i\n", -5);
	//printf("%05i\n", -5);
	//printf("%.5i\n", -5);
	
	printf("%0*.*d\n", 100, 100, -100);
	printf("%0.*d\n", 100, -100);
	printf("%0*d\n", 100, -100);
	

	double ff = -3.14;
	printf("%010f\n", ff);
	printf("%0*f\n", -20, ff);
	printf("%+*.*f\n", -10, 5, 3.14);

	char *str = "P$l33t";
	//printf("%05s\n", str);

	

	return (0);
}
