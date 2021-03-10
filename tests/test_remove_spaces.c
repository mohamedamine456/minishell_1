# include <stdio.h>
# include "../libft/libft.h"

int main()
{
	char *str;
	char *new;

	str = ft_strdup("e            v   t   w ff fqw        f");
	new = remove_spaces(str);
	free(NULL);
	printf("%s", new);
}