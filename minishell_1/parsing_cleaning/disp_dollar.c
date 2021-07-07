# include "parsing_cleaning.h"

char	*special_char(char *str, int *i)
{
	char	*new_str;
	char	*tmp;
	char	*variable;

	new_str = ft_substr(str, 0, *i);
	tmp = ft_substr(str, *i + 2, ft_strlen(str) - *i - 2);
	//variable = special_variable(str[*i + 1]);
	new_str = ft_strjoin(new_str, variable);
	new_str = ft_strjoin(new_str, tmp);
	free(str);
	free(tmp);
	*i += ft_strlen(variable) - 1;
	free(variable);
	return(new_str);
}

char	*alpha_char(char *str, int *i)
{
	int		j;
	char	*new_str;
	char	*tmp;

	j = 1;
	while (str[*i + j] != '\0')
	{
		if (!ft_isalnum(str[*i + j]))
			break ;
		j++;
	}
	new_str = ft_substr(str, 0, *i);
	tmp = ft_substr(str, *i + 1	, j);
	tmp = search_env(tmp, NULL);		//replace NULL with envp variables
	if (tmp == NULL)
		tmp = ft_strdup("");
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	tmp = ft_substr(str, *i + j + 1, ft_strlen(str) - *i - j - 1);
	new_str = ft_strjoin(new_str, tmp);
	// free them all
	free(str);
	free(tmp);
	return (new_str);

}

char	*digit_char(char *str, int *i)
{
	char	*new_str;
	char	*tmp;
	char	*variable;

	new_str = ft_substr(str, 0, *i);
	tmp = ft_substr(str, *i + 2, ft_strlen(str) - *i - 2);
	//variable = digit_variable([*i + 1]);
	new_str = ft_strjoin(new_str, variable);
	new_str = ft_strjoin(new_str, tmp);
	free(str);
	free(tmp);
	*i += ft_strlen(variable) - 1;
	free(variable);
	return(new_str);
}
