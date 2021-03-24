#include "check_functions.h"

/*
* this function to check if the given string is an option or not
*/

int		is_option(char *str, char *name)
{
	int		i;

	i = 1;
	if (!ft_strcmp(clean_str(ft_strdup(name)), "echo") && !ft_strcmp(clean_str(ft_strdup(str)), "-n"))
		return (1);
    else if (!ft_strcmp(clean_str(ft_strdup(name)), "export") && !ft_strcmp(clean_str(ft_strdup(str)), "-p"))
        return (1);
    else if (!ft_strcmp(clean_str(ft_strdup(name)), "unset") && (!ft_strcmp(clean_str(ft_strdup(str)), "-f") || !ft_strcmp(clean_str(ft_strdup(str)), "-v")))
        return (1);
	return (0);
}
