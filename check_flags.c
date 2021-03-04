#include "minishell.h"

/*
*	This function to check if there is a '\' before ';' or not
*/

int		check_bs(char *line, int i)
{
	if (i == 0)
		return (0);
	else
	{
		if (line[i - 1] == '\\')
			return(1);
		else
			return (0);
	}
}