
#include <stdio.h>


int	main()
{

	double f = 3.14;

	printf("%f\n", f);
	printf("%.1f\n", f);
	printf("%.2f\n", f);
	printf("%.3f\n", f);
	printf("%0.0f\n", f);
	printf("%0.1f\n", f);
	printf("%0.2f\n", f);
	printf("%0.3f\n", f);
	printf("%1.0f\n", f);
	printf("%1.1f\n", f);
	printf("%1.2f\n", f);
	printf("%1.3f\n", f);
	printf("%2.0f\n", f);
	printf("%2.1f\n", f);
	printf("%2.2f\n", f);
	printf("%2.3f\n", f);
	printf("%3.0f\n", f);
	printf("%3.1f\n", f);
	printf("%3.2f\n", f);
	printf("%3.3f\n", f);
	
	printf("%4.0f\n", f);
	printf("%4.1f\n", f);
	printf("%4.2f\n", f);
	printf("%4.3f\n", f);

	printf("%-4.0fP\n", f);
	printf("%-4.1fP\n", f);
	printf("%-4.2fP\n", f);
	printf("%-4.3fP\n", f);
	
	printf("%9f\n", f);

	return (0);
}
