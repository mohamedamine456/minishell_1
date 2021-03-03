#include "minishell.h"

int     main(int argc, char **argv, char **env)
{
	char	*command_line;
    t_commands  *commands;

    if (argc == 1)
    {
        while (TRUE)
        {
            write(1, "Minishell $> ", 13);
            if (get_next_line(0, &command_line) > 0)
            {
                parse_command(command_line, &commands);
                write(1, "\n", 1);
            }
        }
    }
}