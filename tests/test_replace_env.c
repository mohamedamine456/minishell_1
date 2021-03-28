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
	tmp = search_env(tmp, envp);		//replace NULL with envp variables
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	tmp = ft_substr(str, *i + j + 1, ft_strlen(str) - *i - j - 1);
	new_str = ft_strjoin(new_str, tmp);
	// free them all
	return (new_str);

}

int main(int argv, char **argc, char **envp)
{
	char	*str;
	int		i;

	i = 25;
	str = alpha_char_test(ft_strdup("hello world$LESS  fjkdhsf$PATH"), &i, envp);
	printf("%s\n", str);
	//free(str);
	while (1)
	{
		continue ;
	}	
	return (0);
}
