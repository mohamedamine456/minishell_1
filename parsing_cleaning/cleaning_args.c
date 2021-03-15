# include "../minishell.h"

char	*clean_args(char *str)
{
	char	*new;
	int		i;
	int		len;
	t_flags	fl;

	i = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	len = ft_strlen(str);
	new = (char *)malloc(len + 1);
	if (new != NULL)
		fatal("in ec_malloc() on memory allocation.");
	while (i < len)
	{
		
		fl = check_flags(fl, str[i]);
		//if (str[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
		i++;
	}
	return (str);
}