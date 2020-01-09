#include <unistd.h>

void    pm_putnbr_hex(int i)//, int case)
{
	char out;

	if (i > 16)
		pm_putnbr_hex(i / 16);
	out = (i % 16 < 10) ? '0' + i % 16 : 'a' + i % 16 % 10;
	write(1, &out, 1);
	i /= 16;
}

/*
123456789 10 11 12 13 14 15 16  17  18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42
123456789 a  b  c  d  e  f  10  11  12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f 20 21 22 23 24 25 26 27 28 29 2a

32 = 20
32 / 16 = 2
32 % 16 = 0

33 = 21
33 / 16 = 2
33 % 16 = 1

42 = 2a
42 / 16 = 2
42 % 16 = a
*/

void	pm_putnbr_bin(int i)
{
	if (i == 0)
		return;
	pm_putnbr_bin(i / 2);
	if (i % 2)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main()
{
	//pm_putnbr_bin(26);
	//pm_putnbr_bin(15);
	pm_putnbr_hex(32);
	write(1, "\n", 1);
	pm_putnbr_hex(33);
	write(1, "\n", 1);
	pm_putnbr_hex(42);
	write(1, "\n", 1);
	pm_putnbr_hex(500);
	write(1, "\n", 1);
	return (0);
}
