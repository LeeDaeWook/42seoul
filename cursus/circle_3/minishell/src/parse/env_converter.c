/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeonkim <kyeonkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:19:46 by kyeonkim          #+#    #+#             */
/*   Updated: 2023/04/04 00:02:15 by kyeonkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_temp	*ft_find_env(t_temp *head, t_env *envp)
{
	t_temp	*p;
	int		total_size;
	char	*str;
	int		count;

	p = head;
	while (p)
	{
		if (p->is_quote)
		{
			count = ft_env_dollar_count(p->str);
			while (count)
			{
				total_size = ft_total_size(p->str, envp);
				str = (char *)malloc(sizeof(char) * (total_size + 1));
				if (!str)
					ft_malloc_exit();
				p->str = ft_env_converter(p->str, str, NULL, envp);
				count--;
			}
		}
		p = p->next;
	}
	return (head);
}

int	ft_total_size(char *str, t_env *envp)
{
	int		size;
	int		end;
	char	*ft_env;

	size = 0;
	end = 0;
	ft_env = NULL;
	while (str[size] != '$')
		size++;
	end = 1;
	while (str[size + end] && ft_check_env(str[size + end]))
		end++;
	if (str[size + end] == '?' && end == 1)
		end++;
	ft_env = ft_substr(str, size, end);
	size += end;
	while (str[size])
		size++;
	ft_env = ft_env_convert(ft_env, envp);
	size += ft_strlen(ft_env) - end;
	free(ft_env);
	return (size);
}

char	*ft_env_converter(char *str, char *af_s, char *ft_env, t_env *envp)
{
	int	size;
	int	end;
	int	i;

	size = -1;
	while (str[++size] != '$')
		af_s[size] = str[size];
	end = 1;
	while (str[size + end] && ft_check_env(str[size + end]))
		end++;
	if (str[size + end] == '?' && end == 1)
		end++;
	ft_env = ft_substr(str, size, end);
	ft_env = ft_env_convert(ft_env, envp);
	i = -1;
	while (ft_env[++i])
		af_s[size + i] = ft_env[i];
	size -= 1;
	while (str[++size + end])
		af_s[size + i] = str[size + end];
	af_s[size + i] = 0;
	free(str);
	str = NULL;
	free(ft_env);
	return (af_s);
}

int	ft_check_env(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	else
		return (0);
}

char	*ft_env_convert(char *ft_env, t_env *envp)
{
	t_env	*head;

	if (ft_check_env_dollar(ft_env))
		return (ft_env);
	head = envp;
	while (head)
	{
		if (!ft_strcmp("$?", ft_env))
		{
			free(ft_env);
			ft_env = ft_itoa(g_exit_state);
			return (ft_env);
		}
		if (!ft_strcmp(head->key, ft_env + 1))
		{
			free(ft_env);
			ft_env = ft_strdup(head->value);
			return (ft_env);
		}
		head = head->next;
	}
	free(ft_env);
	ft_env = ft_strdup("\0");
	return (ft_env);
}
