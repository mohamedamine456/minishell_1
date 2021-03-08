# include "libft.h"

int		next_space(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			return (i);
		i++;
	}
	return (i);
}