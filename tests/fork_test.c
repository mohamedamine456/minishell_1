/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:21:23 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/09 11:28:17 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int main()
{
	pid_t	pid;
	int		i;
	char	buffer[100];

	fork();
	pid = getpid();
	for (i = 0; i < 200; i++)
		printf("This line is from pid %d, value = %d\n", pid, i);
	return (0);
}
