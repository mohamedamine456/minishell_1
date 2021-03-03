# include "minishell.h"

t_commands      *parse_command(char *line, t_commands *commands)
{
    char    **tab_elements;

    commands = last_command(commands);
    commands = new_command();
    tab_elements = split_command(line);
    put_elements_command(tab_elements, &commands);
    //printf("\n%s, %s, %d, %s\n", commands->name, commands->options, commands->id_command_pipe, commands->redirect);
    return(commands);
}

char            **split_command(char *line)
{
    char    **tab;

    tab = ft_split(line, ' ');
    return (tab);
}

void            put_elements_command(char **tab, t_commands **cmd)
{
    (*cmd)->name = ft_strdup(tab[0] != NULL ? tab[0] : "");
    (*cmd)->arguments = (char **)malloc(sizeof(char *) * 2);
    (*cmd)->arguments[0] = ft_strdup(tab[1] != NULL ? tab[1] : "");
    (*cmd)->arguments[1] = NULL;
}