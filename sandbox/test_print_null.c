
#include <unistd.h>

int	main()
{
	write(1, "\0", 1);
	write( 1, "\n", 1);
	return (0);
}
