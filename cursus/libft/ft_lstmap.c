#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newnode;

	newlist = 0;
	if (!lst || !f)
		return 0;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return 0;
		}
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	newnode = 0;
	return (newlist);
}
