#include "minishell.h"

int     main(int argc, char **argv, char **env)
{
	char	*command_line;
    t_commands  *commands;
    //int     fd = open("file.txt", O_RDONLY);

    commands = NULL;
    if (argc == 1 && argv != NULL && env != NULL)
    {
        while (TRUE)
        {
            write(1, "Minishell $> ", 13);
            if (get_next_line(0, &command_line) > 0)
            {
                commands = parse_command(command_line, commands);
                write_history(command_line);  // to write the line in a file responsible for history
                write(1, "\n", 1);
                free(command_line);
                command_line = NULL;
            }
        }
    }
}