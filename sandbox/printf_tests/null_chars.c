
#include <stdio.h>


int	main()
{
	char z = '\0';
	printf("assert(ft_printf(\"%%c\\n\", %c) == printf(\"%%c\\n\", %c));\n", z, z);

	return (0);
}
