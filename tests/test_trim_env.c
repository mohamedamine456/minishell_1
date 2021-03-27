# include <stdio.h>
# include "../parsing_cleaning/parsing_cleaning.h"

int main()
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = trim_env("$3r", &i, &j);
	printf("str = %s, i = %d, j = %d", str, i, j);
	return (0);
}
