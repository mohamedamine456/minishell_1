#include "check_functions.h"

/*
* this function to check if the given string is an option or not
*/

int		is_option(char *str, char *name)
{
	int		i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_strcmp("echo", clean_str(ft_strdup(name))) && !char_in_string(str[i], ECHO_OPTIONS))
			return (0);
		else if (!ft_strcmp("pwd", clean_str(ft_strdup(name))) && !char_in_string(str[i], PWD_OPTIONS))
			return (0);
		else if (!ft_strcmp("env", clean_str(ft_strdup(name))) && !char_in_string(str[i], ENV_OPTIONS))
			return (0);
		i++;
	}
	return (1);
}
