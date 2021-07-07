#include "check_functions.h"

/**
 * This function to check if there is a redirection inside a string and return index
*/

int		check_redirection(char *str, int len)
{
	int		i;
	t_flags	fl;

	i = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == '\\' && fl.d_q % 2 == 0 && fl.s_q % 2 == 0)
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (str[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
			fl.d_q++;
		if (str[i] == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
			fl.s_q++;
		if (fl.d_q % 2 == 0 && fl.s_q % 2 == 0 && fl.b_s == 0)
		{
			if (str[i] == '>' || str[i] == '<')
				return (i + 1);
		}
		i++;
	}
	return (i + 1);
}