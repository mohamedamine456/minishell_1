# include <stdio.h>
# include "../libft/libft.h"

int main()
{
	char *str;
	char *new;

	str = ft_strdup("   hello world  blabla    b");
	new = remove_spaces(str);
	printf("%s", new);
}