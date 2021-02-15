#include "minishell.h"

void		first_shell_test()
{
	char *str;

	//str = malloc(100);
	write(1, "*_*_*_*_*_*_* Welcome to minishell *_*_*_*_*_*_*\n", 49);
	write(1, "MiniShell $> ", 13);
	while (get_next_line(0, &str))
	{
		if (!ft_strncmp(str, "exit", ft_strlen(str)))
			exit(0);
		write(1, "\n", 1);
		write(1, str, ft_strlen(str));
		write(1, "\nMiniShell $> ", 14);
		
	}
	free(str);
}
