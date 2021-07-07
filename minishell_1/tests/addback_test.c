#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
		while (lst->next != NULL)
			lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *lst;

	lst = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		lst = ft_lstlast(*alst);
		lst->next = new;
		// lst++;
		// lst = new;
	}
}

int main()
{
	t_list	*list;
	t_list	*new;
	t_list	*new2;
	int		i = 0;

	list = (t_list *)malloc(sizeof(t_list));
	list->content = strdup("Hello World");
	list->next = (t_list *)NULL;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = strdup("Good Morning");
	new->next = (t_list *)NULL;
	ft_lstadd_back(&list, new);

	new2 = (t_list *)malloc(sizeof(t_list));
	new2->content = strdup("Good Afternoon");
	new2->next = (t_list *)NULL;
	ft_lstadd_back(&list, new2);

	free(new->content);
	free(new);
	new = (t_list *)NULL;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = strdup("Good Evening");
	new->next = (t_list *)NULL;
	ft_lstadd_back(&list, new);
	// new->content = strdup("Good Night");
	// new->next = NULL;
	// ft_lstadd_back(&list, new);
	// new->content = strdup("Good Luck");
	// new->next = NULL;
	// ft_lstadd_back(&list, new);
	while (list != NULL)
	{
		printf("Element %d: [%s : %s]\n", i + 1, (char *)(list->content), (char *)(list->next));
		i++;
		list = list->next;
		sleep(1);
	}
	return (0);
}