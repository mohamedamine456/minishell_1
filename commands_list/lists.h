#ifndef LISTS_H
# define LISTS_H
# include <unistd.h>
#include <stdlib.h>
# include "../structs.h"
# include "../libft/libft.h"

/**
*	t_commands list functions
*/

t_commands      *new_command();
t_commands      *last_command(t_commands *commands);
int             size_commands(t_commands *commands);
void            clear_commands(t_commands **commands);
void            addback_commands(t_commands **commands, t_commands *new);
void            addfront_commands(t_commands **commands, t_commands *new);

/**
*	t_pipes list functions
*/

int				size_pipes(t_pipes *pipes);
t_pipes			*new_pipe();
t_pipes			*last_pipe(t_pipes *pipes);
void			addback_pipes(t_pipes **pipes, t_pipes *new);
void			addfront_pipes(t_pipes **pipes, t_pipes *new);
void			clear_pipes(t_pipes **pipes);

#endif