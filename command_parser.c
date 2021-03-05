#include "minishell.h"

t_commands *parse_command(char *line, t_commands *commands)
{
	char **tab_commands;

	tab_commands = split_line_commands(line);
	commands = split_command(tab_commands, commands);
	print_commands(tab_commands);
	// commands = last_command(commands);
	// commands = new_command();
	// tab_elements = split_command(line);
	// put_elements_command(tab_elements, &commands);
	//printf("\n%s, %s, %d, %s\n", commands->name, commands->options, commands->id_command_pipe, commands->redirect);
	ft_free_args(tab_commands);
	return (commands);
}

char		**split_line_commands(char *line)
{
	char **tab;
	int i;
	int j;
	t_flags fl;

	i = 0;
	j = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	tab = allocat_tab();
	while (line[i] != '\0')
	{
		if (line[i] == '\\' && fl.d_q % 2 == 0 && fl.s_q % 2 == 0)
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (line[i] == '\"' && fl.b_s == 0)
			fl.d_q++;
		if (line[i] == '\'' && fl.b_s == 0)
			fl.s_q++;
		if (fl.s_q % 2 == 0 && fl.d_q % 2 == 0 && line[i] == ';' && fl.b_s == 0)
		{
			tab = resize_tab(tab, ft_substr(line, j, i - j));
			j = i + 1;
			fl.p_v++;
		}
		if ((line[i] == ';' || line[i] == '\'' || line[i] == '\"') && fl.b_s == 1)
			fl.b_s = 0;
		i++;
	}
	tab = resize_tab(tab, ft_substr(line, j, i - j));
	fl.p_v++;
	return (tab);
}

t_commands	*split_command(char **tab_cmd, t_commands *commands)
{
	char **tab;
	int i;

	i = 0;
	while (tab_cmd[i] != NULL)
	{
		tab = split_pipes(tab_cmd[i]);
		i++;
	}
	return (commands);
}

char		**split_pipes(char *cmd)
{
	char **tab;
	int i;
	int j;
	t_flags fl;

	i = 0;
	j = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	tab = allocat_tab();
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '\\' && fl.d_q % 2 == 0 && fl.s_q % 2 == 0)
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (cmd[i] == '\'' && fl.b_s == 0)
			fl.s_q++;
		if (cmd[i] == '\"' && fl.b_s == 0)
			fl.d_q++;
		if (fl.s_q % 2 == 0 && fl.d_q % 2 == 0 && cmd[i] == '|' && fl.b_s == 0)
		{
			tab = resize_tab(tab, ft_substr(cmd, j, i - j));
			j = i + 1;
		}
		if ((cmd[i] == '|' || cmd[i] == '\'' || cmd[i] == '\"') && fl.b_s == 1)
			fl.b_s = 0;
		i++;
	}
	tab = resize_tab(tab, ft_substr(cmd, j, i - j));
	return (tab);
}

void put_elements_command(char **tab, t_commands **cmd)
{
	(*cmd)->name = ft_strdup(tab[0] != NULL ? tab[0] : "");
	(*cmd)->arguments = (char **)malloc(sizeof(char *) * 2);
	(*cmd)->arguments[0] = ft_strdup(tab[1] != NULL ? tab[1] : "");
	(*cmd)->arguments[1] = NULL;
}
