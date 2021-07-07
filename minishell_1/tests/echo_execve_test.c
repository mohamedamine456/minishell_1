# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		printf("argv[%d] : %s\n", i, argv[i]);
		i++;
	}
	exit(EXIT_SUCCESS);
}
