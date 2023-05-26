/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:25:33 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/01 15:59:49 by kyeonkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*ft_merge(t_env *left, t_env *right)
{
	t_env	*result;

	result = NULL;
	if (left == NULL)
		return (right);
	else if (right == NULL)
		return (left);
	if (ft_strcmp(left->key, right->key) <= 0)
	{
		result = left;
		result->next = ft_merge(left->next, right);
	}
	else
	{
		result = right;
		result->next = ft_merge(left, right->next);
	}
	return (result);
}

void	ft_move_next(t_env **slow, t_env **fast)
{
	*slow = (*slow)->next;
	*fast = (*fast)->next;
}

void	ft_mergesort(t_env **headRef)
{
	t_env	*head;
	t_env	*left;
	t_env	*right;
	t_env	*slow;
	t_env	*fast;

	head = *headRef;
	if (head == NULL || head->next == NULL)
		return ;
	slow = head;
	fast = head->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
			ft_move_next(&slow, &fast);
	}
	left = head;
	right = slow->next;
	slow->next = NULL;
	ft_mergesort(&left);
	ft_mergesort(&right);
	*headRef = ft_merge(left, right);
}

void	ft_print_env(t_env *new_list)
{
	t_env	*temp;

	while (new_list)
	{
		printf("declare -x %s", new_list->key);
		if (ft_strchr(new_list->content, '='))
		{
			printf("=");
			printf("\"%s\"\n", new_list->value);
		}
		else
			printf("\n");
		temp = new_list;
		new_list = new_list->next;
		ft_free_env(temp);
	}
}

t_env	*ft_duplicate_list(t_env *custom_env)
{
	t_env	*origin_list;
	t_env	*new_list;
	t_env	*new_node;

	origin_list = custom_env;
	new_list = NULL;
	while (origin_list)
	{
		new_node = env_lstnew(origin_list->content);
		env_lstadd_back(&new_list, new_node);
		origin_list = origin_list->next;
	}
	return (new_list);
}
