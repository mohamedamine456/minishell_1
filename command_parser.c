#include "minishell.h"

t_commands *parse_command(char *line, t_commands *commands)
{
	char	**tab_commands;

	tab_commands = split_line_commands(line);
	split_command(tab_commands, &commands);
	print_command_parts(commands);
	//print_commands(tab_commands);
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
		if (line[i] != '\\' && fl.b_s == 1)		// see a pipe leak commit for old instruction
			fl.b_s = 0;
		i++;
	}
	tab = resize_tab(tab, ft_substr(line, j, i - j));
	fl.p_v++;
	return (tab);
}

void	split_command(char **tab_cmd, t_commands **commands)
{
	char **tab;
	int i;

	i = 0;
	while (tab_cmd[i] != NULL)
	{
		tab = split_pipes(tab_cmd[i]);
		put_elements_command(tab, commands);
		i++;
		ft_free_args(tab);
	}
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

void	split_redirections(char *part)
{
	char	**tab_redir;
	char	**tab_cmd_pipe;
	int		i;
	int		j;
	t_flags fl;

	i = 0;
	j = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	tab_redir = allocat_tab();
	tab_cmd_pipe = allocat_tab();
	while (part[i] != '\0')
	{
		if (part[i] == '\\' && fl.d_q % 2 == 0 && fl.s_q % 2 == 0)
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (part[i] == '\"' && fl.b_s == 0)
			fl.d_q++;
		if (part[i] == '\'' && fl.b_s == 0)
			fl.s_q++;
		if (fl.d_q % 2 == 0 && fl.s_q % 2 == 0 && fl.b_s == 0)
		{
			if (part[i] == '>' || part[i] =='<')
				printf("redirection\n");
		}
		if (part[i] != '\\' && fl.b_s == 1)
			fl.b_s = 0;
		i++;
	}
}