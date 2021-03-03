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
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# define TRUE 1
# define FALSE 0

void		fatal(char *error);
void		*ec_malloc(unsigned int size);

/**
 * initializer.c to initialize list of commands 
*/
void        initialize_commands(t_commands **commands);

/**
 * command_parser.c to parse commands 
*/
t_commands      *parse_command(char *line, t_commands **commands);

/*
 * functions for tests 
*/

int         check_line_errors(char *command);
int         parse_command_line(char	*command_line);
void        print_env_variables(char **env);

#endif
