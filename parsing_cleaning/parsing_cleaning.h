#ifndef PARSING_CLEANING_H
# define PARSING_CLEANING_H
# include "../structs.h"
# include "../libft/libft.h"
# include "../commands_list/lists.h"
# include "../get_next_line/get_next_line.h"
# include "../check_functions/check_functions.h"
# include <fcntl.h>
# define TRUE 1
# define FALSE 0

/**
 * command_parser.c to parse commands 
*/

t_commands		*parse_command(char *line, t_commands *commands);
char			**split_line_commands(char *line);
void			split_command(char **tab_cmd, t_commands **commands);
char			**split_pipes(char *cmd);
void			split_redirections(char *part, t_commands **new_cmd);
void			split_pipes_redirections(char *part, t_pipes **new_pipe);

/**
 * fill_command.c  
*/
void			put_elements_command(char **tab, t_commands **cmd);
void			put_simple_command(char *simple_cmd, t_commands **cmd);
void			put_args_to_command(t_commands **cmd, char **args);
void			put_pipes_to_command(char *pipe_cmd, t_commands **cmd);
void			put_args_to_pipe(t_pipes **pipe, char **args);

/*
* allocation_functions.c
*/

char			**resize_tab(char **old, char *chaine);

/*
*	remove_tab_from_string.c
*/

char			*remove_tab_from_string(char *str, char **tab);



char			*clean_str(char *str);


void			clean_command(t_commands **new_cmd);
char			**clean_args(char **args);

void            replace_env(t_commands **new_cmd);
char            **replace_args(char **args);
char			*replace_str(char *str, char **envp);
char			*search_env(char *str, char **envp);
char			*trim_replace(char *str, char **envp);


char			*special_char(char *str, int *i);
char			*alpha_char(char *str, int *i);
char			*digit_char(char *str, int *i);

#endif
