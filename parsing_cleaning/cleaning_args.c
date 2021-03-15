# include "../minishell.h"

char	*clean_args(char *str)
{
	char	*new;
	int		i;
	int		j;
	int		len;
	t_flags	fl;

	i = 0;
	j = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	len = ft_strlen(str);
	new = (char *)malloc(len + 1);
	if (new == NULL)
		fatal("in ec_malloc() on memory allocation.");
	while (i < len)
	{
		if (!is_flag(str[i]))
			new[j++] = str[i];
		else
		{
			fl = check_flags(fl, str[i]);
			if (str[i] == '\\')
			{
				if (fl.s_q % 2 == 1 || fl.b_s == 1 || (fl.b_s == 1 && fl.d_q % 2 == 1))
					new[j++] = str[i];
			}
			else if (str[i] == '\'' && (fl.b_s == 1 || fl.d_q % 2 == 1))
				new[j++] = str[i];
			else if (str[i] == '\"' && (fl.b_s == 1 || fl.s_q % 2 == 1))
				new[j++] = str[i];
		}
		if (str[i] != '\\' && fl.b_s == 1)		// see a pipe leak commit for old instruction
			fl.b_s = 0;
		i++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}