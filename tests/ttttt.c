#include <stdio.h>
# include "../libft/libft.h"
# include "../allocation_functions.c"

int main()
{
	char **tab;
	tab = NULL;
	tab = resize_tab(tab, ft_strdup("hello"));
	tab = resize_tab(tab, ft_strdup("world"));
	tab = resize_tab(tab, ft_strdup("good"));
	tab = resize_tab(tab, ft_strdup("Morning"));
	tab = resize_tab(tab, ft_strdup("HI"));
	tab = resize_tab(tab, ft_strdup("Hey"));
	tab = resize_tab(tab, ft_strdup("hello"));
	tab = resize_tab(tab, ft_strdup("world"));
	tab = resize_tab(tab, ft_strdup("Morning"));
	tab = resize_tab(tab, ft_strdup("world"));
	printf("%s\n", remove_tab_from_string(ft_strdup("Good Morning Hello Where Are You going Hi , hello world"), tab));
	printf("Hello\n");
	sleep(10);
	// tab = resize_tab(tab, ft_strdup("Morning"));
	// tab = resize_tab(tab, ft_strdup("world"));
	// tab = resize_tab(tab, ft_strdup("Hello"));
	// tab = resize_tab(tab, ft_strdup("world"));
	// tab = resize_tab(tab, ft_strdup("Morning"));
	// tab = resize_tab(tab, ft_strdup("world"));
	// tab = resize_tab(tab, ft_strdup("hello"));
	// tab = resize_tab(tab, ft_strdup("Hi"));
	// tab = resize_tab(tab, ft_strdup("hello"));
	// tab = resize_tab(tab, ft_strdup("world"));
	// if (tab[0] == NULL)
	// 	printf("non %d", ft_size_args(tab));
	// else
	// 	printf("yes %d", ft_size_args(tab));
	// char *str;
	// int i = 0;
	// int	bs = 0;

	// str = ft_strdup("Hello \' \" \\ World");
	// while (str[i] != '\0')
	// {
	// 	if (str[i] == '\\')
	// 	{
	// 		if (bs == 1)
	// 			bs = 0;
	// 		else
	// 			bs = 1;
	// 	}
	// 	if ((str[i] == '\'' || str[i] == '\"' || str[i] == '\\') && bs == 1)
	// 	{
	// 		bs = 0;
	// 		str = ft_strdup(ft_memmove(str - 1, str, ft_strlen(str) - 1));
	// 	}
	// 	i++;
	// }
	// printf("%s", str);
	// sleep(20);
	// free(str);
	// sleep(20);
}