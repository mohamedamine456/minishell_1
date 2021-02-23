/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_shell_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:39:33 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/23 12:09:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


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
