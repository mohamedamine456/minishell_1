# include "parsing_cleaning.h"

char        *replace_str(char *str, char **envp)
{
    char    *new_str;

	new_str = NULL;
	if (str == NULL || envp == NULL)
		return (NULL);
	new_str = trim_replace(str, NULL);
	free(str);
    return (new_str);
}

char	*trim_replace(char *str, char **envp)
{
	t_flags	fl;
	int		i;
	char	*(*func[])(char *, int *) = {special_char, alpha_char, digit_char};

	fl = (t_flags){0, 0, 0, 0, 0, 0};
	i = 0;
	while (str[i] != '\0')
	{
		fl = check_flags(fl, str[i]);
		if (fl.s_q % 2 == 0 && fl.b_s == 0 && str[i] == '$')
		{
			if (ft_isalnum(str[i + 1]) || char_in_string(str[i + 1], "#?*@"))
				str = func[char_to_func(str[i + 1])](str, &i);
		}
		i++;
	}
	return (str);
}

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
	free(str);
	return (new_str);
}
