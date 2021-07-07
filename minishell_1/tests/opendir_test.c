/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opendir_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 08:25:56 by mlachheb          #+#    #+#             */
/*   Updated: 2021/02/15 08:42:11 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>


int main(int argc, char ** argv)
{
	DIR				*dip;
	struct dirent	*dit;
	int				i = 0;

	/*
	 * Check if user entered a directory name 
	 */
	if (argc < 2)
	{
		printf("Usage: %s <directory>\n", argv[0]);
		return (0);
	}
	/*
	 * DIR *opendir(const char *name);
	 *
	 * open a directory stream to argv[1] and make sure
	 * it's a readable and valid (directory).
	 */
	if ((dip = opendir(argv[1])) == NULL)
	{
		perror("opendir()");
		return (0);
	}
	printf("Directory stream is now open\n");

	/*
	 * struct dirent *readdir(DIR *dir);
	 * Read in the files from argv[1] and print.
	 */
	while ((dit = readdir(dip)) != NULL)
	{
		i++;
		printf("File %2d ==> %s\n", i, dit->d_name);
	}
	printf("\n\n readdir() found a total of %i files\n", i);	

	/*
	 * int closedir(DIR *dir);
	 * Close the stream to argv[1]. And check for errors.
	 */
	if (closedir(dip) == -1)
	{
		perror("closedir()");
		return (0);
	}
	printf("\n Directory stream is now closed\n");
	return (1);
}
