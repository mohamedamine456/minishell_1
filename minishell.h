/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:50:32 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/11 11:07:28 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "structs.h"
# include "libft/libft.h"
# include "commands_list/lists.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# define TRUE 1
# define FALSE 0

void		fatal(char *error);
void		*ec_malloc(unsigned int size);

/**
 * command_parser.c to parse commands 
*/
t_commands		*parse_command(char *line, t_commands *commands);
char			**split_line_commands(char *line);
void			split_command(char **tab_cmd, t_commands **commands);
char			**split_pipes(char *cmd);
void			put_elements_command(char **tab, t_commands **cmd);
char			**remove_backslash(char **tab);


/*
* allocation_functions.c
*/

char		**resize_tab(char **old, char *chaine);
char		**allocat_tab();

/*
*	check_flags.c
*/

int			is_flag(char c);

/*
 * functions for tests 
*/

int         check_line_errors(char *command);
int         parse_command_line(char	*command_line);
void		print_env_variables(char **env);
void		print_commands(char **tab);

#endif