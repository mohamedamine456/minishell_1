# include "../check_functions/check_functions.h"
# include "../get_next_line/get_next_line.h"
# define TRUE 1

int main(int argv, char **argc)
{
	char *str;
	char *line;
	while (TRUE)
	{
		write(1, "Minishell $> ", 13);
		if (get_next_line(0, &line) > 0)
		{
			str = clean_args(line);
			write(1, str, ft_strlen(str));
			write(1, "\n", 1);
			free(str);
			str = NULL;
		}
	}
}