#include "../includes/ft_printf.h"

#include <assert.h>
#include <limits.h>

#include <time.h>
#include <stdlib.h>

void	swap(int *a, int *b) 
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int     numlen(long double i)
{
	long long int 	n = (long long int)i; 
	int     	len;

	len = 0;
	if (i == 0)
		return (1);
	while (n > 0)
	{
		++len;
		n /= 10;
	}
	return (len);
}

int	exponent(int x)
{
	int i = 1;
	x++;

	while(--x)
		i *= 10;
	return (i);
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

	unsigned int pqr = 42;
	printf("assert(ft_printf(\"%%O\\n\", %O) == printf(\"%%O\\n\", %O));\n", pqr, pqr);
	assert(ft_printf("%O\n", pqr) == printf("%O\n", pqr));

	unsigned long long xyz = 0;
	//ft_printf("%lo\n", xyz - 1);

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

	printf("assert(ft_printf(\"\\\\ \\n\") == printf(\"\\\\ \\n\"));\n");
	assert(ft_printf("\\ \n") == printf("\\ \n"));
	printf("assert(ft_printf(\"\\\\\\\\ \\n\") == printf(\"\\\\\\\\ \\n\"));\n");
	assert(ft_printf("\\\\ \n") == printf("\\\\ \n"));
	printf("assert(ft_printf(\"\\\\\\\\\\\\ \\n\") == printf(\"\\\\\\\\\\\\ \\n\"));\n");
	assert(ft_printf("\\\\\\ \n") == printf("\\\\\\ \n"));
	printf("assert(ft_printf(\"\\\\\\\\\\\\\\\\ \\n\") == printf(\"\\\\\\\\\\\\\\\\ \\n\"));\n");
	assert(ft_printf("\\\\\\\\ \n") == printf("\\\\\\\\ \n"));

	printf("assert(ft_printf(\"\\n\") == printf(\"\\n\"));\n");
	assert(ft_printf("\n") == printf("\n"));
printf("*skip*\n");
	printf("assert(ft_printf(\"\\n\\n\") == printf(\"\\n\\n\"));\n");
	assert(ft_printf("\n\n") == printf("\n\n"));
	printf("assert(ft_printf(\"\\n\\n\\n\") == printf(\"\\n\\n\\n\"));\n");
	assert(ft_printf("\n\n\n") == printf("\n\n\n"));
	printf("assert(ft_printf(\"\\n \\n\") == printf(\"\\n \\n\"));\n");
	assert(ft_printf("\n \n") == printf("\n \n"));
printf("*skip*\n");
	printf("assert(ft_printf(\"\\t\\n\") == printf(\"\\t\\n\"));\n");
	assert(ft_printf("\t\n") == printf("\t\n"));
	printf("assert(ft_printf(\"\\t\\t\\n\") == printf(\"\\t\\t\\n\"));\n");
	assert(ft_printf("\t\t\n") == printf("\t\t\n"));
	printf("assert(ft_printf(\"\\t\\t\\t\\n\") == printf(\"\\t\\t\\t\\n\"));\n");
	assert(ft_printf("\t\t\t\n") == printf("\t\t\t\n"));
	printf("assert(ft_printf(\"\\t\\t\\t\\t\\n\") == printf(\"\\t\\t\\t\\t\\n\"));\n");
	assert(ft_printf("\t\t\t\t\n") == printf("\t\t\t\t\n"));
	printf("assert(ft_printf(\"\\t \\t\\n\") == printf(\"\\t \\t\\n\"));\n");
	assert(ft_printf("\t \t\n") == printf("\t \t\n"));
	printf("assert(ft_printf(\"\\t \\t \\n\") == printf(\"\\t \\t \\n\"));\n");
	assert(ft_printf("\t \t \n") == printf("\t \t \n"));

	printf("assert(ft_printf(\"\\\\p\\n\") == printf(\"\\\\p\\n\"));\n");
	assert(ft_printf("\\p\n") == printf("\\p\n"));
printf("*skip*\n");
	printf("assert(ft_printf(\"\\a\") == printf(\"\\a\"));\n");
	assert(ft_printf("\a") == printf("\a"));
	printf("assert(ft_printf(\"\\a\\a\") == printf(\"\\a\\a\"));\n");
	assert(ft_printf("\a\a") == printf("\a\a"));
	printf("assert(ft_printf(\"\\a\\a\\a\") == printf(\"\\a\\a\\a\"));\n");
	assert(ft_printf("\a\a\a") == printf("\a\a\a"));
	printf("assert(ft_printf(\"\\a \\a\") == printf(\"\\a \\a\"));\n");
	assert(ft_printf("\a \a") == printf("\a \a"));

	printf("assert(ft_printf(\"\\b\") == printf(\"\\b\"));\n");
	assert(ft_printf("\b") == printf("\b"));
	printf("assert(ft_printf(\"\\b\\b\") == printf(\"\\b\\b\"));\n");
	assert(ft_printf("\b\b") == printf("\b\b"));
	printf("assert(ft_printf(\"\\b\\b\\b\") == printf(\"\\b\\b\\b\"));\n");
	assert(ft_printf("\b\b\b") == printf("\b\b\b"));
	printf("assert(ft_printf(\"\\b \\b\") == printf(\"\\b \\b\"));\n");
	assert(ft_printf("\b \b") == printf("\b \b"));

	printf("assert(ft_printf(\"\\f\") == printf(\"\\f\"));\n");
	assert(ft_printf("\f") == printf("\f"));
	printf("assert(ft_printf(\"\\f\\f\") == printf(\"\\f\\f\"));\n");
	assert(ft_printf("\f\f") == printf("\f\f"));
	printf("assert(ft_printf(\"\\f\\f\\f\") == printf(\"\\f\\f\\f\"));\n");
	assert(ft_printf("\f\f\f") == printf("\f\f\f"));
	printf("assert(ft_printf(\"\\f \\f\") == printf(\"\\f \\f\"));\n");
	assert(ft_printf("\f \f") == printf("\f \f"));

	printf("assert(ft_printf(\"\\r\") == printf(\"\\r\"));\n");
	assert(ft_printf("\r") == printf("\r"));
	printf("assert(ft_printf(\"\\r\\r\") == printf(\"\\r\\r\"));\n");
	assert(ft_printf("\r\r") == printf("\r\r"));
	printf("assert(ft_printf(\"\\r\\r\\r\") == printf(\"\\r\\r\\r\"));\n");
	assert(ft_printf("\r\r\r") == printf("\r\r\r"));
	printf("assert(ft_printf(\"\\r \\r\") == printf(\"\\r \\r\"));\n");
	assert(ft_printf("\r \r") == printf("\r \r"));

	printf("assert(ft_printf(\"\\v\") == printf(\"\\v\"));\n");
	assert(ft_printf("\v") == printf("\v"));
	printf("assert(ft_printf(\"\\v\\v\") == printf(\"\\v\\v\"));\n");
	assert(ft_printf("\v\v") == printf("\v\v"));
	printf("assert(ft_printf(\"\\v\\v\\v\") == printf(\"\\v\\v\\v\"));\n");
	assert(ft_printf("\v\v\v") == printf("\v\v\v"));
	printf("assert(ft_printf(\"\\v \\v\") == printf(\"\\v \\v\"));\n");
	assert(ft_printf("\v \v") == printf("\v \v"));

	printf("assert(ft_printf(\"\\'\") == printf(\"\\'\"));\n");
	assert(ft_printf("\'") == printf("\'"));
	printf("assert(ft_printf(\"\\'\\'\") == printf(\"\\'\\'\"));\n");
	assert(ft_printf("\'\'") == printf("\'\'"));
	printf("assert(ft_printf(\"\\'\\'\\'\") == printf(\"\\'\\'\\'\"));\n");
	assert(ft_printf("\'\'\'") == printf("\'\'\'"));
	printf("assert(ft_printf(\"\\' \\'\") == printf(\"\\' \\'\"));\n");
	assert(ft_printf("\' \'") == printf("\' \'"));

	printf("assert(ft_printf(\"\\\"\") == printf(\"\\\"\"));\n");
	assert(ft_printf("\"") == printf("\""));
	printf("assert(ft_printf(\"\\\"\\\"\") == printf(\"\\\"\\\"\"));\n");
	assert(ft_printf("\"\"") == printf("\"\""));
	printf("assert(ft_printf(\"\\\"\\\"\\\"\") == printf(\"\\\"\\\"\\\"\"));\n");
	assert(ft_printf("\"\"\"") == printf("\"\"\""));
	printf("assert(ft_printf(\"\\\" \\\"\") == printf(\"\\\" \\\"\"));\n");
	assert(ft_printf("\" \"") == printf("\" \""));

	printf("assert(ft_printf(\"\\?\") == printf(\"\\?\"));\n");
	assert(ft_printf("\?") == printf("\?"));
	printf("assert(ft_printf(\"\\?\\?\") == printf(\"\\?\\?\"));\n");
	assert(ft_printf("\?\?") == printf("\?\?"));
	printf("assert(ft_printf(\"\\?\\?\\?\") == printf(\"\\?\\?\\?\"));\n");
	assert(ft_printf("\?\?\?") == printf("\?\?\?"));
	printf("assert(ft_printf(\"\\? \\?\") == printf(\"\\? \\?\"));\n");
	assert(ft_printf("\? \?") == printf("\? \?"));

	printf("assert(ft_printf(\"\\?\") == printf(\"\\?\"));\n");
	assert(ft_printf("\?") == printf("\?"));
	printf("assert(ft_printf(\"\\?\\?\") == printf(\"\\?\\?\"));\n");
	assert(ft_printf("\?\?") == printf("\?\?"));
	printf("assert(ft_printf(\"\\?\\?\\?\") == printf(\"\\?\\?\\?\"));\n");
	assert(ft_printf("\?\?\?") == printf("\?\?\?"));
	printf("assert(ft_printf(\"\\? \\?\") == printf(\"\\? \\?\"));\n");
	assert(ft_printf("\? \?") == printf("\? \?"));
printf("\n*skip*\n");

// SAME CODE BLOCK AS PREVIOUS 80 lines, except including newlines for the purpose of verfiying equal character output (see test_suite)

	printf("assert(ft_printf(\"\\a\\n\") == printf(\"\\a\\n\"));\n");
	assert(ft_printf("\a\n") == printf("\a\n"));
	printf("assert(ft_printf(\"\\a\\a\\n\") == printf(\"\\a\\a\\n\"));\n");
	assert(ft_printf("\a\a\n") == printf("\a\a\n"));
	printf("assert(ft_printf(\"\\a\\a\\a\\n\") == printf(\"\\a\\a\\a\\n\"));\n");
	assert(ft_printf("\a\a\a\n") == printf("\a\a\a\n"));
	printf("assert(ft_printf(\"\\a \\a\\n\") == printf(\"\\a \\a\\n\"));\n");
	assert(ft_printf("\a \a\n") == printf("\a \a\n"));

	printf("assert(ft_printf(\"\\b\\n\") == printf(\"\\b\\n\"));\n");
	assert(ft_printf("\b\n") == printf("\b\n"));
	printf("assert(ft_printf(\"\\b\\b\\n\") == printf(\"\\b\\b\\n\"));\n");
	assert(ft_printf("\b\b\n") == printf("\b\b\n"));
	printf("assert(ft_printf(\"\\b\\b\\b\\n\") == printf(\"\\b\\b\\b\\n\"));\n");
	assert(ft_printf("\b\b\b\n") == printf("\b\b\b\n"));
	printf("assert(ft_printf(\"\\b \\b\\n\") == printf(\"\\b \\b\\n\"));\n");
	assert(ft_printf("\b \b\n") == printf("\b \b\n"));

	printf("assert(ft_printf(\"\\f\\n\") == printf(\"\\f\\n\"));\n");
	assert(ft_printf("\f\n") == printf("\f\n"));
	printf("assert(ft_printf(\"\\f\\f\\n\") == printf(\"\\f\\f\\n\"));\n");
	assert(ft_printf("\f\f\n") == printf("\f\f\n"));
	printf("assert(ft_printf(\"\\f\\f\\f\\n\") == printf(\"\\f\\f\\f\\n\"));\n");
	assert(ft_printf("\f\f\f\n") == printf("\f\f\f\n"));
	printf("assert(ft_printf(\"\\f \\f\\n\") == printf(\"\\f \\f\\n\"));\n");
	assert(ft_printf("\f \f\n") == printf("\f \f\n"));

	printf("assert(ft_printf(\"\\r\\n\") == printf(\"\\r\\n\"));\n");
	assert(ft_printf("\r\n") == printf("\r\n"));
	printf("assert(ft_printf(\"\\r\\r\\n\") == printf(\"\\r\\r\\n\"));\n");
	assert(ft_printf("\r\r\n") == printf("\r\r\n"));
	printf("assert(ft_printf(\"\\r\\r\\r\\n\") == printf(\"\\r\\r\\r\\n\"));\n");
	assert(ft_printf("\r\r\r\n") == printf("\r\r\r\n"));
	printf("assert(ft_printf(\"\\r \\r\\n\") == printf(\"\\r \\r\\n\"));\n");
	assert(ft_printf("\r \r\n") == printf("\r \r\n"));

	printf("assert(ft_printf(\"\\v\\n\") == printf(\"\\v\\n\"));\n");
	assert(ft_printf("\v\n") == printf("\v\n"));
	printf("assert(ft_printf(\"\\v\\v\\n\") == printf(\"\\v\\v\\n\"));\n");
	assert(ft_printf("\v\v\n") == printf("\v\v\n"));
	printf("assert(ft_printf(\"\\v\\v\\v\\n\") == printf(\"\\v\\v\\v\\n\"));\n");
	assert(ft_printf("\v\v\v\n") == printf("\v\v\v\n"));
	printf("assert(ft_printf(\"\\v \\v\\n\") == printf(\"\\v \\v\\n\"));\n");
	assert(ft_printf("\v \v\n") == printf("\v \v\n"));

	printf("assert(ft_printf(\"\\'\\n\") == printf(\"\\'\\n\"));\n");
	assert(ft_printf("\'\n") == printf("\'\n"));
	printf("assert(ft_printf(\"\\'\\'\\n\") == printf(\"\\'\\'\\n\"));\n");
	assert(ft_printf("\'\'\n") == printf("\'\'\n"));
	printf("assert(ft_printf(\"\\'\\'\\'\\n\") == printf(\"\\'\\'\\'\\n\"));\n");
	assert(ft_printf("\'\'\'\n") == printf("\'\'\'\n"));
	printf("assert(ft_printf(\"\\' \\'\\n\") == printf(\"\\' \\'\\n\"));\n");
	assert(ft_printf("\' \'\n") == printf("\' \'\n"));

	printf("assert(ft_printf(\"\\\"\\n\") == printf(\"\\\"\\n\"));\n");
	assert(ft_printf("\"\n") == printf("\"\n"));
	printf("assert(ft_printf(\"\\\"\\\"\\n\") == printf(\"\\\"\\\"\\n\"));\n");
	assert(ft_printf("\"\"\n") == printf("\"\"\n"));
	printf("assert(ft_printf(\"\\\"\\\"\\\"\\n\") == printf(\"\\\"\\\"\\\"\\n\"));\n");
	assert(ft_printf("\"\"\"\n") == printf("\"\"\"\n"));
	printf("assert(ft_printf(\"\\\" \\\"\\n\") == printf(\"\\\" \\\"\\n\"));\n");
	assert(ft_printf("\" \"\n") == printf("\" \"\n"));

	printf("assert(ft_printf(\"\\?\\n\") == printf(\"\\?\\n\"));\n");
	assert(ft_printf("\?\n") == printf("\?\n"));
	printf("assert(ft_printf(\"\\?\\?\\n\") == printf(\"\\?\\?\\n\"));\n");
	assert(ft_printf("\?\?\n") == printf("\?\?\n"));
	printf("assert(ft_printf(\"\\?\\?\\?\\n\") == printf(\"\\?\\?\\?\\n\"));\n");
	assert(ft_printf("\?\?\?\n") == printf("\?\?\?\n"));
	printf("assert(ft_printf(\"\\? \\?\\n\") == printf(\"\\? \\?\\n\"));\n");
	assert(ft_printf("\? \?\n") == printf("\? \?\n"));

	printf("assert(ft_printf(\"\\?\\n\") == printf(\"\\?\\n\"));\n");
	assert(ft_printf("\?\n") == printf("\?\n"));
	printf("assert(ft_printf(\"\\?\\?\\n\") == printf(\"\\?\\?\\n\"));\n");
	assert(ft_printf("\?\?\n") == printf("\?\?\n"));
	printf("assert(ft_printf(\"\\?\\?\\?\\n\") == printf(\"\\?\\?\\?\\n\"));\n");
	assert(ft_printf("\?\?\?\n") == printf("\?\?\?\n"));
	printf("assert(ft_printf(\"\\? \\?\\n\") == printf(\"\\? \\?\\n\"));\n");
	assert(ft_printf("\? \?\n") == printf("\? \?\n"));

/*
	%% non-existing and %% existing flags
	null strings and null characters
*/

	//char z = '\0';
	char *zero_s;
	if(!(zero_s = (char *)malloc(sizeof(char) * 1)))
		exit(1);
	zero_s[0] = '\0';
	
	printf("assert(ft_printf(\"%%%%a\\n\") == printf(\"%%%%a\\n\"));\n");
	assert(ft_printf("%%a\n") == printf("%%a\n"));
	printf("assert(ft_printf(\"%%%%s\\n\") == printf(\"%%%%s\\n\"));\n");
	assert(ft_printf("%%s\n") == printf("%%s\n"));
	printf("assert(ft_printf(\"%%%%c\\n\") == printf(\"%%%%c\\n\"));\n");
	assert(ft_printf("%%c\n") == printf("%%c\n"));
	printf("assert(ft_printf(\"%%%%i\\n\") == printf(\"%%%%i\\n\"));\n");
	assert(ft_printf("%%i\n") == printf("%%i\n"));
	printf("assert(ft_printf(\"%%%%d\\n\") == printf(\"%%%%d\\n\"));\n");
	assert(ft_printf("%%d\n") == printf("%%d\n"));
	printf("assert(ft_printf(\"%%%%o\\n\") == printf(\"%%%%o\\n\"));\n");
	assert(ft_printf("%%o\n") == printf("%%o\n"));
	printf("assert(ft_printf(\"%%%%u\\n\") == printf(\"%%%%u\\n\"));\n");
	assert(ft_printf("%%u\n") == printf("%%u\n"));
	printf("assert(ft_printf(\"%%%%x\\n\") == printf(\"%%%%x\\n\"));\n");
	assert(ft_printf("%%x\n") == printf("%%x\n"));

	printf("assert(ft_printf(\"%%s\\n\", %s) == printf(\"%%s\\n\", %s));\n", &z, &z);
	assert(ft_printf("%s\n", &z) == printf("%s\n", &z));
	printf("assert(ft_printf(\"%%s%%s\\n\", %s, %s) == printf(\"%%s%%s\\n\", %s, %s));\n", &z, &z, &z, &z);
	assert(ft_printf("%s%s\n", &z, &z) == printf("%s%s\n", &z, &z));
	printf("assert(ft_printf(\"%%s %%s\\n\", %s, %s) == printf(\"%%s %%s\\n\", %s, %s));\n", &z, &z, &z, &z);
	assert(ft_printf("%s %s\n", &z, &z) == printf("%s %s\n", &z, &z));
	printf("assert(ft_printf(\"%%s\\n\", \"\") == printf(\"%%s\\n\", \"\"));\n");
	assert(ft_printf("%s\n", "") == printf("%s\n", ""));
	printf("assert(ft_printf(\"%%s%%s\\n\", \"\", \"\") == printf(\"%%s%%s\\n\", \"\", \"\"));\n");
	assert(ft_printf("%s%s\n", "", "") == printf("%s%s\n", "", ""));
	printf("assert(ft_printf(\"%%s %%s\\n\", \"\", \"\") == printf(\"%%s %%s\\n\", \"\", \"\"));\n");
	assert(ft_printf("%s %s\n", "", "") == printf("%s %s\n", "", ""));
	printf("assert(ft_printf(\"%%s\\n\", %s) == printf(\"%%s\\n\", %s));\n", zero_s, zero_s);
	assert(ft_printf("%s\n", zero_s) == printf("%s\n", zero_s));
	printf("assert(ft_printf(\"%%s%%s\\n\", %s, %s) == printf(\"%%s%%s\\n\", %s, %s));\n", zero_s, zero_s, zero_s, zero_s);
	assert(ft_printf("%s%s\n", zero_s, zero_s) == printf("%s%s\n", zero_s, zero_s));
	printf("assert(ft_printf(\"%%s %%s\\n\", %s, %s) == printf(\"%%s %%s\\n\", %s, %s));\n", zero_s, zero_s, zero_s, zero_s);
	assert(ft_printf("%s %s\n", zero_s, zero_s) == printf("%s %s\n", zero_s, zero_s));
	
//Hand checked these- they now print the correct number of characters and the strings match 
printf("\n*skip*\n");
	printf("assert(ft_printf(\"%%c\\n\", %c) == printf(\"%%c\\n\", %c));\n", z, z);
	assert(ft_printf("%c\n", z) == printf("%c\n", z));
	printf("assert(ft_printf(\"%%c%%c\\n\", %c, %c) == printf(\"%%c%%c\\n\", %c, %c));\n", z, z, z, z);
	assert(ft_printf("%c%c\n", z, z) == printf("%c%c\n", z, z));
	printf("assert(ft_printf(\"%%c %%c\\n\", %c, %c) == printf(\"%%c %%c\\n\", %c, %c));\n", z, z, z, z);
	assert(ft_printf("%c %c\n", z, z) == printf("%c %c\n", z, z));
	printf("assert(ft_printf(\"%%c\\n\", \'\\0\') == printf(\"%%c\\n\", \'\\0\'));\n");
	assert(ft_printf("%c\n", '\0') == printf("%c\n", '\0'));
	printf("assert(ft_printf(\"%%c%%c\\n\", \'\\0\', \'\\0\') == printf(\"%%c%%c\\n\", \'\\0\', \'\\0\'));\n");
	assert(ft_printf("%c%c\n", '\0', '\0') == printf("%c%c\n", '\0', '\0'));
	printf("assert(ft_printf(\"%%c %%c\\n\", \'\\0\', \'\\0\') == printf(\"%%c %%c\\n\", \'\\0\', \'\\0\'));\n");
	assert(ft_printf("%c %c\n", '\0', '\0') == printf("%c %c\n", '\0', '\0'));
	printf("assert(ft_printf(\"%%c\\n\", %c) == printf(\"%%c\\n\", %c));\n", *zero_s, *zero_s);
	assert(ft_printf("%c\n", *zero_s) == printf("%c\n", *zero_s));
	printf("assert(ft_printf(\"%%c%%c\\n\", %c, %c) == printf(\"%%c%%c\\n\", %c, %c));\n", *zero_s, *zero_s, *zero_s, *zero_s);
	assert(ft_printf("%c%c\n", *zero_s, *zero_s) == printf("%c%c\n", *zero_s, *zero_s));
	printf("assert(ft_printf(\"%%c %%c\\n\", %c, %c) == printf(\"%%c %%c\\n\", %c, %c));\n", *zero_s, *zero_s, *zero_s, *zero_s);
	assert(ft_printf("%c %c\n", *zero_s, *zero_s) == printf("%c %c\n", *zero_s, *zero_s));
printf("\n*skip*\n");
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
	printf("assert(ft_printf(\"%%0i\\n\", %0i) == printf(\"%%0i\\n\", %0i));\n", i, i);
	assert(ft_printf("%0i\n", i) == printf("%0i\n", i));
	ft_printf("%0-i\n", i) == printf("%0-i\n", i));
	ft_printf("%-0i\n", i);
*/


/*
	float tests!!!! Project is developing nicely.
*/

/*
float f_l_o_a_t = 0;
float f_l_o_a_t_original;
int random;
srand(time(NULL));

for (int x = 0; x < 100; x++) {
	random = rand() % 50;
	f_l_o_a_t *= -1;
	f_l_o_a_t *= random;
	f_l_o_a_t_original = f_l_o_a_t;
	for (int y = 0; y < 100; y++) {
		if (y < 50) {
			f_l_o_a_t += random;
			f_l_o_a_t += f_l_o_a_t / exponent(numlen(f_l_o_a_t));
			assert(ft_printf("\t\t\tWORD %.15f\n", f_l_o_a_t) == printf("\t\t\tWORD %.15f\n", f_l_o_a_t));
		} else {
			f_l_o_a_t -= random;
			f_l_o_a_t -= f_l_o_a_t / exponent(numlen(f_l_o_a_t));
			assert(ft_printf("\t\t\tWORD %.15f\n", f_l_o_a_t) == printf("\t\t\tWORD %.15f\n", f_l_o_a_t));
		}
		if (y == 50) { f_l_o_a_t = f_l_o_a_t_original; }
	}
}

double f_l_o_a_t2 = 0;
double f_l_o_a_t_original2;
srand(time(NULL));

for (int x = 0; x < 100; x++) {
	random = rand() % 50;
	f_l_o_a_t2 *= -1;
	f_l_o_a_t2 *= random;
	f_l_o_a_t_original2 = f_l_o_a_t2;
	for (int y = 0; y < 100; y++) {
		if (y < 50) {
			f_l_o_a_t2 += random;
			f_l_o_a_t2 += 0.1 * random;
			assert(ft_printf("\t\t\tWORD %.15f\n", f_l_o_a_t2) == printf("\t\t\tWORD %.15f\n", f_l_o_a_t2));
		} else {
			f_l_o_a_t2 -= random;
			f_l_o_a_t2 -= 0.1 * random;
			assert(ft_printf("\t\t\tWORD %.15f\n", f_l_o_a_t2) == printf("\t\t\tWORD %.15f\n", f_l_o_a_t2));
		}
		if (y == 50) { f_l_o_a_t2 = f_l_o_a_t_original2; }
	}
}

long double f_l_o_a_t3 = 0;
long double f_l_o_a_t_original3;

for (int x = 0; x < 100; x++) {
	random = rand() % 50;
	f_l_o_a_t3 *= -1;
	f_l_o_a_t3 *= random;
	f_l_o_a_t_original3 = f_l_o_a_t3;
	for (int y = 0; y < 100; y++) {
		if (y < 50) {
			f_l_o_a_t3 += random;
			f_l_o_a_t3 += 0.1 * random;
			assert(ft_printf("\t\t\tWORD %.15Lf\n", f_l_o_a_t3) == printf("\t\t\tWORD %.15Lf\n", f_l_o_a_t3));
		} else {
			f_l_o_a_t3 -= random;
			f_l_o_a_t3 -= 0.1 * random;
			assert(ft_printf("\t\t\tWORD %.15Lf\n", f_l_o_a_t3) == printf("\t\t\tWORD %.15Lf\n", f_l_o_a_t3));
		}
		if (y == 50) { f_l_o_a_t3 = f_l_o_a_t_original3; }
	}
}
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


	printf("assert(ft_printf(\"%%is\\n\", %is) == printf(\"%%is\\n\", %is));\n", 5, 5);
	assert(ft_printf("%is\n", 5) == printf("%is\n", 5));
	printf("assert(ft_printf(\"%%isabcd\\n\", %isabcd) == printf(\"%%isabcd\\n\", %isabcd));\n", 5, 5);
	assert(ft_printf("%isabcd\n", 5) == printf("%isabcd\n", 5));
	printf("assert(ft_printf(\"%%id\\n\", %id) == printf(\"%%id\\n\", %id));\n", 5, 5);
	assert(ft_printf("%id\n", 5) == printf("%id\n", 5));
	printf("assert(ft_printf(\"%%ix\\n\", %ix) == printf(\"%%ix\\n\", %ix));\n", 5, 5);
	assert(ft_printf("%ix\n", 5) == printf("%ix\n", 5));
	printf("assert(ft_printf(\"%%ii\\n\", %ii) == printf(\"%%ii\\n\", %ii));\n", 5, 5);
	assert(ft_printf("%ii\n", 5) == printf("%ii\n", 5));
	printf("assert(ft_printf(\"%%ip\\n\", %ip) == printf(\"%%ip\\n\", %ip));\n", 5, 5);
	assert(ft_printf("%ip\n", 5) == printf("%ip\n", 5));
	printf("assert(ft_printf(\"%%ic\\n\", %ic) == printf(\"%%ic\\n\", %ic));\n", 5, 5);
	assert(ft_printf("%ic\n", 5) == printf("%ic\n", 5));
	printf("assert(ft_printf(\"%%io\\n\", %io) == printf(\"%%io\\n\", %io));\n", 5, 5);
	assert(ft_printf("%io\n", 5) == printf("%io\n", 5));

	printf("assert(ft_printf(\"%%id%%id\\n\", %id, %id) == printf(\"%%id%%id\\n\", %id, %id));\n", 5, 5, 5, 5);
	assert(ft_printf("%id%id\n", 5, 5) == printf("%id%id\n", 5, 5));
	printf("assert(ft_printf(\"%%ix%%ix\\n\", %ix, %ix) == printf(\"%%ix%%ix\\n\", %ix, %ix));\n", 5, 5, 5, 5);
	assert(ft_printf("%ix%ix\n", 5, 5) == printf("%ix%ix\n", 5, 5));
	printf("assert(ft_printf(\"%%ii%%ii\\n\", %ii, %ii) == printf(\"%%ii%%ii\\n\", %ii, %ii));\n", 5, 5, 5, 5);
	assert(ft_printf("%ii%ii\n", 5, 5) == printf("%ii%ii\n", 5, 5));
	printf("assert(ft_printf(\"%%ip%%ip\\n\", %ip, %ip) == printf(\"%%ip%%ip\\n\", %ip, %ip));\n", 5, 5, 5, 5);
	assert(ft_printf("%ip%ip\n", 5, 5) == printf("%ip%ip\n", 5, 5));
	printf("assert(ft_printf(\"%%ic%%ic\\n\", %ic, %ic) == printf(\"%%ic%%ic\\n\", %ic, %ic));\n", 5, 5, 5, 5);
	assert(ft_printf("%ic%ic\n", 5, 5) == printf("%ic%ic\n", 5, 5));
	printf("assert(ft_printf(\"%%io%%io\\n\", %io, %io) == printf(\"%%io%%io\\n\", %io, %io));\n", 5, 5, 5, 5);
	assert(ft_printf("%io%io\n", 5, 5) == printf("%io%io\n", 5, 5));



	/*
		Tests for size modifiers
			1) %hi
			2) %hhi
			3) %li
			4) %lli
			5) %ho
			6) %hu
			7) %hx
			8) %hX
			9) %hho
			10) %hhu
			11) %hhx
			12) %hhX
			13) %lo
			14) %lu
			15) %lx
			16) %lX
			17) %llo
			18) %llu
			19) %llx
			20) %llX
	*/

	//#1 %hi
	int zero_count = 0;
	for (short i = SHRT_MIN; i <= SHRT_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hi\\n\", %hi) == printf(\"%%hi\\n\", %hi));\n", i, i);
		assert(ft_printf("%hi\n", i) == printf("%hi\n", i));
		if (i == 0)
			++zero_count;
	}

	//#2 %hhi
	zero_count = 0;
	for (char i = CHAR_MIN; i <= CHAR_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hhi\\n\", %hhi) == printf(\"%%hhi\\n\", %hhi));\n", i, i);
		assert(ft_printf("%hhi\n", i) == printf("%hhi\n", i));
		if (i == 0)
			++zero_count;
	}
	
	//#3 %li
	for (long i = 0, y = LONG_MIN; i < 5; i++, y += ((LONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%li\\n\", %li) == printf(\"%%li\\n\", %li));\n", y - 1, y - 1);
		assert(ft_printf("%li\n", y - 1) == printf("%li\n", y - 1));
		printf("assert(ft_printf(\"%%li\\n\", %li) == printf(\"%%li\\n\", %li));\n", y, y);
		assert(ft_printf("%li\n", y) == printf("%li\n", y));
		printf("assert(ft_printf(\"%%li\\n\", %li) == printf(\"%%li\\n\", %li));\n", y + 1, y + 1);
		assert(ft_printf("%li\n", y + 1) == printf("%li\n", y + 1));
	}
	
	//#4 %lli
	for (struct {int i; long long y;} two_vars = {0, LLONG_MIN}; two_vars.i < 5 ; two_vars.i++, two_vars.y += ((LLONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"\\t%%lli\\n\", %lli) == printf(\"\\t%%lli\\n\", %lli));\n", two_vars.y - 1, two_vars.y - 1);
		assert(ft_printf("\t%lli\n", two_vars.y - 1) == printf("\t%lli\n", two_vars.y - 1));
		printf("assert(ft_printf(\"\\t%%lli\\n\", %lli) == printf(\"\\t%%lli\\n\", %lli));\n", two_vars.y, two_vars.y);
		assert(ft_printf("\t%lli\n", two_vars.y) == printf("\t%lli\n", two_vars.y));
		printf("assert(ft_printf(\"\\t%%lli\\n\", %lli) == printf(\"\\t%%lli\\n\", %lli));\n", two_vars.y + 1, two_vars.y + 1);
		assert(ft_printf("\t%lli\n", two_vars.y + 1) == printf("\t%lli\n", two_vars.y + 1));
	}

	//#5 %ho unsigned short
	zero_count = 0;
	for (unsigned short i = 0; i <= USHRT_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%ho\\n\", %ho) == printf(\"%%ho\\n\", %ho));\n", i, i);
		assert(ft_printf("%ho\n", i) == printf("%ho\n", i));
		if (i == 0)
			++zero_count;
	}
	

	//#6 %hu
	zero_count = 0;
	for (unsigned short i = 0; i <= USHRT_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hu\\n\", %hu) == printf(\"%%hu\\n\", %hu));\n", i, i);
		assert(ft_printf("%hu\n", i) == printf("%hu\n", i));
		if (i == 0)
			++zero_count;
	}

	//#7 %hx
	zero_count = 0;
	for (unsigned short i = 0; i <= USHRT_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hx\\n\", %hx) == printf(\"%%hx\\n\", %hx));\n", i, i);
		assert(ft_printf("%hx\n", i) == printf("%hx\n", i));
		if (i == 0)
			++zero_count;
	}

	//#8 %hX
	zero_count = 0;
	for (unsigned short i = 0; i <= USHRT_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hX\\n\", %hX) == printf(\"%%hX\\n\", %hX));\n", i, i);
		assert(ft_printf("%hX\n", i) == printf("%hX\n", i));
		if (i == 0)
			++zero_count;
	}

	//#9 %hho unsigned character
	zero_count = 0;
	for (unsigned char i = 0; i <= UCHAR_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hho\\n\", %hho) == printf(\"%%hho\\n\", %hho));\n", i, i);
		assert(ft_printf("%hho\n", i) == printf("%hho\n", i));
		if (i == 0)
			++zero_count;
	}
	

	//#10 %hhu
	zero_count = 0;
	for (unsigned char i = 0; i <= UCHAR_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hhu\\n\", %hhu) == printf(\"%%hhu\\n\", %hhu));\n", i, i);
		assert(ft_printf("%hhu\n", i) == printf("%hhu\n", i));
		if (i == 0)
			++zero_count;
	}

	//#11 %hhx
	zero_count = 0;
	for (unsigned char i = 0; i <= UCHAR_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hhx\\n\", %hhx) == printf(\"%%hhx\\n\", %hhx));\n", i, i);
		assert(ft_printf("%hhx\n", i) == printf("%hhx\n", i));
		if (i == 0)
			++zero_count;
	}

	//#12 %hhX
	zero_count = 0;
	for (unsigned char i = 0; i <= UCHAR_MAX && zero_count < 2; i++) {
		printf("assert(ft_printf(\"%%hhX\\n\", %hhX) == printf(\"%%hhX\\n\", %hhX));\n", i, i);
		assert(ft_printf("%hhX\n", i) == printf("%hhX\n", i));
		if (i == 0)
			++zero_count;
	}


	//#13 %lo unsigned long
	for (unsigned long i = 0, y = 0; i < 5; i++, y += ((ULONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%lo\\n\", %lo) == printf(\"%%lo\\n\", %lo));\n", y - 1, y - 1);
		assert(ft_printf("%lo\n", y - 1) == printf("%lo\n", y - 1));
		printf("assert(ft_printf(\"%%lo\\n\", %lo) == printf(\"%%lo\\n\", %lo));\n", y, y);
		assert(ft_printf("%lo\n", y) == printf("%lo\n", y));
		printf("assert(ft_printf(\"%%lo\\n\", %lo) == printf(\"%%lo\\n\", %lo));\n", y + 1, y + 1);
		assert(ft_printf("%lo\n", y + 1) == printf("%lo\n", y + 1));
	}

	//#14 %lu unsigned long
	for (unsigned long i = 0, y = 0; i < 5; i++, y += ((ULONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%lu\\n\", %lu) == printf(\"%%lu\\n\", %lu));\n", y - 1, y - 1);
		assert(ft_printf("%lu\n", y - 1) == printf("%lu\n", y - 1));
		printf("assert(ft_printf(\"%%lu\\n\", %lu) == printf(\"%%lu\\n\", %lu));\n", y, y);
		assert(ft_printf("%lu\n", y) == printf("%lu\n", y));
		printf("assert(ft_printf(\"%%lu\\n\", %lu) == printf(\"%%lu\\n\", %lu));\n", y + 1, y + 1);
		assert(ft_printf("%lu\n", y + 1) == printf("%lu\n", y + 1));
	}

	//#15 %lx unsigned long
	for (unsigned long i = 0, y = 0; i < 5; i++, y += ((ULONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%lx\\n\", %lx) == printf(\"%%lx\\n\", %lx));\n", y - 1, y - 1);
		assert(ft_printf("%lx\n", y - 1) == printf("%lx\n", y - 1));
		printf("assert(ft_printf(\"%%lx\\n\", %lx) == printf(\"%%lx\\n\", %lx));\n", y, y);
		assert(ft_printf("%lx\n", y) == printf("%lx\n", y));
		printf("assert(ft_printf(\"%%lx\\n\", %lx) == printf(\"%%lx\\n\", %lx));\n", y + 1, y + 1);
		assert(ft_printf("%lx\n", y + 1) == printf("%lx\n", y + 1));
	}

	//#16 %lX unsigned long
	for (unsigned long i = 0, y = 0; i < 5; i++, y += ((ULONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%lX\\n\", %lX) == printf(\"%%lX\\n\", %lX));\n", y - 1, y - 1);
		assert(ft_printf("%lX\n", y - 1) == printf("%lX\n", y - 1));
		printf("assert(ft_printf(\"%%lX\\n\", %lX) == printf(\"%%lX\\n\", %lX));\n", y, y);
		assert(ft_printf("%lX\n", y) == printf("%lX\n", y));
		printf("assert(ft_printf(\"%%lX\\n\", %lX) == printf(\"%%lX\\n\", %lX));\n", y + 1, y + 1);
		assert(ft_printf("%lX\n", y + 1) == printf("%lX\n", y + 1));
	}

	//#17 %llo unsigned long long 
	for (unsigned long long i = 0, y = 0; i < 5; i++, y += ((ULONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%llo\\n\", %llo) == printf(\"%%llo\\n\", %llo));\n", y - 1, y - 1);
		assert(ft_printf("%llo\n", y - 1) == printf("%llo\n", y - 1));
		printf("assert(ft_printf(\"%%llo\\n\", %llo) == printf(\"%%llo\\n\", %llo));\n", y, y);
		assert(ft_printf("%llo\n", y) == printf("%llo\n", y));
		printf("assert(ft_printf(\"%%llo\\n\", %llo) == printf(\"%%llo\\n\", %llo));\n", y + 1, y + 1);
		assert(ft_printf("%llo\n", y + 1) == printf("%llo\n", y + 1));
	}

	//#18 %llu unsigned long long 
	for (unsigned long long i = 0, y = 0; i < 5; i++, y += ((ULONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%llu\\n\", %llu) == printf(\"%%llu\\n\", %llu));\n", y - 1, y - 1);
		assert(ft_printf("%llu\n", y - 1) == printf("%llu\n", y - 1));
		printf("assert(ft_printf(\"%%llu\\n\", %llu) == printf(\"%%llu\\n\", %llu));\n", y, y);
		assert(ft_printf("%llu\n", y) == printf("%llu\n", y));
		printf("assert(ft_printf(\"%%llu\\n\", %llu) == printf(\"%%llu\\n\", %llu));\n", y + 1, y + 1);
		assert(ft_printf("%llu\n", y + 1) == printf("%llu\n", y + 1));
	}
	
	//#19 %llx unsigned long long 
	for (unsigned long long i = 0, y = 0; i < 5; i++, y += ((ULONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%llx\\n\", %llx) == printf(\"%%llx\\n\", %llx));\n", y - 1, y - 1);
		assert(ft_printf("%llx\n", y - 1) == printf("%llx\n", y - 1));
		printf("assert(ft_printf(\"%%llx\\n\", %llx) == printf(\"%%llx\\n\", %llx));\n", y, y);
		assert(ft_printf("%llx\n", y) == printf("%llx\n", y));
		printf("assert(ft_printf(\"%%llx\\n\", %llx) == printf(\"%%llx\\n\", %llx));\n", y + 1, y + 1);
		assert(ft_printf("%llx\n", y + 1) == printf("%llx\n", y + 1));
	}

	//#20 %llX unsigned long long 
	for (unsigned long long i = 0, y = 0; i < 5; i++, y += ((ULONG_MAX / 2) + 1)) {
		printf("assert(ft_printf(\"%%llX\\n\", %llX) == printf(\"%%llX\\n\", %llX));\n", y - 1, y - 1);
		assert(ft_printf("%llX\n", y - 1) == printf("%llX\n", y - 1));
		printf("assert(ft_printf(\"%%llX\\n\", %llX) == printf(\"%%llX\\n\", %llX));\n", y, y);
		assert(ft_printf("%llX\n", y) == printf("%llX\n", y));
		printf("assert(ft_printf(\"%%llX\\n\", %llX) == printf(\"%%llX\\n\", %llX));\n", y + 1, y + 1);
		assert(ft_printf("%llX\n", y + 1) == printf("%llX\n", y + 1));
	}




	//Successfully passed tests message:
	printf("\n\n\t\t##########################################\n\t\t#  Congratulations!!! All Tests Passed!  #\n\t\t##########################################\n\n\n");

	return (0);
}
