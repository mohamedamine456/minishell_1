/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 08:50:05 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/09 09:32:59 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argv, char **args)
{
	if (argv > 1)
		fatal("in main() a lot of arguments");
	args[0][0] = '\0';			// Just for flags
	write(1, "Doing good...", 13);
	return (0);
}
