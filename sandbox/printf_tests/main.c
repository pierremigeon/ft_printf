#include <stdio.h>
#include <limits.h>


/* NOTES OF THINGS LEARNED:


	1) %d and %i are one and the same in printf
	2) This is true even when inputing hex/octal values
	3) Zero padding wins over space padding. 
	4) This means a width of 4 and an value 11 int and padding of 2 will print "0011"
	4) Zero padding is only ever left padding
	5) Space padding can be both left or right padded
	6) %-5i will give right padding to min width of 5 
	7) %5i will give left padding to min width of 5
	8) %0.5i will give zeros left padding


*/


int	main()
{
	int	a;

	a = -500;

	int	i = 5;
	float	f = 5.78;
	float	f2 = 0.78;
	float	f3 = 0;
	char	c = 'a';
	char	*s = "yolo";
	long	l = INT_MAX;

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

	// print a pointer address and then add spaces to it:

	printf("%p\n", s);
	printf("%15p\n", s);
	printf("%#15x\n", (unsigned int)5000050);
	
	printf("%10.5i\n", 500);

	printf("%p\n", NULL);
        printf("%p\n", NULL + 1);
        printf("%p\n", NULL + 3);
        printf("%p\n", NULL + 100);
        printf("%p\n", NULL + 1000);
        printf("%p\n", NULL + 10000);
        printf("%p\n", NULL + 100000);
        printf("%p\n", NULL + 1000000);
        printf("%p\n", NULL + 10000000);
        printf("%p\n", NULL + 100000000);
        printf("%p\n", NULL + 1000000000);
        printf("%p\n", NULL + 10000000000);
        printf("%p\n", NULL + 100000000000);
        printf("%p\n", NULL + 1000000000000);
        printf("%p\n", NULL + 10000000000000);
        printf("%p\n", NULL + 100000000000000);
        printf("%p\n", NULL + 1000000000000000);
        printf("%p\n", NULL + 10000000000000000);
        printf("%p\n", NULL + 100000000000000000);
	//printf("%-05i\n", 10);
	printf("%i\n", 033);
	printf("%d\n", 033);
	printf("%-10.4iP\n", 033);
	printf("%-4.4iP\n", 033);
	printf("%-5.4iQ\n", 033);
	printf("%0.4iX\n", 033);
	

	//Strings don't ever seem to be zero-paddable. You can pad them with spaces before and after and use width specifier. 
	printf("%.7sP\n", s);
	//What is this? When you use a %.s nothing is printed for the string. 
	printf("%.sP\n", s);
	//It doesn't do this when you try it with an %i format conversion flag:
	printf("%.iP\n", 55);

	printf("%-4.6i\n", i);
	printf("%4.6i\n", i);
	
	printf("%6.4i\n", i);
	printf("%6.2i\n", i);
	
	printf("%i\n", -i);
	printf("%+.*i\n", 5, -5);
	printf("%+*i\n", 5, -5);
	printf("%-*iP\n", 5, -5);
	printf("%+*i\n", 5, 5);
	printf("%-i\n", 5);
	printf("%+i\n", 5);
	printf("% i\n", 5);
	printf("% i\n", -5);	
	printf("% .2i\n", 5);
	printf("% 2i\n", 5);
	printf("% 5.2i\n", 5);
	printf("% 5.2i\n", -5);
	printf("%-5.2i\n", -5);


	printf("%c\n", -1);
	//printf("% c\n", c);
	//printf("%5.5c\n", c);
	//printf("%.*c\n", 5, c);


	//String stuff
	printf("%s\n", s);
	printf("%.2s\n", s);
	printf("%5s\n", s);
	printf("%5.2s\n", s);
	printf("%.10s\n", s);
	printf("%.0s\n", s);

	printf("%6.4s\n", s);
	printf("%0*d\n", i, i);

	printf("%-6.2sP\n", s);
	printf("%-6.10sP\n", s);

//Strings %s not compatible with ' '+0 flags

	printf("%*.2sP\n", i, s);
	printf("%*.10sP\n", i, s);
	
	printf("%.*sP\n", i, s);
	printf("%.*sP\n", i, s);

	printf("%05i\n", 5);
	printf("%08.6i\n", 5);
	
	printf("%0.*d\n", 0,0);
	printf("%1.2i\n", 0);
	printf("%+0.0iP\n", 0);
	printf("%0.1i\n", 0);
	printf("%0.2i\n", 0);
	printf("%1.0i\n", 0);
	printf("%1.1i\n", 0);
	printf("%1.2i\n", 0);
	printf("%1.1i\n", 1);
	printf("%1.2i\n", 1);
	printf("%1.3i\n", 1);

	printf("%i\n", 0);
	printf("%5.0i\n", 0);
	printf("% 5.0i\n", 0);
		
	printf("%-f\n", f);
	printf("% f\n", f);
	printf("%+f\n", f);
	printf("%0f\n", f);
	printf("%f\n", f);
	printf("%#f\n", f);

	printf("%-10.2fQ\n", f);
	printf("%10.2fQ\n", f);
	
	//Can characters have padding and the like?
	printf("%c\n", c);
	printf("%5c\n", c);
	printf("%-5cP\n", c);
	printf("%5c\n", c);

	//zero with zero padding prints nothing
	printf("%.0i\n", 0);

	// experimenting with what float output is like: what about float output of zero?
	printf("%05.1f\n", f3);
	printf("%05.2f\n", f3);
	printf("%-5.1f\n", f3);
	printf("%-5.2f\n", f3);
	
	printf("%f\n", f3);

	//down-casting from long to int, does this cause overflow?
	printf("%i\n", (int)(l + 1));


	return (0);
}
