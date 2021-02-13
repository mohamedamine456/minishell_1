/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:04:47 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/13 10:19:02 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DEST_PATH "/Users/mlachheb/cursus/Minishell/libft"
#define CURR_PATH_SIZE 39
#define DEST_PATH_SIZE 39

int main()
{
	char	*curr_path;
	char	*dest_path;

	curr_path = malloc(CURR_PATH_SIZE);
	dest_path = malloc(DEST_PATH_SIZE);
	// Get the curent directory
	if (getcwd(curr_path, CURR_PATH_SIZE) == NULL)
		perror("getcwd() error");
	else
		printf("current working directory is: %s\n", curr_path);
	// Change the directory
	printf("\n*_*_*_*_* Changing the Directory *_*_*_*_*\n");
	if (chdir(DEST_PATH) != 0)
		perror("chdir() error");
	if (getcwd(dest_path, DEST_PATH_SIZE) == NULL)
		perror("getcwd() error");
	else
		printf("current working directory is: %s\n", dest_path);
}
