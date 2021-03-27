# include "parsing_cleaning.h"

char        *replace_str(char *str, char **envp)
{
    char    *new_str;

	new_str = NULL;
	if (str == NULL || envp == NULL)
		return (NULL);
    new_str = search_env(str, envp);
    if (new_str == NULL)
		new_str = ft_strdup("");
	free(str);
    return (new_str);
}

char	*search_env(char *str, char **envp)
{
	int		i;
	char	*new_str;
	char	**tab;

	i = 0;
	tab = NULL;
	while (envp[i]!= NULL)
	{
		tab = ft_split(envp[i], '=');
		if (tab != NULL && tab[0] != NULL)
		{
			if (!ft_strcmp(str, tab[0]))
			{
				new_str = ft_substr(envp[i], ft_strlen(tab[0]) + 1, ft_strlen(envp[i]) - ft_strlen(tab[0]) - 1);
				ft_free_args(tab);
				return (new_str);
			}
		}
		i++;
	}
	return (NULL);
}
