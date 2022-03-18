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

#include "../includes/minishell.h"

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
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\''
		&& str[i] != '"' && str[i] != '|' && str[i] != '$')
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\''
		&& str[i] != '"' && str[i] != '|' && str[i] != '$')
	{
		ret[i] = str[i]; 
		i++;
	}
	ret[i] = '\0';
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
	ret += ft_strlen(key);
	value = get_va_env_value(key);
	if (value == NULL)
	{
		free(key);
		return (ret);
	}
	*count += ft_strlen(value);
	free(key);
	free(value);
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
		free(key);
		return (NULL);
	}
	free(key);
	return (value);
}