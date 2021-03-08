# include "libft.h"

int		next_space(char *str)
{
	int		i;
	t_flags	fl;

	i = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (str[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
			fl.d_q++;
		if (str[i] == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
			fl.s_q++;
		if (str[i] == ' ' && fl.s_q % 2 == 0 && fl.d_q % 2 == 0 && fl.b_s == 0)
			return (i);
		i++;
	}
	return (i);
}