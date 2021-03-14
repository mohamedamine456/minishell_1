#include "../minishell.h"

/*
* This function takes line from the main function
* remove_spaces : to remove additional spaces from the line
* split_line_commands: splits the line to commands based on ';'
* split_command : split a command to main command and pipes
* print_command_parts : just to print the list of commands
* ft_free_args : to free all items in a table of strings
*/

t_commands *parse_command(char *line, t_commands *commands)
{
	char	**tab_commands;

	line = remove_spaces(ft_strdup(line));
	tab_commands = split_line_commands(line);
	split_command(tab_commands, &commands);
	print_command_parts(commands);
	ft_free_args(tab_commands);
	free(line);
	return (commands);
}

/**
 * This function split a line to commands by ';'
 * it does skip ';' if it is prefixed by '\' or it is inside a ""
 * all this function do is take a line and return a table of commands
 * i used substr to split command
*/

char		**split_line_commands(char *line)
{
	char **tab;
	int i;
	int j;
	t_flags fl;

	i = 0;
	j = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	tab = NULL;
	while (line[i] != '\0')
	{
		// if (line[i] == '\\')
		// 	fl.b_s = fl.b_s == 1 ? 0 : 1;
		// if (line[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
		// 	fl.d_q++;
		// if (line[i] == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
		// 	fl.s_q++;
		fl = check_flags(fl, line[i]);
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

/**
 * this function to plit all the command in the table from the previous function
 * and split each command in the table with pipe : "split_pipes" doeas that
 * after spliting a command with pipes
 * put element_command take cre of putting those parts in the list
*/

void	split_command(char **tab_cmd, t_commands **commands)
{
	char **tab;
	int i;

	i = 0;
	while (tab_cmd[i] != NULL)
	{
		if (ft_strcmp("", tab_cmd[i]))
		{
			tab = split_pipes(tab_cmd[i]);
			put_elements_command(tab, commands);
			ft_free_args(tab);
		}
		i++;
	}
}

/**
 * This funtion to split a given command with pipes 
 * it also skip the '|' inside "" or '|' prefixed by \
*/

char		**split_pipes(char *str_cmd)
{
	char **tab;
	int i;
	int j;
	t_flags fl;

	i = 0;
	j = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	tab = NULL;
	while (str_cmd[i] != '\0')
	{
		if (str_cmd[i] == '\\')
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (str_cmd[i] == '\'' && fl.b_s == 0 && fl.s_q % 2 == 0)
			fl.s_q++;
		if (str_cmd[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
			fl.d_q++;
		if (fl.s_q % 2 == 0 && fl.d_q % 2 == 0 && str_cmd[i] == '|' && fl.b_s == 0)
		{
			tab = resize_tab(tab, ft_substr(str_cmd, j, i - j));
			j = i + 1;
		}
		if (str_cmd[i] != '\\' && fl.b_s == 1)
			fl.b_s = 0;
		i++;
	}
	tab = resize_tab(tab, ft_substr(str_cmd, j, i - j));
	return (tab);
}

/**
 * This function to split commands and pipes with  redirections and put them in the list
*/

void	split_redirections(char *part, t_commands **new_cmd)
{
	char	**tab_redir;
	char	**tab_input;
	int		i;
	int		n_s;
	t_flags fl;

	i = 0;
	n_s = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	tab_redir = NULL;
	tab_input = NULL;
	while (part[i] != '\0')
	{
		if (part[i] == '\\')
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (part[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
			fl.d_q++;
		if (part[i] == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
			fl.s_q++;
		if (fl.d_q % 2 == 0 && fl.s_q % 2 == 0 && fl.b_s == 0)
		{
			if (part[i] == '>')
			{
				if (part[i + 1] == '>')
				{
					n_s = next_space(part + i + 2);
					tab_redir = resize_tab(tab_redir, ft_substr(part, i, n_s + 2));
					i += n_s + 1;
				}
				else
				{
					n_s = next_space(part + i + 1);
					tab_redir = resize_tab(tab_redir, ft_substr(part, i, n_s + 1));
					i += n_s;
				}
			}
			if (part[i] == '<')
			{
				n_s = next_space(part + i + 1);
				tab_input = resize_tab(tab_input, ft_substr(part, i, n_s + 1));
				i += n_s;
			}
		}
		if (part[i] != '\\' && fl.b_s == 1)
			fl.b_s = 0;
		i++;
	}
	(*new_cmd)->redirect = tab_redir;
	(*new_cmd)->input = tab_input;
	free(part);
}

void	split_pipes_redirections(char *part, t_pipes **new_pipe)
{
	char	**tab_redir;
	char	**tab_input;
	int		i;
	int		n_s;
	t_flags fl;

	i = 0;
	n_s = 0;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	tab_redir = NULL;
	tab_input = NULL;
	while (part[i] != '\0')
	{
		if (part[i] == '\\' && fl.d_q % 2 == 0 && fl.s_q % 2 == 0)
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (part[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
			fl.d_q++;
		if (part[i] == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
			fl.s_q++;
		if (fl.d_q % 2 == 0 && fl.s_q % 2 == 0 && fl.b_s == 0)
		{
			if (part[i] == '>')
			{
				if (part[i + 1] == '>')
				{
					n_s = next_space(part + i + 2);
					n_s = check_redirection(part + i + 2, n_s);
					tab_redir = resize_tab(tab_redir, ft_substr(part, i, n_s + 2));
					i += n_s + 1;
				}
				else
				{
					n_s = next_space(part + i + 1);
					n_s = check_redirection(part + i + 2, n_s);
					tab_redir = resize_tab(tab_redir, ft_substr(part, i, n_s + 1));
					i += n_s;
				}
			}
			if (part[i] == '<')
			{
				n_s = next_space(part + i + 1);
				n_s = check_redirection(part + i + 2, n_s);
				tab_input = resize_tab(tab_input, ft_substr(part, i, n_s + 1));
				i += n_s;
			}
		}
		if (part[i] != '\\' && fl.b_s == 1)
			fl.b_s = 0;
		i++;
	}
	(*new_pipe)->redirect = tab_redir;
	(*new_pipe)->input = tab_input;
	free(part);
}