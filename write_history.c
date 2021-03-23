# include "minishell.h"

void	write_history(char *line)
{
	int	fd;

	fd = open(".minishell_histroy", O_RDWR | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
	if (fd == -1)
		fatal("Couldn\'nt Open .minishell_history File to Write History");
	write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
	close(fd);
	// check if commit works
}
