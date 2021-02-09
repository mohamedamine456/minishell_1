/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_test2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:28:32 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/09 12:28:19 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT 200

void		child_process()
{
	int		i;

	for (i = 0; i < MAX_COUNT; i++)
		printf("	This Line is from the child, value = %d\n", i);
	printf("	*** Child Process Done ***");
}

void		parent_process()
{
	int		i;
	for (i = 0; i < MAX_COUNT; i++)
		printf("This Line is from parent, value = %d\n", i);
	printf("*** Parent Process Done ***");
}

int main()
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		child_process();
	else
		parent_process();
	return (0);
}
