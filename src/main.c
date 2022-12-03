#include "../includes/ft_printf.h"

#include <assert.h>

void	swap(int *a, int *b) 
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

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
	double	f = 3.14;
	double	f3 = -3.14;
	double	zero = 0;
	float	f2 = -f;

	setbuf(stdout, NULL);


/*
	ft_printf must handle the cspdioOuUxX% flags.
	Basic cspdioOuxX% tests here.
*/

	printf("assert(ft_printf(\"%%s\\n\", %s) == printf(\"%%s\\n\", %s));\n", string, string);
	assert(ft_printf("%s\n", string) == printf("%s\n", string));
	printf("assert(ft_printf(\"%%d\\n\", %i) == printf(\"%%d\\n\", %i));\n", i, i);
	assert(ft_printf("%d\n", i) == printf("%d\n", i));
	printf("assert(ft_printf(\"%%X\\n\", %i) == printf(\"%%X\\n\", %i));\n", i, i);
	assert(ft_printf("%X\n", i) == printf("%X\n", i));
	printf("assert(ft_printf(\"%%X\\n\", %i) == printf(\"%%X\\n\", %i));\n", i2, i2);
	assert(ft_printf("%X\n", i2) == printf("%X\n", i2));
	printf("assert(ft_printf(\"%%p\\n\", %s) == printf(\"%%p\\n\", %s));\n",  string, string);
	assert(ft_printf("%p\n", string) == printf("%p\n", string));
	printf("assert(ft_printf(\"%%d\\n\", %i) == printf(\"%%d\\n\", %i));\n", i, i);
	assert(ft_printf("%d\n", i) == printf("%d\n", i));
	printf("assert(ft_printf(\"%%i\\n\", %i) == printf(\"%%i\\n\", %i));\n", i, i);
	assert(ft_printf("%i\n", i) == printf("%i\n", i));
	printf("assert(ft_printf(\"%%o\\n\", %i) == printf(\"%%o\\n\", %i));\n", i, i);
	assert(ft_printf("%o\n", i) == printf("%o\n", i));
	//printf("assert(ft_printf(\"%%O\\n\", %i) == printf(\"%%O\\n\", %i));\n", i, i);
	//assert(ft_printf("%O\n", i) == printf("%O\n", i));
	printf("assert(ft_printf(\"%%u\\n\", %u) == printf(\"%%u\\n\", %u));\n", u, u);
	assert(ft_printf("%u\n", u) == printf("%u\n", u));
	//printf("assert(ft_printf(\"%%U\\n\", %u) == printf(\"%%U\\n\", %u));\n", u, u);
	//assert(ft_printf("%U\n", u) == printf("%U\n", u));
	printf("assert(ft_printf(\"%%x\\n\", %i) == printf(\"%%x\\n\", %i));\n", i, i);
	assert(ft_printf("%x\n", i) == printf("%x\n", i));
	printf("assert(ft_printf(\"%%X\\n\", %i) == printf(\"%%X\\n\", %i));\n", i, i);
	assert(ft_printf("%X\n", i) == printf("%X\n", i));
	printf("assert(ft_printf(\"%%c\\n\", %c) == printf(\"%%c\\n\",  %c));\n", c, c);
	assert(ft_printf("%c\n", c) == printf("%c\n", c));
	printf("assert(ft_printf(\"%%%%\\n\") == printf(\"%%%%\\n\"));\n");
	assert(ft_printf("%%\n") == printf("%%\n"));



/*
	escape character tests here
*/
	char z = '\0';

	assert(ft_printf("\\ \n") == printf("\\ \n"));
	assert(ft_printf("\\\\ \n") == printf("\\\\ \n"));
	assert(ft_printf("\\\\\\ \n") == printf("\\\\\\ \n"));
	assert(ft_printf("\\\\\\\\ \n") == printf("\\\\\\\\ \n"));

	assert(ft_printf("\n") == printf("\n"));
	assert(ft_printf("\n\n") == printf("\n\n"));
	assert(ft_printf("\n\n\n") == printf("\n\n\n"));
	assert(ft_printf("\n \n") == printf("\n \n"));

	assert(ft_printf("\t\n") == printf("\t\n"));
	assert(ft_printf("\t\t\n") == printf("\t\t\n"));
	assert(ft_printf("\t\t\t\n") == printf("\t\t\t\n"));
	assert(ft_printf("\t\t\t\t\n") == printf("\t\t\t\t\n"));
	assert(ft_printf("\t \t\n") == printf("\t \t\n"));
	assert(ft_printf("\t \t \n") == printf("\t \t \n"));

	assert(ft_printf("\\p\n") == printf("\\p\n"));

	assert(ft_printf("\a") == printf("\a"));
	assert(ft_printf("\a\a") == printf("\a\a"));
	assert(ft_printf("\a\a\a") == printf("\a\a\a"));
	assert(ft_printf("\a \a") == printf("\a \a"));

	assert(ft_printf("\b") == printf("\b"));
	assert(ft_printf("\b\b") == printf("\b\b"));
	assert(ft_printf("\b\b\b") == printf("\b\b\b"));
	assert(ft_printf("\b \b") == printf("\b \b"));

	assert(ft_printf("\f") == printf("\f"));
	assert(ft_printf("\f\f") == printf("\f\f"));
	assert(ft_printf("\f\f\f") == printf("\f\f\f"));
	assert(ft_printf("\f \f") == printf("\f \f"));

	assert(ft_printf("\r") == printf("\r"));
	assert(ft_printf("\r\r") == printf("\r\r"));
	assert(ft_printf("\r\r\r") == printf("\r\r\r"));
	assert(ft_printf("\r \r") == printf("\r \r"));

	assert(ft_printf("\v") == printf("\v"));
	assert(ft_printf("\v\v") == printf("\v\v"));
	assert(ft_printf("\v\v\v") == printf("\v\v\v"));
	assert(ft_printf("\v \v") == printf("\v \v"));

	assert(ft_printf("\'") == printf("\'"));
	assert(ft_printf("\'\'") == printf("\'\'"));
	assert(ft_printf("\'\'\'") == printf("\'\'\'"));
	assert(ft_printf("\' \'") == printf("\' \'"));

	assert(ft_printf("\"") == printf("\""));
	assert(ft_printf("\"\"") == printf("\"\""));
	assert(ft_printf("\"\"\"") == printf("\"\"\""));
	assert(ft_printf("\" \"") == printf("\" \""));

	assert(ft_printf("\?") == printf("\?"));
	assert(ft_printf("\?\?") == printf("\?\?"));
	assert(ft_printf("\?\?\?") == printf("\?\?\?"));
	assert(ft_printf("\? \?") == printf("\? \?"));

	assert(ft_printf("\?") == printf("\?"));
	assert(ft_printf("\?\?") == printf("\?\?"));
	assert(ft_printf("\?\?\?") == printf("\?\?\?"));
	assert(ft_printf("\? \?") == printf("\? \?"));



/*
	%% non-existing and %% existing flags
	null strings and null characters
*/

	//char z = '\0';
	char *zero_s;
	if(!(zero_s = (char *)malloc(sizeof(char) * 1)))
		exit(1);
	zero_s[0] = '\0';
	
	assert(ft_printf("%%a\n") == printf("%%a\n"));
	assert(ft_printf("%%s\n") == printf("%%s\n"));
	assert(ft_printf("%%c\n") == printf("%%c\n"));
	assert(ft_printf("%%i\n") == printf("%%i\n"));
	assert(ft_printf("%%d\n") == printf("%%d\n"));
	assert(ft_printf("%%o\n") == printf("%%o\n"));
	assert(ft_printf("%%u\n") == printf("%%u\n"));
	assert(ft_printf("%%x\n") == printf("%%x\n"));

	assert(ft_printf("%s\n", &z) == printf("%s\n", &z));
	assert(ft_printf("%s%s\n", &z, &z) == printf("%s%s\n", &z, &z));
	assert(ft_printf("%s %s\n", &z, &z) == printf("%s %s\n", &z, &z));
	assert(ft_printf("%s\n", "") == printf("%s\n", ""));
	assert(ft_printf("%s%s\n", "", "") == printf("%s%s\n", "", ""));
	assert(ft_printf("%s %s\n", "", "") == printf("%s %s\n", "", ""));
	assert(ft_printf("%s\n", zero_s) == printf("%s\n", zero_s));
	assert(ft_printf("%s%s\n", zero_s, zero_s) == printf("%s%s\n", zero_s, zero_s));
	assert(ft_printf("%s %s\n", zero_s, zero_s) == printf("%s %s\n", zero_s, zero_s));
	
	assert(ft_printf("%c\n", z) == printf("%c\n", z));
	assert(ft_printf("%c%c\n", z, z) == printf("%c%c\n", z, z));
	assert(ft_printf("%c %c\n", z, z) == printf("%c %c\n", z, z));
	assert(ft_printf("%c\n", '\0') == printf("%c\n", '\0'));
	assert(ft_printf("%c%c\n", '\0', '\0') == printf("%c%c\n", '\0', '\0'));
	assert(ft_printf("%c %c\n", '\0', '\0') == printf("%c %c\n", '\0', '\0'));
	assert(ft_printf("%c\n", *zero_s) == printf("%c\n", *zero_s));
	assert(ft_printf("%c%c\n", *zero_s, *zero_s) == printf("%c%c\n", *zero_s, *zero_s));
	assert(ft_printf("%c %c\n", *zero_s, *zero_s) == printf("%c %c\n", *zero_s, *zero_s));

	free(zero_s);

/*
	Tests for char %c and string %s here
	develop the %lc tests also, which is the same thing as %C
*/


for (int x = 32; x < 127; x++) {
	char *test;

	printf("assert(ft_printf(\"%%c\\n\", %c) == printf(\"%%c\\n\", %c));\n", x, x);
	assert(ft_printf("%c\n", x) == printf("%c\n", x));
	for (int y = 5; y < 31; y *= 6) {
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~x is %i and y is %i\n", x, y);
		test = ft_strnew2(y, x);
		printf("assert(ft_printf(\"%%s\\n\", %s) == printf(\"%%s\\n\", %s));\n", test, test);
		assert(ft_printf("%s\n", test) == printf("%s\n", test));
		printf("assert(ft_printf(\"%%.0s\\n\", %s) == printf(\"%%.0s\\n\", %s));\n", test, test);
		assert(ft_printf("%.0s\n", test) == printf("%.0s\n", test));
		printf("assert(ft_printf(\"%%.1s\\n\", %s) == printf(\"%%.1s\\n\", %s));\n", test, test);
		assert(ft_printf("%.1s\n", test) == printf("%.1s\n", test));
		printf("assert(ft_printf(\"%%.2s\\n\", %s) == printf(\"%%.2s\\n\", %s));\n", test, test);
		assert(ft_printf("%.2s\n", test) == printf("%.2s\n", test));
		printf("assert(ft_printf(\"%%.3s\\n\", %s) == printf(\"%%.3s\\n\", %s));\n", test, test);
		assert(ft_printf("%.3s\n", test) == printf("%.3s\n", test));
		printf("assert(ft_printf(\"%%.4s\\n\", %s) == printf(\"%%.4s\\n\", %s));\n", test, test);
		assert(ft_printf("%.4s\n", test) == printf("%.4s\n", test));
		printf("assert(ft_printf(\"%%.5s\\n\", %s) == printf(\"%%.5s\\n\", %s));\n", test, test);
		assert(ft_printf("%.5s\n", test) == printf("%.5s\n", test));
		printf("assert(ft_printf(\"%%1s\\n\", %s) == printf(\"%%1s\\n\", %s));\n", test, test);
		assert(ft_printf("%1s\n", test) == printf("%1s\n", test));
		printf("assert(ft_printf(\"%%2s\\n\", %s) == printf(\"%%2s\\n\", %s));\n", test, test);
		assert(ft_printf("%2s\n", test) == printf("%2s\n", test));
		printf("assert(ft_printf(\"%%3s\\n\", %s) == printf(\"%%3s\\n\", %s));\n", test, test);
		assert(ft_printf("%3s\n", test) == printf("%3s\n", test));
		printf("assert(ft_printf(\"%%4s\\n\", %s) == printf(\"%%4s\\n\", %s));\n", test, test);
		assert(ft_printf("%4s\n", test) == printf("%4s\n", test));
		printf("assert(ft_printf(\"%%5s\\n\", %s) == printf(\"%%5s\\n\", %s));\n", test, test);
		assert(ft_printf("%5s\n", test) == printf("%5s\n", test));
		printf("assert(ft_printf(\"%%8s\\n\", %s) == printf(\"%%8s\\n\", %s));\n", test, test);
		assert(ft_printf("%8s\n", test) == printf("%8s\n", test));
		printf("assert(ft_printf(\"%%15s\\n\", %s) == printf(\"%%15s\\n\", %s));\n", test, test);
		assert(ft_printf("%15s\n", test) == printf("%15s\n", test));
		free(test);
	}
}

	// Some more precision and field width tests with (-) flag
	printf("assert(ft_printf(\"%%5.2sP\\n\", %s) == printf(\"%%5.2sP\\n\",  %s));\n", string, string);
	assert(ft_printf("%5.2sP\n", string) == printf("%5.2sP\n", string));
	printf("assert(ft_printf(\"%%-5.2sP\\n\", %s) == printf(\"%%-5.2sP\\n\",  %s));\n", string, string);
	assert(ft_printf("%-5.2sP\n", string) == printf("%-5.2sP\n", string));
	printf("assert(ft_printf(\"%%-5.6sP\\n\", %s) == printf(\"%%-5.6sP\\n\",  %s));\n", string, string);
	assert(ft_printf("%-5.6sP\n", string) == printf("%-5.6sP\n", string));
	printf("assert(ft_printf(\"%%-2.2sP\\n\", %s) == printf(\"%%-2.2sP\\n\",  %s));\n", string, string);
	assert(ft_printf("%-2.2sP\n", string) == printf("%-2.2sP\n", string));

	//Some tests for precision and field width using .* and *:
	printf("assert(ft_printf(\"%%*.2sP\\n\", %i, %s) == printf(\"%%*.2sP\\n\",  %i, %s));\n", i, string, i, string);
	assert(ft_printf("%*.2sP\n", i, string) == printf("%*.2sP\n", i, string));
	printf("assert(ft_printf(\"%%-*.2sP\\n\", %i, %s) == printf(\"%%-*.2sP\\n\",  %i, %s));\n", i, string, i, string);
	assert(ft_printf("%-*.2sP\n", i, string) == printf("%-*.2sP\n", i, string));
	printf("assert(ft_printf(\"%%-*.6sP\\n\", %i, %s) == printf(\"%%-*.6sP\\n\", %i, %s));\n", i, string, i, string);
	assert(ft_printf("%-*.6sP\n", i, string) == printf("%-*.6sP\n", i, string));
	printf("assert(ft_printf(\"%%-*.2sP\\n\", %i, %s) == printf(\"%%-*.2sP\\n\", %i, %s));\n", 2, string, 2, string);
	assert(ft_printf("%-*.2sP\n", 2, string) == printf("%-*.2sP\n", 2, string));
	
	printf("assert(ft_printf(\"%%.*sP\\n\", %i, %s) == printf(\"%%.*sP\\n\", %i, %s));\n", i, string, i, string);
	assert(ft_printf("%.*sP\n", i, string) == printf("%.*sP\n", i, string));
	printf("assert(ft_printf(\"%%-.*sP\\n\", %i, %s) == printf(\"%%-.*sP\\n\", %i, %s));\n", i, string, i, string);
	assert(ft_printf("%-.*sP\n", i, string) == printf("%-.*sP\n", i, string));
	printf("assert(ft_printf(\"%%-.*sP\\n\", %i, %s) == printf(\"%%-.*sP\\n\", %i, %s));\n", 2, string, 2, string);
	assert(ft_printf("%-.*sP\n", 2, string) == printf("%-.*sP\n", 2, string));
	printf("assert(ft_printf(\"%%-.*sP\\n\", %i, %s) == printf(\"%%-.*sP\\n\", %i, %s));\n", 50, string, 50, string);
	assert(ft_printf("%-.*sP\n", 50, string) == printf("%-.*sP\n", 50, string));

/*
	ft_printf must handle '-0.* +' flags with minimum field width with all conversions.
*/

	// A couple random width and precision specifier tests
	printf("assert(ft_printf(\"%%*i\\n\", %i, %i) == printf(\"%%*i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));
	printf("assert(ft_printf(\"%% 50.10i\\n\", %i) == printf(\"%% 50.10i\\n\", %i));\n", i, i);
	assert(ft_printf("% 50.10i\n", i) == printf("% 50.10i\n", i));
	printf("assert(ft_printf(\"%%+50.10i\\n\", %i) == printf(\"%%+50.10i\\n\", %i));\n", i, i);
	assert(ft_printf("%+50.10i\n", i) == printf("%+50.10i\n", i));
	printf("assert(ft_printf(\"%%-50.10i\\n\", %i) == printf(\"%%-50.10i\\n\", %i));\n", i, i);
	assert(ft_printf("%-50.10i\n", i) == printf("%-50.10i\n", i));


	// Plus (+), Minus(-) and Space( ) tests with pos/neg ints of varying sizes
	printf("assert(ft_printf(\"%%+i\\n\", %i) == printf(\"%%+i\\n\", %i));\n", i, i);
	assert(ft_printf("%+i\n", i) == printf("%+i\n", i));
	printf("assert(ft_printf(\"%%+i\\n\", %i) == printf(\"%%+i\\n\", %i));\n", neg_i, neg_i);
	assert(ft_printf("%+i\n", neg_i) == printf("%+i\n", neg_i));
	printf("assert(ft_printf(\"%%-i\\n\", %i) == printf(\"%%-i\\n\", %i));\n", i, i);
	assert(ft_printf("%-i\n", i) == printf("%-i\n", i));
	printf("assert(ft_printf(\"%%-i\\n\", %i) == printf(\"%%-i\\n\", %i));\n", neg_i, neg_i);
	assert(ft_printf("%-i\n", neg_i) == printf("%-i\n", neg_i));
	printf("assert(ft_printf(\"%% i\\n\", %i) == printf(\"%% i\\n\", %i));\n", i, i);
	assert(ft_printf("% i\n", i) == printf("% i\n", i));
	printf("assert(ft_printf(\"%% i\\n\", %i) == printf(\"%% i\\n\", %i));\n", neg_i, neg_i);
	assert(ft_printf("% i\n", neg_i) == printf("% i\n", neg_i));

	printf("assert(ft_printf(\"%%+i\\n\", %i) == printf(\"%%+i\\n\", %i));\n",  i2, i2);
	assert(ft_printf("%+i\n", i2) == printf("%+i\n", i2));
	printf("assert(ft_printf(\"%%+i\\n\", %i) == print:f(\"%%+i\\n\", %i));\n", neg_i2, neg_i2);
	assert(ft_printf("%+i\n", neg_i2) == printf("%+i\n", neg_i2));
	printf("assert(ft_printf(\"%%-i\\n\", %i) == printf(\"%%-i\\n\", %i));\n", i2, i2);
	assert(ft_printf("%-i\n", i2) == printf("%-i\n", i2));
	printf("assert(ft_printf(\"%%-i\\n\", %i) == printf(\"%%-i\\n\", %i));\n", neg_i2, neg_i2);
	assert(ft_printf("%-i\n", neg_i2) == printf("%-i\n", neg_i2));
	printf("assert(ft_printf(\"%% i\\n\", %i) == printf(\"%% i\\n\", %i));\n", i2, i2);
	assert(ft_printf("% i\n", i2) == printf("% i\n", i2));
	printf("assert(ft_printf(\"%% i\\n\", %i) == printf(\"%% i\\n\", %i));\n", neg_i2, neg_i2);
	assert(ft_printf("% i\n", neg_i2) == printf("% i\n", neg_i2));

	printf("assert(ft_printf(\"%%+i\\n\", %i) == printf(\"%%+i\\n\", %i));\n", i3, i3);
	assert(ft_printf("%+i\n", i3) == printf("%+i\n", i3));
	printf("assert(ft_printf(\"%%+i\\n\", %i) == printf(\"%%+i\\n\", %i));\n", neg_i3, neg_i3);
	assert(ft_printf("%+i\n", neg_i3) == printf("%+i\n", neg_i3));
	printf("assert(ft_printf(\"%%-i\\n\", %i) == printf(\"%%-i\\n\", %i));\n", i3, i3);
	assert(ft_printf("%-i\n", i3) == printf("%-i\n", i3));
	printf("assert(ft_printf(\"%%-i\\n\", %i) == printf(\"%%-i\\n\", %i));\n", neg_i3, neg_i3);
	assert(ft_printf("%-i\n", neg_i3) == printf("%-i\n", neg_i3));
	printf("assert(ft_printf(\"%% i\\n\", %i) == printf(\"%% i\\n\", %i));\n", i3, i3);
	assert(ft_printf("% i\n", i3) == printf("% i\n", i3));
	printf("assert(ft_printf(\"%% i\\n\", %i) == printf(\"%% i\\n\", %i));\n", neg_i3, neg_i3);
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
	printf("assert(ft_printf(\"%%*i\\n\", %i, %i) == printf(\"%%*i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%*i\n", i, i) == printf("%*i\n", i, i));
	printf("assert(ft_printf(\"%%+*i\\n\", %i, %i) == printf(\"%%+*i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%+*i\n", i, i) == printf("%+*i\n", i, i));
	printf("assert(ft_printf(\"%% *i\\n\", %i, %i) == printf(\"%% *i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("% *i\n", i, i) == printf("% *i\n", i, i));
	printf("assert(ft_printf(\"%%-*i\\n\", %i, %i) == printf(\"%%-*i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%-*i\n", i, i) == printf("%-*i\n", i, i));
	printf("assert(ft_printf(\"%%.*i\\n\", %i, %i) == printf(\"%%.*i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%.*i\n", i, i) == printf("%.*i\n", i, i));
	printf("assert(ft_printf(\"%%+.*i\\n\", %i, %i) == printf(\"%%+.*i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%+.*i\n", i, i) == printf("%+.*i\n", i, i));
	printf("assert(ft_printf(\"%%-.*i\\n\", %i, %i) == printf(\"%%-.*i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%-.*i\n", i, i) == printf("%-.*i\n", i, i));
	printf("assert(ft_printf(\"%% .*i\\n\", %i, %i) == printf(\"%% .*i\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("% .*i\n", i, i) == printf("% .*i\n", i, i));
	printf("assert(ft_printf(\"%%.*i\\n\", %i, %i) == printf(\"%%.*i\\n\", %i, %i));\n", i, i, i, i);
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
//	assert(ft_printf("%0*i\n", i, i) == printf("%0*i\n", i, i));


/* All the %i tests with %d */



	// A couple random width and precision specifier tests
	printf("assert(ft_printf(\"%%*d\\n\", %i, %i) == printf(\"%%*d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%*d\n", i, i) == printf("%*d\n", i, i));
	printf("assert(ft_printf(\"%% 50.10d\\n\", %i) == printf(\"%% 50.10d\\n\", %i));\n", i, i);
	assert(ft_printf("% 50.10d\n", i) == printf("% 50.10d\n", i));
	printf("assert(ft_printf(\"%%+50.10d\\n\", %i) == printf(\"%%+50.10d\\n\", %i));\n", i, i);
	assert(ft_printf("%+50.10d\n", i) == printf("%+50.10d\n", i));
	printf("assert(ft_printf(\"%%-50.10d\\n\", %i) == printf(\"%%-50.10d\\n\", %i));\n", i, i);
	assert(ft_printf("%-50.10d\n", i) == printf("%-50.10d\n", i));

	// Plus (+), Minus(-) and Space( ) tests with pos/neg ints of varying sizes
	printf("assert(ft_printf(\"%%+d\\n\", %i) == printf(\"%%+d\\n\", %i));\n", i, i);
	assert(ft_printf("%+d\n", i) == printf("%+d\n", i));
	printf("assert(ft_printf(\"%%+d\\n\", %i) == printf(\"%%+d\\n\", %i));\n", neg_i, neg_i);
	assert(ft_printf("%+d\n", neg_i) == printf("%+d\n", neg_i));
	printf("assert(ft_printf(\"%%-d\\n\", %i) == printf(\"%%-d\\n\", %i));\n", i, i);
	assert(ft_printf("%-d\n", i) == printf("%-d\n", i));
	printf("assert(ft_printf(\"%%-d\\n\", %i) == printf(\"%%-d\\n\", %i));\n", neg_i, neg_i);
	assert(ft_printf("%-d\n", neg_i) == printf("%-d\n", neg_i));
	printf("assert(ft_printf(\"%% d\\n\", %i) == printf(\"%% d\\n\", %i));\n", i, i);
	assert(ft_printf("% d\n", i) == printf("% d\n", i));
	printf("assert(ft_printf(\"%% d\\n\", %i) == printf(\"%% d\\n\", %i));\n", neg_i, neg_i);
	assert(ft_printf("% d\n", neg_i) == printf("% d\n", neg_i));

	printf("assert(ft_printf(\"%%+d\\n\", %i) == printf(\"%%+d\\n\", %i));\n", i2, i2);
	assert(ft_printf("%+d\n", i2) == printf("%+d\n", i2));
	printf("assert(ft_printf(\"%%+d\\n\", %i) == printf(\"%%+d\\n\", %i));\n", neg_i2, neg_i2);
	assert(ft_printf("%+d\n", neg_i2) == printf("%+d\n", neg_i2));
	printf("assert(ft_printf(\"%%-d\\n\", %i) == printf(\"%%-d\\n\", %i));\n", i2, i2);
	assert(ft_printf("%-d\n", i2) == printf("%-d\n", i2));
	printf("assert(ft_printf(\"%%-d\\n\", %i) == printf(\"%%-d\\n\", %i));\n", neg_i2, neg_i2);
	assert(ft_printf("%-d\n", neg_i2) == printf("%-d\n", neg_i2));
	printf("assert(ft_printf(\"%% d\\n\", %i) == printf(\"%% d\\n\", %i));\n", i2, i2);
	assert(ft_printf("% d\n", i2) == printf("% d\n", i2));
	printf("assert(ft_printf(\"%% d\\n\", %i) == printf(\"%% d\\n\", %i));\n", neg_i2, neg_i2);
	assert(ft_printf("% d\n", neg_i2) == printf("% d\n", neg_i2));

	printf("assert(ft_printf(\"%%+d\\n\", %i) == printf(\"%%+d\\n\", %i));\n", i3, i3);
	assert(ft_printf("%+d\n", i3) == printf("%+d\n", i3));
	printf("assert(ft_printf(\"%%+d\\n\", %i) == printf(\"%%+d\\n\", %i));\n", neg_i3, neg_i3);
	assert(ft_printf("%+d\n", neg_i3) == printf("%+d\n", neg_i3));
	printf("assert(ft_printf(\"%%-d\\n\", %i) == printf(\"%%-d\\n\", %i));\n",i3, i3);
	assert(ft_printf("%-d\n", i3) == printf("%-d\n", i3));
	printf("assert(ft_printf(\"%%-d\\n\", %i) == printf(\"%%-d\\n\", %i));\n", neg_i3, neg_i3);
	assert(ft_printf("%-d\n", neg_i3) == printf("%-d\n", neg_i3));
	printf("assert(ft_printf(\"%% d\\n\", %i) == printf(\"%% d\\n\", %i));\n", i3, i3);
	assert(ft_printf("% d\n", i3) == printf("% d\n", i3));
	printf("assert(ft_printf(\"%% d\\n\", %i) == printf(\"%% d\\n\", %i));\n", neg_i3, neg_i3);
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

	printf("assert(ft_printf(\"%%*d\\n\", %i, %i) == printf(\"%%*d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%*d\n", i, i) == printf("%*d\n", i, i));
	printf("assert(ft_printf(\"%%+*d\\n\", %i, %i) == printf(\"%%+*d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%+*d\n", i, i) == printf("%+*d\n", i, i));
	printf("assert(ft_printf(\"%% *d\\n\", %i, %i) == printf(\"%% *d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("% *d\n", i, i) == printf("% *d\n", i, i));
	printf("assert(ft_printf(\"%%-*d\\n\", %i, %i) == printf(\"%%-*d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%-*d\n", i, i) == printf("%-*d\n", i, i));
	printf("assert(ft_printf(\"%%.*d\\n\", %i, %i) == printf(\"%%.*d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%.*d\n", i, i) == printf("%.*d\n", i, i));
	printf("assert(ft_printf(\"%%+.*d\\n\", %i, %i) == printf(\"%%+.*d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%+.*d\n", i, i) == printf("%+.*d\n", i, i));
	printf("assert(ft_printf(\"%%-.*d\\n\", %i, %i) == printf(\"%%-.*d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("%-.*d\n", i, i) == printf("%-.*d\n", i, i));
	printf("assert(ft_printf(\"%% .*d\\n\", %i, %i) == printf(\"%% .*d\\n\", %i, %i));\n", i, i, i, i);
	assert(ft_printf("% .*d\n", i, i) == printf("% .*d\n", i, i));
	printf("assert(ft_printf(\"%%.*d\\n\", %i, %i) == printf(\"%%.*d\\n\", %i, %i));\n", i, i, i, i);
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

	for(int z = 0, a = -100; z < 2; z++, a = -100) {
		for (int b = (z) ? -1 * a : a; a <= 100; a++, b += (z) ? -1 : 1) {
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~a is %i and b is %i\n", a, b);
			printf("assert(ft_printf(\"%%0*d\\n\", %i, %i) == printf(\"%%0*d\\n\", %i, %i));\n", a, a, a, a);
			assert(ft_printf("%0*d\n", a, a) == printf("%0*d\n", a, a));
			printf("assert(ft_printf(\"%%0.*d\\n\", %i, %i) == printf(\"%%0.*d\\n\", %i, %i));\n", a, a, a, a);
			assert(ft_printf("%0.*d\n", a, a) == printf("%0.*d\n", a, a));
			printf("assert(ft_printf(\"%%0*.*d\\n\", %i, %i, %i) == printf(\"%%0*.*d\\n\", %i, %i, %i));\n", a, a, a, a, a, a);
			assert(ft_printf("%0*.*d\n", a, a, a) == printf("%0*.*d\n", a, a, a));
		
			printf("assert(ft_printf(\"%%0*d\\n\", %i, %i) == printf(\"%%0*d\\n\", %i, %i));\n", a, b, a, b);
			assert(ft_printf("%0*d\n", a, b) == printf("%0*d\n", a, b));
			printf("assert(ft_printf(\"%%0.*d\\n\", %i, %i) == printf(\"%%0.*d\\n\", %i, %i));\n", a, b, a, b);
			assert(ft_printf("%0.*d\n", a, b) == printf("%0.*d\n", a, b));
			printf("assert(ft_printf(\"%%0*.*d\\n\", %i, %i, %i) == printf(\"%%0*.*d\\n\", %i, %i, %i));\n", a, b, b, a, b, b);
			assert(ft_printf("%0*.*d\n", a, b, b) == printf("%0*.*d\n", a, b, b));
			printf("assert(ft_printf(\"%%0*.*d\\n\", %i, %i, %i) == printf(\"%%0*.*d\\n\", %i, %i, %i));\n", a, b, a, a, b, a);
			assert(ft_printf("%0*.*d\n", a, b, a) == printf("%0*.*d\n", a, b, a));

			printf("assert(ft_printf(\"%%0*d\\n\", %i, %i) == printf(\"%%0*d\\n\",%i, %i));\n", b, a, b, a);
			assert(ft_printf("%0*d\n", b, a) == printf("%0*d\n", b, a));
			printf("assert(ft_printf(\"%%0.*d\\n\", %i, %i) == printf(\"%%0.*d\\n\", %i, %i));\n", b, a, b, a);
			assert(ft_printf("%0.*d\n", b, a) == printf("%0.*d\n", b, a));
			printf("assert(ft_printf(\"%%0*.*d\\n\", %i, %i, %i) == printf(\"%%0*.*d\\n\", %i, %i, %i));\n", b, b, a, b, b, a);
			assert(ft_printf("%0*.*d\n", b, b, a) == printf("%0*.*d\n", b, b, a));
			printf("assert(ft_printf(\"%%0*.*d\\n\", %i, %i, %i) == printf(\"%%0*.*d\\n\", %i, %i, %i));\n", b, b, b, b, b, b);
			assert(ft_printf("%0*.*d\n", b, b, b) == printf("%0*.*d\n", b, b, b));
		}
	}






/*
	the original printf throws an error if you try to run these two flags together. For this, I plan to implement a checker to verify the validity of the string, and exit with error message if invalid string is used. This will immitate the native function. 
	printf("Tests for 0- precedence\n");
	printf("assert(ft_printf(\"%%-i\\n\", %i) == printf(\"%%-i\\n\", %i));\n",  i);
	assert(ft_printf("%-i\n", i) == printf("%-i\n", i));
	assert(ft_printf("%0i\n", i) == printf("%0i\n", i));
	ft_printf("%0-i\n", i) == printf("%0-i\n", i));
	ft_printf("%-0i\n", i);
*/


/*
	float tests!!!! Project is developing nicely.
*/


int	a;
// Tests of * and .* with 0 flags
	for (a = 0; a <= 100; a++) {
	printf("~~~~~~~~~~a is %i\n", a);
	
		printf("assert(ft_printf(\"%%*f\\n\", %i, %f) == printf(\"%%*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("%*f\n", a, f2) == printf("%*f\n", a, f2));
		printf("assert(ft_printf(\"%%.*f\\n\", %i, %f) == printf(\"%%.*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("%.*f\n", a, f2) == printf("%.*f\n", a, f2));
		printf("assert(ft_printf(\"%%0*f\\n\", %i, %f) == printf(\"%%0*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("%0*f\n", a, f2) == printf("%0*f\n", a, f2));
		printf("assert(ft_printf(\"%%0.*f\\n\", %i, %f) == printf(\"%%0.*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("%0.*f\n", a, f2) == printf("%0.*f\n", a, f2));
		printf("assert(ft_printf(\"%%-*f\\n\", %i, %f) == printf(\"%%-*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("%-*f\n", a, f2) == printf("%-*f\n", a, f2));
		printf("assert(ft_printf(\"%%-.*f\\n\", %i, %f) == printf(\"%%-.*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("%-.*f\n", a, f2) == printf("%-.*f\n", a, f2));
		printf("assert(ft_printf(\"%%+*f\\n\", %i, %f) == printf(\"%%+*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("%+*f\n", a, f2) == printf("%+*f\n", a, f2));
		printf("assert(ft_printf(\"%%+.*f\\n\", %i, %f) == printf(\"%%+.*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("%+.*f\n", a, f2) == printf("%+.*f\n", a, f2));
		printf("assert(ft_printf(\"%% *f\\n\", %i, %f) == printf(\"%% *f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("% *f\n", a, f2) == printf("% *f\n", a, f2));
		printf("assert(ft_printf(\"%% .*f\\n\", %i, %f) == printf(\"%% .*f\\n\", %i, %f));\n", a, f2, a, f2);
		assert(ft_printf("% .*f\n", a, f2) == printf("% .*f\n", a, f2));
		printf("assert(ft_printf(\"%%*.*f\\n\", %i, %i, %f) == printf(\"%%*.*f\\n\", %i, %i, %f));\n", a, a, f2, a, a, f2);
		assert(ft_printf("%*.*f\n", a, a, f2) == printf("%*.*f\n", a, a, f2));
		printf("assert(ft_printf(\"%%0*.*f\\n\", %i, %i, %f) == printf(\"%%0*.*f\\n\", %i, %i, %f));\n", a, a, f2, a, a, f2);
		assert(ft_printf("%0*.*f\n", a, a, f2) == printf("%0*.*f\n", a, a, f2));
		printf("assert(ft_printf(\"%%-*.*f\\n\", %i, %i, %f) == printf(\"%%-*.*f\\n\", %i, %i, %f));\n", a, a, f2, a, a, f2);
		assert(ft_printf("%-*.*f\n", a, a, f2) == printf("%-*.*f\n", a, a, f2));
		printf("assert(ft_printf(\"%%+*.*f\\n\", %i, %i, %f) == printf(\"%%+*.*f\\n\", %i, %i, %f));\n", a, a, f2, a, a, f2);
		assert(ft_printf("%+*.*f\n", a, a, f2) == printf("%+*.*f\n", a, a, f2));
		printf("assert(ft_printf(\"%% *.*f\\n\", %i, %i, %f) == printf(\"%% *.*f\\n\", %i, %i, %f));\n", a, a, f2, a, a, f2);
		assert(ft_printf("% *.*f\n", a, a, f2) == printf("% *.*f\n", a, a, f2));

		printf("assert(ft_printf(\"%%*f\\n\", %i, %f) == printf(\"%%*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("%*f\n", a, f) == printf("%*f\n", a, f));
		printf("assert(ft_printf(\"%%.*f\\n\", %i, %f) == printf(\"%%.*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("%.*f\n", a, f) == printf("%.*f\n", a, f));
		printf("assert(ft_printf(\"%%0*f\\n\", %i, %f) == printf(\"%%0*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("%0*f\n", a, f) == printf("%0*f\n", a, f));
		printf("assert(ft_printf(\"%%0.*f\\n\", %i, %f) == printf(\"%%0.*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("%0.*f\n", a, f) == printf("%0.*f\n", a, f));
		printf("assert(ft_printf(\"%%-*f\\n\", %i, %f) == printf(\"%%-*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("%-*f\n", a, f) == printf("%-*f\n", a, f));
		printf("assert(ft_printf(\"%%-.*f\\n\", %i, %f) == printf(\"%%-.*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("%-.*f\n", a, f) == printf("%-.*f\n", a, f));
		printf("assert(ft_printf(\"%%+*f\\n\", %i, %f) == printf(\"%%+*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("%+*f\n", a, f) == printf("%+*f\n", a, f));
		printf("assert(ft_printf(\"%%+.*f\\n\", %i, %f) == printf(\"%%+.*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("%+.*f\n", a, f) == printf("%+.*f\n", a, f));
		printf("assert(ft_printf(\"%% *f\\n\", %i, %f) == printf(\"%% *f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("% *f\n", a, f) == printf("% *f\n", a, f));
		printf("assert(ft_printf(\"%% .*f\\n\", %i, %f) == printf(\"%% .*f\\n\", %i, %f));\n", a, f, a, f);
		assert(ft_printf("% .*f\n", a, f) == printf("% .*f\n", a, f));
	
		printf("assert(ft_printf(\"%%*.*f\\n\", %i, %i, %f) == printf(\"%%*.*f\\n\", %i, %i, %f));\n", a, a, f, a, a, f);
		assert(ft_printf("%*.*f\n", a, a, f) == printf("%*.*f\n", a, a, f));
		printf("assert(ft_printf(\"%%0*.*f\\n\", %i, %i, %f) == printf(\"%%0*.*f\\n\", %i, %i, %f));\n", a, a, f, a, a, f);
		assert(ft_printf("%0*.*f\n", a, a, f) == printf("%0*.*f\n", a, a, f));
		printf("assert(ft_printf(\"%%-*.*f\\n\", %i, %i, %f) == printf(\"%%-*.*f\\n\", %i, %i, %f));\n", a, a, f, a, a, f);
		assert(ft_printf("%-*.*f\n", a, a, f) == printf("%-*.*f\n", a, a, f));
		printf("assert(ft_printf(\"%%+*.*f\\n\", %i, %i, %f) == printf(\"%%+*.*f\\n\", %i, %i, %f));\n", a, a, f, a, a, f);
		assert(ft_printf("%+*.*f\n", a, a, f) == printf("%+*.*f\n", a, a, f));
		printf("assert(ft_printf(\"%% *.*f\\n\", %i, %i, %f) == printf(\"%% *.*f\\n\", %i, %i, %f));\n", a, a, f, a, a, f);
		assert(ft_printf("% *.*f\n", a, a, f) == printf("% *.*f\n", a, a, f));
	}

	a--;
	int b = -100;
	for (int z = 0; z < 2; z++, swap(&a, &b)) {
		while (a != b) {
			printf("~~~~~~~~~~~~~~~~~a is %i b is %i\n", a, b);
		printf("assert(ft_printf(\"%%*.*f\\n\", %i, %i, %f) == printf(\"%%*.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("%*.*f\n", a, b, f) == printf("%*.*f\n", a, b, f));	
		printf("assert(ft_printf(\"%%0*.*f\\n\", %i, %i, %f) == printf(\"%%0*.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("%0*.*f\n", a, b, f) == printf("%0*.*f\n", a, b, f));
		printf("assert(ft_printf(\"%%-*.*f\\n\", %i, %i, %f) == printf(\"%%-*.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("%-*.*f\n", a, b, f) == printf("%-*.*f\n", a, b, f));
		printf("assert(ft_printf(\"%%+*.*f\\n\", %i, %i, %f) == printf(\"%%+*.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("%+*.*f\n", a, b, f) == printf("%+*.*f\n", a, b, f));
		printf("assert(ft_printf(\"%% *.*f\\n\", %i, %i, %f) == printf(\"%% *.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("% *.*f\n", a, b, f) == printf("% *.*f\n", a, b, f));
			a += (a < b) ? 1 : 0;
			b += (a > b) ? 1 : 0;
		}
		b = -100;
	}
	b = -100;
	for (int z = 0; z < 2; z++, a = -100) {
		while(a <= 100) {
			printf("~~~~~~~~~~~~~~~a is %i b is %i\n", a, b);
		printf("assert(ft_printf(\"%%*.*f\\n\", %i, %i, %f) == printf(\"%%*.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("%*.*f\n", a, b, f) == printf("%*.*f\n", a, b, f));	
		printf("assert(ft_printf(\"%%0*.*f\\n\", %i, %i, %f) == printf(\"%%0*.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("%0*.*f\n", a, b, f) == printf("%0*.*f\n", a, b, f));
		printf("assert(ft_printf(\"%%-*.*f\\n\", %i, %i, %f) == printf(\"%%-*.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("%-*.*f\n", a, b, f) == printf("%-*.*f\n", a, b, f));
		printf("assert(ft_printf(\"%%+*.*f\\n\", %i, %i, %f) == printf(\"%%+*.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("%+*.*f\n", a, b, f) == printf("%+*.*f\n", a, b, f));
		printf("assert(ft_printf(\"%% *.*f\\n\", %i, %i, %f) == printf(\"%% *.*f\\n\", %i, %i, %f));\n", a, b, f, a, b, f);
			assert(ft_printf("% *.*f\n", a, b, f) == printf("% *.*f\n", a, b, f));	
			b += (a == b) ? 1 : -1;
			a++;
		}
		b--;
	}

	double f4 = 0.0;
	double f5 = 0.05;
	double f6 = -0.0;
	double f7 = -0.05;

	printf("assert(ft_printf(\"%%f\\n\", %f) == printf(\"%%f\\n\", %f));\n", f4, f4);
	assert(ft_printf("%f\n", f4) == printf("%f\n", f4));
	printf("assert(ft_printf(\"%%f\\n\", %f) == printf(\"%%f\\n\", %f));\n", f5, f5);
	assert(ft_printf("%f\n", f5) == printf("%f\n", f5));
	printf("assert(ft_printf(\"%%f\\n\", %f) == printf(\"%%f\\n\", %f));\n", f6, f6);
	assert(ft_printf("%f\n", f6) == printf("%f\n", f6));
	printf("assert(ft_printf(\"%%015f\\n\", %f) == printf(\"%%015f\\n\", %f));\n", f6, f6);
	assert(ft_printf("%015f\n", f6) == printf("%015f\n", f6));
	printf("assert(ft_printf(\"%%-15f\\n\", %f) == printf(\"%%-15f\\n\", %f));\n", f6, f6);
	assert(ft_printf("%-15f\n", f6) == printf("%-15f\n", f6));
	printf("assert(ft_printf(\"%%f\\n\", %f) == printf(\"%%f\\n\", %f));\n", f7, f7);
	assert(ft_printf("%f\n", f7) == printf("%f\n", f7));


	assert(ft_printf("%is\n", 5) == printf("%is\n", 5));
	assert(ft_printf("%isabcd\n", 5) == printf("%isabcd\n", 5));
	assert(ft_printf("%id\n", 5) == printf("%id\n", 5));
	assert(ft_printf("%ix\n", 5) == printf("%ix\n", 5));
	assert(ft_printf("%ii\n", 5) == printf("%ii\n", 5));
	assert(ft_printf("%ip\n", 5) == printf("%ip\n", 5));
	assert(ft_printf("%ic\n", 5) == printf("%ic\n", 5));
	assert(ft_printf("%io\n", 5) == printf("%io\n", 5));

	assert(ft_printf("%id%id\n", 5, 5) == printf("%id%id\n", 5, 5));
	assert(ft_printf("%ix%ix\n", 5, 5) == printf("%ix%ix\n", 5, 5));
	assert(ft_printf("%ii%ii\n", 5, 5) == printf("%ii%ii\n", 5, 5));
	assert(ft_printf("%ip%ip\n", 5, 5) == printf("%ip%ip\n", 5, 5));
	assert(ft_printf("%ic%ic\n", 5, 5) == printf("%ic%ic\n", 5, 5));
	assert(ft_printf("%io%io\n", 5, 5) == printf("%io%io\n", 5, 5));






	//Successfully passed tests message:
	printf("\n\n\t\t##########################################\n\t\t#  Congratulations!!! All Tests Passed!  #\n\t\t##########################################\n\n\n");

	return (0);
}
