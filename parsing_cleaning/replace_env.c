# include "parsing_cleaning.h"

void        replace_env(t_commands **new_cmd)
{
        t_pipes *pip;

        if (*new_cmd != NULL)
        {
                if ((*new_cmd)->name != NULL)
                        (*new_cmd)->name = replace_str((*new_cmd)->name, NULL);
                if ((*new_cmd)->options != NULL)
                        (*new_cmd)->options = replace_str((*new_cmd)->options, NULL);
                if ((*new_cmd)->arguments != NULL)
                        (*new_cmd)->arguments = replace_args((*new_cmd)->arguments);
                if ((*new_cmd)->input != NULL)
                        (*new_cmd)->input = replace_args((*new_cmd)->input);
                if ((*new_cmd)->redirect != NULL)
                        (*new_cmd)->redirect = replace_args((*new_cmd)->redirect);
                if ((*new_cmd)->piped != NULL)
                {
                        pip = (*new_cmd)->piped;
                        while (pip != NULL)
                        {
                                if (pip->name != NULL)
                                        pip->name = replace_str(pip->name, NULL);
                                if (pip->options != NULL)
                                        pip->options = replace_str(pip->options, NULL);
                                if (pip->args != NULL)
                                        pip->args = replace_args(pip->args);
                                if (pip->redirect != NULL)
                                        pip->redirect = replace_args(pip->redirect);
                                if (pip->input != NULL)
                                        pip->input = replace_args(pip->input);
                                pip = pip->next;
                        }
                }
        }
}

char            **replace_args(char **args)
{
        int i;

        i = 0;
        if (args == NULL)
                return (NULL);
        while (args[i] != NULL)
        {
                args[i] = replace_str(args[i], NULL);
                i++;
        }
        return (args);
}
