/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_env_fct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asimon <asimon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:18:02 by asimon            #+#    #+#             */
/*   Updated: 2022/03/17 01:18:04 by asimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell_parsing.h"

char	*get_va_env_value(char *str)
{
	t_env		*buff;

	buff = shell.env;
	while (buff != NULL)
	{
		if (ft_strcmp(str, buff->key) == 1)
			return (ft_strncpy(buff->value, ft_strlen(buff->value)));
		buff = buff->next;
	}
	return (NULL);
}

char	*get_va_env_key(char *str)
{
	char	*cmp;
	int		i[2];
	char	*ret;

	i[0] = 0;
	i[1] = 0;
	while (str[i[0]] && str[i[0]] != ' ' && str[i[0]] != '\''
		&& str[i[0]] != '"' && str[i[0]] != '|' && str[i[0]] != '$')
		i[0]++;
	ret = malloc(sizeof(char) * (i[0] + 1));
	if (ret == NULL)
		return (NULL);
	gb_col_add_list((void *)ret);
	while (str[i[1]] && str[i[1]] != ' ' && str[i[1]] != '\''
		&& str[i[1]] != '"' && str[i[1]] != '|' && str[i[1]] != '$')
	{
		ret[i[1]] = str[i[1]]; 
		i[1]++;
	}
	ret[i[1]] = '\0';
	return (ret);
}

int	count_va_envl(int *count, char *str)
{
	char	*key;
	char	*value;
	int		ret;
	int		i;

	i = -1;
	ret = 1;
	key = get_va_env_key(str);
	if (key == NULL)
		return (0);
	ret += ft_strlen(key) - 1;
	value = get_va_env_value(key);
	if (value == NULL)
	{
		free(key);
		return (ret);
	}
	*count += ft_strlen(value);
	return (ret);
}

char	*get_va_env(char *str)
{
	char	*key;
	char	*value;
	int		i;

	i = -1;
	key = get_va_env_key(str);
	if (key == NULL)
		return (0);
	value = get_va_env_value(key);
	if (value == NULL)
	{
		return (NULL);
	}
	return (value);
}