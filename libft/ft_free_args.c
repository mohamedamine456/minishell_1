# include "libft.h"

void        ft_free_args(char **args)
{
    int     i;

    i = 0;
    if (args != NULL)
    {
        while (args[i] != NULL)
        {
            free(args[i]);
            i++;
        }
        free(args);
        args = NULL;
    }
}