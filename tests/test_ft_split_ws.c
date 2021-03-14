# include "../libft/libft.h"

int main()
{
	char **tab;

	tab = ft_split_white_spaces("echo \"\\\" + 5");
	int	i = 0;

	while (tab[i] != NULL)
	{
		printf("|%s| - ", tab[i]);
		i++;
	}
	ft_free_args(tab);
	printf("Hello End");
	sleep(10);
}