#include "philo_bonus.h"

t_list	*ft_create_elem(int data)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	merror((void *)elem);
	elem->next = NULL;
	elem->data = data;
	return (elem);
}

t_list	*ft_find_bot_elem(t_list *list)
{
	if (!list)
		return (0);
	while (list->next != 0)
		list = list->next;
	return (list);
}

t_list	*ft_add_bottom_elem(t_list *list, int data)
{
	t_list	*elem;

	if (!list)
		list = ft_create_elem(data);
	else
	{
		elem = ft_create_elem(data);
		elem->next = NULL;
		ft_find_bot_elem(list)->next = elem;
	}
	return (list);
}

void	display_list(t_list *list)
{
	while (list && list->next)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	if (list)
		printf("%d\n", list->data);
}
