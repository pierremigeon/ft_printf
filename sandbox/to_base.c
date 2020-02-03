
#include <unistd.h>

void	to_base(int val, int base)
{
	int	out;

	if (val >= base)
		to_base(val / base, base);
	out = (val % base >= 10) ? 'a' + val % base % 10 : '0' + val % base;
	write(1, &out, 1);
}

int	main()
{
	int val;

	val = 10;
	to_base(val, 16);
	write(1, "\n", 1);

	val = 15;
        to_base(val, 16);
        write(1, "\n", 1);

        val = 16;
        to_base(val, 16);
        write(1, "\n", 1);

	return (0);
}
