/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:50:05 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/11 10:05:37 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		read_line(char **buffer)
{
	if (get_next_line(0, buffer))
	{
		if (ft_strcmp(*buffer, "") == 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

int		main()
{
	int 	i;
	int		j;
	char	*buffer;
	char	**table;

	j = 1;
	i = 0;
	table = (char **)malloc(sizeof(char *));
	write(1, "MiniShell $> ", 13);
	while (j)
	{
		if (read_line(&buffer))
		{
			table[i] = ft_strdup(buffer);
			table[i + 1] = NULL;
			i = i + 1;
		}
		else
		{
			write(1, "--------------------\n", 22);
			i = 0;
			while (table[i] != NULL)
			{
				write(1, table[i], ft_strlen(table[i]));
				write(1, "\n--------------------\n", 22);
				i = i + 1;
			}
			write(1, "MiniShell $> ", 13);
		}
	}
	return (0);
}
