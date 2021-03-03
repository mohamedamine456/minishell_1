# include "minishell.h"

t_commands      *parse_command(char *line, t_commands *commands)
{
    char    **parts_of_command;

    parts_of_command = ft_split(line, ' ');
    commands = last_command(commands);
    commands = initialize_commands();
    if (commands->name == NULL)
        write(1, "null", 4);
    return(commands);
}