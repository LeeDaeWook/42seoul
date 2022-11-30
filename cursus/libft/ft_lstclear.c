#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del && lst)
	{
		del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!del || !(*lst))
		return	;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = 0;
}

/*
#include <stdio.h>

int main(void)
{
	t_list	*head;
	t_list	first;
	t_list	second;
	int	*con1;
	int	*con2;

	head = &first;

	//*con1 = 123;
	//first.content = malloc(sizeof(int) * 1);
	first.content = con1;
	//first.next = (t_list*)malloc(sizeof(t_list) * 1);
	first.next = &second;

	//*con2 = 456;
	//second.content = malloc(sizeof(int) * 1);
	second.content = con2;
	//second.next = (t_list*)malloc(sizeof(t_list) * 1);
	second.next = 0;

	ft_lstclear(&head, del);

	//printf("%d\n", ft_lstsize(head));

	return (0);
}
*/
