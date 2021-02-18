/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_shell_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:39:33 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/18 12:09:05 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			check_quotes(char *buffer)
{
	int 	i;
	int		quotes;

	i = 0;
	quotes = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\"')
			quotes++;
		i++;
	}
	if ((quotes % 2) == 0)
		return (1);
	else
		return (0);
}

char		*add_quotes(char *buffer)
{
	char	*str;

	write(1, "> ", 2);
	get_next_line(1, &str);
	buffer = ft_strjoin(buffer, str);
	if (!check_quotes(buffer))
		buffer = add_quotes(buffer);
	return (buffer);	
}

void		first_shell_test()
{
	char	*buffer;
	char	*str;
	int		i;
	int		j;

	//str = malloc(100);
	write(1, "*_*_*_*_*_*_* Welcome to minishell *_*_*_*_*_*_*\n", 49);
	write(1, "MiniShell $> ", 13);
	while (get_next_line(0, &buffer))
	{
		if (!check_quotes(buffer))
			buffer = add_quotes(buffer);	
		if (!ft_strncmp(buffer, "exit", ft_strlen(buffer)))
			exit(0);
		else
		{
			i = 0;
			while (buffer[i] != '\0')
			{
				j = i;
				while (buffer[i] != ' ' && buffer[i] != '\0')
					i++;
				str = ft_substr(buffer, j, i - j);	
				write(1, str, ft_strlen(str));
				write(1, "\n", 1);
				i++;
			}
		}
		write(1, "MiniShell $> ", 14);	
	}
	free(str);
}
