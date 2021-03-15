#include "check_functions.h"

/*
*	This function to check if there is a '\' before ';' or not
*/

int		is_flag(char c)
{
	if (c == '\\' || c == ';' || c == '\'' || c == '|' || c == '\"' || c == '$')
		return (1);
	return (0);
}


t_flags		check_flags(t_flags fl, char c)
{
	if (c == '\\' && fl.s_q % 2 == 0)
	{
		if (fl.b_s == 1)
			fl.b_s = 0;
		else
			fl.b_s = 1;
	}
	if (c == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
		fl.d_q++;
	if (c == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
		fl.s_q++;
	return (fl);
}

t_flags		clean_flags(t_flags fl, char c)
{
	if (c == '\\' && fl.s_q == 0)
	{
		if (fl.b_s == 1)
			fl.b_s = 0;
		else
			fl.b_s = 1;
	}
	if (c == '\'')
	{
		if ((fl.b_s == 0 && fl.d_q == 0) || fl.s_q == 0)
			fl.s_q = 1;
		else
			fl.s_q = 0;
	}
	if (c == '\"')
	{
		if ((fl.b_s == 0 && fl.s_q == 0) || fl.d_q == 0)
			fl.d_q = 1;
		else
			fl.d_q = 0;
	}
	return (fl);
}