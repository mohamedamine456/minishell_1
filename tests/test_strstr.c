# include <stdio.h>
# include "../libft/libft.h"

int main()
{
	char *str1, *str2, *str3;

	str1 = ft_strdup("Hello World, Good Morning, blabla blala");
	str2 = ft_strdup("blala");

	str3 = ft_strstr(str1, str2);
	printf("%s", str3);
}