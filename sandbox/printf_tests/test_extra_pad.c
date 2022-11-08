
#include <stdio.h>


int	main()
{
	printf("%i\n", 5);
	printf("% i\n", 5);
	printf("% 2i\n", 5);
	printf("% *i\n", 2, 5);
	printf("% 3i\n", 5);
	printf("% *i\n", 3, 5);	

	printf("%i\n", 5);
	printf("% i\n", 5);
	printf("% .2i\n", 5);
	printf("% .*i\n", 2, 5);
	printf("% .3i\n", 5);
	printf("% .*i\n", 3, 5);	

	printf("%i\n", -5);
	printf("% i\n", -5);
	printf("% 2i\n", -5);
	printf("% *i\n", 2, -5);
	printf("% 3i\n", -5);
	printf("% *i\n", 3, -5);	

	printf("% *i\n", 0, -5);

	printf("%01i\n", -5);
	printf("%02i\n", -5);
	printf("%03i\n", -5);

	printf("%0*f\n", -10, 3.14);


	return (0);
}
