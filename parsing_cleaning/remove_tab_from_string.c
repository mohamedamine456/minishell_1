# include "../minishell.h"

/**
 * This function takes a string and atable of strings and remove elements of the table from the string
*/

char	*remove_tab_from_string(char *str, char **tab)
{
	int	i;
	int	j;
	int	k;
	char	*new;
	char	*tmp;

	if (str != NULL && tab != NULL)
	{
		k = 0;
		i = 0;
		new = ft_strdup("");
		while (tab[k] != NULL)
		{
			j = ft_strstri(str + i, tab[k]);
			if (j >= 0)
			{
				tmp = ft_substr(str, i, j);
				new = ft_strjoin(new, tmp);
				free(tmp);
				i += j + ft_strlen(tab[k]);
			}
			k++;
		}
		tmp = ft_substr(str, i, ft_strlen(str) - i);
		new = ft_strjoin(new, tmp);
		free(tmp);
		free(str);
		return (new);
	}
	return (str);
}