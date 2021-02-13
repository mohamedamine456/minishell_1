#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		main(int argc, char **argv)
{
	int		pipefd[2];
	pid_t	cpid;
	char	buffer;

	if (argc != 2)
	{
		fprintf(stdout, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	cpid = fork();
	if (cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		close(pipefd[1]);
		while (read(pipefd[0], &buffer, 1) > 0)
			write(1, &buffer, 1);
		write(1, "\n", 1);
		close(pipefd[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[0]);
		write(pipefd[1], argv[1], strlen(argv[1]));
		close(pipefd[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
}
