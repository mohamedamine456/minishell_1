#include "minishell.h"

/*
*	This function to check if there is a '\' before ';' or not
*/

int		is_flag(char c)
{
	if (c == '\\' || c == ';' || c == '\'' || c == '|' || c == '\"')
		return (1);
	return (0);
}