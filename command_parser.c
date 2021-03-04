# include "minishell.h"

t_commands      *parse_command(char *line, t_commands *commands)
{
    char    **tab_commands;

    tab_commands = split_line_commands(line);
	print_commands(tab_commands);
    // commands = last_command(commands);
    // commands = new_command();
    // tab_elements = split_command(line);
    // put_elements_command(tab_elements, &commands);
    //printf("\n%s, %s, %d, %s\n", commands->name, commands->options, commands->id_command_pipe, commands->redirect);
    return(commands);
}

char			**split_line_commands(char *line)
{
    char    **tab;
    int     i;
	int		j;
	t_flags	fl;

    i = 0;
	j = 0;
	fl.p_v = 0;
	fl.d_q = 0;
	fl.s_q = 0;
	tab = allocat_tab();
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
			fl.d_q = fl.d_q + 1;
		if (line[i] == '\'')
			fl.s_q = fl.s_q + 1;
		if (fl.s_q % 2 == 0 && fl.d_q % 2 == 0 && line[i] == ';')
		{
			tab = resize_tab(tab, ft_substr(line, j, i - j));
			j = i + 1;
			fl.p_v = fl.p_v + 1;
		}
		i++;
	}
	tab = resize_tab(tab, ft_substr(line, j, i));
	fl.p_v = fl.p_v + 1;
	return (tab);
}



void			put_elements_command(char **tab, t_commands **cmd)
{
    (*cmd)->name = ft_strdup(tab[0] != NULL ? tab[0] : "");
    (*cmd)->arguments = (char **)malloc(sizeof(char *) * 2);
    (*cmd)->arguments[0] = ft_strdup(tab[1] != NULL ? tab[1] : "");
    (*cmd)->arguments[1] = NULL;
}

char			**split_command(char *line)
{
    t_commands  *cmd;
    char        **tab;
    int         i;
	

    i = 0;
    while (line[i] != '\0')
    {
        
        i++;
    }

    tab = ft_split(line, ' ');
    return (tab);
}