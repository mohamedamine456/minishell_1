# include "parsing_cleaning.h"

char        *replace_str(char *str, char **envp)
{
    char    *new_str;
	char	*tmp_env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_str = NULL;
	if (str == NULL || envp == NULL)
		return (NULL);
    new_str = search_env(str, envp);
    if (new_str == NULL)
		new_str = ft_strdup("");
	free(str);
    return (new_str);
}

/*
 * char	*trim_env(char *str, int *i, int *j)
{
	t_flags	fl;
	char	*tmp;

	fl = (t_flags){0, 0, 0, 0, 0, 0};
	while (str[*i + *j] != '\0')
	{
		fl = check_flags(fl, str[*i]);
		if (fl.s_q % 2 == 0 && fl.b_s == 0 && str[*i] == '$')
		{
			(*j)++;
			while (str[*j + *i] != '\0')
			{
				if (!ft_isalnum(str[*i + *j]))
				{
					tmp = ft_substr(str, *i, *j);
					return (tmp);
				}
				(*j)++;
			}
		}
		(*i)++;
	}
	return (ft_strdup(""));
}
*/

char	*search_env(char *str, char **envp)
{
	int		i;
	char	*new_str;
	char	**tab;

	i = 0;
	tab = NULL;
	new_str = NULL;
	if (str == NULL || envp == NULL)
		return (NULL);
	while (envp[i] != NULL)
	{
		tab = ft_split(envp[i], '=');
		if (tab != NULL && tab[0] != NULL)
		{
			if (!ft_strcmp(str, tab[0]))
			{
				new_str = ft_substr(envp[i], ft_strlen(tab[0]) + 1, ft_strlen(envp[i]) - ft_strlen(tab[0]) - 1);
				ft_free_args(tab);
				break ;
			}
			ft_free_args(tab);
		}
		i++;
	}
	return (new_str);
}
