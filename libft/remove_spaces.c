# include "libft.h"

char	*remove_spaces(char *str)
{
	int		i;
	int		j;
	char	*new;
	t_flags	fl;
	int		spaces;

	i = 0;
	j = 0;
	spaces = 0;
	new = (char *)malloc(ft_strlen(str) + 1);
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	while (str[i] != '\0')
	{
		if (str[i] =='\\' && fl.d_q % 2 == 0 && fl.s_q % 2 == 0)
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (str[i] == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
			fl.s_q++;
		if (str[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
			fl.d_q++;
		if (str[i] == ' ' && fl.s_q % 2 == 0 && fl.d_q % 2 == 0 && fl.b_s == 0)
			spaces++;
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		if(str[i] != ' ')
		{
			if (spaces > 0)
				new[j++] = ' ';
			new[j] = str[i];
			spaces = 0;
			j++;
		}
		i++;
	}
	return(str);
}