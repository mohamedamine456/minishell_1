# include "libft.h"

t_flags		check_flags(t_flags fl, char c)
{
	if (c == '\\')
			fl.b_s = fl.b_s == 1 ? 0 : 1;
	if (c == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
		fl.d_q++;
	if (c == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
		fl.s_q++;
	return (fl);
}