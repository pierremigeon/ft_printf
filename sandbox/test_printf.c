




#include <stdio.h>



void	test_pf()
{
	//int8_t	c = 33;
	//wchar_t *s;
	//long	c = 5;
	//char *s = "hello";
	int i = 5;

	/* Test flags */
	printf ("% i\n", i);
	i = -5;
	printf ("% i\n", i);
	/* result: with space, it's a space unless it's negative, then it's just a '-' */
	
	/* Can you put a number before the flags? */
	printf ("%20hi\n", (short)5);
	//The second one prints 520
	printf ("%hi20\n", (short)5);


	//throws compiler error:
	//printf ("%hhji", (char)5);
	//%lC or %lS or %lD %lO %lU
	//printf ("%lc", c);
	//printf ("%lS", c);
	//printf("%lD", c);
	//printf("%lO",c);
	//printf("%lU",c);

	//printf ("%is", 5);

	//printf ("%ih", 5);
	//The field width specifier needs to come first
	//printf ("%20hi", (short)5);
	//printf ("%hi20", (short)5);	
	// won't compile printf ("%h20i", (short)5);

}




int	main()
{
	test_pf();
	return (0);
}
