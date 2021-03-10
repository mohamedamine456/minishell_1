# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char **argv, char **envp)
{
	char	*new_argv[] = { NULL, "Hello World", "Good Morning", NULL};
	char	*new_envp[] = { NULL };
	int		ret;

	if  (argc != 2)
	{
		printf("Usage: %s <file-to-execute>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	new_argv[0] = argv[1];
	execve(argv[1], new_argv, new_envp);
	perror("execve");
	exit(EXIT_FAILURE);
}
