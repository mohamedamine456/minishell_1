# include "parsing_cleaning.h"

char        *replace_str(char *str, char **envp)
{
    char    *new_str;
    int     exist;

    exist = -1;
    exist = search_env(str, envp, &new_str);
    if (exist != -1)
    {
        free(str);
        return (new_str);
    }
    return (str);
}
