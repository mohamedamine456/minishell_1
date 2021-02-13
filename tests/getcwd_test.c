/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 09:42:20 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/13 10:06:11 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define PATH_SIZE 39

int main()
{
	char	*path;
	
	path = malloc(PATH_SIZE);
	if (getcwd(path, PATH_SIZE) == NULL)
		perror("getcwd() error");
	else
		printf("current working directory is: %s\n", path);
}
