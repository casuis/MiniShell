/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:13:13 by asimon            #+#    #+#             */
/*   Updated: 2022/03/03 13:13:14 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"

char	*set_key_env(char *str)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	size = 0;
	if (str == NULL)
		return (NULL);
	while (str[size] && str[size] != '=')
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	while (i < size)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*set_value_env(char *str)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	size = 0;
	if (str == NULL)
		return (NULL);
	while (*str && *str != '=')
		str++;
	if (*(str + 1))
		str++;
	while (str[size])
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	while (i < size)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

static t_env	*set_strings_env(t_env *ret, t_env *buff, t_env *start)
{
	int		i;

	i = 0;
	while (penv[i] != NULL)
	{
		if (i > 0)
		{
			ret = malloc(sizeof(t_env));
			if (ret == NULL)
				return (NULL);
			gb_col_add_list((void *)ret);
		}
		ret->key = set_key_env(penv[i]);
		ret->value = set_value_env(penv[i]);
		buff->next = ret;
		ret->next = NULL;
		buff = ret;
		i++;
	}
	return (start);
}

t_env	*set_env(char **penv)
{
	int		i;
	t_env	*ret;
	t_env	*buff;
	t_env	*start;

	if (penv == NULL || penv[i] == NULL)
		return (NULL);
	ret = malloc(sizeof(t_env));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	buff = ret;
	start = ret;
	return (set_strings_env(ret, buff, start));
}