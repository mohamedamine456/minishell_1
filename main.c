#include "minishell.h"

int     main(int argc, char **argv, char **env)
{
	char	*command_line;
    t_commands  *commands;

    commands = NULL;
    if (argc == 1 && argv != NULL && env != NULL)
    {
        while (TRUE)
        {
            write(1, "Minishell $> ", 13);
            if (get_next_line(0, &command_line) > 0)
            {
                commands = parse_command(command_line, commands);
                // if (!ft_strcmp(commands->name, "echo"))
                //     write(1, commands->arguments[0], ft_strlen(commands->arguments[0]));
                write(1, "\n", 1);
            }
        }
    }
}