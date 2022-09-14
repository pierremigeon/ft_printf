

#include <stdio.h>


int	main()
{
	int i = 5;
	float x = 5.1;

	//test to see if multiple zero flags can be used (spoiler, they can!)
	printf("%00005i\n", i);

	//test to see if you can have zero precision:
	printf("%f\n", x);

	//test to see if you need to have the numbers next to the period:
	//printf("%500.+10", x);    <-- fails

	printf("%500.*f", i, x);

	return (0);
}
