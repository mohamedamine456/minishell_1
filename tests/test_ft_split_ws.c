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
}