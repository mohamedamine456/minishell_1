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
# include "parsing_cleaning/parsing_cleaning.h"

void			fatal(char *error);
void			*ec_malloc(unsigned int size);



/*
* functions for tests 
*/

int         	check_line_errors(char *command);
int         	parse_command_line(char	*command_line);
void			print_env_variables(char **env);
void			print_commands(char **tab);
void			print_command_parts(t_commands *command);
void			print_redirections(char **tab_redir);
void			print_inputs(char **tab_input);

/**
 * write_history.c 
*/
void			write_history(char *line);

#endif