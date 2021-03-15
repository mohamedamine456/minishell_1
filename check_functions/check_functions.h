#ifndef CHECK_FUNCTIONS_H
# define CHECK_FUNCTIONS_H
# include "../libft/libft.h"

/*
*	check_flags.c
*/

int			is_flag(char c);
t_flags		check_flags(t_flags fl, char c);
/*
*	check_options.c
*/

int			is_option(char *str,char *name);

int			check_redirection(char *str, int len);

char		*clean_args(char *str);
t_flags		clean_flags(t_flags fl, char c);

#endif