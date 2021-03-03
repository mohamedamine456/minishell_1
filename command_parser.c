# include "minishell.h"

t_commands      *parse_command(char *line, t_commands *commands)
{
    char    **parts_of_command;

    commands = last_command(commands);
    commands = new_command();
    //printf("\n%s, %s, %d, %s\n", commands->name, commands->options, commands->id_command_pipe, commands->redirect);
    return(commands);
}