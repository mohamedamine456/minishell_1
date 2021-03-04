#include <stdio.h>
# include "libft/libft.h"
# include "allocation_functions.c"

int main()
{
	char **tab;
	tab = allocat_tab();
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	tab = resize_tab(tab, "hello");
	tab = resize_tab(tab, "world");
	if (tab[0] == NULL)
		printf("non %d", ft_size_args(tab));
	else
		printf("yes %d", ft_size_args(tab));
}