




#include <stdio.h>



void	test_pf()
{
	//int8_t	c = 33;
	//wchar_t *s;
	//long	c = 5;
	//char *s = "hello";

	//throws compiler error:
	//printf ("%hhji", (char)5);
	//%lC or %lS or %lD %lO %lU
	//printf ("%lc", c);
	//printf ("%lS", c);
	//printf("%lD", c);
	//printf("%lO",c);
	//printf("%lU",c);

	//printf ("%is", 5);

	printf ("%ih", 5);

}



int	main()
{
	test_pf();
	return (0);
}
