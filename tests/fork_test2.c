/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_test2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:28:32 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/10 15:18:16 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

#define MAX_COUNT 200

void		child_process()
{
	int		i;
	char	*str;

	str = malloc(15);
	strcpy(str, "Hello child!!!");
	for (i = 0; i < MAX_COUNT; i++)
		printf("	This Line is from the child, value = %d at @ %p || string : %s at @ %p\n", i, &i, str, str);
	free(str);
	printf("\n	*** Child Process Done ***\n");
}

void		parent_process()
{
	int		j;
	char	*str1;

	str1 = malloc(16);
	strcpy(str1, "Hello parent!!!");
	for (j = 0; j < MAX_COUNT; j++)
		printf("This Line is from parent, value = %d at @ %p || string : %s at @ %p\n", j, &j, str1, str1);
	printf("\n*** Parent Process Done ***\n");
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
