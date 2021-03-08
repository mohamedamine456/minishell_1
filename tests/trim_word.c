#include "../libft/libft.h"
#include "../minishell.h"

int main(void)
{
	char *str;
	char *result;
	char n_s = 0;
	int i = 0;
	t_flags fl = (t_flags){0, 0, 0, 0, 0, 0};

	str = ft_strdup("echo -n hello world | grep h ; echo -p good morning > \"file file\" | grep n");
	while (str[i] != '\0')
	{
		if (str[i] == '\\' && fl.d_q % 2 == 0 && fl.s_q % 2 == 0)
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (str[i] == '\'' && fl.b_s == 0)
			fl.s_q++;
		if (str[i] == '\"' && fl.b_s == 0)
			fl.d_q++;
		if ((str[i] == '>' || str[i] == '<') && fl.d_q % 2 == 0 && fl.s_q % 2 == 0 && fl.b_s == 0)
		{
			n_s = next_space(str + i + 2);
			result = ft_substr(str, i, n_s + 2);
			ft_memmove(str + i, str + i + n_s + 2, ft_strlen(str + i) - n_s - 2);
			str[ft_strlen(str) - n_s - 2] = '\0';
		}
		i++;
	}
	printf("str = [[ %s ]]\nresult = [[ %s ]]", str, result);
}