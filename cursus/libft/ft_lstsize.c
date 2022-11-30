#include "libft.h"

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

/*
#include <stdio.h>

int main(void)
{
	t_list	*head;
	//t_list	first_node;
	//t_list	second_node;

	head = 0;
	//head = &first_node;
	//first_node.next = &second_node;
	//second_node.next = 0;
	//ft_lstsize(head);

	printf("%d\n", ft_lstsize(head));
	
	return (0);
}
*/
