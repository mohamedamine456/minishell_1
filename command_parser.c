#include "minishell.h"

t_commands *parse_command(char *line, t_commands *commands)
{
	char	**tab_commands;

	tab_commands = split_line_commands(line);
	split_command(tab_commands, &commands);
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
		if ((line[i] == ';' || line[i] == '\'' || line[i] == '\"' || line[i] != '\\') && fl.b_s == 1)
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
		put_elements_command(tab, commands);		// i'm here
		i++;
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

void	put_elements_command(char **tab, t_commands **cmd)
{
	t_commands	*new_cmd;
	int			i;

	i = 1;
	new_cmd = new_command();
	if (tab[0] != NULL)
		put_simple_command(tab[0], &new_cmd);
	while (tab[i] != NULL)
	{
		put_pipes_to_command(tab[i], &new_cmd);
		i++;
	}	
}

void	put_simple_command(char *simple_cmd, t_commands **cmd)
{
	char	**tab;
	int		op;

	op = 0;
	tab = ft_split(simple_cmd, ' ');
	if (tab[0] != NULL)
		(*cmd)->name = ft_strdup(tab[0]);
	if (tab[1] != NULL && is_option(tab[1]))
	{
		(*cmd)->options = ft_strdup(tab[1]);
		op = 1;
	}
	else if(tab[1] != NULL && op == 0)
		put_args_to_command(cmd, tab + 1);
	else if (op == 1 && tab[2] != NULL)
		put_args_to_command(cmd, tab + 2);
	ft_free_args(tab);
}

void	put_args_to_command(t_commands **cmd, char **args)
{
	int	i;
	int	size;

	i = 0;
	size = ft_size_args(args);
	(*cmd)->arguments = (char **)malloc(sizeof(char *) * (size + 1));
	while (args[i]!= NULL)
	{
		(*cmd)->arguments[i] = ft_strdup(args[i]);
		i++;
	}
	(*cmd)->arguments[i] = NULL;
}

void	put_pipes_to_command(char *pipe_cmd, t_commands **cmd)
{
	char	**tab;
	int		op;
	t_pipes	*last_pipe;

	tab = ft_split(pipe_cmd, ' ');
	if (tab[0] != NULL)
		(*cmd)->piped->name = ft_strdup(tab[0]);
	if (tab[1] != NULL && is_option(tab[1]))
	{
		(*cmd)->options = ft_strdup(tab[1]);
		op = 1;
	}
	else if (tab[1] != NULL && op == 0)
		put_args_to_pipe(&((*cmd)->piped), tab + 1);
	else if (tab[2] != NULL && op == 1)
		put_args_to_pipe(&((*cmd)->piped), tab + 2);
}

void	put_args_to_pipe(t_pipes **pipe, char **args)
{
	int	i;
	int	size;

	i = 0;
	size = ft_size_args(args);
	(*pipe)->args = (char **)malloc(sizeof(char *) * (size + 1));
	while (args[i]!= NULL)
	{
		(*pipe)->args[i] = ft_strdup(args[i]);
		i++;
	}
	(*pipe)->args[i] = NULL;
}