# include "../libft/libft.h"
# include "../parsing_cleaning/parsing_cleaning.h"
# include "../check_functions/check_functions.h"
# include <stdio.h>

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

char	*alpha_char_test(char *str, int *i, char **envp)
{
	int		j;
	char	*new_str;
	char	*tmp;

	j = 0;
	while (str[*i + j + 1] != '\0')
	{
		if (!ft_isalnum(str[*i + j + 1]))
			break ;
		j++;
	}
	new_str = ft_substr(str, 0, *i);
	tmp = ft_substr(str, *i + 1	, j);
	tmp = search_env(tmp, envp);
	if (tmp == NULL)
		tmp = ft_strdup("");
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	tmp = ft_substr(str, *i + j + 1, ft_strlen(str) - *i - j - 1);
	new_str = ft_strjoin(new_str, tmp);
	// free them all
	free(tmp);
	free(str);
	return (new_str);

}

char	*trim_replace(char *str, char **envp)
{
	t_flags	fl;
	int		i;
	//char	*(*func[])(char *, int *) = {special_char, alpha_char, digit_char};

	fl = (t_flags){0, 0, 0, 0, 0, 0};
	i = 0;
	while (str[i] != '\0')
	{
		fl = check_flags(fl, str[i]);
		if (fl.s_q % 2 == 0 && fl.b_s == 0 && str[i] == '$')
		{
			if (ft_isalnum(str[i + 1]) || char_in_string(str[i + 1], "#?*@"))
				str = alpha_char_test(str, &i, envp);
		}
		i++;
	}
	return (str);
}

int main(int argv, char **argc, char **envp)
{
	char	*str;
	int		i;

	i = 25;
	str = trim_replace(ft_strdup("$ $ADMIN $LESS$USER$PATH$LESS$USER"), envp);
	printf("%s\n", str);
	//free(str);
	while (1)
	{
		continue ;
	}	
	return (0);
}
