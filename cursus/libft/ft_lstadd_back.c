#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!(*lst) && new)
	{
		*lst = new;
		return ;
	}
	else if (!new)
		return ;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = temp;
}

/*
#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*present_node;
	while (lst)
	{
		present_node = lst;
		lst = lst->next;
	}
	return	(present_node);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int main(void)
{
	t_list	*head;
	t_list	first;
	t_list	second;
	t_list	new;
	int	content;

	head = &first;
	first.next = &second;
	second.next = 0;
	
	content = 12345;

	new.content = &content;
	new.next = 0;
	
	printf("%d\n", ft_lstsize(head));
	ft_lstadd_back(&head, &new);
	printf("%d\n", ft_lstsize(head));
	printf("%d\n", *(int*)ft_lstlast(head)->content);

	return (0);
}
*/
