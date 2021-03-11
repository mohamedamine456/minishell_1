# include "../libft/libft.h"

int main()
{
	char **tab;

	tab = ft_split_white_spaces("echo \"Hello World\" > file \"good morning\"");
	int	i = 0;

	while (tab[i] != NULL)
	{
		printf("|%s| - ", tab[i]);
		i++;
	}
}