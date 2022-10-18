#include "../includes/ft_printf.h"

#include <assert.h>

int	main()
{
	char *string = "this is a test run to make sure that it works ";
	int	i = 5;
	int	neg_i = -5;
	int	i2 = 10;
	int	neg_i2 = -10;
	int	i3 = 10000;
	int	neg_i3 = -10000;
	long	l = 10;
	char	c = 'A';
	unsigned int	u = 42;
	int		bytes_printed;
	char	*s2 = "YoLo";
	float	f = 3.14;
	float	zero = 0;

	setbuf(stdout, NULL);
	
	ft_printf("%0*d\n", 0, 0);

	ft_printf("%f\n", f);
	ft_printf("%f\n", zero);
	ft_printf("%5.8f\n", zero);
	ft_printf("%5.8f\n", f);

	//ft_printf("% 50.10i\n", i);

	//ft_printf("%0.*d\n", 0, 0);

	//ft_printf("%.0s\n", s2);
	//ft_printf("%+.*i\n", i, i);

	//printf("%+50.10i\n", i);
	//printf("%i\n", printf("%+50.10i\n", i));	
	//ft_printf("%+50.10i\n", i);
	//printf("%i\n", ft_printf("%+50.10i\n", i));

	//printf("%-i\n", neg_i);
	//printf("%i\n",printf("%-i\n", neg_i));
	//ft_printf("%-i\n", neg_i);
	//printf("%i\n", ft_printf("%-i\n", neg_i));

/*
	ft_printf must handle the cspdioOuUxX% flags.
	Basic cspdioOuxX% tests here.
*/

	assert(ft_printf("%s\n", string) == printf("%s\n", string));
	assert(ft_printf("%d\n", i) == printf("%d\n", i));
	assert(ft_printf("%X\n", i) == printf("%X\n", i));
	assert(ft_printf("%X\n", i2) == printf("%X\n", i2));
	assert(ft_printf("%p\n", string) == printf("%p\n", string));
	assert(ft_printf("%d\n", i) == printf("%d\n", i));
	assert(ft_printf("%i\n", i) == printf("%i\n", i));
	assert(ft_printf("%o\n", i) == printf("%o\n", i));
	//assert(ft_printf("%O\n", i) == printf("%O\n", i));
	assert(ft_printf("%u\n", u) == printf("%u\n", u));
	//assert(ft_printf("%U\n", u) == printf("%U\n", u));
	assert(ft_printf("%x\n", i) == printf("%x\n", i));
	assert(ft_printf("%X\n", i) == printf("%X\n", i));
	assert(ft_printf("%c\n", c) == printf("%c\n", c));
	assert(ft_printf("%%\n") == printf("%%\n"));

/*
	Tests for char %c and string %s here
	develop the %lc tests also, which is the same thing as %C
*/

for (int x = 32; x < 127; x++) {
	char *test;

	assert(ft_printf("%c\n", x) == printf("%c\n", x));
	for (int y = 5; y < 31; y *= 6) {
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~x is %i and y is %i\n", x, y);
		test = ft_strnew2(y, x);
		assert(ft_printf("%s\n", test) == printf("%s\n", test));
		assert(ft_printf("%.0s\n", test) == printf("%.0s\n", test));
		assert(ft_printf("%.1s\n", test) == printf("%.1s\n", test));
		assert(ft_printf("%.2s\n", test) == printf("%.2s\n", test));
		assert(ft_printf("%.3s\n", test) == printf("%.3s\n", test));
		assert(ft_printf("%.4s\n", test) == printf("%.4s\n", test));
		assert(ft_printf("%.5s\n", test) == printf("%.5s\n", test));
		assert(ft_printf("%1s\n", test) == printf("%1s\n", test));
		assert(ft_printf("%2s\n", test) == printf("%2s\n", test));
		assert(ft_printf("%3s\n", test) == printf("%3s\n", test));
		assert(ft_printf("%4s\n", test) == printf("%4s\n", test));
		assert(ft_printf("%5s\n", test) == printf("%5s\n", test));
		assert(ft_printf("%8s\n", test) == printf("%8s\n", test));
		assert(ft_printf("%15s\n", test) == printf("%15s\n", test));
		free(test);
	}
}

	// Some more precision and field width tests with (-) flag
	assert(ft_printf("%5.2sP\n", string) == printf("%5.2sP\n", string));
	assert(ft_printf("%-5.2sP\n", string) == printf("%-5.2sP\n", string));
	assert(ft_printf("%-5.6sP\n", string) == printf("%-5.6sP\n", string));
	assert(ft_printf("%-2.2sP\n", string) == printf("%-2.2sP\n", string));
	

	//Some tests for precision and field width using .* and *:
	assert(ft_printf("%*.2sP\n", i, string) == printf("%*.2sP\n", i, string));
	assert(ft_printf("%-*.2sP\n", i, string) == printf("%-*.2sP\n", i, string));
	assert(ft_printf("%-*.6sP\n", i, string) == printf("%-*.6sP\n", i, string));
	assert(ft_printf("%-*.2sP\n", 2, string) == printf("%-*.2sP\n", 2, string));
	
	assert(ft_printf("%.*sP\n", i, string) == printf("%.*sP\n", i, string));
	assert(ft_printf("%-.*sP\n", i, string) == printf("%-.*sP\n", i, string));
	assert(ft_printf("%-.*sP\n", 2, string) == printf("%-.*sP\n", 2, string));
	assert(ft_printf("%-.*sP\n", 50, string) == printf("%-.*sP\n", 50, string));



/*
	ft_printf must handle '-0.* +' flags with minimum field width with all conversions.
*/


	// A couple random width and precision specifier tests
	assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));
	assert(ft_printf("% 50.10i\n", i) == printf("% 50.10i\n", i));
	assert(ft_printf("%+50.10i\n", i) == printf("%+50.10i\n", i));
	assert(ft_printf("%-50.10i\n", i) == printf("%-50.10i\n", i));

	// Plus (+), Minus(-) and Space( ) tests with pos/neg ints of varying sizes
	assert(ft_printf("%+i\n", i) == printf("%+i\n", i));
	assert(ft_printf("%+i\n", neg_i) == printf("%+i\n", neg_i));
	assert(ft_printf("%-i\n", i) == printf("%-i\n", i));
	assert(ft_printf("%-i\n", neg_i) == printf("%-i\n", neg_i));
	assert(ft_printf("% i\n", i) == printf("% i\n", i));
	assert(ft_printf("% i\n", neg_i) == printf("% i\n", neg_i));

	assert(ft_printf("%+i\n", i2) == printf("%+i\n", i2));
	assert(ft_printf("%+i\n", neg_i2) == printf("%+i\n", neg_i2));
	assert(ft_printf("%-i\n", i2) == printf("%-i\n", i2));
	assert(ft_printf("%-i\n", neg_i2) == printf("%-i\n", neg_i2));
	assert(ft_printf("% i\n", i2) == printf("% i\n", i2));
	assert(ft_printf("% i\n", neg_i2) == printf("% i\n", neg_i2));

	assert(ft_printf("%+i\n", i3) == printf("%+i\n", i3));
	assert(ft_printf("%+i\n", neg_i3) == printf("%+i\n", neg_i3));
	assert(ft_printf("%-i\n", i3) == printf("%-i\n", i3));
	assert(ft_printf("%-i\n", neg_i3) == printf("%-i\n", neg_i3));
	assert(ft_printf("% i\n", i3) == printf("% i\n", i3));
	assert(ft_printf("% i\n", neg_i3) == printf("% i\n", neg_i3));

// Plus (+), Minus(-) and Space( ) tests with pos/neg longs of varying sizes

	// Test (-) flag with varying field widths
	//printf("*~~~*\n");
	//printf("%-5i%s\n", i, "words");	
	//ft_printf("%-5i%s\n", i, "words");
	//printf("%-5.5i%s\n", i, "words");
	//ft_printf("%-5.5i%s\n", i, "words");
	//printf("%-8.5i%s\n", i, "words");
	//ft_printf("%-8.5i%s\n", i, "words");
	//printf("%8.5i%s\n", i, "words");
	//ft_printf("%8.5i%s\n", i, "words");
	//printf("*~~~*\n");

//Test Plus (+), Minus(-) and Space( ) flags with strings

// Time to test * and .* flags!!!
// * and .* with +/-/ / flags
	assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));
	assert(ft_printf("%+*i\n", i, i) == printf("%+*i\n", i, i));
	assert(ft_printf("% *i\n", i, i) == printf("% *i\n", i, i));
	assert(ft_printf("%-*i\n", i, i) == printf("%-*i\n", i, i));
	assert(ft_printf("%.*i\n", i, i) == printf("%.*i\n", i, i));
	assert(ft_printf("%+.*i\n", i, i) == printf("%+.*i\n", i, i));
	assert(ft_printf("%-.*i\n", i, i) == printf("%-.*i\n", i, i));
	assert(ft_printf("% .*i\n", i, i) == printf("% .*i\n", i, i));
	assert(ft_printf("%.*i\n", i, i) == printf("%.*i\n", i, i));

//// * and .* with +/-/ / flags using a long
	//assert(ft_printf("%*li\n", i, l) == printf("%*li\n", i, l));
	//assert(ft_printf("%+*i\n", i, l) == printf("%+*i\n", i, l));
	//assert(ft_printf("% *i\n", i, l) == printf("% *i\n", i, l));
	//assert(ft_printf("%-*i\n", i, l) == printf("%-*i\n", i, l));
	//assert(ft_printf("%.*i\n", i, l) == printf("%.*i\n", i, l));
	//assert(ft_printf("%+.*i\n", i, l) == printf("%+.*i\n", i, l));
	//assert(ft_printf("%-.*i\n", i, l) == printf("%-.*i\n", i, l));
	//assert(ft_printf("% .*i\n", i, l) == printf("% .*i\n", i, l));
	//assert(ft_printf("%.*i\n", i, l) == printf("%.*i\n", i, l));



// Tests of * and .* with 0 flags
	assert(ft_printf("%0*i\n", i, i) == printf("%0*i\n", i, i));


/* All the %i tests with %d */



	// A couple random width and precision specifier tests
	assert(ft_printf("%*d\n", i, i) == printf("%*d\n", i, i));
	assert(ft_printf("% 50.10d\n", i) == printf("% 50.10d\n", i));
	assert(ft_printf("%+50.10d\n", i) == printf("%+50.10d\n", i));
	assert(ft_printf("%-50.10d\n", i) == printf("%-50.10d\n", i));

	// Plus (+), Minus(-) and Space( ) tests with pos/neg ints of varying sizes
	assert(ft_printf("%+d\n", i) == printf("%+d\n", i));
	assert(ft_printf("%+d\n", neg_i) == printf("%+d\n", neg_i));
	assert(ft_printf("%-d\n", i) == printf("%-d\n", i));
	assert(ft_printf("%-d\n", neg_i) == printf("%-d\n", neg_i));
	assert(ft_printf("% d\n", i) == printf("% d\n", i));
	assert(ft_printf("% d\n", neg_i) == printf("% d\n", neg_i));

	assert(ft_printf("%+d\n", i2) == printf("%+d\n", i2));
	assert(ft_printf("%+d\n", neg_i2) == printf("%+d\n", neg_i2));
	assert(ft_printf("%-d\n", i2) == printf("%-d\n", i2));
	assert(ft_printf("%-d\n", neg_i2) == printf("%-d\n", neg_i2));
	assert(ft_printf("% d\n", i2) == printf("% d\n", i2));
	assert(ft_printf("% d\n", neg_i2) == printf("% d\n", neg_i2));

	assert(ft_printf("%+d\n", i3) == printf("%+d\n", i3));
	assert(ft_printf("%+d\n", neg_i3) == printf("%+d\n", neg_i3));
	assert(ft_printf("%-d\n", i3) == printf("%-d\n", i3));
	assert(ft_printf("%-d\n", neg_i3) == printf("%-d\n", neg_i3));
	assert(ft_printf("% d\n", i3) == printf("% d\n", i3));
	assert(ft_printf("% d\n", neg_i3) == printf("% d\n", neg_i3));

// Plus (+), Minus(-) and Space( ) tests with pos/neg longs of varying sizes



	// Test (-) flag with varying field widths
	//printf("*~~~*\n");
	//printf("%-5d%s\n", i, "words");	
	//ft_printf("%-5d%s\n", i, "words");
	//printf("%-5.5d%s\n", i, "words");
	//ft_printf("%-5.5d%s\n", i, "words");
	//printf("%-8.5d%s\n", i, "words");
	//ft_printf("%-8.5d%s\n", i, "words");
	//printf("%8.5d%s\n", i, "words");
	//ft_printf("%8.5d%s\n", i, "words");
	//printf("*~~~*\n");

//Test Plus (+), Minus(-) and Space( ) flags with strings

// Time to test * and .* flags!!!
// * and .* with +/-/ / flags
	assert(ft_printf("%*d\n", i, i) == printf("%*d\n", i, i));
	assert(ft_printf("%+*d\n", i, i) == printf("%+*d\n", i, i));
	assert(ft_printf("% *d\n", i, i) == printf("% *d\n", i, i));
	assert(ft_printf("%-*d\n", i, i) == printf("%-*d\n", i, i));
	assert(ft_printf("%.*d\n", i, i) == printf("%.*d\n", i, i));
	assert(ft_printf("%+.*d\n", i, i) == printf("%+.*d\n", i, i));
	assert(ft_printf("%-.*d\n", i, i) == printf("%-.*d\n", i, i));
	assert(ft_printf("% .*d\n", i, i) == printf("% .*d\n", i, i));
	assert(ft_printf("%.*d\n", i, i) == printf("%.*d\n", i, i));

//// * and .* with +/-/ / flags using a long
	//assert(ft_printf("%*li\n", i, l) == printf("%*li\n", i, l));
	//assert(ft_printf("%+*i\n", i, l) == printf("%+*i\n", i, l));
	//assert(ft_printf("% *i\n", i, l) == printf("% *i\n", i, l));
	//assert(ft_printf("%-*i\n", i, l) == printf("%-*i\n", i, l));
	//assert(ft_printf("%.*i\n", i, l) == printf("%.*i\n", i, l));
	//assert(ft_printf("%+.*i\n", i, l) == printf("%+.*i\n", i, l));
	//assert(ft_printf("%-.*i\n", i, l) == printf("%-.*i\n", i, l));
	//assert(ft_printf("% .*i\n", i, l) == printf("% .*i\n", i, l));
	//assert(ft_printf("%.*i\n", i, l) == printf("%.*i\n", i, l));



// Tests of * and .* with 0 flags
	for (int a = 0; a < 100; a++) {
		assert(ft_printf("%0*d\n", a, a) == printf("%0*d\n", a, a));
		assert(ft_printf("%0.*d\n", a, a) == printf("%0.*d\n", a, a));
		assert(ft_printf("%05d\n", a) == printf("%05d\n", a));
		assert(ft_printf("%0.5d\n", a) == printf("%0.5d\n", a));
		assert(ft_printf("%015.15d\n", a) == printf("%015.15d\n", a));
	}





/*
	the original printf throws an error if you try to run these two flags together. For this, I plan to implement a checker to verify the validity of the string, and exit with error message if invalid string is used. This will immitate the native function. 
	printf("Tests for 0- precedence\n");
	assert(ft_printf("%-i\n", i) == printf("%-i\n", i));
	assert(ft_printf("%0i\n", i) == printf("%0i\n", i));
	ft_printf("%0-i\n", i) == printf("%0-i\n", i));
	ft_printf("%-0i\n", i);
*/


/*
	float tests!!!! Project is developing nicely.
*/


// Tests of * and .* with 0 flags
//	for (int a = 0; a < 100; a++) {
//		assert(ft_printf("%0*f\n", a, f) == printf("%0*f\n", a, f));
//		assert(ft_printf("%0.*f\n", a, f) == printf("%0.*f\n", a, f));
//		assert(ft_printf("%05f\n", f) == printf("%05f\n", f));
//		assert(ft_printf("%0.5f\n", f) == printf("%0.5f\n", f));
//		assert(ft_printf("%015.15f\n", f) == printf("%015.15f\n", f));
//	}














	//Successfully passed tests message:
	printf("\n\n\t\t##########################################\n\t\t#  Congratulations!!! All Tests Passed!  #\n\t\t##########################################\n\n\n");

	return (0);
}
