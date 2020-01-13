

#include <unistd.h>


void	putnbr_oct(int i)
{
	char out;

	if (i > 7)
		putnbr_oct(i / 8);
	out = '0' + i % 8;	
	write(1, &out, 1);
}

int	main()
{
	putnbr_oct(500);
	return (0);
}
