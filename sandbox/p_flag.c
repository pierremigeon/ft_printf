
#include <stdio.h>










int	main()
{
	char *string = "This is a string";

	for (int i = 0; i < 5; i++)
		printf("string is %s and %p\n", string, string);
	printf("addres is %x", (unsigned int)string);
	return (0);
}
