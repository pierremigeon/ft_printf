#include "../../libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>

void	free_strings(char **s, int x)
{
	for (int i = 0; i < x; i++) {
		free(s[i]);
		s[i] = NULL;
	}
}

int	check_equal(char **strings)
{
	int	check;

	check = ft_strcmp(strings[1], strings[2]);
	return (!(check));
}

char	**init_compare(int i)
{
	char **out;

	if (!(out = (char **)malloc(sizeof(char *) * i)))
		exit(1);
	for (int x = 0; x < i; x++) {
		out[x] = NULL;
	}
	return (out);
}

int	main()
{
	int	fd;
	int	r;
	char 	**compare;
	int	i;
	int	correct;
	int	wrong;
	int	skip;

	correct = wrong = i = skip = 0;
	compare = init_compare(3);
	fd = open("assert_test_output_filtered.txt", O_RDONLY);	
	if (fd == -1)
		if (printf("ERROR: NO INPUT FILE FOUND!\n"))
			exit(1);
	while ((r = get_next_line(fd, &compare[i]) > 0))
	{
		if (!(ft_strcmp(compare[i], "*skip*")))
			if ((!skip && (skip = 1) || skip && !(skip = 0) && (i = -1)))
				free_strings(compare, 1);
		if (compare[1] && compare[2])
		{
			if(check_equal(compare))
				correct++;
			else
			{
				printf("%s\n%s\n%s\n", compare[0], compare[1], compare[2]);
				wrong++;
			}
			free_strings(compare, 3);
		}
		if (skip)
			i = -1;
		i = (i < 2) ? i + 1 : 0;
	}
	if (wrong == 0)
			printf("\n\n\t\t##########################################\n\t\t#  Congratulations!!! All Tests Passed!  #\n\t\t##########################################\n\n\n");
	//print summary statistics
	printf("Correct is %i and incorrect is %i\n", correct, wrong);
	close(fd);
	return (0);
}
