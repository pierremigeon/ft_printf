
#include <stdio.h>

int	main()
{

	unsigned char c;
	char c2 = 'A';

	c = 0;
	
	printf("%hhd\n", c2++);

	while (c > 0)
	{
		printf("%hhX\n", c++);
	}


	return (0);
}
